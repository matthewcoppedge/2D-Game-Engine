#include "rangedEn.h"

#include <time.h>
#include <cmath>

rangedEn::rangedEn()
{
    vert[0].x = -0.5f; vert[0].y = -0.5f; vert[0].z = -1.0f;
    vert[1].x =  0.5f; vert[1].y = -0.5f; vert[1].z = -1.0f;
    vert[2].x =  0.5f; vert[2].y =  0.5f; vert[2].z = -1.0f;
    vert[3].x = -0.5f; vert[3].y =  0.5f; vert[3].z = -1.0f;
}

void rangedEn::init()
{
    pos.x =0.5;    // Default position settings
    pos.y =-0.6;
    pos.z =-1.0f;

    eScale.x =.28; // default scaling
    eScale.y =.28;


    eRotate.x =0;  // default rotations
    eRotate.y =0;
    eRotate.z =0;

    framesX =8;   // number of columns in the sprite sheet
    framesY =8;   // number of rows in the spritesheet

    xMax =1.0/framesX;  // default image
    xMin=0;
    yMax=6.0/framesY;
    yMin=5.0/framesY;
    speed = 0.0015;
    mode = 0;
    itime = 0;
    aTime = 0;
    pDiff = 0.4;
    animV = 120;
    initProj();
    hb = new hitBox();
    hb->createCircle(0.1);
    hb->name = "archer";
    texture->loadTexture("images/enemies/archer.png");
    pPLayerDir =true;

}
void rangedEn :: initProj()
{
    arrowProj = new projectile();
    arrowTex = new GLTexture();
    arrowTex->loadTexture("images/enemies/arrow.png");
    arrowProj->speed = 0.1;
    arrowProj->eScale.x = 0.1;
    arrowProj->eScale.y = 0.08;
    arrowProj->hb->radius = 0.45;

}

rangedEn::~rangedEn()
{
    //dtor
}
void rangedEn::drawEnemy()
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

void rangedEn::PlaceEnemy(float x, float y, float z)
{
    pos.x=x;
    pos.y=y;
    pos.z=z;
}

void rangedEn::actions(float dTime, vec3 playerPos,hitBox* player)
{
    float tmp;
    animation(dTime);
    if (playerPos.x < pos.x)
    {
        tmp = xMax;
        xMax = xMin;
        xMin = tmp;
    }
    hb->updateCenter(pos.x,pos.y);
    switch(mode)
    {
       case 0:
            if (itime < 3500)itime+=dTime;
            else {mode = 1; itime=0;}
            break;
        case 1:
            if (itime < 1200 && !dCheck(playerPos.x)) moveEn(playerPos.x);
            else
            {
                mode =2;
                itime = 0;
                aTime = 0;
            }
            break;
        case 2:
            if (itime < 800) {itime += dTime;}
            else {itime=0; mode=3;}
            break;
        case 3:
            if (pos.x < playerPos.x) arrowProj->spawn(pos.x,0);
            else{ arrowProj->spawn(pos.x,0);}

            mode = 4;
            itime = 0;
            break;
        case 4:
            if (playerPos.x > pos.x) playerDir = false;
            else playerDir = true;
            mode = 5;
            break;
        case 5:

            if (itime <8000 && arrowProj->isAlive)
            {
                fireArrow(playerPos.x,player);
                itime +=dTime;
            }
            else
            {
                itime = 0;
                mode = 0;
            }
            break;
        case 6:
            break;
        case 8:
            break;
        case 9:
        if (itime < 500)
        {
            rmoveEn(playerPos.x);
        }
        else {mode = 0;}
        itime +=dTime;
        break;
    }
}

void rangedEn::animation(float dTime)
{

    if (mode == 2)
    {
        if (aTime < animV) {xMin=0; xMax = 1.0/framesX; yMin=3.0/framesY; yMax = 4.0/framesY;}
        if (aTime > animV && aTime < animV*2) {xMin=1.0/framesX; xMax = 2.0/framesX; yMin=3.0/framesY; yMax = 4.0/framesY;}
        if (aTime > animV*2 && aTime < animV*3) {xMin=2.0/framesX; xMax = 3.0/framesX; yMin=3.0/framesY; yMax = 4.0/framesY;}
        if (aTime > animV*3 && aTime < animV*4) {xMin=3.0/framesX; xMax = 4.0/framesX; yMin=3.0/framesY; yMax = 4.0/framesY;}
        if (aTime > animV*4 && aTime < animV*5) {xMin=4.0/framesX; xMax = 5.0/framesX; yMin=3.0/framesY; yMax = 4.0/framesY;}
        if (aTime > animV*5 && aTime < animV*6) {xMin=5.0/framesX; xMax = 6.0/framesX; yMin=3.0/framesY; yMax = 4.0/framesY;}
        if (aTime > animV*6 && aTime < animV*7) {xMin=6.0/framesX; xMax = 7.0/framesX; yMin=3.0/framesY; yMax = 4.0/framesY;}
    }
    else if (mode == 6)
    {
        if (aTime < animV) {xMin=0; xMax = 1.0/framesX; yMin=3.0/framesY; yMax = 4.0/framesY;}
        if (aTime > animV && aTime < animV*2) {xMin=1.0/framesX; xMax = 2.0/framesX; yMin=1.0/framesY; yMax = 2.0/framesY;}
        if (aTime > animV*2 && aTime < animV*3) {xMin=2.0/framesX; xMax = 3.0/framesX; yMin=1.0/framesY; yMax = 2.0/framesY;}
        if (aTime > animV*3 && aTime < animV*4) {xMin=3.0/framesX; xMax = 4.0/framesX; yMin=1.0/framesY; yMax = 2.0/framesY;}
        if (aTime > animV*4 && aTime < animV*5) {xMin=4.0/framesX; xMax = 5.0/framesX; yMin=1.0/framesY; yMax = 2.0/framesY;}
        if (aTime > animV*5 && aTime < animV*6) {xMin=5.0/framesX; xMax = 6.0/framesX; yMin=1.0/framesY; yMax = 2.0/framesY;}
        if (aTime > animV*7 && aTime < animV*7) {xMin=6.0/framesX; xMax = 7.0/framesX; yMin=1.0/framesY; yMax = 2.0/framesY;}
        if (aTime > animV*8 && aTime < animV*8) {xMin=7.0/framesX; xMax = 8.0/framesX; yMin=1.0/framesY; yMax = 2.0/framesY;}
        if (aTime > animV*9 && aTime < animV*9) {xMin=7.0/framesX; xMax = 9.0/framesX; yMin=1.0/framesY; yMax = 2.0/framesY; mode = 8;}
    }
    else
    {
        xMax =1.0/framesX;  // default image
        xMin=0;
        yMax=6.0/framesY;
        yMin=5.0/framesY;
    }
    aTime+=dTime;

}
void rangedEn::rmoveEn(float pPos)
{
    if (pPos < pos.x){pos.x-=speed;}
    else pos.x+=speed;
}
void rangedEn::moveEn(float pPos)
{
    if (pPos < pos.x){pos.x+=speed;}
    else pos.x-=speed;
}


void rangedEn::fireArrow(float pPos,hitBox* player)
{
   arrowTex->bindTexture();
   if (playerDir) {arrowProj->movement(true,player);arrowProj->hb->updateCenter(arrowProj->pos.x+1.8,0);}     //left fire
   else {arrowProj->movement(false,player);arrowProj->hb->updateCenter(arrowProj->pos.x-0.8,0);}    //right fire  //shift if necessary to function on screen

}

bool rangedEn::dCheck(float pPos)
{
    if (abs(pPos - pos.x) >= pDiff) return true;
    else return false;
}
void rangedEn::die()
{
    mode = 6;
    alive = false;
}


