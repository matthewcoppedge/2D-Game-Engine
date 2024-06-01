#ifndef GLWIZARD_H
#define GLWIZARD_H

#include "Common.h"
#include "GLTexture.h"
#include "GLTimer.h"
#include "hitBox.h"
#include "GLInventory.h"
#include "projectile.h"

class GLWizard
{
    public:
        GLWizard();
        virtual ~GLWizard();


        GLTexture*  texture[6];
        GLTexture* tmpTex = new GLTexture;
        GLTimer*   myTime     = new GLTimer();

        float r = 1.0f, g = 1.0f, b = 1.0f, a = 1.0f;

        bool faceRight;
        bool wasFace;

        bool firstTime;

        float health, maxHealth;

        bool alive;

        enum {IDLE, WALKLEFT, WALKRIGHT, RUN, JUMP, ATTACK, FALL, SPECIAL};

        hitBox* hb = new hitBox();

        bool inventoryOpened;
        GLInventory* inventory = new GLInventory;


        float xMax, xMin, yMax, yMin;
        int framesX;
        int framesY;
        int animFrame;
        //int actionTrigger;                                    //Used for loading actions

        bool actionTrigger[8];                                  //Used for loading actions
        float oneSec;
        float jClock;
        float pos;


        void initWizard(int, int);            //number of x, y frames
        void drawWiz(float);
        void actions(float);

        float mana, maxMana;

        vec3 wizPosition;
        vec3 wizScale;
        vec3 vert[4];

        vec2 wizAccel;
        vec2 wizVelocity;

        void movement();
        projectile* blast = new projectile();
        GLTexture* blastTex = new GLTexture();
        void initproj();
        bool projAlive;
        bool attackTiming;

        bool fixMov = false;

    protected:

    private:
};

#endif // GLWIZARD_H
