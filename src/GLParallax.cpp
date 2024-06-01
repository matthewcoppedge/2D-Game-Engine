#include "GLParallax.h"

GLParallax::GLParallax()
{
    xMin = 0.0f;
    xMax = 1.0f;
    yMin = 1.0f;
    yMax = 0.0f;
}

GLParallax::~GLParallax()
{
    //dtor
}

void GLParallax::parallaxInit(char* fileName)
{
    background->loadTexture(fileName);              //Loading Background
    myTime->startTime = clock();
}

void GLParallax::parallaxScroll(bool Auto, string dir, float speed)
{
    if (Auto)
    {
        if (clock() - myTime->startTime > 15) {
            if (dir == "up")    { yMin -= speed; yMax -= speed; }
            if (dir == "down")  { yMin += speed; yMax += speed; }
            if (dir == "left")  { xMin -= speed; xMax -= speed; }
            if (dir == "right") { xMin += speed; xMax += speed; }

            myTime->startTime = clock();
        }

        //myTime->startTime = clock();
    }
}

void GLParallax::parallaxDraw(float width, float height)
{

    glPushMatrix();
    glColor4f(r, g, b, a);                     //White   Rectangle
    glScalef(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0f, 0.0f, 0.0f);
    background->bindTexture();                 //Binding Background
    glBegin(GL_POLYGON);
        glTexCoord2f(xMin, yMin);
        glVertex3f(-width/height, -1.0f, -8.0f);
        glTexCoord2f(xMax, yMin);
        glVertex3f( width/height, -1.0f, -8.0f);
        glTexCoord2f(xMax, yMax);
        glVertex3f( width/height,  1.0f, -8.0f);
        glTexCoord2f(xMin, yMax);
        glVertex3f(-width/height,  1.0f, -8.0f);
    glEnd();
    glPopMatrix();

}
