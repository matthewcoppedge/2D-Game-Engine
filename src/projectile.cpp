#include "projectile.h"
#include "GLTexture.h"

projectile::projectile()
{

    pos.x = 0;    // Default position settings
    pos.y = 0;
    pos.z = -1.0;

    eScale.x = 1; // default scaling
    eScale.y = 1;

    eRotate.x = 0;  // default rotations
    eRotate.y = 180;
    eRotate.z = 0;

    framesX = 1;   // number of columns in the sprite sheet
    framesY = 1;   // number of rows in the spritesheet

    xMax = 1.0 / framesX;  // default image
    xMin = 0;
    yMax = 1.0 / framesY;
    yMin = 0;
    speed = 0.01;
    isAlive = false;
    hb = new hitBox();
    hb->createCircle(0.5);
    hb->name = "arrow";
    aTime = 0;
}

projectile::~projectile()
{
    //dtor
}

void projectile::draw()
{
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTranslatef(pos.x, pos.y, pos.z);
    glRotatef(eRotate.x, 1, 0, 0);
    glRotatef(eRotate.y, 0, 1, 0);
    glRotatef(eRotate.z, 0, 0, 1);

    glScalef(eScale.x, eScale.y, 1.0);

    glBegin(GL_QUADS);
    glTexCoord2f(xMin, yMax);
    glVertex3f(-1, -1, 0);

    glTexCoord2f(xMax, yMax);
    glVertex3f(1, -1, 0);

    glTexCoord2f(xMax, yMin);
    glVertex3f(1, 1, 0);

    glTexCoord2f(xMin, yMin);
    glVertex3f(-1, 1, 0);

    glEnd();
    glPopMatrix();
}

void projectile::spawn(float x, float y)
{
    pos.x = x;
    pos.y = y;
    isAlive = true;
    dTravel = 0;
}

bool projectile::movement(bool dir, hitBox* o1)
{
    float tmp;
    draw();
    if (dir) { pos.x -= speed; xMin = 0; xMax = 1; }
    else { pos.x += speed; xMin = 1; xMax = 0; }
    if (cc.isCollideCircle(hb, o1)) { isAlive = false; return true; }
    else false;
}

void projectile::blast(bool dir, float dTime)
{
    float tmp;
    if (isAlive)
    {
        draw();
        if (aTime < 100) { xMin = 0; xMax = 1.0 / framesX; }
        if (aTime > 100 && aTime < 200) { xMin = 1.0 / framesX; xMax = 2.0 / framesX; }
        if (aTime > 300 && aTime < 400) { xMin = 2.0 / framesX; xMax = 3.0 / framesX; }
        if (aTime > 400) { xMin = 0; xMax = 1.0 / framesX; aTime -= aTime; }
        if (dir) pos.x += speed;
        else
        {
            pos.x -= speed;
            tmp = xMax;
            xMax = xMin;
            xMin = tmp;

        }
        aTime += dTime;
        dTravel += speed;
    }
    if (dTravel >= 1.5) isAlive = false;


}




