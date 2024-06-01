#ifndef GLPLAYER_H
#define GLPLAYER_H

#include "Common.h"
#include "GLTexture.h"
#include "GLTimer.h"

class GLPlayer
{
    public:
        GLPlayer();
        virtual ~GLPlayer();

        GLTexture* texture    = new GLTexture();
        GLTimer*   myTime     = new GLTimer();

        enum {STAND, WALKLEFT, WALKRIGHT, RUN, JUMP, ATTACK};

        float xMax, xMin, yMax, yMin;
        int framesX;
        int framesY;
        int actionTrigger;                                    //Used for loading actions

        void initPlayer(int, int, char* fileName);            //number of x, y frames
        void drawPlayer();
        void actions();

        vec3 plPosition;
        vec3 plScale;
        vec3 vert[4];

    protected:

    private:
};

#endif // GLPLAYER_H
