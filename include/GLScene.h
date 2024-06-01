#ifndef GLSCENE_H
#define GLSCENE_H

#include "Common.h"
#include "bClock.h"

class GLScene
{
    public:
        GLScene();
        virtual ~GLScene();
        GLint   initGL();
        GLint   drawScene();
        GLvoid  resizeScene(GLsizei width, GLsizei height);
        void    drawMainMenu();
        void    drawLandingPage(chrono::duration<float>& deltaTime);
        void    drawVictoryScreen(chrono::duration<float>& deltaTime);
        void    drawLevelOne(chrono::duration<float>& deltaTime);
        void    drawLevelTwo(chrono::duration<float>& deltaTime);
        void    drawLevelThree(chrono::duration<float>& deltaTime);
        void    drawControlsPage();
        void    updateMusic();
        void    drawSlimes();
        void    checkCollisions();
        void    drawHelpScreen();
        void    idle();
        void    gameOverCheck(chrono::duration<float>& deltaTime);
        void    drawNewGameScreen(chrono::duration<float>& deltaTime);
        void    drawSettingScreen(chrono::duration<float>& deltaTime);
        void    levelOneIntro(chrono::duration<float>& deltaTime);
        void    levelTwoIntro(chrono::duration<float>& deltaTime);
        void    levelThreeIntro(chrono::duration<float>& deltaTime);
        void    victoryIntro(chrono::duration<float>& deltaTime);
        void    drawPlayerAndHUD(bClock*);

        enum CLASS {WIZARD, ROGUE, WARRIOR};

        int level = 6;
        int prev_level = 0;
        int next_level = 0;

        int selected_class = 0;

        bool main_menu = true;
        bool settings_menu = false;
        bool fullscreen;
        bool move_to_shop = false;
        bool oneTime = true;
        bool bossTrigger = false;
        bool phaseTwo = false;

        chrono::high_resolution_clock::time_point lastFrameTime;

        bool firstTime[3];

        bool victory = false;

        int windMsg(HWND, UINT, WPARAM, LPARAM);               //Take Windows Inputs

        WPARAM wParam;                                         //Keyboard/Mouse msg

        float screenWidth;                                     //Get values from main
        float screenHeight;                                    //Get values from main


    protected:

    private:
};

#endif // GLSCENE_H
