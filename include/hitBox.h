#ifndef HITBOX_H
#define HITBOX_H
#include<common.h>
#include<GLTexture.h>
#include<GLTimer.h>

class hitBox
{
    public:
        hitBox();
        hitBox(vec4,vec2);
        virtual ~hitBox();

        box verts;
        string name;
        float radius;
        vec2 center;
        void createBox(float,float);
        void updateCenter(vec2);
        void updateCenter(float,float);
        void createCircle(float);
        void display(vec2);
        void displayCircle();
        void drawLine(vec2,vec2,float);
        box boundsToBox();
        void printBounds();
        void printCenter();

    protected:

    private:
};

#endif // HITBOX_H
