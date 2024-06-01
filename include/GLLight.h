#ifndef GLLIGHT_H
#define GLLIGHT_H

#include<GLScene.h>


class GLLight : GLScene                 //Inheritance from Scene Class (Derived : Base)
{
    public:
        GLLight();                      //Default Constructor
        GLLight(GLenum Lights);         //Override Constructor
        virtual ~GLLight();             //Destructor

        GLvoid setLight(GLenum);        //Setting Lights

        const GLfloat light_ambient[4]  = { 0.0f, 0.0f, 0.0f, 1.0f };
        const GLfloat light_diffuse[4]  = { 1.0f, 1.0f, 1.0f, 1.0f };
        const GLfloat light_specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
        const GLfloat light_position[4] = { 2.0f, 5.0f, 5.0f, 0.0f };

        const GLfloat mat_ambient[4]    = { 0.7f, 0.7f, 0.7f, 1.0f };
        const GLfloat mat_diffuse[4]    = { 0.8f, 0.8f, 0.8f, 1.0f };
        const GLfloat mat_specular[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
        const GLfloat high_shininess[4] = { 100.0f };

    protected:

    private:
};

#endif // GLLIGHT_H
