#include "GLInputs.h"


GLInputs::GLInputs()
{
    //ctor

    prev_MouseX = 0;
    prev_MouseY = 0;
                                      //Init Mouse Values
    mouse_Translate = false;
    mouse_Rotate    = false;

}

GLInputs::~GLInputs()
{
    //dtor
}
void GLInputs::keyPress(bool& victory, GLWizard* wiz, GLSounds* open, GLSounds* close, GLSounds* step, int& level_id, int& prev_level, int& selected_class, GLWarrior* warrior, GLRogue* rogue)
{

    if (GetAsyncKeyState(VK_RETURN) < 0) {
        if (level_id == 6) {
            close->playSound("sounds/interface_click.wav");
            level_id = 0;
            prev_level = 0;
            close->setVolume(0.75f);
        }
    }

     if(GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(0x41) & 0x8000){

        warrior->actionTrigger[warrior->STAND] = false;
        warrior->actionTrigger[warrior->WALKLEFT] = true;
        warrior->actionTrigger[warrior->WALKRIGHT] = false;

        wiz->actionTrigger[wiz->IDLE] = false;
        wiz->actionTrigger[wiz->WALKLEFT] = true;
        wiz->actionTrigger[wiz->WALKRIGHT] = false;

        rogue->actionTrigger[rogue->STAND] = false;
        rogue->actionTrigger[rogue->WALKLEFT] = true;
        rogue->actionTrigger[rogue->WALKRIGHT] = false;
        step->setVolume(0.25f);
        step->playSound("sounds/step.wav");
    }

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(0x44) & 0x8000){
        warrior->actionTrigger[warrior->STAND] = false;
        warrior->actionTrigger[warrior->WALKLEFT] = false;
        warrior->actionTrigger[warrior->WALKRIGHT] = true;
        wiz->actionTrigger[wiz->IDLE] = false;
        wiz->actionTrigger[wiz->WALKLEFT] = false;
        wiz->actionTrigger[wiz->WALKRIGHT] = true;
        rogue->actionTrigger[rogue->STAND] = false;
        rogue->actionTrigger[rogue->WALKLEFT] = false;
        rogue->actionTrigger[rogue->WALKRIGHT] = true;

        step->setVolume(0.25f);
        step->playSound("sounds/step.wav");
    }
    if (GetKeyState(VK_UP) < 0 || GetKeyState(0x57 < 0)) {
        //Model->RotateX += 1.0;
    }
    if (GetKeyState(VK_DOWN) < 0 || GetKeyState(0x53) < 0) {
        //Model->RotateX -= 1.0;
    }
    if (GetKeyState(VK_SPACE) < 0) {
        if (selected_class == 2) {
            if (warrior->plPosition.y <= 1.25) {
                warrior->actionTrigger[warrior->JUMP] = true;
            }
        }
        if (selected_class == 1) {
            if (rogue->plPosition.y <= 1.25) {
                rogue->actionTrigger[rogue->JUMP] = true;
            }
        }
    }
    if (GetKeyState(0x49) < 0) {
        if (!wiz->inventoryOpened) {
            wiz->inventoryOpened = true;
            open->playSound("sounds/open_bag.wav");
        }
        else if (wiz->inventoryOpened) {
            wiz->inventoryOpened = false;
            close->setVolume(1.0f);
            close->playSound("sounds/close_bag.wav");
        }

        if (!warrior->inventoryOpened) {
            warrior->inventoryOpened = true;
            open->playSound("sounds/open_bag.wav");
        }
        else if (warrior->inventoryOpened) {
            warrior->inventoryOpened = false;
            close->playSound("sounds/close_bag.wav");
        }
        if (!rogue->inventoryOpened) {
            rogue->inventoryOpened = true;
            open->playSound("sounds/open_bag.wav");
        }
        else if (rogue->inventoryOpened) {
            rogue->inventoryOpened = false;
            close->playSound("sounds/close_bag.wav");
        }
        wiz->actionTrigger[wiz->IDLE] = true;
        wiz->actionTrigger[wiz->ATTACK] = false;
        wiz->actionTrigger[wiz->JUMP] = false;
        wiz->actionTrigger[wiz->WALKLEFT] = false;
        wiz->actionTrigger[wiz->WALKRIGHT] = false;
    }

    if (GetKeyState(0x35) < 0) {
        victory = true;
    }



    if (GetKeyState(0x30) < 0) {
        prev_level = level_id;
        level_id = 0;
    }
    if (GetKeyState(0x31) < 0) {
        prev_level = level_id;
        level_id = 1;
    }
    if (GetKeyState(0x32) < 0) {
        prev_level = level_id;
        level_id = 2;
    }

    if (GetKeyState(0x33) < 0) {
        prev_level = level_id;
        level_id = 7;
    }

    if (GetKeyState(0x37) < 0) {
        selected_class = 0;
    }

    if (GetKeyState(0x38) < 0) {
        selected_class = 2;
    }
    if (GetKeyState(0x39) < 0) {
        selected_class = 1;
    }

    if (GetKeyState(VK_SHIFT) < 0) {
       wiz->actionTrigger[wiz->RUN] = true;
       warrior->actionTrigger[warrior->RUN] = true;
       rogue->actionTrigger[rogue->RUN] = true;
    }

    if (GetKeyState(0x48) < 0) {
        level_id = 8;
    }
    if (GetKeyState(0x45) < 0) {
        if (warrior->inventory->relics[0]->lvl > 0) {
            warrior->health += 10.0;
            warrior->inventory->relics[0]->lvl -= 1;
        }
        if (rogue->inventory->relics[0]->lvl > 0) {
            rogue->health += 10.0;
            rogue->inventory->relics[0]->lvl -= 1;
        }
        if (wiz->inventory->relics[0]->lvl > 0) {
            wiz->health += 10.0;
            wiz->inventory->relics[0]->lvl -= 1;
        }
    }
    if (GetKeyState(0x51) < 0) {
        if (warrior->inventory->relics[1]->lvl > 0) {
            warrior->stamina += 10.0;
            warrior->inventory->relics[1]->lvl -= 1;
        }
        if (rogue->inventory->relics[1]->lvl > 0) {
            rogue->stamina += 10.0;
            rogue->inventory->relics[1]->lvl -= 1;
        }
        if (wiz->inventory->relics[1]->lvl > 0) {
            wiz->mana += 10.0;
            wiz->inventory->relics[1]->lvl -= 1;
        }
    }
}

void GLInputs::keyUp(GLWizard* wiz, GLSounds* open, GLSounds* close, int& level_id, GLWarrior* warrior, GLRogue* rogue)
{
    switch(wParam)
    {
    case VK_LEFT:
    case VK_RIGHT:
    case 0x41:
    case 0x44:
        warrior->actionTrigger[warrior->STAND] = true;
        warrior->actionTrigger[warrior->WALKLEFT] = false;
        warrior->actionTrigger[warrior->WALKRIGHT] = false;
        wiz->actionTrigger[wiz->IDLE] = true;
        wiz->actionTrigger[wiz->WALKLEFT] = false;
        wiz->actionTrigger[wiz->WALKRIGHT] = false;
        rogue->actionTrigger[rogue->STAND] = true;
        rogue->actionTrigger[rogue->WALKLEFT] = false;
        rogue->actionTrigger[rogue->WALKRIGHT] = false;

        wiz->wizVelocity.x = 0.0f;

        //wiz->lastAction = wiz->IDLE;
        //prlx->dir = prlx->STOP;
        break;
    case VK_SHIFT:
        wiz->actionTrigger[wiz->RUN] = false;
    default:
        break;
    }


}

void GLInputs::mouseEventDown(int& level, int& prev_level, int& next_level, int& selected_class, bool* fT, GLWizard* wiz, GLWarrior* warrior, GLRogue* rogue, GLSounds* click, GLSounds* attack, bool full, double x, double y, float width, float height)
{
    prev_MouseX =x;   //keep previous x val
    prev_MouseY =y;   // keep previous y val

    float scale = 60 * (width / height);
    float mx = (float)(x - width / 2.0) / scale;                               //Operations to convert pixel space to
    float my = (float)(height / 2.0 - y) / scale;                              //---opengl window/view space

    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY, winZ;
    GLdouble posX, posY, posZ;
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);

    winX = (float)x;
    winY = (float)viewport[3] - (float)y;
    glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

    gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

    //cout << "X Value: " << posX << " | Y Value: " << posY << "\n";


    //cout << "MX: " << mx << " | MY: " << my << endl;

    float temp;
    if (full)
        temp = 20.0f;
    else
        temp = 0.0f;

    switch (wParam)
    {
        case MK_LBUTTON:
            switch(level) {
                case 0:
                    if (posX >= -0.5254 && posX <= 0.52 && posY >= -.22 && posY <= 0.22) {
                        if (!fT[0]) {
                            //prev_level = level;
                            //level = 3;
                            level = prev_level;
                            click->playSound("sounds/interface_click.wav");
                        }
                        else {
                            prev_level = level;
                            level = 3;
                            click->playSound("sounds/interface_click.wav");
                        }
                    }
                    if (posX >= -0.52 && posX <= 0.55 && posY >= -.93 && posY <= -0.425) {
                        //cout << "SETTINGS" "\n";
                        prev_level = level;
                        level = 4;
                        click->playSound("sounds/interface_click.wav");
                    }
                    if (posX >= -0.47 && posX <= 0.46 && posY >= -1.71 && posY <= -1.21) {
                        //cout << "HELP" "\n";
                        prev_level = level;
                        level = 5;
                        click->playSound("sounds/interface_click.wav");
                    }
                    if (posX >= -0.46 && posX <= 0.46 && posY >= -2.51 && posY <= -2.01) {
                        //cout << "EXIT" << "\n";
                        click->playSound("sounds/interface_click.wav");
                        exit(-1);
                    }
                    //cout << x << " " << y << "\n";
                    break;
                case 1:
                    if (x >= 50 && x <= 160 && y >= (40 + temp) && y <= (120 + temp)) {
                        prev_level = level;
                        level = 0;
                        click->playSound("sounds/interface_click.wav");
                    }

                    if (selected_class == 2 && !warrior->actionTrigger[warrior->SPECIAL]) {
                        warrior->actionTrigger[warrior->ATTACK]=true;
                        attack->playSound("sounds/sword_swing.wav");
                    }
                    else if (selected_class == 1 && !rogue->actionTrigger[rogue->SPECIAL] ) {
                        rogue->actionTrigger[rogue->ATTACK] = true;
                        attack->playSound("sounds/rogue_sword.wav");
                    }
                    else if (selected_class == 0 && !wiz->actionTrigger[wiz->SPECIAL]) {
                        wiz->actionTrigger[wiz->ATTACK] = true;
                        //wiz->actionTrigger[wiz->IDLE] = false;
                        //wiz->actionTrigger[wiz->WALKLEFT] = false;
                        //wiz->actionTrigger[wiz->WALKRIGHT] = false;
                        //wiz->actionTrigger[wiz->JUMP] = false;
                    }

                    //wiz->lastAction = wiz->ATTACK;
                    break;
                case 2:
                    if (posX >= -4.77 && posX <= -3.96 && posY >= 2.015 && posY <= 2.467) {
                        if (selected_class == 2) {
                            if (warrior->health <= 0.0f) {
                                fT[0] = true;
                                fT[1] = true;
                                prev_level = 0;
                                level = 0;
                                click->playSound("sounds/interface_click.wav");
                            }
                            else {
                                prev_level = level;
                                level = 0;
                                click->playSound("sounds/interface_click.wav");
                            }
                        }
                    }
                    if (selected_class == 2  && !warrior->actionTrigger[warrior->SPECIAL]) {
                        warrior->actionTrigger[warrior->ATTACK]=true;
                        attack->playSound("sounds/sword_swing.wav");
                    }
                    else if (selected_class == 1 && !rogue->actionTrigger[rogue->SPECIAL]) {
                        rogue->actionTrigger[rogue->ATTACK] = true;
                        attack->playSound("sounds/rogue_sword.wav");
                    }
                    else if (selected_class == 0 && !rogue->actionTrigger[rogue->SPECIAL]) {
                        wiz->actionTrigger[wiz->ATTACK] = true;
                        //wiz->actionTrigger[wiz->IDLE] = false;
                        //wiz->actionTrigger[wiz->WALKLEFT] = false;
                        //wiz->actionTrigger[wiz->WALKRIGHT] = false;
                        //wiz->actionTrigger[wiz->JUMP] = false;
                    }

                    break;
                case 3:
                    //cout << x << " " << y << "\n";
                    if (posX >= -4.757 && posX <= -2.0211 && posY >= -2.702 && posY <= 1.657) {            //Wizard
                        click->playSound("sounds/interface_click.wav");
                        next_level = 1;
                        prev_level = level = 3;
                        selected_class = 0;
                    }
                    if (posX >= -1.28 && posX <= 1.35 && posY >= -2.43 && posY <= 1.69) {            //Rogue
                        click->playSound("sounds/interface_click.wav");
                        next_level = 1;
                        prev_level = level = 3;
                        selected_class = 2;
                    }
                    if (posX >= 2.080 && posX <= 4.77 && posY >= -2.72 && posY <= 1.68) {           //Warrior
                        click->playSound("sounds/interface_click.wav");
                        next_level = 1;
                        prev_level = level = 3;
                        selected_class = 1;
                    }
                    if (posX >= -4.77 && posX <= -3.96 && posY >= 2.015 && posY <= 2.467) {
                        //level = prev_level;
                        prev_level = level;
                        level = 0;
                        click->playSound("sounds/interface_click.wav");
                    }
                    break;
                case 4:
                    //cout << x << " " << y << "\n";
                    if (posX >= -4.77 && posX <= -3.96 && posY >= 2.015 && posY <= 2.467) {
                        level = prev_level;
                        prev_level = level;
                        click->playSound("sounds/interface_click.wav");
                    }
                    break;
                case 5:
                    //cout << x << " " << y << endl;
                    if (posX >= -4.77 && posX <= -3.96 && posY >= 2.015 && posY <= 2.467) {
                        level = prev_level;
                        prev_level = level;
                        click->playSound("sounds/interface_click.wav");
                    }
                    if (posX >= 3.69 && posX <= 4.54 && posY >= 2.007 && posY <= 2.60) {
                        prev_level = level;
                        level = 9;
                        click->playSound("sounds/interface_click.wav");
                    }
                    break;
                case 7:
                    if (posX >= -4.77 && posX <= -3.96 && posY >= 2.015 && posY <= 2.467) {
                        //level = prev_level;
                        prev_level = level;
                        level = 0;
                        click->playSound("sounds/interface_click.wav");
                    }
                    if (selected_class == 2 && !warrior->actionTrigger[warrior->SPECIAL]) {
                        warrior->actionTrigger[warrior->ATTACK]=true;
                        attack->playSound("sounds/sword_swing.wav");
                    }
                    else if (selected_class == 1 && !rogue->actionTrigger[rogue->SPECIAL]) {
                        rogue->framesX = 10;
                        rogue->actionTrigger[rogue->ATTACK] = true;
                        attack->playSound("sounds/rogue_sword.wav");
                    }
                    else if (selected_class == 0 && !wiz->actionTrigger[wiz->SPECIAL]) {
                        wiz->actionTrigger[wiz->ATTACK] = true;
                    }
                    break;
                case 9:
                    if (posX >= -4.77 && posX <= -3.96 && posY >= 2.015 && posY <= 2.467) {
                        //level = prev_level;
                        //prev_level = level;
                        level = 0;
                        prev_level = 0;
                        click->playSound("sounds/interface_click.wav");
                    }
                    break;

            }
            break;
        case MK_RBUTTON:
            switch(level) {
            case 1:
            case 2:
            case 7:
                if (selected_class == 2 && warrior->stamina >= 3.0f && !warrior->actionTrigger[warrior->ATTACK]) {
                    warrior->actionTrigger[warrior->SPECIAL] = true;
                    attack->playSound("sounds/sword_swing.wav");
                    warrior->stamina -= 3.0f;
                }
                   if (selected_class == 1 && rogue->stamina >= 1.5f && !rogue->actionTrigger[rogue->ATTACK]) {
                    rogue->actionTrigger[rogue->SPECIAL] = true;
                    attack->playSound("sounds/rogue_sword.wav");
                    rogue->stamina -= 1.5;
                }
                if (selected_class == 0 && wiz->mana >= 2.5 && !wiz->projAlive && !wiz->actionTrigger[wiz->ATTACK]) {
                    wiz->actionTrigger[wiz->SPECIAL] = true;
                    wiz->mana -= 2.5;
                    attack->playSound("sounds/blast.mp3");
                }
                break;
            }
        case MK_MBUTTON:
            break;
        default:
            break;
    }
}

void GLInputs::mouseEventUp(GLWizard* wiz)
{
    mouse_Rotate    = false;             //Reset Rotation    Flag
    mouse_Translate = false;             //Reset Translation Flag
/*
    wiz->actionTrigger[wiz->ATTACK] = false;
    wiz->actiontrigger = wiz->IDLE;
    wiz->framesX = 6;
    wiz->xMin = 0.0f;
    wiz->xMax = 1 / (float)wiz->framesX;

    wiz->actionTrigger[wiz->IDLE] = true;
    wiz->actionTrigger[wiz->WALKLEFT] = false;
    wiz->actionTrigger[wiz->WALKRIGHT] = false;
    wiz->actionTrigger[wiz->ATTACK] = false;
    //wiz->xMin = 0.0;
    wiz->framesX = 6;

    //wiz->xMax = 1 / (float)wiz->framesX;
*/
}

void GLInputs::mouseWheel(GLModel* mdl, double delta)
{
    mdl->zPos += delta / 100.0 ;      //Mouse Wheel Movement
}

void GLInputs::mouseMove(GLModel* mdl, GLParallax* text[], GLParallax* icons[], int& level, bool full,  double x, double y)
{
    if (mouse_Translate)
    {
        mdl->xPos += (x - prev_MouseX) / 100.0;                   //Move Model X Direction
        mdl->yPos -= (y - prev_MouseY) / 100.0;                   //Move Model Y Direction

        prev_MouseX = x;                                          //Update Previous Mouse X
        prev_MouseY = y;                                          //Update Previous Mouse Y

    }

    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY, winZ;
    GLdouble posX, posY, posZ;
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);

    winX = (float)x;
    winY = (float)viewport[3] - (float)y;
    glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

    gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);


    switch (level) {
        case 0:     //Main Menu
            if (posX >= -0.5254 && posX <= 0.52 && posY >= -.22 && posY <= 0.22) {
                //cout << "NEW GAME!" << "\n";
                text[1]->r = 0.0f;
                //text[1]->z += 1.0f;
                text[6]->r = 0.0f;
            }
            else {
                text[1]->r = 1.0f;
                //text[1]->z -= 1.0f;
                text[6]->r = 1.0f;
            }
            if (posX >= -0.52 && posX <= 0.55 && posY >= -.93 && posY <= -0.425)  {
                //cout << "SETTINGS" "\n";
                text[2]->r = 0.0f;
                text[2]->z += 1.0f;
            }
            else {
                text[2]->r = 1.0f;
                text[2]->z - 1.0f;
            }
            if (posX >= -0.47 && posX <= 0.46 && posY >= -1.71 && posY <= -1.21) {
                //cout << "HELP" "\n";
                text[3]->r = 0.0f;
                text[3]->z += 1.0f;
            }
            else {
                text[3]->r = 1.0f;
                text[3]->z -= 1.0f;
            }
            if (posX >= -0.46 && posX <= 0.46 && posY >= -2.51 && posY <= -2.01) {
                //cout << "EXIT" << "\n";
                text[4]->r = 0.0f;
                text[4]->z += 1.0f;
            }
            else {
                text[4]->r = 1.0f;
                text[4]->z -= 1.0f;
            }
            break;
        case 1:
            if (posX >= -4.77 && posX <= -3.96 && posY >= 2.015 && posY <= 2.467) {
                text[5]->r = 0.0f;
                text[5]->b = 0.0f;
            }
            else {
                text[5]->r = 1.0f;
                text[5]->b = 1.0f;
            }
            break;
        case 2:
            if (posX >= -4.77 && posX <= -3.96 && posY >= 2.015 && posY <= 2.467) {
                text[5]->r = 0.0f;
                text[5]->b = 0.0f;
            }
            else {
                text[5]->r = 1.0f;
                text[5]->b = 1.0f;
            }
            break;
        case 3:     //New Game
            //cout << x << " " << y << "\n";
            if (posX >= -4.757 && posX <= -2.0211 && posY >= -2.702 && posY <= 1.657) {            //Wizard
                icons[0]->r = 0.0f;
                icons[0]->b = 0.0f;
            }
            else {
                icons[0]->r = 1.0f;
                icons[0]->b = 1.0f;
            }
            if (posX >= -1.28 && posX <= 1.35 && posY >= -2.43 && posY <= 1.69) {            //Rogue
                icons[1]->r = 0.0f;
                icons[1]->b = 0.0f;
            }
            else {
                icons[1]->r = 1.0f;
                icons[1]->b = 1.0f;
            }
            if (posX >= 2.080 && posX <= 4.77 && posY >= -2.72 && posY <= 1.68) {           //Warrior
                icons[2]->r = 0.0f;
                icons[2]->b = 0.0f;
                //cout << "here" << "\n";
            }
            else {
                icons[2]->r = 1.0f;
                icons[2]->b = 1.0f;
            }
            if (posX >= -4.77 && posX <= -3.96 && posY >= 2.015 && posY <= 2.467) {              //Arrow
                text[5]->r = 0.0f;
                text[5]->b = 0.0f;
            }
            else {
                text[5]->r = 1.0f;
                text[5]->b = 1.0f;
            }
            break;
        case 4:
            if (posX >= -4.77 && posX <= -3.96 && posY >= 2.015 && posY <= 2.467) {
                text[5]->r = 0.0f;
                text[5]->b = 0.0f;
            }
            else {
                text[5]->r = 1.0f;
                text[5]->g = 1.0f;
                text[5]->b = 1.0f;
            }
            break;
        case 5:
            if (posX >= -4.77 && posX <= -3.96 && posY >= 2.015 && posY <= 2.467) {
                text[5]->r = 0.0f;
                text[5]->b = 0.0f;
            }
            else {
                text[5]->r = 1.0f;
                text[5]->g = 1.0f;
                text[5]->b = 1.0f;
            }
            if (posX >= 3.69 && posX <= 4.54 && posY >= 2.007 && posY <= 2.60) {
                text[5]->r = 0.0f;
                text[5]->b = 0.0f;
            }
            else {
                text[5]->r = 1.0f;
                text[5]->g = 1.0f;
                text[5]->b = 1.0f;
            }
            break;
        case 7:
            if (posX >= -4.77 && posX <= -3.96 && posY >= 2.015 && posY <= 2.467) {
                text[5]->r = 0.0f;
                text[5]->b = 0.0f;
            }
            else {
                text[5]->r = 1.0f;
                text[5]->g = 1.0f;
                text[5]->b = 1.0f;
            }
            break;
        case 9:
            if (posX >= -4.77 && posX <= -3.96 && posY >= 2.015 && posY <= 2.467) {
                text[5]->r = 0.0f;
                text[5]->b = 0.0f;
            }
            else {
                text[5]->r = 1.0f;
                text[5]->g = 1.0f;
                text[5]->b = 1.0f;
            }
            break;
        default:
            break;

    }


    if (mouse_Rotate)
    {
        mdl->RotateY += (x - prev_MouseX) / 3.0;                  //Model Rotation on X Direction
        mdl->RotateX += (y - prev_MouseY) / 3.0;                  //Model Rotation on Y Direction

        prev_MouseX = x;                                          //Update Previous Mouse X
        prev_MouseY = y;                                          //Update Previous Mouse Y
    }
}

void GLInputs::keyBackground(GLParallax* prlx, float speed)
{
        //if (clock() - myTime->startTime > 15) {
        switch(wParam) {
            case VK_UP:    prlx->yMin -= speed; prlx->yMax -= speed; break;      //Move Background UP
            case VK_DOWN:  prlx->yMin += speed; prlx->yMax += speed; break;      //Move Background DOWN
            case VK_LEFT:  prlx->xMin -= speed; prlx->xMax -= speed; break;      //Move Background LEFT
            case VK_RIGHT: prlx->xMin += speed; prlx->xMax += speed; break;      //Move Background RIGHT
          //  myTime->startTime = clock();
        }
}
