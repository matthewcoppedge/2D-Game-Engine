#ifndef SLIME_H
#define SLIME_H
#include<common.h>
#include<GLTexture.h>
#include<GLTimer.h>
#include<collisionCheck.h>
#include "hitBox.h"
#include "GLSounds.h"
//#include "glEnemy.h"

class slime
{
    public:
        slime();
        virtual ~slime();
        void draw();
        bool actions(float,vec3, GLSounds*);
        void jump(float, GLSounds*);
        void slide(float);
        void rslide(float);
        void animation(float);
        void initSlime(int);
        void initBoss(int);


        bool isAlive;
        float jumpStart;
        float jumpEnd;
        float jumpLength;
        float midPoint;

        vec3 pos;
        vec2 eScale;
        vec3 eRotate;
        vec3 vert[4];

        int framesX;
        int framesY;

        float r = 1.0f, g = 1.0f, b = 1.0f;

        float health = 10.0f;

        bool alive = true;
        bool returnedRelic = false;

        int mode;
        int animationMode;
        int action;
        float speed;
        float time;
        float aTime;
        float xMax,xMin,yMax,yMin;
        float frameNum;
        float moveSpeed;
        float jScale;
        hitBox* hb;
        GLTexture* texture = new GLTexture();
        void takedmg(float);
        float initialy;
        bool isboss;
        void die();
        bool getHit();

    protected:

    private:
};

#endif // SLIME_H
#include<common.h>
#include<GLTexture.h>
#include<GLTimer.h>
#include<collisionCheck.h>
