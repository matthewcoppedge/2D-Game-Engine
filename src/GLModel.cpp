#include "GLModel.h"

GLModel::GLModel()
{
    RotateX = 0.0f;
    RotateY = 0.0f;                   //Init Rotation Values
    RotateZ = 0.0f;

    //zoom = -8.0f;
    xPos =   0.0f;
    yPos =   0.0f;                    //Init Model Position Values
    zPos =  -8.0f;
}

GLModel::~GLModel()
{
    //dtor
}

void GLModel::drawModel()
{
    glColor3f(1.0, 1.0, 1.0);         //Set Model Color
    glTranslatef(xPos, yPos, zPos);   //Set Model Position

    glRotatef(RotateX, 1, 0, 0);
    glRotatef(RotateY, 0, 1, 0);      //Rotation Controllers
    glRotatef(RotateZ, 0, 0, 1);

    glutSolidTeapot(1.5);             //Load and render object

}
