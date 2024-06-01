#include "GLSounds.h"



GLSounds::GLSounds()
{
    //ctor
}

GLSounds::~GLSounds()
{
    //dtor
    engine->drop();
}

void GLSounds::playMusic(char* File)
{
    engine->play2D(File, true);
}

void GLSounds::playSound(char* File)
{
    if(!engine->isCurrentlyPlaying(File))
    engine->play2D(File, false,false);
}

void GLSounds::setVolume(float val) {
    engine->setSoundVolume((ik_f32)val);
}

void GLSounds::pauseSound(char* File)
{
    //engine->pause2D(File,true,false);
    engine->stopAllSounds();
}

int GLSounds::initSounds()
{
    if(!engine){cout<<" ERROR: *** The Sound Engine Could Not Star"<<endl;
    return 0;}
    return 1;
}

void GLSounds::changeSpeed(float val) {
    //engine->setPlaybackSpeed(val);
}
