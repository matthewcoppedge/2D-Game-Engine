#include "bClock.h"
#include "GLTimer.h"

bClock::bClock()
{
    cTime = (float)clock();
    sTime = cTime;
}

bClock::~bClock()
{
    //dtor
}
float bClock::update()
{
   sTime = cTime;
   cTime = (float)clock();
   dTime = cTime-sTime;
}
