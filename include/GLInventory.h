#ifndef GLINVENTORY_H
#define GLINVENTORY_H

#include "Common.h"
#include "GLTexture.h"
#include "GLTimer.h"
#include <vector>
#include <ctime>
#include <cstdlib>


class invNode {
    public:
    int lvl = 0;
    int maxLvl;
    float xMin, xMax, yMin, yMax, framesX, framesY;
    GLTexture* tex = new GLTexture;
    vec3 pos;

    void initNode(char* fileName, float x, float y) {
        tex->loadTexture(fileName);
        framesX = (float)tex->width / 20.0;
        framesY = (float)tex->height / 20.0;
        xMin = x / framesX; xMax = xMin + 1.0/framesX;
        yMin = y / framesY; yMax = yMin + 1.0/framesY;
    }

    void setNode(float x, float y) {
        xMin = x / framesX; xMax = xMin + 1.0/framesX;
        yMin = y / framesY; yMax = yMin + 1.0/framesY;
    }

    void setNode(char* fileName, float x, float y) {
        tex->loadTexture(fileName);
        framesX = (float)tex->width / 20.0;
        framesY = (float)tex->height / 20.0;
        xMin = x / framesX; xMax = xMin + 1.0/framesX;
        yMin = y / framesY; yMax = yMin + 1.0/framesY;
    }
};


class GLInventory
{
    public:
        GLInventory();
        virtual ~GLInventory();

        vec3 vert[4];

        enum {hpPot, clsPot, dmgUp, hpUp, clsUp, dtUp, goldUp, revive};

        invNode* relics[8];

        void initInventory(int);
        void drawInventory(int);

        void awardRelic();
        void removeRelic(int);

        vector<int> drops = {goldUp, goldUp, goldUp, hpUp, clsUp, revive};

        GLTimer* tmr = new GLTimer;

        int level = 0;


    protected:

    private:
};

#endif // GLINVENTORY_H
