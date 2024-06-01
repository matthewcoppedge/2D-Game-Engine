#include "hitBox.h"
#include "common.h"
#include <cmath>

hitBox::hitBox() //standard constructor for hitbox
{
    center.x = 0;
    center.y = 0;
    cout << "hitbox created" << endl;
}

hitBox::~hitBox()
{
    //dtor
}
hitBox::hitBox(vec4 b, vec2 c)
{
    center = c;
}

void hitBox::createCircle(float rad) //creates hitbox for circle given radius
{
    radius = rad;
}

void hitBox::createBox(float x, float y)
{
    verts.v1.x = -x;
    verts.v1.y = y;

    verts.v2.x = x;
    verts.v2.y = y;

    verts.v3.x = x;
    verts.v3.y = -y;

    verts.v4.x = -x;
    verts.v4.y = -y;

}

void hitBox::drawLine(vec2 v1, vec2 v2,float color)
{
    glLineWidth(1.5);
    glColor3f(color,0.0,0.0);
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
        glVertex3f(v1.x,v1.y,-5);
        glVertex3f(v2.x,v2.y,-5);
    glEnd();
    glEnable(GL_LIGHTING);
}
box hitBox::boundsToBox()
{
    box b;

    b.v1.x = center.x + verts.v1.x;
    b.v1.y = center.y + verts.v1.y;

    b.v2.x = center.x + verts.v2.x;
    b.v2.y = center.y + verts.v2.y;

    b.v3.x = center.x + verts.v3.x;
    b.v3.y = center.y + verts.v3.y;

    b.v4.x = center.x + verts.v4.x;
    b.v4.y = center.y + verts.v4.y;
}

void hitBox::display(vec2 c)
{
    center = c;
    vec2 v1,v2;

    v1.x = center.x + verts.v1.x;
    v1.y = center.y + verts.v1.y;
    v2.x = center.x + verts.v2.x;
    v2.y = center.y + verts.v2.y;
    drawLine(v1,v2,1.0);

    v1.x = center.x + verts.v2.x;
    v1.y = center.y + verts.v2.y;
    v2.x = center.x + verts.v3.x;
    v2.y = center.y + verts.v3.y;
    drawLine(v1,v2,0.5);

    v1.x = center.x + verts.v3.x;
    v1.y = center.y + verts.v3.y;
    v2.x = center.x + verts.v4.x;
    v2.y = center.y + verts.v4.y;
    drawLine(v1,v2,0.75);

    v1.x = center.x + verts.v4.x;
    v1.y = center.y + verts.v4.y;
    v2.x = center.x + verts.v1.x;
    v2.y = center.y + verts.v1.y;
    drawLine(v1,v2,0.25);

}

void hitBox::displayCircle() //shows circle hitbox on screen
{
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glColor3f(1.0f, 0.0f, 0.0f); // Set color to red
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 20; i++)
        {
            float theta = 2.0f * M_PI * float(i) / float(20);
            float x = radius * cosf(theta);
            float y = radius * sinf(theta);
            glVertex2f(x + center.x, y + center.y);
        }
    glColor3f(1.0, 1.0, 1.0);
    glEnd();
    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
}
void hitBox::updateCenter(vec2 c) //updates center of circle
{
    center.x = c.x;
    center.y = c.y;
}


void hitBox::updateCenter(float x, float y) //override for center update
{
    center.x = x;
    center.y = y;
}

void hitBox::printBounds()
{

    cout << "topBound = " << center.x << ", " << center.y+radius << endl;
    cout << "rightBound = " << center.x+radius << ", " << center.y << endl;
    cout << "bottomBound = " << center.x << ", " << center.y-radius << endl;
    cout << "leftBound = " << center.x-radius << ", " << center.y << endl;

}

void hitBox::printCenter()
{
    cout << "Center = " << center.x << ", " << center.y;
}
