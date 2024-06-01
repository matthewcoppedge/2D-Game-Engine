#include "GLScene.h"
#include "GLLight.h"
#include "GLTexture.h"
#include "GLModel.h"
#include "GLInputs.h"
#include "GLParallax.h"
#include "GLPlayer.h"
#include "GLWizard.h"
#include "GLSkeleton.h"
#include "GLSounds.h"
#include "GLWarrior.h"
#include "bClock.h"
#include "slime.h"
#include "collisionCheck.h"
#include "GLRogue.h"
#include "rangedEn.h"

///////////////////
//Load All Assets//
///////////////////

bClock*     iClock = new bClock();

GLTexture*  teapotTex   = new GLTexture();       //Texture object
GLModel*    teaPotModel = new GLModel();         //Model   object
GLInputs*   KbMs        = new GLInputs();        //Keyboard and Mouse
GLParallax* plx         = new GLParallax();      //Parallax close  background
GLParallax* plx1        = new GLParallax();      //Parallax far    background
//GLPlayer*   pl          = new GLPlayer();        //Player Original

GLWizard*    wiz          = new GLWizard();        //Wizard
GLWarrior*    warrior     = new GLWarrior();        //Warrior
GLRogue*     rogue        = new GLRogue();
slime*       slimeEnemy   = new slime();           //Slime
slime*       slimeEnemy2  = new slime();           //Slime


collisionCheck* wizCol   = new collisionCheck();
collisionCheck* warCol   = new collisionCheck();
collisionCheck* rogCol   = new collisionCheck();


//GLSkeleton* skel        = new GLSkeleton();
GLParallax* title       = new GLParallax();      //Forest
GLParallax* title_2     = new GLParallax();      //Dungeon
GLParallax* title_3     = new GLParallax();      //Underworld

GLParallax* dungeon_0   = new GLParallax();      //Base Color for Dungeon
GLParallax* dungeon_1   = new GLParallax();      //Top layer
GLParallax* dungeon_2   = new GLParallax();      //Middle Layer
GLParallax* dungeon_3   = new GLParallax();      //Bottom Layer
GLParallax* dungeon_4   = new GLParallax();      //Light

GLParallax* underworld_7   = new GLParallax();      //Base Color for Dungeon
GLParallax* underworld_6   = new GLParallax();      //Top layer
GLParallax* underworld_5   = new GLParallax();      //Middle Layer
GLParallax* underworld_4   = new GLParallax();      //Bottom Layer
GLParallax* underworld_3   = new GLParallax();      //Light
GLParallax* underworld_2   = new GLParallax();      //Light
GLParallax* underworld_1   = new GLParallax();      //Light
GLParallax* underworld_g   = new GLParallax();      //Underworld Ground Texture


GLParallax* main_1   = new GLParallax();
GLParallax* main_2   = new GLParallax();      //Top layer
GLParallax* main_3   = new GLParallax();      //Middle Layer
GLParallax* main_4   = new GLParallax();      //Bottom Layer
GLParallax* main_5   = new GLParallax();      //Light


GLParallax* victory_screen = new GLParallax();

GLParallax* text_1   = new GLParallax();      //Arcane
GLParallax* text_2   = new GLParallax();      //New Game
GLParallax* text_3   = new GLParallax();      //Settings
GLParallax* text_4   = new GLParallax();      //Help
GLParallax* text_5   = new GLParallax();      //Exit
GLParallax* text_6   = new GLParallax();      //Choose Your Class
GLParallax* text_7   = new GLParallax();      //Continue Button
GLParallax* text_8   = new GLParallax();      //Next Level

GLParallax* landing_page_enter = new GLParallax();   //Press enter to start text

GLParallax* settingsIcon  = new GLParallax();  //Construction Guy
GLParallax* backArrow     = new GLParallax();  //Back Arrow
GLParallax* back_to_menu  = new GLParallax();  //Back to menu icon
GLParallax* help_menu     = new GLParallax();  //How to Play Image
GLParallax* controls_page = new GLParallax();

GLParallax* wizardIcon   = new GLParallax();
GLParallax* warriorIcon  = new GLParallax();
GLParallax* rogueIcon    = new GLParallax();

GLParallax* wizardName   = new GLParallax();
GLParallax* warriorName  = new GLParallax();
GLParallax* rogueName    = new GLParallax();

GLParallax* wizardProfile  = new GLParallax();
GLParallax* warriorProfile = new GLParallax();
GLParallax* rogueProfile   = new GLParallax();

GLParallax* inventory  = new GLParallax();
GLParallax* health_bar = new GLParallax();
GLParallax* mana_bar   = new GLParallax();
GLParallax* game_over  = new GLParallax();

const int targetFPS = 60;
const int frameDuration = 1000 / targetFPS; // in milliseconds



GLSounds* main_theme              = new GLSounds();
GLSounds* menu_click              = new GLSounds();
GLSounds* open_inventory          = new GLSounds();
GLSounds* close_inventory         = new GLSounds();
GLSounds* settings_construction   = new GLSounds();
GLSounds* dark_souls              = new GLSounds();
GLSounds* step                    = new GLSounds();
GLSounds* level_one_background    = new GLSounds();
GLSounds* level_two_background    = new GLSounds();
GLSounds* level_three_background  = new GLSounds();
GLSounds* warrior_death           = new GLSounds();
GLSounds* dark_souls_death        = new GLSounds();
GLSounds* warrior_attack_1        = new GLSounds();
GLSounds* warrior_damage_taken    = new GLSounds();


rangedEn* archer = new rangedEn();
GLSkeleton* skel = new GLSkeleton();

slime* bossSlime1 = new slime();
slime* bossSlime2 = new slime();
slime* bossSlime3 = new slime();


GLParallax* text[7];           // Used to send all text to input class to handle color changes
GLParallax* icons[4];          // Used to send all icons to input class to handle color changes

GLint GLScene::initGL()
{
    glShadeModel(GL_SMOOTH);                  //for smooth render
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);     //clear background to black
    glClearDepth(1.0f);                       //depth test for layers
    glEnable(GL_DEPTH_TEST);                  //activate depth test
    glDepthFunc(GL_LEQUAL);                   //depth function

    GLLight Light(GL_LIGHT0);
    Light.setLight(GL_LIGHT0);

    selected_class = NULL;

    glEnable(GL_BLEND);                                    //Transparent effect on png
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    teapotTex->loadTexture("images/teapot.jpg");
    plx->parallaxInit("images/background.png");
    plx1->parallaxInit("images/sky.png");
    dungeon_0->parallaxInit("images/dun/Sky.png");
    dungeon_1->parallaxInit("images/dun/TopLayer.png");
    dungeon_2->parallaxInit("images/dun/MiddleLayer.png");
    dungeon_3->parallaxInit("images/dun/DownLayer.png");
    dungeon_4->parallaxInit("images/dun/Light.png");
    title->parallaxInit("images/title.png");
    title_2->parallaxInit("images/title_2.png");
    title_3->parallaxInit("images/main_menu/underworld_title.png");
    landing_page_enter->parallaxInit("images/main_menu/press_enter.png");

    wiz->initWizard(6, 1);

    warrior->initPlayer();
    warrior->actionTrigger[warrior->STAND] = true;

    rogue->initPlayer();
    rogue->actionTrigger[rogue->STAND] = true;

    slimeEnemy->initSlime(3);
    slimeEnemy2->initSlime(3);

    bossSlime1->initBoss(3);
    bossSlime2->initBoss(2);
    bossSlime3->initBoss(1);

    slimeEnemy2->yMin = 1.0 / slimeEnemy2->framesY;
    slimeEnemy2->yMax = 2.0 / slimeEnemy2->framesY;
    slimeEnemy2->pos.x = 0.95f;


    main_1->parallaxInit("images/main_menu/1.png");
    main_2->parallaxInit("images/main_menu/2.png");
    main_3->parallaxInit("images/main_menu/3.png");
    main_4->parallaxInit("images/main_menu/4.png");
    main_5->parallaxInit("images/main_menu/5.png");

    victory_screen->parallaxInit("images/main_menu/victoryScreen.jpg");

    text_1->parallaxInit("images/main_menu/arcane.png");
    text_2->parallaxInit("images/main_menu/new_game.png");
    text_3->parallaxInit("images/main_menu/settings.png");
    text_4->parallaxInit("images/main_menu/help.png");
    text_5->parallaxInit("images/main_menu/exit.png");
    text_6->parallaxInit("images/main_menu/choose_class.png");
    text_7->parallaxInit("images/main_menu/continue.png");
    //text_8->parallaxInit("images/main_men/next_level.png");

    underworld_1->parallaxInit("images/und/1.png");
    underworld_2->parallaxInit("images/und/2.png");
    underworld_3->parallaxInit("images/und/3.png");
    underworld_4->parallaxInit("images/und/4.png");
    underworld_5->parallaxInit("images/und/5.png");
    underworld_6->parallaxInit("images/und/6.png");
    underworld_7->parallaxInit("images/und/7.png");
    underworld_g->parallaxInit("images/und/ground.png");

    underworld_7->g = 0.35; underworld_7->b = 0.35;
    underworld_6->g = 0.35; underworld_6->b = 0.35;
    underworld_5->g = 0.35; underworld_5->b = 0.35;
    underworld_4->g = 0.35; underworld_4->b = 0.35;
    underworld_3->g = 0.35; underworld_3->b = 0.35;
    underworld_2->g = 0.35; underworld_2->b = 0.35;
    underworld_1->g = 0.35; underworld_1->b = 0.35;
    underworld_g->g = 0.25; underworld_g->b = 0.25; underworld_g->r = 0.45f;

    help_menu->parallaxInit("images/main_menu/HELP.jpg");
    controls_page->parallaxInit("images/main_menu/controls_page.jpg");

    wizardName->parallaxInit("images/main_menu/wizardName.png");
    warriorName->parallaxInit("images/main_menu/warriorName.png");
    rogueName->parallaxInit("images/main_menu/rogueName.png");

    game_over->parallaxInit("images/main_menu/game_over.jpg");



    wizardIcon->parallaxInit("images/main_menu/wizardIcon.jpg");
    warriorIcon->parallaxInit("images/main_menu/rogueIcon.jpg");
    //warriorIcon->parallaxInit("images/main_menu/questionMark.jpg");
    rogueIcon->parallaxInit("images/main_menu/warriorIcon.png");
    //rogueIcon->parallaxInit("images/main_menu/questionMark.jpg");
    backArrow->parallaxInit("images/main_menu/backArrow.png");

    wizardProfile->parallaxInit("images/main_menu/wizardProfilePicture.png");
    warriorProfile->parallaxInit("images/warrior/warriorIcon.jpg");
    rogueProfile->parallaxInit("images/Rogue/rogueProfilePicture.png");

    settingsIcon->parallaxInit("images/main_menu/settingsIcon.jpg");

    inventory->parallaxInit("images/main_menu/inventory.png");

    health_bar->parallaxInit("images/main_menu/health_bar.jpg");
    mana_bar->parallaxInit("images/main_menu/mana_bar.jpg");

    main_theme->initSounds();
    menu_click->initSounds();
    dark_souls->initSounds();
    open_inventory->initSounds();
    close_inventory->initSounds();
    step->initSounds();
    level_one_background->initSounds();
    level_two_background->initSounds();
    level_three_background->initSounds();
    warrior_death->initSounds();
    warrior_attack_1->initSounds();
    dark_souls_death->initSounds();
    warrior_damage_taken->initSounds();

    bossSlime3->pos.x = 0.125f;


    title_2->a = 0.1f;
    title_3->a = 0.1f;
    game_over->a = 0.2f;

    text[0] = text_1;           //Arcane
    text[1] = text_2;           //New Game
    text[2] = text_3;           //Settings
    text[3] = text_4;           //Help
    text[4] = text_5;           //Exit
    text[5] = backArrow;        //Back Arrow
    text[6] = text_7;

    icons[0] = wizardIcon;
    icons[1] = rogueIcon;
    icons[2] = warriorIcon;
    icons[3] = back_to_menu;

    firstTime[0] = true;
    firstTime[1] = true;
    firstTime[2] = true;

    lastFrameTime = chrono::high_resolution_clock::now();

    skel->init();
    archer->init();

    return true;
}

void GLScene::checkCollisions() {
    if (selected_class == WARRIOR) {
        if ( ((((level == 1 || level == 2 || level == 7) && warCol->isCollideCircle(warrior->hb, slimeEnemy2->hb) && slimeEnemy2->health >= 0.0f && warrior->health >= 0.0f )
                || ((level == 1 || level == 2 || level == 7) && warCol->isCollideCircle(warrior->hb, slimeEnemy->hb) && slimeEnemy->health >= 0.0f && warrior->health >= 0.0f)
                        || ( (level == 7) && (warCol->isCollideCircle(warrior->hb, skel->hb) && skel->health >= 0.0f) && warrior->health >= 0.0f)
                            || (((level == 2 || level == 7) && (warCol->isCollideCircle(warrior->hb, archer->hb)) && archer->health >= 0.0f) && warrior->health >= 0.0f)
                                || (((level == 1)) && (warCol->isCollideCircle(warrior->hb, bossSlime1->hb)) && bossSlime1->health >= 0.0f) && warrior->health >= 0.0f && bossTrigger)
                                    || (((level == 2)) && (warCol->isCollideCircle(warrior->hb, bossSlime2->hb)) && bossSlime2->health >= 0.0f) && warrior->health >= 0.0f && bossTrigger)
                                        || (((level == 7)) && (warCol->isCollideCircle(warrior->hb, bossSlime3->hb)) && bossSlime3->health >= 0.0f) && warrior->health >= 0.0f && bossTrigger) {
            warrior->r = 1.0f;
            warrior->g = 0.0f;
            warrior->b = 0.0f;
            warrior->health -= 0.1;
            warrior_damage_taken->setVolume(0.50f);
            if (level == 1) {
                //health_bar->x_scale += 0.001f;
                //health_bar->x_translate += 0.00165f;
            }
            else if (level == 2) {
                //health_bar->x_scale += 0.0045f;
                //health_bar->x_translate += 0.00725f;
            }
            else if (level == 7) {
                //health_bar->x_scale += 0.0055f;
                //health_bar->x_translate += 0.00825f;
            }
            if (level == 1 || level == 2 || level == 7 && warrior->health >= 0.1f)
                warrior_damage_taken->playSound("sounds/warrior_damage.wav");
            else if (level == 1 || level == 2 || level == 7 && warrior->health <= 0.0f) {
                warrior_damage_taken->pauseSound("blank");
            }
        }
        else {
            warrior->r = 1.0f;
            warrior->g = 1.0f;
            warrior->b = 1.0f;
        }

        if (warrior->health < 15.0f && warrior->health >= 0.0f && warrior->alive) {
            health_bar->x_scale -= 0.0001f;
            health_bar->x_translate -= 0.000165f;
        }
        if (warrior->stamina < 10.0f && warrior->health >= 0.0f && warrior->alive) {
            mana_bar->x_scale -= 0.0001f;
            mana_bar->x_translate -= 0.000165f;
        }


        if ( ((warrior->actionTrigger[warrior->ATTACK] && (warrior->faceRight && slimeEnemy2->pos.x > warrior->plPosition.x)) &&
                abs(warrior->plPosition.x - slimeEnemy2->pos.x) <= 0.315) || ((warrior->actionTrigger[warrior->ATTACK] && (!warrior->faceRight && slimeEnemy2->pos.x < warrior->plPosition.x)) &&
                abs(warrior->plPosition.x - slimeEnemy2->pos.x) <= 0.315) )

            {
            slimeEnemy2->r = 1.0f;
            slimeEnemy2->g = 0.0f;
            slimeEnemy2->b = 0.0f;
            if (slimeEnemy2->getHit() && !slimeEnemy2->returnedRelic) {
                    slimeEnemy2->returnedRelic = true;
                    warrior->inventory->awardRelic();
            }
            slimeEnemy2->health -= 0.55;
        }
        else {
            slimeEnemy2->r = 1.0f;
            slimeEnemy2->g = 1.0f;
            slimeEnemy2->b = 1.0f;
        }
        if ( ((warrior->actionTrigger[warrior->ATTACK] && (warrior->faceRight && slimeEnemy->pos.x > warrior->plPosition.x)) &&
                abs(warrior->plPosition.x - slimeEnemy->pos.x) <= 0.315) || ((warrior->actionTrigger[warrior->ATTACK] && (!warrior->faceRight && slimeEnemy->pos.x < warrior->plPosition.x)) &&
                abs(warrior->plPosition.x - slimeEnemy->pos.x) <= 0.315) )

            {
            slimeEnemy->r = 1.0f;
            slimeEnemy->g = 0.0f;
            slimeEnemy->b = 0.0f;
            //slimeEnemy->getHit();
            //sslimeEnemy->health -= 0.1;
            if (slimeEnemy->getHit() && !slimeEnemy->returnedRelic) {
                    slimeEnemy->returnedRelic = true;
                    warrior->inventory->awardRelic();
            }
            slimeEnemy->health -= 0.55;
        }
        else {
            slimeEnemy->r = 1.0f;
            slimeEnemy->g = 1.0f;
            slimeEnemy->b = 1.0f;
        }
        if (level == 1) {
            if ( ((warrior->actionTrigger[warrior->ATTACK] && (warrior->faceRight && bossSlime1->pos.x > warrior->plPosition.x)) &&
                    abs(warrior->plPosition.x - bossSlime1->pos.x) <= 0.315) || ((warrior->actionTrigger[warrior->ATTACK] && (!warrior->faceRight && bossSlime1->pos.x < warrior->plPosition.x)) &&
                    abs(warrior->plPosition.x - bossSlime1->pos.x) <= 0.315) )

                {
                bossSlime1->r = 1.0f;
                bossSlime1->g = 0.0f;
                bossSlime1->b = 0.0f;
                bossSlime1->health -= 0.05;
            }
            else {
                bossSlime1->r = 1.0f;
                bossSlime1->g = 1.0f;
                bossSlime1->b = 1.0f;
            }
        }
        if (level == 2) {
            if ( ((warrior->actionTrigger[warrior->ATTACK] && (warrior->faceRight && bossSlime2->pos.x > warrior->plPosition.x)) &&
                    abs(warrior->plPosition.x - bossSlime2->pos.x) <= 0.315) || ((warrior->actionTrigger[warrior->ATTACK] && (!warrior->faceRight && bossSlime2->pos.x < warrior->plPosition.x)) &&
                    abs(warrior->plPosition.x - bossSlime2->pos.x) <= 0.315) )

                {
                bossSlime2->r = 1.0f;
                bossSlime2->g = 0.0f;
                bossSlime2->b = 0.0f;
                bossSlime2->health -= 0.05;
            }
            else {
                bossSlime2->r = 1.0f;
                bossSlime2->g = 1.0f;
                bossSlime2->b = 1.0f;
            }
        }
        if (level == 7) {
            if ( ((warrior->actionTrigger[warrior->ATTACK] && (warrior->faceRight && bossSlime3->pos.x > warrior->plPosition.x)) &&
                    abs(warrior->plPosition.x - bossSlime3->pos.x) <= 0.315) || ((warrior->actionTrigger[warrior->ATTACK] && (!warrior->faceRight && bossSlime3->pos.x < warrior->plPosition.x)) &&
                    abs(warrior->plPosition.x - bossSlime3->pos.x) <= 0.315) )

                {
                bossSlime3->r = 1.0f;
                bossSlime3->g = 0.0f;
                bossSlime3->b = 0.0f;
                bossSlime3->health -= 0.05;
            }
            else {
                bossSlime3->r = 1.0f;
                bossSlime3->g = 1.0f;
                bossSlime3->b = 1.0f;
            }
        }
        if ( ((warrior->actionTrigger[warrior->ATTACK] && (warrior->faceRight && archer->pos.x > warrior->plPosition.x)) &&
                abs(warrior->plPosition.x - archer->pos.x) <= 0.315) || ((warrior->actionTrigger[warrior->ATTACK] && (!warrior->faceRight && archer->pos.x < warrior->plPosition.x)) &&
                abs(warrior->plPosition.x - archer->pos.x) <= 0.315) )

            {
            archer->r = 1.0f;
            archer->g = 0.0f;
            archer->b = 0.0f;
            archer->health -= 0.1;
        }
        else {
            archer->r = 1.0f;
            archer->g = 1.0f;
            archer->b = 1.0f;
        }
        if (level == 7) {
            if ( ((warrior->actionTrigger[warrior->ATTACK] && (warrior->faceRight && skel->pos.x > warrior->plPosition.x)) &&
                    abs(warrior->plPosition.x - skel->pos.x) <= 0.315) || ((warrior->actionTrigger[warrior->ATTACK] && (!warrior->faceRight && skel->pos.x < warrior->plPosition.x)) &&
                    abs(warrior->plPosition.x - skel->pos.x) <= 0.315) )

                {
                skel->r = 1.0f;
                skel->g = 0.0f;
                skel->b = 0.0f;
                skel->health -= 0.1;
            }
            else {
                skel->r = 1.0f;
                skel->g = 1.0f;
                skel->b = 1.0f;
        }
        }
        if (health_bar->x_scale >= 1.10f) {
            warrior->health = -1.0f;
            return;
        }

        if (level == 7) {
            if ( ((skel->mode == 2 && (skel->pos.x > warrior->plPosition.x)) &&
                    abs(warrior->plPosition.x - skel->pos.x) <= 0.315) || ((skel->mode == 2 && (skel->pos.x < warrior->plPosition.x)) &&
                    abs(warrior->plPosition.x - skel->pos.x) <= 0.315) )

            {
                warrior->r = 1.0f;
                warrior->g = 0.0f;
                warrior->b = 0.0f;
                warrior->health -= 0.01;
            }
            else {
                warrior->r = 1.0f;
                warrior->g = 1.0f;
                warrior->b = 1.0f;
            }
        }

    }
   else if (selected_class == WIZARD) {
        if ( ((((level == 1 || level == 2 || level == 7) && wizCol->isCollideCircle(wiz->hb, slimeEnemy2->hb) && slimeEnemy2->health >= 0.0f && wiz->health >= 0.0f )
                || ((level == 1 || level == 2 || level == 7) && wizCol->isCollideCircle(wiz->hb, slimeEnemy->hb) && slimeEnemy->health >= 0.0f && wiz->health >= 0.0f)
                        || ( (level == 7) && (wizCol->isCollideCircle(wiz->hb, skel->hb) && skel->health >= 0.0f) && wiz->health >= 0.0f)
                            || (((level == 2 || level == 7) && (wizCol->isCollideCircle(wiz->hb, archer->hb)) && archer->health >= 0.0f) && wiz->health >= 0.0f)
                                || (((level == 1)) && (wizCol->isCollideCircle(wiz->hb, bossSlime1->hb)) && bossSlime1->health >= 0.0f) && wiz->health >= 0.0f && bossTrigger)
                                    || (((level == 2)) && (wizCol->isCollideCircle(wiz->hb, bossSlime2->hb)) && bossSlime2->health >= 0.0f) && wiz->health >= 0.0f && bossTrigger)
                                        || (((level == 7)) && (wizCol->isCollideCircle(wiz->hb, bossSlime3->hb)) && bossSlime3->health >= 0.0f) && wiz->health >= 0.0f && bossTrigger) {
            wiz->r = 1.0f;
            wiz->g = 0.0f;
            wiz->b = 0.0f;
            wiz->health -= 0.1;
            warrior_damage_taken->setVolume(0.50f);
            if (level == 1) {
                health_bar->x_scale += 0.001f;
                health_bar->x_translate += 0.00165f;
            }
            else if (level == 2) {
                health_bar->x_scale += 0.0045f;
                health_bar->x_translate += 0.00725f;
            }
            else if (level == 7) {
                health_bar->x_scale += 0.0055f;
                health_bar->x_translate += 0.00825f;
            }
            if (level == 1 || level == 2 || level == 7 && wiz->health >= 0.1f)
                warrior_damage_taken->playSound("sounds/warrior_damage.wav");
            else if (level == 1 || level == 2 || level == 7 && wiz->health <= 0.0f) {
                warrior_damage_taken->pauseSound("blank");
            }
        }
        else {
            wiz->r = 1.0f;
            wiz->g = 1.0f;
            wiz->b = 1.0f;
        }

        if (wiz->health < 15.0f && wiz->health >= 0.0f && wiz->alive) {
            health_bar->x_scale -= 0.0001f;
            health_bar->x_translate -= 0.000165f;
        }
        if (wiz->mana < 10.0f && wiz->health >= 0.0f && wiz->alive) {
            mana_bar->x_scale -= 0.0001f;
            mana_bar->x_translate -= 0.000165f;
        }


        if ( ((wiz->actionTrigger[wiz->ATTACK] && wiz->attackTiming&& (wiz->faceRight && slimeEnemy2->pos.x > wiz->wizPosition.x)) &&
                abs(wiz->wizPosition.x - slimeEnemy2->pos.x) <= 0.315) || ((wiz->actionTrigger[wiz->ATTACK] && (!wiz->faceRight && slimeEnemy2->pos.x < wiz->wizPosition.x)) &&
                abs(wiz->wizPosition.x - slimeEnemy2->pos.x) <= 0.315) )

            {
            slimeEnemy2->r = 1.0f;
            slimeEnemy2->g = 0.0f;
            slimeEnemy2->b = 0.0f;
            if (slimeEnemy2->getHit() && !slimeEnemy2->returnedRelic) {
                    slimeEnemy2->returnedRelic = true;
                    wiz->inventory->awardRelic();
            }
            slimeEnemy2->health -= 0.55;
        }
        else {
            slimeEnemy2->r = 1.0f;
            slimeEnemy2->g = 1.0f;
            slimeEnemy2->b = 1.0f;
        }
        if ( ((wiz->actionTrigger[wiz->ATTACK] && wiz->attackTiming && (wiz->faceRight && slimeEnemy->pos.x > wiz->wizPosition.x)) &&
                abs(wiz->wizPosition.x - slimeEnemy->pos.x) <= 0.315) || ((wiz->actionTrigger[wiz->ATTACK] && (!wiz->faceRight && slimeEnemy->pos.x < wiz->wizPosition.x)) &&
                abs(wiz->wizPosition.x - slimeEnemy->pos.x) <= 0.315) )

            {
            slimeEnemy->r = 1.0f;
            slimeEnemy->g = 0.0f;
            slimeEnemy->b = 0.0f;
            //slimeEnemy->getHit();
            //sslimeEnemy->health -= 0.1;
            if (slimeEnemy->getHit() && !slimeEnemy->returnedRelic) {
                    slimeEnemy->returnedRelic = true;
                    wiz->inventory->awardRelic();
            }
            slimeEnemy->health -= 0.55;
        }
        else {
            slimeEnemy->r = 1.0f;
            slimeEnemy->g = 1.0f;
            slimeEnemy->b = 1.0f;
        }
        if (level == 1) {
            if ( ((wiz->actionTrigger[wiz->ATTACK] && (wiz->faceRight && bossSlime1->pos.x > wiz->wizPosition.x)) &&
                    abs(wiz->wizPosition.x - bossSlime1->pos.x) <= 0.315) || ((wiz->actionTrigger[wiz->ATTACK] && (!wiz->faceRight && bossSlime1->pos.x < wiz->wizPosition.x)) &&
                    abs(wiz->wizPosition.x - bossSlime1->pos.x) <= 0.315) )

                {
                bossSlime1->r = 1.0f;
                bossSlime1->g = 0.0f;
                bossSlime1->b = 0.0f;
                bossSlime1->health -= 0.1;
            }
            else {
                bossSlime1->r = 1.0f;
                bossSlime1->g = 1.0f;
                bossSlime1->b = 1.0f;
            }
        }
        if (level == 2) {
            if ( ((wiz->actionTrigger[wiz->ATTACK] && (wiz->faceRight && bossSlime2->pos.x > wiz->wizPosition.x)) &&
                    abs(wiz->wizPosition.x - bossSlime2->pos.x) <= 0.315) || ((wiz->actionTrigger[wiz->ATTACK] && (!wiz->faceRight && bossSlime2->pos.x < wiz->wizPosition.x)) &&
                    abs(wiz->wizPosition.x - bossSlime2->pos.x) <= 0.315) )

                {
                bossSlime2->r = 1.0f;
                bossSlime2->g = 0.0f;
                bossSlime2->b = 0.0f;
                bossSlime2->health -= 0.1;
            }
            else {
                bossSlime2->r = 1.0f;
                bossSlime2->g = 1.0f;
                bossSlime2->b = 1.0f;
            }
        }
        if (level == 7) {
            if ( ((wiz->actionTrigger[wiz->ATTACK] && (wiz->faceRight && bossSlime3->pos.x > wiz->wizPosition.x)) &&
                    abs(wiz->wizPosition.x - bossSlime3->pos.x) <= 0.315) || ((wiz->actionTrigger[wiz->ATTACK] && (!wiz->faceRight && bossSlime3->pos.x < wiz->wizPosition.x)) &&
                    abs(wiz->wizPosition.x - bossSlime3->pos.x) <= 0.315) )

                {
                bossSlime3->r = 1.0f;
                bossSlime3->g = 0.0f;
                bossSlime3->b = 0.0f;
                bossSlime3->health -= 0.1;
            }
            else {
                bossSlime3->r = 1.0f;
                bossSlime3->g = 1.0f;
                bossSlime3->b = 1.0f;
            }
        }
        if ( ((wiz->actionTrigger[wiz->ATTACK] && (wiz->faceRight && archer->pos.x > wiz->wizPosition.x)) &&
                abs(wiz->wizPosition.x - archer->pos.x) <= 0.315) || ((wiz->actionTrigger[wiz->ATTACK] && (!wiz->faceRight && archer->pos.x < wiz->wizPosition.x)) &&
                abs(wiz->wizPosition.x - archer->pos.x) <= 0.315) )

            {
            archer->r = 1.0f;
            archer->g = 0.0f;
            archer->b = 0.0f;
            archer->health -= 0.1;
        }
        else {
            archer->r = 1.0f;
            archer->g = 1.0f;
            archer->b = 1.0f;
        }
        if (level == 7) {
            if ( ((wiz->actionTrigger[wiz->ATTACK] && (wiz->faceRight && skel->pos.x > wiz->wizPosition.x)) &&
                    abs(wiz->wizPosition.x - skel->pos.x) <= 0.315) || ((wiz->actionTrigger[wiz->ATTACK] && (!wiz->faceRight && skel->pos.x < wiz->wizPosition.x)) &&
                    abs(wiz->wizPosition.x - skel->pos.x) <= 0.315) )

                {
                skel->r = 1.0f;
                skel->g = 0.0f;
                skel->b = 0.0f;
                skel->health -= 0.1;
            }
            else {
                skel->r = 1.0f;
                skel->g = 1.0f;
                skel->b = 1.0f;
        }
        }
        if (health_bar->x_scale >= 1.10f) {
            wiz->health = -1.0f;
            return;
        }

        if (level == 7) {
            if ( ((skel->mode == 2 && (skel->pos.x > wiz->wizPosition.x)) &&
                    abs(wiz->wizPosition.x - skel->pos.x) <= 0.315) || ((skel->mode == 2 && (skel->pos.x < wiz->wizPosition.x)) &&
                    abs(wiz->wizPosition.x - skel->pos.x) <= 0.315) )

            {
                wiz->r = 1.0f;
                wiz->g = 0.0f;
                wiz->b = 0.0f;
                wiz->health -= 0.01;
            }
            else {
                wiz->r = 1.0f;
                wiz->g = 1.0f;
                wiz->b = 1.0f;
            }
        }
        if (wiz->projAlive) {
            if (wizCol->isCollideCircle(wiz->blast->hb, slimeEnemy->hb)) {slimeEnemy->health -= 10.0f; if (slimeEnemy->getHit() && !slimeEnemy->returnedRelic) {wiz->inventory->awardRelic(); slimeEnemy->returnedRelic = true;}}
            if (wizCol->isCollideCircle(wiz->blast->hb, slimeEnemy2->hb)) {slimeEnemy2->health-= 10.0f; if (slimeEnemy2->getHit() && !slimeEnemy2->returnedRelic) {wiz->inventory->awardRelic(); slimeEnemy2->returnedRelic = true;}}
        }

    }

   else if (selected_class == ROGUE && !rogue->actionTrigger[rogue->SPECIAL]) {
        if ( ((((level == 1 || level == 2 || level == 7) && rogCol->isCollideCircle(rogue->hb, slimeEnemy2->hb) && slimeEnemy2->health >= 0.0f && rogue->health >= 0.0f )
                || ((level == 1 || level == 2 || level == 7) && rogCol->isCollideCircle(rogue->hb, slimeEnemy->hb) && slimeEnemy->health >= 0.0f && rogue->health >= 0.0f)
                        || ( (level == 7) && (rogCol->isCollideCircle(rogue->hb, skel->hb) && skel->health >= 0.0f) && rogue->health >= 0.0f)
                            || (((level == 2 || level == 7) && (rogCol->isCollideCircle(rogue->hb, archer->hb)) && archer->health >= 0.0f) && rogue->health >= 0.0f)
                                || (((level == 1)) && (rogCol->isCollideCircle(rogue->hb, bossSlime1->hb)) && bossSlime1->health >= 0.0f) && rogue->health >= 0.0f && bossTrigger)
                                    || (((level == 2)) && (rogCol->isCollideCircle(rogue->hb, bossSlime2->hb)) && bossSlime2->health >= 0.0f) && rogue->health >= 0.0f && bossTrigger)
                                        || (((level == 7)) && (rogCol->isCollideCircle(rogue->hb, bossSlime3->hb)) && bossSlime3->health >= 0.0f) && rogue->health >= 0.0f && bossTrigger) {
            rogue->r = 1.0f;
            rogue->g = 0.0f;
            rogue->b = 0.0f;
            rogue->health -= 0.1;
            warrior_damage_taken->setVolume(0.50f);
            if (level == 1) {
                health_bar->x_scale += 0.001f;
                health_bar->x_translate += 0.00165f;
            }
            else if (level == 2) {
                health_bar->x_scale += 0.0045f;
                health_bar->x_translate += 0.00725f;
            }
            else if (level == 7) {
                health_bar->x_scale += 0.0055f;
                health_bar->x_translate += 0.00825f;
            }
            if (level == 1 || level == 2 || level == 7 && rogue->health >= 0.1f)
                warrior_damage_taken->playSound("sounds/warrior_damage.wav");
            else if (level == 1 || level == 2 || level == 7 && rogue->health <= 0.0f) {
                warrior_damage_taken->pauseSound("blank");
            }
        }
        else {
            rogue->r = 1.0f;
            rogue->g = 1.0f;
            rogue->b = 1.0f;
        }

        if (rogue->health < 15.0f && rogue->health >= 0.0f && rogue->alive) {
            health_bar->x_scale -= 0.0001f;
            health_bar->x_translate -= 0.000165f;
        }
        if (rogue->stamina < 10.0f && rogue->health >= 0.0f && rogue->alive) {
            mana_bar->x_scale -= 0.0001f;
            mana_bar->x_translate -= 0.000165f;
        }


        if ( ((rogue->actionTrigger[rogue->ATTACK] && (rogue->faceRight && slimeEnemy2->pos.x > rogue->plPosition.x)) &&
                abs(rogue->plPosition.x - slimeEnemy2->pos.x) <= 0.315) || ((rogue->actionTrigger[rogue->ATTACK] && (!rogue->faceRight && slimeEnemy2->pos.x < rogue->plPosition.x)) &&
                abs(rogue->plPosition.x - slimeEnemy2->pos.x) <= 0.315) )

            {
            slimeEnemy2->r = 1.0f;
            slimeEnemy2->g = 0.0f;
            slimeEnemy2->b = 0.0f;
            if (slimeEnemy2->getHit() && !slimeEnemy2->returnedRelic) {
                    slimeEnemy2->returnedRelic = true;
                    rogue->inventory->awardRelic();
            }
            slimeEnemy2->health -= 0.55;
        }
        else {
            slimeEnemy2->r = 1.0f;
            slimeEnemy2->g = 1.0f;
            slimeEnemy2->b = 1.0f;
        }
        if ( ((rogue->actionTrigger[rogue->ATTACK] && (rogue->faceRight && slimeEnemy->pos.x > rogue->plPosition.x)) &&
                abs(rogue->plPosition.x - slimeEnemy->pos.x) <= 0.315) || ((rogue->actionTrigger[rogue->ATTACK] && (!rogue->faceRight && slimeEnemy->pos.x < rogue->plPosition.x)) &&
                abs(rogue->plPosition.x - slimeEnemy->pos.x) <= 0.315) )

            {
            slimeEnemy->r = 1.0f;
            slimeEnemy->g = 0.0f;
            slimeEnemy->b = 0.0f;
            //slimeEnemy->getHit();
            //sslimeEnemy->health -= 0.1;
            if (slimeEnemy->getHit() && !slimeEnemy->returnedRelic) {
                    slimeEnemy->returnedRelic = true;
                    rogue->inventory->awardRelic();
            }
            slimeEnemy->health -= 0.55;
        }
        else {
            slimeEnemy->r = 1.0f;
            slimeEnemy->g = 1.0f;
            slimeEnemy->b = 1.0f;
        }
        if (level == 1) {
            if ( ((rogue->actionTrigger[rogue->ATTACK] && (rogue->faceRight && bossSlime1->pos.x > rogue->plPosition.x)) &&
                    abs(rogue->plPosition.x - bossSlime1->pos.x) <= 0.315) || ((rogue->actionTrigger[rogue->ATTACK] && (!rogue->faceRight && bossSlime1->pos.x < rogue->plPosition.x)) &&
                    abs(rogue->plPosition.x - bossSlime1->pos.x) <= 0.315) )

                {
                bossSlime1->r = 1.0f;
                bossSlime1->g = 0.0f;
                bossSlime1->b = 0.0f;
                bossSlime1->health -= 0.05;
            }
            else {
                bossSlime1->r = 1.0f;
                bossSlime1->g = 1.0f;
                bossSlime1->b = 1.0f;
            }
        }
        if (level == 2) {
            if ( ((rogue->actionTrigger[rogue->ATTACK] && (rogue->faceRight && bossSlime2->pos.x > rogue->plPosition.x)) &&
                    abs(rogue->plPosition.x - bossSlime2->pos.x) <= 0.315) || ((rogue->actionTrigger[rogue->ATTACK] && (!rogue->faceRight && bossSlime2->pos.x < rogue->plPosition.x)) &&
                    abs(rogue->plPosition.x - bossSlime2->pos.x) <= 0.315) )

                {
                bossSlime2->r = 1.0f;
                bossSlime2->g = 0.0f;
                bossSlime2->b = 0.0f;
                bossSlime2->health -= 0.05;
            }
            else {
                bossSlime2->r = 1.0f;
                bossSlime2->g = 1.0f;
                bossSlime2->b = 1.0f;
            }
        }
        if (level == 7) {
            if ( ((rogue->actionTrigger[rogue->ATTACK] && (rogue->faceRight && bossSlime3->pos.x > rogue->plPosition.x)) &&
                    abs(rogue->plPosition.x - bossSlime3->pos.x) <= 0.315) || ((rogue->actionTrigger[rogue->ATTACK] && (!rogue->faceRight && bossSlime3->pos.x < rogue->plPosition.x)) &&
                    abs(rogue->plPosition.x - bossSlime3->pos.x) <= 0.315) )

                {
                bossSlime3->r = 1.0f;
                bossSlime3->g = 0.0f;
                bossSlime3->b = 0.0f;
                bossSlime3->health -= 0.05;
            }
            else {
                bossSlime3->r = 1.0f;
                bossSlime3->g = 1.0f;
                bossSlime3->b = 1.0f;
            }
        }
        if ( ((rogue->actionTrigger[rogue->ATTACK] && (rogue->faceRight && archer->pos.x > rogue->plPosition.x)) &&
                abs(rogue->plPosition.x - archer->pos.x) <= 0.315) || ((rogue->actionTrigger[rogue->ATTACK] && (!rogue->faceRight && archer->pos.x < rogue->plPosition.x)) &&
                abs(rogue->plPosition.x - archer->pos.x) <= 0.315) )

            {
            archer->r = 1.0f;
            archer->g = 0.0f;
            archer->b = 0.0f;
            archer->health -= 0.1;
        }
        else {
            archer->r = 1.0f;
            archer->g = 1.0f;
            archer->b = 1.0f;
        }
        if (level == 7) {
            if ( ((rogue->actionTrigger[rogue->ATTACK] && (rogue->faceRight && skel->pos.x > rogue->plPosition.x)) &&
                    abs(rogue->plPosition.x - skel->pos.x) <= 0.315) || ((rogue->actionTrigger[rogue->ATTACK] && (!rogue->faceRight && skel->pos.x < rogue->plPosition.x)) &&
                    abs(rogue->plPosition.x - skel->pos.x) <= 0.315) )

                {
                skel->r = 1.0f;
                skel->g = 0.0f;
                skel->b = 0.0f;
                skel->health -= 0.1;
            }
            else {
                skel->r = 1.0f;
                skel->g = 1.0f;
                skel->b = 1.0f;
        }
        }
        if (health_bar->x_scale >= 1.10f) {
            rogue->health = -1.0f;
            return;
        }

        if (level == 7) {
            if ( ((skel->mode == 2 && (skel->pos.x > rogue->plPosition.x)) &&
                    abs(rogue->plPosition.x - skel->pos.x) <= 0.315) || ((skel->mode == 2 && (skel->pos.x < rogue->plPosition.x)) &&
                    abs(rogue->plPosition.x - skel->pos.x) <= 0.315) )

            {
                rogue->r = 1.0f;
                rogue->g = 0.0f;
                rogue->b = 0.0f;
                rogue->health -= 0.01;
            }
            else {
                rogue->r = 1.0f;
                rogue->g = 1.0f;
                rogue->b = 1.0f;
            }
        }

    }
}

void GLScene::drawControlsPage() {
    glPushMatrix();
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glScalef(3.33f, 3.33f, 1.0f);
        controls_page->a = 1.0f;
        controls_page->parallaxDraw(screenWidth, screenHeight);
    glPopMatrix();
    glPushMatrix();
        glScalef(0.25, 0.25, 1.0f);
        glTranslatef(-17.50f, 9.0f, 1.0f);
        backArrow->parallaxDraw(screenWidth, screenHeight);
    glPopMatrix();
}

void GLScene::drawSlimes() {
    vec3 temp;
    hitBox* playerHB;
    if (selected_class == WIZARD){
        temp = wiz->wizPosition;
        playerHB = wiz->hb;
    }
    else if (selected_class == WARRIOR) {
        temp = warrior->plPosition;
        playerHB = warrior->hb;
    }
    else if (selected_class == ROGUE) {
        temp = rogue->plPosition;
        playerHB = rogue->hb;
    }

    if(slimeEnemy2->health <= 0.0f) {
        slimeEnemy2->die();
    }

    if (slimeEnemy->health <= 0.0f) {
        slimeEnemy->die();
    }


    if (level == 1) {
        glPushMatrix();
            if (slimeEnemy2->health >= 0.0f) {
                slimeEnemy2->yMin = 2.0f / (float)slimeEnemy2->framesY;
                slimeEnemy2->yMax = 3.0f / (float)slimeEnemy2->framesY;
                slimeEnemy2->draw();
                slimeEnemy2->actions(iClock->dTime, temp, settings_construction);
                slimeEnemy2->hb->updateCenter(slimeEnemy2->pos.x, slimeEnemy2->pos.y + 0.45);
                //slimeEnemy2->hb->displayCircle();
            }
        glPopMatrix();
        glPushMatrix();
            if (slimeEnemy->health >= 0.0f) {
                slimeEnemy->yMin = 2.0f / (float)slimeEnemy2->framesY;
                slimeEnemy->yMax = 3.0f / (float)slimeEnemy2->framesY;
                slimeEnemy->r = 0.85; slimeEnemy->b =0.85;
                slimeEnemy->draw();
                slimeEnemy->actions(iClock->dTime, temp, settings_construction);
                slimeEnemy->hb->updateCenter(slimeEnemy->pos.x, slimeEnemy->pos.y + 0.50f);
                //slimeEnemy->hb->displayCircle();
            }
        glPopMatrix();
        if (!slimeEnemy->isAlive &&!slimeEnemy2->isAlive) bossTrigger = true;
        if (bossTrigger) {
            if (bossSlime1->isAlive) {
                glPushMatrix();
                    bossSlime1->draw();
                    bossSlime1->actions(iClock->dTime, temp, settings_construction);
                glPopMatrix();
            }
            else if (!phaseTwo) {
                slimeEnemy->isAlive = true;
                slimeEnemy->health = 10;
                slimeEnemy->pos.x = bossSlime1->pos.x;
                slimeEnemy2->isAlive = true;
                slimeEnemy2->health = 10;
                slimeEnemy2->pos.x = bossSlime1->pos.x + 0.05;
                phaseTwo = true;
            }
            /*
            if (phaseTwo && !slimeEnemy2->isAlive && !slimeEnemy->isAlive) {
                bossTrigger = false;
                phaseTwo = false;
                level = 2;
            }
            */
        }
    }

    if (level == 2) {
        glPushMatrix();
            if (slimeEnemy2->health >= 0.0f) {
                slimeEnemy2->yMin = 1.0f / (float)slimeEnemy2->framesY;
                slimeEnemy2->yMax = 2.0f / (float)slimeEnemy2->framesY;
                slimeEnemy2->draw();
                slimeEnemy2->actions(iClock->dTime, temp, settings_construction);
                slimeEnemy2->hb->updateCenter(slimeEnemy2->pos.x, slimeEnemy2->pos.y + 0.45);
                //slimeEnemy2->hb->displayCircle();
            }
        glPopMatrix();
        glPushMatrix();
            if (slimeEnemy->health >= 0.0f) {
                slimeEnemy->yMin = 1.0f / (float)slimeEnemy2->framesY;
                slimeEnemy->yMax = 2.0f / (float)slimeEnemy2->framesY;
                slimeEnemy->r = 0.85; slimeEnemy->b =0.85;
                slimeEnemy->draw();
                slimeEnemy->actions(iClock->dTime, temp, settings_construction);
                slimeEnemy->hb->updateCenter(slimeEnemy->pos.x, slimeEnemy->pos.y + 0.50f);
                //slimeEnemy->hb->displayCircle();
            }
        glPopMatrix();
        if (!slimeEnemy->isAlive &&!slimeEnemy2->isAlive) bossTrigger = true;
        if (bossTrigger) {
            if (bossSlime2->isAlive) {
                glPushMatrix();
                    bossSlime2->draw();
                    bossSlime2->actions(iClock->dTime, temp, settings_construction);
                glPopMatrix();
            }
            else if (!phaseTwo) {
                slimeEnemy->isAlive = true;
                slimeEnemy->health = 10;
                slimeEnemy->pos.x = bossSlime1->pos.x;
                slimeEnemy2->isAlive = true;
                slimeEnemy2->health = 10;
                slimeEnemy2->pos.x = bossSlime1->pos.x + 0.05;
                phaseTwo = true;
            }
            /*
            if (phaseTwo && !slimeEnemy2->isAlive && !slimeEnemy->isAlive) {
                bossTrigger = false;
                phaseTwo = false;
                level = 7;
                slimeEnemy2->pos.x = 0.585f;
                slimeEnemy->pos.x  = 0.565f;
            }
            */
        }
        glPushMatrix();
            archer->drawEnemy();
            archer->actions(iClock->dTime, temp, playerHB);
        glPopMatrix();
    }

    if (level == 7) {
        glPushMatrix();
            if (slimeEnemy2->health >= 0.0f) {
                slimeEnemy2->yMin = 0.0f / (float)slimeEnemy2->framesY;
                slimeEnemy2->yMax = 1.0f / (float)slimeEnemy2->framesY;
                slimeEnemy2->draw();
                slimeEnemy2->actions(iClock->dTime, temp, settings_construction);
                slimeEnemy2->hb->updateCenter(slimeEnemy2->pos.x, slimeEnemy2->pos.y + 0.45);
                //slimeEnemy2->hb->displayCircle();
            }
        glPopMatrix();
        glPushMatrix();
            if (slimeEnemy->health >= 0.0f) {
                slimeEnemy->yMin = 0.0f / (float)slimeEnemy2->framesY;
                slimeEnemy->yMax = 1.0f / (float)slimeEnemy2->framesY;
                slimeEnemy->r = 0.85; slimeEnemy->b =0.85;
                slimeEnemy->draw();
                slimeEnemy->actions(iClock->dTime, temp, settings_construction);
                slimeEnemy->hb->updateCenter(slimeEnemy->pos.x, slimeEnemy->pos.y + 0.50f);
                //slimeEnemy->hb->displayCircle();
            }
        glPopMatrix();
        glPushMatrix();
            skel->drawEnemy();
            skel->actions(iClock->dTime, temp, playerHB);
        glPopMatrix();
        if (!slimeEnemy->isAlive &&!slimeEnemy2->isAlive) bossTrigger = true;
        if (bossTrigger) {
            if (bossSlime3->isAlive) {
                glPushMatrix();
                    bossSlime3->draw();
                    bossSlime3->actions(iClock->dTime, temp, settings_construction);
                glPopMatrix();
            }
            else if (!phaseTwo) {
                slimeEnemy->isAlive = true;
                slimeEnemy->health = 10;
                slimeEnemy->pos.x = bossSlime1->pos.x;
                slimeEnemy2->isAlive = true;
                slimeEnemy2->health = 10;
                slimeEnemy2->pos.x = bossSlime1->pos.x + 0.05;
                phaseTwo = true;
            }
            if (phaseTwo && !slimeEnemy2->isAlive && !slimeEnemy->isAlive) {
                bossTrigger = false;
                phaseTwo = false;
                level = 8;

            }
        }
        glPushMatrix();
            archer->drawEnemy();
            archer->actions(iClock->dTime, temp, playerHB);
        glPopMatrix();
    }
/*
    if (level == 1 || level == 2) {
        glPushMatrix();
            if (slimeEnemy->health >= 0.0f) {
                slimeEnemy->draw();
                slimeEnemy->actions(iClock->dTime, temp, settings_construction);
                slimeEnemy->hb->updateCenter(slimeEnemy->pos.x, slimeEnemy->pos.y + 0.50f);
                //slimeEnemy->hb->displayCircle();
            }
        glPopMatrix();
    }
*/
/*
    if (level == 1 || level == 2) {
        glPushMatrix();
            if (slimeEnemy2->health <= 0.0f) {
                //warrior->slimesSlain += 1;
                int random = rand() % 2;
                (random == 0) ? slimeEnemy2->pos.x = rand() % 2 : slimeEnemy2->pos.x = rand() % 2 * -1;
                slimeEnemy2->moveSpeed = rand() % 30 / 1000.0f;
                slimeEnemy2->jumpLength = rand() % 10 / 20.0f;
                slimeEnemy2->speed = rand() % 50 / 1000.0f;
                random = rand() % 5;
                /*
                switch (random) {
                case 0:
                    slimeEnemy2->yMin = 0.0f;
                    slimeEnemy2->yMax = 1 / (float)slimeEnemy2->framesY;
                    break;
                case 1:
                    slimeEnemy2->yMin = 1.0f / (float)slimeEnemy2->framesY;
                    slimeEnemy2->yMax = 2.0f / (float)slimeEnemy2->framesY;
                    break;
                case 2:
                    slimeEnemy2->yMin = 2.0f / (float)slimeEnemy2->framesY;
                    slimeEnemy2->yMax = 3.0f / (float)slimeEnemy2->framesY;
                    break;
                case 3:
                    slimeEnemy2->yMin = 3.0f / (float)slimeEnemy2->framesY;
                    slimeEnemy2->yMax = 4.0f / (float)slimeEnemy2->framesY;
                    break;
                case 4:
                    slimeEnemy2->yMin = 4.0f / (float)slimeEnemy2->framesY;
                    slimeEnemy2->yMax = 5.0f / (float)slimeEnemy2->framesY;
                    break;

                }

                slimeEnemy2->health = 10.0f;
            }


            if (slimeEnemy->health <= 0.0f) {
                //warrior->slimesSlain += 1;
                int random = rand() % 2;
                (random == 0) ? slimeEnemy->pos.x = rand() % 2 : slimeEnemy->pos.x = rand() % 2 * -1;
                slimeEnemy->moveSpeed = rand() % 30 / 1000.0f;
                slimeEnemy->jumpLength = rand() % 10 / 20.0f;
                slimeEnemy->speed = rand() % 50 / 1000.0f;

                random = rand() % 5;
                switch (random) {
                    case 0:
                        slimeEnemy->yMin = 0.0f;
                        slimeEnemy->yMax = 1 / (float)slimeEnemy->framesY;
                        break;
                    case 1:
                        slimeEnemy->yMin = 1.0f / (float)slimeEnemy->framesY;
                        slimeEnemy->yMax = 2.0f / (float)slimeEnemy->framesY;
                        break;
                    case 2:
                        slimeEnemy->yMin = 2.0f / (float)slimeEnemy->framesY;
                        slimeEnemy->yMax = 3.0f / (float)slimeEnemy->framesY;
                        break;
                    case 3:
                        slimeEnemy->yMin = 3.0f / (float)slimeEnemy->framesY;
                        slimeEnemy->yMax = 4.0f / (float)slimeEnemy->framesY;
                        break;
                    case 4:
                        slimeEnemy->yMin = 4.0f / (float)slimeEnemy->framesY;
                        slimeEnemy->yMax = 5.0f / (float)slimeEnemy->framesY;
                        break;

                }

                slimeEnemy->health = 15.0f;
                //slimeEnemy->mode = 0;
                //slimeEnemy->eScale.x = 0.08;
                //slimeEnemy->eScale.y = 0.08;
            }
        glPopMatrix();

    }
*/

}



void GLScene::drawLandingPage(chrono::duration<float>& deltaTime) {
            glClearColor(0.0, 0.0, 0.0, 1.0f);
            main_1->a = 1.0f;
            main_2->a = 1.0f;
            main_3->a = 1.0f;
            main_4->a = 1.0f;
            main_5->a = 1.0f;
            text_6->a = 1.0f;
            game_over->a = 0.0f;
            wizardIcon->a = 1.0f;
            rogueIcon->a = 1.0f;
            warriorIcon->a = 1.0f;
            warriorName->a = 1.0f;
            wizardName->a = 1.0f;
            rogueName->a = 1.0f;
            backArrow->a = 1.0f;
            glPushMatrix();
                glScalef(3.33, 3.33, 1.0f);
                glDisable(GL_LIGHTING);
                main_1->parallaxDraw(screenWidth, screenHeight);
                main_2->parallaxDraw(screenWidth, screenHeight);
                main_3->parallaxDraw(screenWidth, screenHeight);
                main_4->parallaxDraw(screenWidth, screenHeight);
                main_5->parallaxDraw(screenWidth, screenHeight);
                main_2->parallaxScroll(true, "right", 0.00001f);
                main_3->parallaxScroll(true, "right", 0.00025);
                main_5->parallaxScroll(true, "right", 0.001f);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.0, 0.25, 0.0);
                glScalef(2.25f, 1.05f, 1.0f);
                text_1->parallaxDraw(screenWidth, screenHeight);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.0, -2.05, 0.0);
                glScalef(1.35f, 0.25f, 1.0f);
                landing_page_enter->parallaxDraw(screenWidth, screenHeight);

                static float fade_6  = 0.0f;
                static float adj_6 = 0.05f * deltaTime.count();

                landing_page_enter->a = fade_6;
                fade_6 += adj_6;
                if (fade_6 >= 1.1f) {
                    adj_6 *= -1.0f;
                }
                if (fade_6 <= 0.0f)
                    adj_6 *= -1.0f;

            glPopMatrix();

            glEnable(GL_LIGHTING);
}

void GLScene::drawVictoryScreen(chrono::duration<float>& deltaTime) {

    static float fade_29 = 0.0f;
    static float adj_29  = 0.35f * deltaTime.count();

    if (fade_29 <= 1.0f)
        fade_29 += adj_29;



    glPushMatrix();
        glScalef(3.33f, 3.33f, 1.0f);
        victory_screen->parallaxDraw(screenWidth, screenHeight);
        victory_screen->a = fade_29;
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0, 0.0, 0.0);
        glScalef(0.25f, 0.25f, 1.0f);
        text_5->parallaxDraw(screenWidth, screenHeight);
        text_5->a = fade_29;
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0, 0.0, 0.0);
        if (selected_class == WIZARD) {
            glPushMatrix();
                wiz->a= fade_29;
                wiz->wizScale.x = 1.35;
                wiz->wizScale.y = 1.35;
            glPopMatrix();
            wiz->wizPosition.x = 0.0;
            wiz->wizPosition.y = -0.165f;
            wiz->actionTrigger[wiz->IDLE] = true;
            //wiz->actionTrigger[wiz->WALKLEFT] = false;
            //wiz->actionTrigger[wiz->WALKRIGHT] = false;
            wiz->drawWiz(iClock->dTime);
        }
        else if (selected_class == WARRIOR) {
            glPushMatrix();
                warrior->a= fade_29;
                warrior->plScale.x = 1.95;
                warrior->plScale.y = 1.95;
            glPopMatrix();
            warrior->actionTrigger[warrior->STAND] = true;
            warrior->drawPlayer(iClock->dTime);
            warrior->plPosition.x = 0.0;
            warrior->plPosition.y = -0.165f;
        }
        else if (selected_class == ROGUE) {
            glPushMatrix();
                rogue->a= fade_29;
                rogue->plScale.x = 0.75;
                rogue->plScale.y = 0.75;
            glPopMatrix();
            rogue->actionTrigger[rogue->STAND] = true;
            rogue->drawPlayer(iClock->dTime);
            rogue->plPosition.x = 0.0;
            rogue->plPosition.y = -0.165f;
        }
    glPopMatrix();
}

void GLScene::drawMainMenu() {
            glClearColor(0.0, 0.0, 0.0, 1.0f);
            main_1->a = 1.0f;
            main_2->a = 1.0f;
            main_3->a = 1.0f;
            main_4->a = 1.0f;
            main_5->a = 1.0f;
            text_6->a = 1.0f;
            game_over->a = 0.0f;
            wizardIcon->a = 1.0f;
            rogueIcon->a = 1.0f;
            warriorIcon->a = 1.0f;
            warriorName->a = 1.0f;
            wizardName->a = 1.0f;
            rogueName->a = 1.0f;
            backArrow->a = 1.0f;
            glPushMatrix();
                glScalef(3.33, 3.33, 1.0f);
                glDisable(GL_LIGHTING);
                main_1->parallaxDraw(screenWidth, screenHeight);
                main_2->parallaxDraw(screenWidth, screenHeight);
                main_3->parallaxDraw(screenWidth, screenHeight);
                main_4->parallaxDraw(screenWidth, screenHeight);
                main_5->parallaxDraw(screenWidth, screenHeight);
                main_2->parallaxScroll(true, "right", 0.00001f);
                main_3->parallaxScroll(true, "right", 0.00025);
                main_5->parallaxScroll(true, "right", 0.001f);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.0, 1.0, 0.0);
                glScalef(1.75f, 0.75f, 1.0f);
                text_1->parallaxDraw(screenWidth, screenHeight);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0, 0.00, 0.0);
                glScalef(0.315f, 0.315f, 1.0f);
                if (firstTime[0]) {
                    text_2->parallaxDraw(screenWidth, screenHeight);
                    //backArrow->a = 1.0f;
                    //backArrow->b = 1.0f;
                    //backArrow->g = 1.0f;
                    //backArrow->r = 1.0f;
                }
                else {
                    text_7->parallaxDraw(screenWidth, screenHeight);
                }
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0, -0.65, 0.0);
                glScalef(0.30f, 0.315f, 1.0f);
                text_3->parallaxDraw(screenWidth, screenHeight);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0, -1.45, 0.0);
                glScalef(0.25f, 0.25f, 1.0f);
                text_4->parallaxDraw(screenWidth, screenHeight);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0, -2.25, 0.0);
                glScalef(0.25f, 0.25f, 1.0f);
                text_5->parallaxDraw(screenWidth, screenHeight);
            glPopMatrix();
            glEnable(GL_LIGHTING);
}

void GLScene::drawLevelOne(chrono::duration<float>& deltaTime) {

static float fade_29 = 1.0f;
static float adj_29  = 0.35f * deltaTime.count();


if (phaseTwo && !slimeEnemy2->isAlive && !slimeEnemy->isAlive) {

    fade_29 -= adj_29;
    if (fade_29 <= 0.0f) {
        bossTrigger = false;
        phaseTwo = false;
        level = 2;
    }
}
//glColor4f(1.0, 1.0, 1.0, fade_29);
glPushMatrix();
    //glColor4f(1.0, 1.0, 1.0, fade_29);
    glPushMatrix();
        glDisable(GL_LIGHTING);
        glScalef(0.25, 0.25, 1.0f);
        glTranslatef(-17.50f, 9.0f, 1.0f);
        backArrow->parallaxDraw(screenWidth, screenHeight);
        backArrow->a = fade_29;
    glPopMatrix();
    glPushMatrix();                                                  //Group object
        glScalef(3.33, 3.33, 1.0);
        glDisable(GL_LIGHTING);
        plx1->parallaxDraw(screenWidth, screenHeight);
        plx->parallaxDraw(screenWidth, screenHeight);                //Draw Model Object
        plx1->parallaxScroll(true, "right", 0.0001f);                 //Parallax Auto Mode
        plx1->a = fade_29;
        plx->a  = fade_29;
        glEnable(GL_LIGHTING);
    glPopMatrix();

glPopMatrix();
}

void GLScene::drawLevelTwo(chrono::duration<float>& deltaTime) {

static float fade_29 = 1.0f;
static float adj_29  = 0.35f * deltaTime.count();


if (phaseTwo && !slimeEnemy2->isAlive && !slimeEnemy->isAlive) {

    fade_29 -= adj_29;
    if (fade_29 <= 0.0f) {
        bossTrigger = false;
        phaseTwo = false;
        level = 7;
        slimeEnemy2->pos.x = 0.585f;
        slimeEnemy->pos.x  = 0.565f;
        //slimeEnemy2->pos.y = -0.575f;
        //slimeEnemy2->pos.y = -0.572f;
    }
}


    //backArrow->a = 1.0f;
    glPushMatrix();
        glScalef(0.25, 0.25, 1.0f);
        glTranslatef(-17.50f, 9.0f, 1.0f);
        backArrow->parallaxDraw(screenWidth, screenHeight);
        backArrow->a = fade_29;
    glPopMatrix();
    glPushMatrix();                                                  //Group object
        glScalef(3.33, 3.33, 1.0);
        glDisable(GL_LIGHTING);
        dungeon_0->parallaxDraw(screenWidth, screenHeight);
        dungeon_3->parallaxDraw(screenWidth, screenHeight);
        dungeon_2->parallaxDraw(screenWidth, screenHeight);
        dungeon_4->parallaxDraw(screenWidth, screenHeight);
        dungeon_1->parallaxDraw(screenWidth, screenHeight);
        dungeon_4->parallaxScroll(true, "left", 0.000015f);

        dungeon_0->a = fade_29;
        dungeon_3->a = fade_29;
        dungeon_2->a = fade_29;
        dungeon_4->a = fade_29;
        dungeon_1->a = fade_29;
        glEnable(GL_LIGHTING);
    glPopMatrix();

}

void GLScene::drawLevelThree(chrono::duration<float>& deltaTime) {

    if (victory) {
        static float fade_100 = 1.0f;
        static float adj_100  = 0.35f * deltaTime.count();
        fade_100 -= adj_100;
        if (fade_100 <= 0.0f) {
            level = 8;
        }
        underworld_1->a = fade_100;
        underworld_2->a = fade_100;
        underworld_3->a = fade_100;
        underworld_4->a = fade_100;
        underworld_5->a = fade_100;
        underworld_6->a = fade_100;
        underworld_7->a = fade_100;
        underworld_g->a = fade_100;

    }

    backArrow->a = 1.0f;
    glPushMatrix();
        glScalef(0.25, 0.25, 1.0f);
        glTranslatef(-17.50f, 9.0f, 1.0f);
        backArrow->parallaxDraw(screenWidth, screenHeight);
    glPopMatrix();
    glPushMatrix();                                                  //Group object
        glScalef(3.33, 3.33, 1.0);
        glDisable(GL_LIGHTING);
        underworld_7->parallaxDraw(screenWidth, screenHeight);
        underworld_6->parallaxDraw(screenWidth, screenHeight);
        underworld_5->parallaxDraw(screenWidth, screenHeight);
        underworld_4->parallaxDraw(screenWidth, screenHeight);
        underworld_3->parallaxDraw(screenWidth, screenHeight);
        underworld_2->parallaxDraw(screenWidth, screenHeight);
        underworld_1->parallaxDraw(screenWidth, screenHeight);
        glEnable(GL_LIGHTING);
    glPopMatrix();
    glPushMatrix();
        glScalef(3.33, 1.0, 1.0);
        glTranslatef(0.0, -3.525, 0.0);
        underworld_g->parallaxDraw(screenWidth, screenHeight);
    glPopMatrix();
    if (move_to_shop) {
        glPushMatrix();
            glDisable(GL_LIGHTING);
            glScalef(0.25, 0.25, 1.0f);
            glTranslatef(-17.50f, 9.0f, 1.0f);
            text_8->parallaxDraw(screenWidth, screenHeight);
        glPopMatrix();
    }
}

void GLScene::drawNewGameScreen(chrono::duration<float>& deltaTime) {
            glPushMatrix();
                if (next_level == 1) {
                    static float fade_3   = 1.0f;
                    static float adj_3  = 0.75f * deltaTime.count();

                    fade_3 -= adj_3;
                    if (fade_3 < 0.0f)
                        level = 1;

                    main_1->a = fade_3;
                    main_2->a = fade_3;
                    main_3->a = fade_3;
                    main_4->a = fade_3;
                    main_5->a = fade_3;
                    text_6->a = fade_3;
                    game_over->a = 1.0f;
                    wizardIcon->a = fade_3;
                    rogueIcon->a = fade_3;
                    warriorIcon->a = fade_3;
                    warriorName->a = fade_3;
                    wizardName->a = fade_3;
                    rogueName->a = fade_3;
                    backArrow->a = fade_3;
                }
                glPushMatrix();
                    glScalef(3.33, 3.33, 1.0f);
                    glDisable(GL_LIGHTING);
                    main_1->parallaxDraw(screenWidth, screenHeight);
                    main_2->parallaxDraw(screenWidth, screenHeight);
                    main_3->parallaxDraw(screenWidth, screenHeight);
                    main_4->parallaxDraw(screenWidth, screenHeight);
                    main_5->parallaxDraw(screenWidth, screenHeight);
                    main_2->parallaxScroll(true, "right", 0.00001f);
                    main_3->parallaxScroll(true, "right", 0.00025);
                    main_5->parallaxScroll(true, "right", 0.001f);
                glPopMatrix();
                glPushMatrix();
                    glScalef(1.25f, 0.5f, 1.0f);
                    glTranslatef(0.0f, 4.15f, 1.0f);
                    text_6->parallaxDraw(screenWidth, screenHeight);
                glPopMatrix();
                glPushMatrix();
                    glTranslatef(-3.0f, -0.5f, 1.0f);
                    glScalef(0.60f, 1.85f, 1.0f);
                    wizardIcon->parallaxDraw(screenWidth, screenHeight);
                glPopMatrix();
                glPushMatrix();
                    glTranslatef(3.0f, -0.5f, 1.0f);
                    glScalef(0.60f, 1.85f, 1.0f);
                    warriorIcon->parallaxDraw(screenWidth, screenHeight);
                glPopMatrix();
                glPushMatrix();
                    glTranslatef(0.0f, -0.5f, 1.0f);
                    glScalef(0.60f, 1.85f, 1.0f);
                    rogueIcon->parallaxDraw(screenWidth, screenHeight);
                glPopMatrix();
                glPushMatrix();
                    glScalef(0.25, 0.25, 1.0f);
                    glTranslatef(-17.50f, 9.0f, 1.0f);
                    backArrow->parallaxDraw(screenWidth, screenHeight);
                glPopMatrix();
                glPushMatrix();
                    glScalef(0.40, 0.15, 1.0f);
                    glTranslatef(-7.35f, -16.85f, 1.0f);
                    wizardName->parallaxDraw(screenWidth, screenHeight);
                glPopMatrix();
                glPushMatrix();
                    glScalef(0.40, 0.15, 1.0f);
                    glTranslatef(-0.05f, -16.85f, 1.0f);
                    warriorName->parallaxDraw(screenWidth, screenHeight);
                glPopMatrix();
                glPushMatrix();
                    glScalef(0.40, 0.15, 1.0f);
                    glTranslatef(7.85f, -16.85f, 1.0f);
                    rogueName->parallaxDraw(screenWidth, screenHeight);
                glPopMatrix();
            glPopMatrix();
}

void GLScene::drawHelpScreen() {
    glPushMatrix();
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glScalef(3.33f, 3.33f, 1.0f);
        help_menu->a = 1.0f;
        help_menu->parallaxDraw(screenWidth, screenHeight);
    glPopMatrix();
    glPushMatrix();
        glScalef(0.25, 0.25, 1.0f);
        glTranslatef(-17.50f, 9.0f, 1.0f);
        backArrow->parallaxDraw(screenWidth, screenHeight);
    glPopMatrix();
    glPushMatrix();
        glScalef(-0.25, 0.25, 1.0f);
        glTranslatef(-16.5f, 9.0f, 1.0f);
        backArrow->parallaxDraw(screenWidth, screenHeight);
    glPopMatrix();
}

void GLScene::drawSettingScreen(chrono::duration<float>& deltaTime) {
    glPushMatrix();
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glScalef(2.5, 2.5, 2.5);
        settingsIcon->parallaxDraw(screenWidth, screenHeight);
    glPopMatrix();
    glPushMatrix();
        glScalef(0.25, 0.25, 1.0f);
        glTranslatef(-17.50f, 9.0f, 1.0f);
        backArrow->parallaxDraw(screenWidth, screenHeight);
    glPopMatrix();
}

void GLScene::levelOneIntro(chrono::duration<float>& deltaTime) {
    glPushMatrix();
        glTranslatef(0.0, 1.0, 0.0);
        wiz->wizPosition.y = -0.55f;
        warrior->plPosition.y = -0.55f;
        rogue->plPosition.y = -0.55f;
        glScalef(1.75f, 0.75f, 1.0f);
        if (firstTime[0]) {
            backArrow->a = 1.0f;
            dark_souls->setVolume(100.0f);
            //wiz->wizPosition.x = -0.695f;
            dark_souls->playSound("sounds/dark_souls.wav");
            static float fade_2  = 0.0f;
            static float adj_2 = 0.75f * deltaTime.count();
            //cout << deltaTime.count() << "\n";
            title->parallaxDraw(screenWidth, screenHeight);
            title->a = fade_2;
            fade_2 += adj_2;
            if (fade_2 >= 1.1f) {
                adj_2 *= -1.0f;
            }
            if (fade_2 <= 0.0f)
                firstTime[0] = false;

            //cout << "Fade_2 value is: " << fade_2 << "\n";
        }
    glPopMatrix();
}

void GLScene::updateMusic() {
    (level == 1 || level == 2 || level == 7) ? main_menu = false : main_menu = true;

    (level == 4) ? (settings_menu = true, main_menu = false) : settings_menu = false;

    (settings_menu) ? settings_construction->playSound("sounds/construction.wav") : settings_construction->pauseSound("blank");

    (main_menu) ? main_theme->playSound("sounds/main_theme.wav") : main_theme->pauseSound("sounds/main_theme.wav");

    (level == 1) ? (level_one_background->setVolume(0.35f), level_one_background->playSound("sounds/level_one_background_music.wav"))
                    : level_one_background->pauseSound("blank");

    //(level == 2) ? (level_two_background->setVolume(0.35f), level_two_background->playSound("sound/cave.wav"))
    //                : level_two_background->pauseSound("blank");

    (level == 7) ? (level_three_background->setVolume(0.35f), level_three_background->playSound("sounds/underworld.wav"))
                    : level_three_background->pauseSound("blank");

    if (selected_class == WARRIOR) {
        if (warrior->health <= 0.0f && oneTime) {
            dark_souls_death->setVolume(0.75f);
            dark_souls_death->playSound("sounds/dark_souls_death_sound.wav");
            warrior_death->setVolume(0.60f);
            warrior_death->playSound("sounds/warrior_death_scream.wav");
            oneTime = false;
        }
    }
    if (selected_class == ROGUE) {
        if (rogue->health <= 0.0f && oneTime) {
            dark_souls_death->setVolume(0.75f);
            dark_souls_death->playSound("sounds/dark_souls_death_sound.wav");
            warrior_death->setVolume(0.60f);
            warrior_death->playSound("sounds/warrior_death_scream.wav");
            oneTime = false;
        }
    }

    if (selected_class == WIZARD) {
        if (wiz->health <= 0.0f && oneTime) {
            dark_souls_death->setVolume(0.75f);
            dark_souls_death->playSound("sounds/dark_souls_death_sound.wav");
            warrior_death->setVolume(0.60f);
            warrior_death->playSound("sounds/warrior_death_scream.wav");
            oneTime = false;
        }
    }
}

void GLScene::gameOverCheck(chrono::duration<float>& deltaTime) {
    if ( warrior->isDead || rogue->health <= 0.0f || wiz->health <= 0.0f) {
        glPushMatrix();
            static float fade_12 = 0.0f;
            static float adj  = 0.35f * deltaTime.count();
            if (fade_12 >= 1.0f) {}
            else {
                fade_12 += adj;
            }
            game_over->parallaxDraw(screenWidth, screenHeight);
            game_over->a = fade_12;
        glPopMatrix();
    }
}

void GLScene::levelTwoIntro(chrono::duration<float>& deltaTime) {
    glPushMatrix();
        glTranslatef(0.0, 1.0, 0.0);
        wiz->wizPosition.y = -0.5f;
        warrior->plPosition.y = -0.5f;
        rogue->plPosition.y = -0.5f;
        //slimeEnemy2->pos.y = -0.60f;
        //slimeEnemy->pos.y = -0.575f;
        glScalef(1.75f, 0.75f, 1.0f);
        if (firstTime[1]) {
            dark_souls->playSound("sounds/dark_souls.wav");
            static float fade_0 = 0.0f;
            slimeEnemy2->health = 10.0f;
            slimeEnemy->health = 10.0f;
            slimeEnemy->isAlive = true;
            slimeEnemy2->isAlive = true;
            //slimeEnemy->pos.x = 0.545;
            bossTrigger = false;
            static float adj  = 0.35f * deltaTime.count();
            title_2->parallaxDraw(screenWidth, screenHeight);
            title_2->a = fade_0;
            fade_0 += adj;
            if (fade_0 >= 1.2f) {
                adj *= -1.0f;
            }
            if (fade_0 < 0.0f)
                firstTime[1] = false;
            //cout << "Fade value is: " << fade << "\n";
        }
    glPopMatrix();
}

void GLScene::levelThreeIntro(chrono::duration<float>& deltaTime) {
    glPushMatrix();
        glTranslatef(0.0, 1.0, 0.0);
        wiz->wizPosition.y = -0.585f;
        warrior->plPosition.y = -0.585f;
        rogue->plPosition.y = -0.585f;
        slimeEnemy2->pos.y = -0.60f;
        slimeEnemy->pos.y = -0.595f;
        glScalef(1.75f, 0.75f, 1.0f);
        if (firstTime[2]) {
            skel->health = 10.0f;
            dark_souls->playSound("sounds/dark_souls.wav");
            static float fade_29 = 0.0f;
            slimeEnemy2->health = 10.0f;
            slimeEnemy->health = 10.0f;
            slimeEnemy->isAlive = true;
            slimeEnemy2->isAlive = true;
            bossTrigger = false;
            static float adj_29  = 0.35f * deltaTime.count();
            title_3->parallaxDraw(screenWidth, screenHeight);
            title_3->a = fade_29;
            fade_29 += adj_29;
            if (fade_29 >= 1.0f) {
                adj_29 *= -1.0f;
            }
            if (fade_29 < 0.0f)
                firstTime[2] = false;
            //cout << "Fade value is: " << fade << "\n";
        }
    glPopMatrix();
}

void GLScene::victoryIntro(chrono::duration<float>& deltaTime) {
    glPushMatrix();
        static float fade_29 = 0.0f;
        static float adj_29  = 0.35f * deltaTime.count();
        //victory_screen->parallaxDraw(screenWidth, screenHeight);
        //victory_screen->a = fade_29;
        wizardProfile->a = fade_29;
        warriorProfile->a = fade_29;
        rogueProfile->a = fade_29;
        health_bar->a = fade_29;
        mana_bar->a = fade_29;
        backArrow->a = fade_29;
        warrior->a = fade_29;
        wiz->a = fade_29;
        rogue->a = fade_29;
        skel->a = fade_29;
        //slimeEnemy2->a = fade_29;
        //slimeEnemy->a = fade_29;
        //archer->a = fade_29;
        text_5->a = fade-29;
        if (fade_29 >= 1.0f) {

        }
        else
            fade_29 += adj_29;

    glPopMatrix();
}

void GLScene::drawPlayerAndHUD(bClock* iClock) {
        //cout << wiz->mana << endl;
        if ( (level == 1 || level == 2 || level == 7) && selected_class == WIZARD) {
                float scaleHp = wiz->maxHealth / 15.0 * wiz->health / wiz->maxHealth;
                float scaleMana = 0.9 * wiz->maxMana / 10.0 * wiz->mana / wiz->maxMana;
                //cout << 0.0f - scaleHp * ((1.0 / scaleHp) - 1) / 2.0 << '\n';
            glPushMatrix();
                glTranslatef(0.0, 2.5f, 1.0f);
                glScalef(scaleHp, 0.05, 1.0);
                health_bar->parallaxDraw(screenWidth, screenHeight);
                health_bar->a = 0.85f;
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0, 2.4f, 1.0f);
                glScalef(scaleMana, 0.05, 1.0f);
                mana_bar->parallaxDraw(screenWidth, screenHeight);
                mana_bar->a = 0.85f;
                mana_bar->r = 1.0f;
                mana_bar->g = 1.0f;
                mana_bar->b = 1.0f;
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0, 2.5f, 1.0f);
                glScalef(0.22f, 0.2f, 1.0f);
                wizardProfile->parallaxDraw(screenWidth, screenHeight);
                wizardProfile->a = 1.0f;
            glPopMatrix();
            glPushMatrix();
                glDisable(GL_LIGHTING);
                wiz->drawWiz(iClock->dTime);
            glPopMatrix();
            if (wiz->inventoryOpened) {
                glPushMatrix();
                    //glTranslatef(3.0f, 2.0f, 1.0f);
                    glScalef(0.8f, .75f, 1.0f);
                    inventory->parallaxDraw(screenWidth, screenHeight);
                    inventory->a = 0.95f;
                    wiz->inventory->drawInventory(0);
                glPopMatrix();
            }

            if (wiz->wizPosition.x >= 1000.0f) {
                wiz->wizPosition.x = -1.0f;
            }

            //wiz->hb->updateCenter(wiz->wizPosition.x, -0.55f);
            //wiz->hb->printCenter();
            //cout << "\n";
        }
        else if ( (level == 1 || level == 2 || level == 7) && selected_class == WARRIOR) {
            glPushMatrix();
                float scaleHp = warrior->maxHealth / 15.0 * warrior->health / warrior->maxHealth;
                float scaleStam = 0.9 * warrior->maxStam / 10.0 * warrior->stamina / warrior->maxStam;
                glTranslatef(0.0f, 2.5f, 1.0f);
                glScalef(scaleHp, 0.05, 1.0);
                health_bar->parallaxDraw(screenWidth, screenHeight);
                health_bar->a = 0.85f;
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0, 2.4f, 1.0f);
                glScalef(scaleStam * .85f, 0.05, 1.0f);
                mana_bar->parallaxDraw(screenWidth, screenHeight);
                mana_bar->a = 0.85f;
                mana_bar->r = 0.0f;
                mana_bar->b = 0.0f;
                mana_bar->g = 1.0f;
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-0.0, 2.4f, 1.0f);
                glScalef(0.2f, 0.2f, 1.0f);
                warriorProfile->parallaxDraw(screenWidth, screenHeight);
                warriorProfile->a = 1.0f;
            glPopMatrix();

            glPushMatrix();
                glDisable(GL_LIGHTING);
                if (warrior->alive)
                    warrior->drawPlayer(iClock->dTime);
                else {}
            glPopMatrix();
            if (warrior->inventoryOpened) {
                glPushMatrix();
                    glScalef(0.8f, .75f, 1.0f);
                    inventory->parallaxDraw(screenWidth, screenHeight);
                    inventory->a = 0.95f;
                    warrior->inventory->drawInventory(0);
                glPopMatrix();
            }
        }
        else if ( (level == 1 || level == 2 || level == 7) && selected_class == ROGUE) {
                float scaleHp = rogue->maxHealth / 15.0 * rogue->health / rogue->maxHealth;
                float scaleStam = 0.9 * rogue->maxStam / 10.0 * rogue->stamina / rogue->maxStam;
            glPushMatrix();
                glTranslatef(0.0, 2.5f, 1.0f);
                glScalef(scaleHp, 0.05, 1.0);
                health_bar->parallaxDraw(screenWidth, screenHeight);
                health_bar->a = 0.85f;
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0, 5.0-2.6f, 1.0f);
                glScalef(scaleStam, 0.05, 1.0f);
                mana_bar->parallaxDraw(screenWidth, screenHeight);
                mana_bar->a = 0.85f;
                mana_bar->r = 0.0f;
                mana_bar->b = 0.0f;
                mana_bar->g = 1.0f;
            glPopMatrix();
            glPushMatrix();
                glTranslatef(0.0, 2.4f, 1.0f);
                glScalef(0.2f, 0.2f, 1.0f);
                rogueProfile->parallaxDraw(screenWidth, screenHeight);
                rogueProfile->a = 1.0f;
            glPopMatrix();
            if (warrior->inventoryOpened) {
                glPushMatrix();
                    glScalef(0.8f, .75f, 1.0f);
                    inventory->parallaxDraw(screenWidth, screenHeight);
                    inventory->a = 0.95f;
                    rogue->inventory->drawInventory(0);
                glPopMatrix();
            }
            glPushMatrix();
                glDisable(GL_LIGHTING);
                if (rogue->alive)
                    rogue->drawPlayer(iClock->dTime);
                else {}
            glPopMatrix();
        }

}

GLint GLScene::drawScene()                                           //This function runs on a loop, do not abuse it!!!
{
    auto start = std::chrono::steady_clock::now();  // Record the start time

    iClock->update();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);              //Each time you draw something, have to clear bits each iteration
    glLoadIdentity();
    //glTranslatef(0.0f, 0.0f, -8.0f);                               //Translate object to x, y , z
    glColor3f(1.0, 1.0, 1.0);                                        //Color the object green

    updateMusic();

    auto now = chrono::high_resolution_clock::now();
    chrono::duration<float> deltaTime = now - lastFrameTime;
    lastFrameTime = now;

    //idle();

    switch(level) {
        case 0:
            drawMainMenu();
            break;
        case 1:
            drawLevelOne(deltaTime);
            levelOneIntro(deltaTime);
            break;
        case 2:
            drawLevelTwo(deltaTime);
            levelTwoIntro(deltaTime);
            break;
        case 3:         //New Game
            drawNewGameScreen(deltaTime);
            break;
        case 4:         //Settings
            drawSettingScreen(deltaTime);
            break;
        case 5:
            drawHelpScreen();
            break;
        case 6:
            drawLandingPage(deltaTime);
            break;
        case 7:
            drawLevelThree(deltaTime);
            levelThreeIntro(deltaTime);
            break;
        case 8:
            victoryIntro(deltaTime);
            drawVictoryScreen(deltaTime);
            break;
        case 9:
            drawControlsPage();
            break;
    }

    drawPlayerAndHUD(iClock);
    drawSlimes();
    checkCollisions();
    gameOverCheck(deltaTime);

    glEnable(GL_LIGHTING);

    // Calculate the elapsed time for this frame
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;

    // If the frame took less time than the desired frame duration, do nothing below
    if (elapsed.count() < frameDuration) {
        auto sleepTime = std::chrono::milliseconds(static_cast<int>(frameDuration - elapsed.count()));

        // Busy-wait or delay to reach the desired frame duration
        while (std::chrono::steady_clock::now() - start < std::chrono::milliseconds(static_cast<int>(frameDuration))) {
            // Do nothing
        }
    }

    return true;
}

GLvoid GLScene::resizeScene(GLsizei width, GLsizei height)
{
    GLfloat aspectRatio = (GLfloat)width/(GLfloat)height;            //keep track of the ratio
    glViewport(0, 0, width, height);                                 //adjusting the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, aspectRatio, 0.1, 100);
    glMatrixMode(GL_MODELVIEW);
}

GLScene::GLScene()
{
    screenWidth  = GetSystemMetrics(SM_CXSCREEN);
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
}

GLScene::~GLScene()
{
    //dtor
}

int GLScene::windMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    //WINDOWPLACEMENT placement = { sizeof(WINDOWPLACEMENT) };
    //GetWindowPlacement(hWnd, & placement);
    //placement.showCmd = SW_SHOWMAXIMIZED;
    //fullscreen = placement.showCmd;



    switch(uMsg)           //check for inputs
    {
    case WM_KEYDOWN:
        KbMs->wParam = wParam;
        KbMs->keyPress(this->victory, wiz, open_inventory, close_inventory, step, this->level, this->prev_level, this->selected_class, warrior, rogue);
        KbMs->keyBackground(plx, 0.005f);
        KbMs->keyBackground(plx1, 0.0005f);
        KbMs->keyBackground(dungeon_2, 0.005f);
        KbMs->keyBackground(dungeon_3, 0.0005f);
        KbMs->keyBackground(underworld_6, 0.000005f);
        KbMs->keyBackground(underworld_5, 0.00005);
        KbMs->keyBackground(underworld_4, 0.0005);
        KbMs->keyBackground(underworld_3, 0.00090);
        KbMs->keyBackground(underworld_2, 0.00075);
        KbMs->keyBackground(underworld_1, 0.00050);
        KbMs->keyBackground(underworld_g, 0.005);
        break;
    case WM_KEYUP:
        KbMs->wParam = wParam;
        KbMs->keyUp(wiz, open_inventory, close_inventory, this->level, warrior, rogue);
        break;
    case WM_LBUTTONDOWN:
        KbMs->wParam = wParam;
        KbMs->mouseEventDown(this->level, this->prev_level, this->next_level, this->selected_class, firstTime, wiz, warrior, rogue, menu_click, warrior_attack_1, fullscreen, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight);
        break;
    case WM_RBUTTONDOWN:
        KbMs->wParam = wParam;
        KbMs->mouseEventDown(this->level, this->prev_level, this->next_level, this->selected_class, firstTime, wiz, warrior, rogue, menu_click, warrior_attack_1, fullscreen, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight);
        break;
    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
        KbMs->mouseEventUp(wiz);
        break;
    case WM_MOUSEMOVE:
        KbMs->wParam = wParam;
        KbMs->mouseMove(teaPotModel, text, icons, this->level, fullscreen, LOWORD(lParam), HIWORD(lParam));
        break;
    case WM_MOUSEWHEEL:
        KbMs->mouseWheel(teaPotModel, (double)GET_WHEEL_DELTA_WPARAM(wParam));
        break;
    }
}
