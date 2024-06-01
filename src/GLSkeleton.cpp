#include "GLSkeleton.h"
#include <cmath>

GLSkeleton::GLSkeleton()
{
    vert[0].x = -0.5f; vert[0].y = -0.5f; vert[0].z = -1.0f;
    vert[1].x =  0.5f; vert[1].y = -0.5f; vert[1].z = -1.0f;
    vert[2].x =  0.5f; vert[2].y =  0.5f; vert[2].z = -1.0f;
    vert[3].x = -0.5f; vert[3].y =  0.5f; vert[3].z = -1.0f;
}

GLSkeleton::~GLSkeleton()
{
    //dtor
}


void GLSkeleton::drawEnemy()
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
}

void GLSkeleton::PlaceEnemy(float, float, float)
{

}

void GLSkeleton::actions(float dTime, vec3 plPos, hitBox*)
{
    if (health <= 0) mode = 5;
    float tmp;
    animation(dTime);
    if (plPos.x < pos.x)
    {
        tmp = xMax;
        xMax = xMin;
        xMin = tmp;
    }
    switch (mode)
    {
        case 0:
            if (itime > 500)
            {
                if (!dCheck(plPos.x))
                {
                    mode = 1;
                }
                else
                {
                    mode = 2;
                }
            }
            break;
        case 1:
            if (!dCheck(plPos.x)) moveEn(plPos.x);
            else mode = 2;
            break;
        case 2:
            if (!(dCheck(plPos.x))) mode = 1;
            break;

        case 5:
            break;
    }
    itime +=dTime;
}

void GLSkeleton::init()
{
    pos.x =0;    // Default position settings
    pos.y =-0.595;
    pos.z =-1.0f;

    eScale.x =0.3; // default scaling
    eScale.y =0.3;


    eRotate.x =0;  // default rotations
    eRotate.y =0;
    eRotate.z =0;

    framesX =13;   // number of columns in the sprite sheet
    framesY =5;   // number of rows in the spritesheet

    xMax =1.0/framesX;  // default image
    xMin=0;
    yMax=1;
    yMin=0;
    speed = 0.0015;
    mode = 0;
    itime = 0;
    aTime = 0;
    pDiff = 0.4;
    animV = 120;
    hb = new hitBox();
    hb->createCircle(0.1);
    hb->name = "skele";
    texture->loadTexture("images/enemies/skele.png");
    pPLayerDir =true;
}

void GLSkeleton::moveEn(float ppos)
{
    if(ppos > pos.x) pos.x +=speed;
    else pos.x -=speed;
    hb->updateCenter(pos.x,0);
}

bool GLSkeleton::dCheck(float ppos)
{
    if (abs(ppos-pos.x) > 0.17) return false;
    else return true;
}
void GLSkeleton::takedmg(float dmg)
{
    health -= dmg;
    if (health <=0) mode = 5;
}


void GLSkeleton::animation(float dTime)
{
    switch(mode)
    {
        case 0:

        yMin = 3.0/framesY;
        yMax = 4.0/framesY;
        if (aTime < 200) {xMin = 0; xMax = 1.0/framesX;}
        if (aTime > 200 && aTime < 400){xMin=1.0/framesX; xMax = 2.0/framesX;}
        if (aTime > 400 && aTime < 600){xMin = 2.0/framesX; xMax = 3.0/framesX;}
        if (aTime > 800 && aTime < 1000) {xMin = 3.0/framesX; xMax = 4.0/framesX;}
        if (aTime >1000 && aTime < 1200){xMin=2.0/framesX; xMax = 3.0/framesX;}
        if (aTime > 1200 && aTime < 1400){xMin = 2.0/framesX; xMax = 3.0/framesX;}
        if (aTime > 1400) {xMin = 1.0/framesX; xMax = 2.0/framesX; aTime-=aTime;}

        break;
        case 1:
            yMin = 2.0/framesY;
            yMax = 3.0/framesY;
            if (aTime < 100) {xMin = 0; xMax = 1.0/framesX;}
            if (aTime > 100 && aTime < 200){xMin=1.0/framesX; xMax = 2.0/framesX;}
            if (aTime > 200 && aTime < 300){xMin = 2.0/framesX; xMax = 3.0/framesX;}
            if (aTime > 300 && aTime < 400) {xMin = 3.0/framesX; xMax = 4.0/framesX;}
            if (aTime > 400 && aTime < 500){xMin = 4.0/framesX; xMax = 5.0/framesX;}
            if (aTime > 500 && aTime < 600){xMin = 5.0/framesX; xMax = 6.0/framesX;}
            if (aTime > 600 && aTime < 700){xMin = 6.0/framesX; xMax = 7.0/framesX;}
            if (aTime > 700 && aTime < 800){xMin = 7.0/framesX; xMax = 8.0/framesX;}
            if (aTime > 800 && aTime < 900){xMin = 8.0/framesX; xMax = 9.0/framesX;}
            if (aTime > 900 && aTime < 1000){xMin = 9.0/framesX; xMax = 10.0/framesX;}
            if (aTime > 1000 && aTime < 1100){xMin = 10.0/framesX; xMax = 11.0/framesX;}
            if (aTime > 1100){xMin = 11.0/framesX; xMax = 12.0/framesX; aTime = 0;}
            break;
        case 2:
                yMin = 0;
                yMax = 1.0/framesY;
                if (aTime < 200) {xMin = 0; xMax = 1.0/framesX;}
                if (aTime > 200 && aTime < 400){xMin=1.0/framesX; xMax = 2.0/framesX;}
                if (aTime > 400 && aTime < 600){xMin = 2.0/framesX; xMax = 3.0/framesX;}
                if (aTime > 800 && aTime < 1000) {xMin = 3.0/framesX; xMax = 4.0/framesX;}
                if (aTime > 1000 && aTime < 1200){xMin = 4.0/framesX; xMax = 5.0/framesX;}
                if (aTime > 1200 && aTime < 1400){xMin = 5.0/framesX; xMax = 6.0/framesX;}
                if (aTime > 1400 && aTime < 1600){xMin = 6.0/framesX; xMax = 7.0/framesX;}
                if (aTime > 1600 && aTime < 1800){xMin = 7.0/framesX; xMax = 8.0/framesX;}
                if (aTime > 2000 && aTime < 2200){xMin = 8.0/framesX; xMax = 9.0/framesX;}
                if (aTime > 2200 && aTime < 2400){xMin = 9.0/framesX; xMax = 10.0/framesX;}
                if (aTime > 2400 && aTime < 2600){xMin = 10.0/framesX; xMax = 11.0/framesX;}
                if (aTime > 2600 && aTime < 2800){xMin = 11.0/framesX; xMax = 12.0/framesX;}
                if (aTime > 2800){xMin = 12.0/framesX; xMax = 13.0/framesX; aTime = 0;}

            break;
        case 5:
            yMin = 1.0/framesY;
            yMax = 2.0/framesY;
            if (aTime < 200) {xMin = 0; xMax = 1.0/framesX;}
            if (aTime > 200 && aTime < 400){xMin=1.0/framesX; xMax = 2.0/framesX;}
            if (aTime > 400 && aTime < 600){xMin = 2.0/framesX; xMax = 3.0/framesX;}
            if (aTime > 800 && aTime < 1000) {xMin = 3.0/framesX; xMax = 4.0/framesX;}
            if (aTime > 1000 && aTime < 1200){xMin = 4.0/framesX; xMax = 5.0/framesX;}
            if (aTime > 1200 && aTime < 1400){xMin = 5.0/framesX; xMax = 6.0/framesX;}
            if (aTime > 1400 && aTime < 1600){xMin = 6.0/framesX; xMax = 7.0/framesX;}
            if (aTime > 1600 && aTime < 1800){xMin = 7.0/framesX; xMax = 8.0/framesX;}
            if (aTime > 2000 && aTime < 2200){xMin = 8.0/framesX; xMax = 9.0/framesX;}
            if (aTime > 2200 && aTime < 2400){xMin = 9.0/framesX; xMax = 10.0/framesX;}
            if (aTime > 2400 && aTime < 2600){xMin = 10.0/framesX; xMax = 11.0/framesX;}
            if (aTime > 2600 && aTime < 2800){xMin = 11.0/framesX; xMax = 12.0/framesX;}
            if (aTime > 2800){xMin = 12.0/framesX; xMax = 13.0/framesX; /*aTime = 0; */}
            if (aTime > 3500) {pos.x = 1000;}
            break;

    }
    aTime += dTime;
}
