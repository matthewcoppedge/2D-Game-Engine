#ifndef GLROGUE_H
#define GLROGUE_H


#include "Common.h"
#include "GLTexture.h"
#include "GLTimer.h"
#include "hitBox.h"
#include "GLInventory.h"

class GLRogue
{
    public:
        GLRogue();
        virtual ~GLRogue();

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

        float health = 15.0f, maxHealth;
        float stamina, maxStam;

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


#endif // GLROGUE_H
