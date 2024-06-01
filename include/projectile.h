#ifndef PROJECTILE_H
#define PROJECTILE_H



#include<common.h>
#include<GLTexture.h>
#include<GLTimer.h>
#include<collisionCheck.h>
#include<hitBox.h>

class projectile
{
public:
    projectile();
    virtual ~projectile();

    void draw();
    void spawn(float, float);
    bool movement(bool, hitBox*);

    bool wait;
    bool isAlive;

    vec3 pos;
    vec2 eScale;
    vec3 eRotate;

    int framesX;
    int framesY;

    int action;
    float speed;
    float xMax, xMin, yMax, yMin;
    hitBox* hb;
    collisionCheck cc;
    void blast(bool, float);
    float aTime;
    float dTravel = 0;


protected:

private:
};

#endif // PROJECTILE_H
