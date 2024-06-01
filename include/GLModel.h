#ifndef GLMODEL_H
#define GLMODEL_H

#include <common.h>

class GLModel
{
    public:
        GLModel();
        virtual ~GLModel();

        GLfloat RotateX;         //Rotation around X
        GLfloat RotateY;         //Rotation around Y
        GLfloat RotateZ;         //Rotation around Z

        //GLfloat zoom;          //Not required (just use z Value)
        GLfloat xPos;            //Model X position
        GLfloat yPos;            //Model Y position
        GLfloat zPos;            //Model Z position

        void drawModel();        //Function to display model on screen

    protected:

    private:
};

#endif // GLMODEL_H
