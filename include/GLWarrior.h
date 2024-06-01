#ifndef GLPLAYER_H
#define GLPLAYER_H

#include "Common.h"
#include "GLTexture.h"
#include "GLTimer.h"
#include "hitBox.h"
#include "GLInventory.h"

class GLWarrior
{
    public:
        GLWarrior();
        virtual ~GLWarrior();

        GLTexture* texture[9];
        GLTimer*   myTime     = new GLTimer();

        enum {STAND, WALKLEFT, WALKRIGHT, RUN, JUMP, ATTACK, SPECIAL, OUCH};

        float xMax, xMin, yMax, yMin;
        float oneSec;
        float jClock;
        float maxy;
        int framesX;
        int framesY;
        int animFrame;
        bool faceRight;
        bool actionTrigger[7];
        float pos;                                                              //Used for loading actions

        bool isDead = false;

        float stamina, maxStam;

        float health, maxHealth;

        bool alive = true;

        float r = 1.0f, g = 1.0f, b = 1.0f, a = 1.0f;

        hitBox* hb = new hitBox();

        void initPlayer();
        void drawPlayer(float);
        void actions(float);

        bool inventoryOpened = false;
        GLInventory* inventory = new GLInventory;


        vec3 plPosition;
        vec3 plScale;
        vec3 vert[4];

        vec2 plAccel;
        vec2 plVelocity;

        void movement();

    protected:

    private:
};

#endif // GLPLAYER_H
