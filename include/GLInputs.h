#ifndef GLINPUTS_H
#define GLINPUTS_H

#include "GLModel.h"
#include "Common.h"
#include "GLParallax.h"
//#include "GlPlayer.h"
#include "GLWizard.h"
#include "GLScene.h"
#include "GLSounds.h"
#include "GLWarrior.h"
#include "GLRogue.h"

class GLInputs
{
    public:
        GLInputs();
        virtual ~GLInputs();

        void keyPress(bool&, GLWizard*, GLSounds*, GLSounds*, GLSounds*, int&, int&, int&, GLWarrior*, GLRogue*);                     //When Key Pressed
        void keyUp(GLWizard*, GLSounds*, GLSounds*, int&, GLWarrior*, GLRogue*);                              //When Key Released
        void keyBackground(GLParallax*, float);             //Parallax Model, Speed

        void mouseEventDown(int&, int&, int&, int&, bool*, GLWizard*, GLWarrior*, GLRogue*, GLSounds*, GLSounds*, bool, double, double, float, float);     //Mouse Button Pressed
        void mouseEventUp(GLWizard*);                                //Mouse Button Released
        void mouseWheel(GLModel*, double);                  //Mouse Wheel  Rolled
        void mouseMove(GLModel*, GLParallax* text[], GLParallax* icons[], int&, bool full, double, double);           //Mouse Has    Moved

        double prev_MouseX;                                 //Current Mouse Location X Before Action
        double prev_MouseY;                                 //Current Mouse Location Y Before Action

        bool   mouse_Translate;                             //If Mouse Moved
        bool   mouse_Rotate;                                //If Mouse Moved for Rotation

        WPARAM wParam;                                      //Keyboard for Input interupt Catching

    protected:

    private:
};

#endif // GLINPUTS_H
