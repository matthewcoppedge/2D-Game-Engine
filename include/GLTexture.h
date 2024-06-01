#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include "Common.h"

class GLTexture
{
    public:
        GLTexture();
        virtual      ~GLTexture();
        GLuint         tex;
        GLint          width;
        GLint          height;
        unsigned char* image;

        void loadTexture(char*);             //Reads the file using path of file
        void bindTexture();                  //Binds the texture

    protected:

    private:
};

#endif // GLTEXTURE_H
