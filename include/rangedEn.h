#ifndef RANGEDEN_H
#define RANGEDEN_H


#include<common.h>
#include<GLTexture.h>
#include<GLTimer.h>
#include<common.h>
#include<GLTexture.h>
#include<GLTimer.h>
//#include<arrow.h>
#include<projectile.h>
#include <hitBox.h>


class rangedEn
{
    public:
        rangedEn();
        virtual ~rangedEn();
        void drawEnemy();
        void PlaceEnemy(float,float,float);
        void actions(float,vec3,hitBox*);
        void init();

        bool alive = true;

        vec3 pos;
        vec2 eScale;
        vec3 eRotate;
        vec3 vert[4];
        GLTexture* texture = new GLTexture();

        float r = 1.0f, g = 1.0f, b = 1.0f;


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
        void rmoveEn(float);
        void fireArrow();
        void fireArrow(float,hitBox*);
        bool dCheck(float);
        projectile* arrowProj;
        GLTexture* arrowTex;
        void animation(float);
        bool playerDir;
        bool pPLayerDir;
        bool nPLayerDir;
        hitBox* hb;
        void initProj();
        float health = 7.0f;
        void takedmg(float);
        void die();
    protected:

    private:
};

#endif // RANGEDEN_H
