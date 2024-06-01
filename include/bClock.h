#ifndef BCLOCK_H
#define BCLOCK_H


class bClock
{
    public:
        bClock();
        virtual ~bClock();

        float sTime,cTime,dTime;

        float update();

    protected:

    private:
};

#endif // BCLOCK_H
