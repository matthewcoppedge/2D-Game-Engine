#ifndef GLSKELETON_H
#define GLSKELETON_H

#include "Common.h"
#include "GLTexture.h"
#include "GLTimer.h"
#include "hitBox.h"

class GLSkeleton
{
    public:
        GLSkeleton();
        virtual ~GLSkeleton();
        void drawEnemy();
        void PlaceEnemy(float,float,float);
        void actions(float,vec3,hitBox*);
        void init();

        vec3 pos;
        vec2 eScale;
        vec3 eRotate;
        vec3 vert[4];
        GLTexture* texture = new GLTexture();

        float r = 1.0f, g = 1.0f, b = 1.0f, a = 1.0f;

        bool firstTime = true;

        int framesX;
        int framesY;

        int action;
        float speed;
        float animV;
        float xMax,xMin,yMax,yMin;

        float itime;
        float aTime;
        float pDiff;
        int mode;
        void moveEn(float);
        bool dCheck(float);
        void animation(float);
        bool playerDir;
        bool pPLayerDir;
        bool nPLayerDir;
        hitBox* hb;
        float health = 10.0f;
        void takedmg(float);
};

#endif // GLSKELETON_H
