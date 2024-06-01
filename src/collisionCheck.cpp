#include "collisionCheck.h"
#include <math.h>

collisionCheck::collisionCheck()
{
    //ctor
}

collisionCheck::~collisionCheck()
{
    //dtor
}


bool collisionCheck::isCollideAA(hitBox* o1, hitBox* o2) //pass in the hitbox of two objects and it will return true if they are touching
{
    box b1,b2;
    if (o1->center.x < o2->center.x)
    {
        b1 = o1->boundsToBox();
        b2 = o2->boundsToBox();
    }
    else
    {
        b1 = o2->boundsToBox();
        b2 = o1->boundsToBox();
    }
    if (b1.v2.x >= b2.v2.x)
    {
        if (b1.v2.y>= b2.v2.y) return true;
        else return false;
    }
    else return false;
}

bool collisionCheck::isCollideCircle(hitBox* o1, hitBox* o2) //pass in two objects in oder to check for collision
{
    float dx,dy,dt;
    float rad = o1->radius+o2->radius;
    dx = abs(o1->center.x - o2->center.x);
    dy = abs(o1->center.y - o2->center.y);
    dt = dx+dy;
    if (dt<= rad)
    {
       //cout << o1->name << "colliding with" << o2->name << endl;
        return true;
    }
    else return false;
}

hitBox* collisionCheck::isCollideCircleL(hitBox* o1, vector<hitBox*> hbs) //pass in two objects in oder to check for collision
{
    hitBox* chb;
    int l = hbs.size()-1;
    for (int i = 0; i<l; i++)
    {
        chb = hbs[i];
        if (isCollideCircle(o1,chb))
        return chb;
    }
    return nullptr;

}
