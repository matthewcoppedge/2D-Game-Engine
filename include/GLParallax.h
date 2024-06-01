#ifndef GLPARALLAX_H
#define GLPARALLAX_H

#include "Common.h"
#include "GLTexture.h"
#include "GLTimer.h"

class GLParallax
{
    public:
        GLParallax();
        GLTexture* background = new GLTexture();
        GLTimer*   myTime     = new GLTimer();
        virtual ~GLParallax();

        float r = 1.0f, g = 1.0f, b = 1.0f, a = 1.0f;

        float x_scale = 0.0f;
        float x_translate = 0.0f;

        float z = 1.0f;

        void parallaxInit(char*);                        //Load filename of the background image
        void parallaxScroll(bool, string, float);        //Auto, Direction, Speed
        void parallaxDraw(float, float);                 //width, height

        float xMax, xMin, yMax, yMin;

    protected:

    private:
};

#endif // GLPARALLAX_H
