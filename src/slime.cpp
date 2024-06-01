#include "slime.h"
#include <time.h>
#include <cmath>
#include "hitBox.h"
#include <cstdlib> // for rand() and srand()
#include <random>


slime::slime()
{
    vert[0].x = -0.5f; vert[0].y = -0.5f; vert[0].z = -1.0f;
    vert[1].x =  0.5f; vert[1].y = -0.5f; vert[1].z = -1.0f;
    vert[2].x =  0.5f; vert[2].y =  0.5f; vert[2].z = -1.0f;
    vert[3].x = -0.5f; vert[3].y =  0.5f; vert[3].z = -1.0f;

}

slime::~slime()
{

}

void slime::draw()
{
    glTranslatef(pos.x, pos.y, pos.z);
    glScalef(eScale.x, eScale.y, 1);

    glColor3f(r, g, b);                        //White   Rectangle
    texture->bindTexture();                             //Binding Player sprite sheet

    glBegin(GL_QUADS);
        glTexCoord2f(xMin, yMax); glVertex3f(vert[0].x,vert[0].y, vert[0].z);
        glTexCoord2f(xMax, yMax); glVertex3f(vert[1].x,vert[1].y, vert[1].z);
        glTexCoord2f(xMax, yMin); glVertex3f(vert[2].x,vert[2].y, vert[2].z);
        glTexCoord2f(xMin, yMin); glVertex3f(vert[3].x,vert[3].y, vert[3].z);
    glEnd();
    //hb->displayCircle();
}


void slime::initSlime(int type)
{

    pos.x =  0.585f;                 //Initialize player x pos
    pos.y = -0.615f;                //Initialize player y pos
    pos.z = -1.0f;                 //Initialize player z pos

    eScale.x =0.08; // default scaling
    eScale.y =0.08;


    eRotate.x =0;  // default rotations
    eRotate.y =0;
    eRotate.z =0;

    framesX =8;   // number of columns in the sprite sheet
    framesY =5;   // number of rows in the spritesheet
    frameNum =1.0/framesX;

    frameNum = 110;
    xMax =1.0/framesX;  // default image
    xMin=0;
    //yMax = 0.2;
    //yMin = 0;
    yMin=(float)(type-1)/framesY;
    yMax=(float)type/framesY;

    speed =0.01;  // moving speed
    action=1;     // set actions
    jumpLength = 0.25601;
    moveSpeed = .015;
    jScale = 4/jumpLength;
    mode = 0;
    time = 0;
    aTime = 0;
    hb = new hitBox();
    hb->name = "slime";
    hb->createCircle(0.125);
    texture->loadTexture("images/enemies/slime.png"); \
    animationMode = 0;
    isAlive = true;
    initialy = pos.y;
    isboss = false;


}


void slime::initBoss(int type)
{
    pos.x =  0.585f;                 //Initialize player x pos
    pos.y = -0.465f;                //Initialize player y pos
    pos.z = -1.0f;                 //Initialize player z pos

    eScale.x =0.35; // default scaling
    eScale.y =0.35;


    eRotate.x =0;  // default rotations
    eRotate.y =0;
    eRotate.z =0;

    framesX =8;   // number of columns in the sprite sheet
    framesY =5;   // number of rows in the spritesheet
    frameNum =1.0/framesX;

    frameNum = 110;
    xMax =1.0/framesX;  // default image
    xMin=0;
    //yMax = 0.2;
    //yMin = 0;
    yMin=(float)(type-1)/framesY;
    yMax=(float)type/framesY;

    speed =0.01;  // moving speed
    action=1;     // set actions
    jumpLength = 0.25601;
    moveSpeed = .015;
    jScale = 4/jumpLength;
    mode = 0;
    time = 0;
    aTime = 0;
    hb = new hitBox();
    hb->name = "slime";
    hb->createCircle(0.12);
    texture->loadTexture("images/enemies/slime.png");
    animationMode = 0;
    isAlive = true;
    initialy = pos.y;
    isboss = true;
}

bool slime::actions(float dTime,vec3 playerPos, GLSounds* slimeJump)
{
    float tval;
    if (isboss) tval = 2500;
    else tval = 1200;
    animation(dTime);
    switch (mode)
    {
    case 0:
        pos.y = initialy;
        if (time < tval) time += dTime;
        else { mode = 1; time = 0; }
        break;
    case 1:
        jumpStart = pos.x;
        if (jumpStart > 0)jumpEnd = jumpStart + jumpLength;
        midPoint = jumpEnd / 2;
        mode = 2;
        break;

    case 2:
        if (time < 200)
        {
            slide(playerPos.x);
            jump(pos.x, slimeJump);
            //jump(pos.x);
            time += dTime;
        }
        else { mode = 0; time = 0; jumpEnd = pos.x;}
        break;
    case 3:
        animationMode = 2;
        break;
    case 4:
        pos.y = -10000;
        mode = 5;
        break;
    case 5:
        break;
    case 6:
        time = 0;
        mode = 7;
        break;
    case 7:
        if (time < 500)
        {
            if (pos.y != initialy) {pos.y = initialy;}
            rslide(playerPos.x);
        }
        else {mode = 1;}
        time +=dTime;
    break;


    }
    if (isboss) {
        hb->updateCenter(pos.x, pos.y+ 0.45);
        hb->createCircle(0.20);
    }
    else {
        hb->updateCenter(pos.x,pos.y+ 0.45);
        hb->createCircle(0.12);
    }
    if (health <= 0) {
        die();
        return true;
    }
    return false;
}

bool slime :: getHit()
{
    if (health > 0.0f) {
        if (mode !=6)
        {
            if (mode != 7)
            {
                mode = 6;
            }
        }
    }
    else {
        die();
        return true;
    }
    return false;

}


void slime::animation(float dTime)
{
    switch (animationMode)
    {
    case 0:
        if (aTime < frameNum) { xMin = 0; xMax = 1.0 / framesX; }
        if (aTime > frameNum && aTime < frameNum * 2) { xMin = 1.0 / framesX; xMax = (2.0 / framesX); }
        if (aTime > frameNum * 2 && aTime < frameNum * 3) { xMin = (2.0 / framesX); xMax = (3.0 / framesX); }
        if (aTime > frameNum * 3 && aTime < frameNum * 4) { xMin = (6.0 / framesX); xMax = (7.0 / framesX); }
        if (aTime > frameNum * 4 && aTime < frameNum * 5) { xMin = 7.0 / framesX; xMax = (8.0 / framesX); }
        if (aTime > frameNum * 5 && aTime < frameNum * 6) { xMin = (8.0 / framesX); xMax = (9.0 / framesX); }
        if (aTime > frameNum * 6) { aTime = 0; }
        aTime += dTime;
        break;

    case 1:
        if (aTime < frameNum) { xMin = 0; xMax = 1.0 / framesX; }
        if (aTime > frameNum && aTime < frameNum * 2) { xMin = 1.0 / framesX; xMax = (2.0 / framesX); }
        if (aTime > frameNum * 2 && aTime < frameNum * 3) { xMin = (2.0 / framesX); xMax = (3.0 / framesX); }
        if (aTime > frameNum * 3 && aTime < frameNum * 4) { xMin = (6.0 / framesX); xMax = (7.0 / framesX); }
        if (aTime > frameNum * 4 && aTime < frameNum * 5) { xMin = 7.0 / framesX; xMax = (8.0 / framesX); }
        if (aTime > frameNum * 5 && aTime < frameNum * 6) { xMin = (8.0 / framesX); xMax = (9.0 / framesX); }
        if (aTime > frameNum * 6) { aTime = 0; }
        aTime += dTime;
        break;

    case 2:
        cout << "called";
        if (aTime < frameNum) { xMin = 0; xMax = 1.0 / framesX; }
        if (aTime > frameNum && aTime < frameNum * 2) { xMin = 1.0 / framesX; xMax = (2.0 / framesX); }
        if (aTime > frameNum * 2 && aTime < frameNum * 3) { xMin = (2.0 / framesX); xMax = (3.0 / framesX); }
        if (aTime > frameNum * 3 && aTime < frameNum * 4) { xMin = (6.0 / framesX); xMax = (7.0 / framesX); }
        if (aTime > frameNum * 4 && aTime < frameNum * 5) { xMin = 7.0 / framesX; xMax = (8.0 / framesX); }
        if (aTime > frameNum * 5 && aTime < frameNum * 6) { xMin = (8.0 / framesX); xMax = (9.0 / framesX); }
        if (aTime > frameNum * 6) { aTime = 0; }
        aTime += dTime;
        eScale.x -= 0.0001;
        eScale.y -= 0.0001;
        if (eScale.x <= 0)
        {
            mode = 4;
            animationMode = 3;
        }
        break;
    case 3:
        break;
    }

}

void slime::slide(float playerX)
{

    if(playerX < pos.x)pos.x-=moveSpeed;
    else if (playerX>pos.x) pos.x+=moveSpeed;

}

void slime::rslide(float playerX)
{

    if(playerX < pos.x)pos.x+=moveSpeed;
    else if (playerX>pos.x) pos.x-=moveSpeed;

}

void slime::jump(float xVal, GLSounds* slimeJump)
{
    slimeJump->playSound("sounds/slimeJump.wav");
    float d = jScale* abs(xVal-jumpStart);
    if (!isboss) pos.y = -0.3 + (0.27* exp(-(pow((d-2),2))));
    else pos.y = -0.15 + (0.27* exp(-(pow((d-2),2))));
}

void slime:: die()
{
    mode = 2;
    isAlive = false;
}
