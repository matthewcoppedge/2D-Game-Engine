#ifndef GLSOUNDS_H
#define GLSOUNDS_H

#include<Common.h>

class GLSounds
{
    public:
        GLSounds();
        virtual ~GLSounds();

        ISoundEngine *engine = createIrrKlangDevice();
        void playMusic(char *);
        void playSound(char *);
        void changeSpeed(float val);
        void pauseSound(char *);
        void setVolume(float);
        int initSounds();

    protected:

    private:
};

#endif // GLSOUNDS_H
