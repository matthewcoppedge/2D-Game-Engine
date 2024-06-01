#ifndef COLLISIONCHECK_H
#define COLLISIONCHECK_H

#include<common.h>
#include<GLTimer.h>
#include <vector>
#include"hitBox.h"
class collisionCheck
{
    public:
        collisionCheck();
        virtual ~collisionCheck();

        bool isCollideAA(hitBox* o1, hitBox* o2);
        hitBox* isCollideCircleL(hitBox* o1, vector<hitBox*>);
        bool isCollideCircle(hitBox* o1, hitBox* o2);


    protected:

    private:
};

#endif // COLLISIONCHECK_H
