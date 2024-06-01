#include "GLInventory.h"


GLInventory::GLInventory()
{
    //ctor
    vert[0].x = -0.5f; vert[0].y = -0.5f; vert[0].z = -1.0f;
    vert[1].x =  0.5f; vert[1].y = -0.5f; vert[1].z = -1.0f;
    vert[2].x =  0.5f; vert[2].y =  0.5f; vert[2].z = -1.0f;
    vert[3].x = -0.5f; vert[3].y =  0.5f; vert[3].z = -1.0f;
}

GLInventory::~GLInventory()
{
    //dtor
}

void GLInventory::initInventory(int cls)
{
    for (int i = 0; i < 8; i++) {
        relics[i] = new invNode;
        relics[i]->pos.x = 0;
        relics[i]->pos.y = 0;
        switch (i) {
            case 0:
            case 1:
                relics[i]->maxLvl = 99;
                break;
            case revive:
                relics[i]->maxLvl = 2;
                break;
            default:
                relics[i]->maxLvl = 3;

        }
    }

    relics[0]->pos.x = -0.1825;
    relics[hpPot]->initNode("images/Relics/BW/Potions.png", 3, 4);
    if (cls == 0) {
        relics[clsPot]->initNode("images/Relics/BW/Potions.png", 3, 0);
        relics[dmgUp]->initNode("images/Relics/BW/Weapons.png", 9, 2);
        relics[clsUp]->initNode("images/Relics/BW/Clothing.png",2, 1);
        relics[dtUp]->initNode("images/Relics/BW/Clothing.png", 0, 7);
    }
    else if (cls == 1) {
        relics[clsPot]->initNode("images/Relics/BW/Potions.png", 1, 0);
        relics[dmgUp]->initNode("images/Relics/BW/Weapons.png", 4, 0);
        relics[clsUp]->initNode("images/Relics/BW/Clothing.png", 6, 0);
        relics[dtUp]->initNode("images/Relics/BW/Clothing.png", 1, 8);
    }
    else {
        relics[clsPot]->initNode("images/Relics/BW/Potions.png", 1, 0);
        relics[dmgUp]->initNode("images/Relics/BW/Weapons.png", 0, 1);
        relics[clsUp]->initNode("images/Relics/BW/Clothing.png", 0, 16);
        relics[dtUp]->initNode("images/Relics/BW/Clothing.png", 0, 10);
    }

    relics[hpUp]->initNode("images/Relics/BW/UI.png", 11, 9);
    relics[goldUp]->initNode("images/Relics/BW/Money.png", 3, 1);
    relics[revive]->initNode("images/Relics/BW/UI.png", 11, 7);

    tmr->startTime = clock();
}

void GLInventory::drawInventory(int cls)
{
    if (relics[hpPot]->lvl > 0) {
        relics[hpPot]->setNode("images/Relics/Color/Potions.png", 3, 4);
    }
    if (relics[hpUp]->lvl == 1) {
            relics[hpUp]->setNode("images/Relics/Color/UI.png", 11, 9);
    }
    else if (relics[hpUp]->lvl == 2) {
            relics[hpUp]->setNode("images/Relics/Color/UI.png", 10, 9);
    }
    else if (relics[hpUp]->lvl == 3) {
            relics[hpUp]->setNode("images/Relics/Color/UI.png", 9, 9);
    }
    if (relics[goldUp]->lvl == 1) {
            relics[goldUp]->setNode("images/Relics/Color/Money.png", 3, 1);
    }
    else if (relics[goldUp]->lvl == 2) {
            relics[goldUp]->setNode("images/Relics/Color/Money.png", 1, 1);
    }
    else if (relics[goldUp]->lvl == 3) {
            relics[goldUp]->setNode("images/Relics/Color/Money.png", 0, 1);
    }
    if (relics[revive]->lvl == 1) {
            relics[revive]->setNode("images/Relics/Color/UI.png", 11, 7);
    }
    else if (relics[revive]->lvl == 2) {
            relics[revive]->setNode("images/Relics/Color/UI.png", 9, 7);
    }
    if (cls == 0) {
        if (relics[clsPot]->lvl > 0) {
            relics[clsPot]->setNode("images/Relics/Color/Potions.png", 3, 0);
        }
        if (relics[dmgUp]->lvl == 1) {
            relics[dmgUp]->setNode("images/Relics/Color/Weapons.png", 9, 2);
        }
        else if (relics[dmgUp]->lvl == 2) {
            relics[dmgUp]->setNode("images/Relics/Color/Weapons.png", 7, 2);
        }
        else if (relics[dmgUp]->lvl == 3) {
            relics[dmgUp]->setNode("images/Relics/Color/Weapons.png", 1, 2);
        }
        if (relics[clsUp]->lvl == 1) {
            relics[clsUp]->setNode("images/Relics/Color/Clothing.png", 2, 1);
        }
        else if (relics[clsUp]->lvl == 2) {
            relics[clsUp]->setNode("images/Relics/Color/Clothing.png", 0, 2);
        }
        else if (relics[clsUp]->lvl == 3) {
            relics[clsUp]->setNode("images/Relics/Color/Clothing.png", 0, 1);
        }
        if (relics[dtUp]->lvl == 1) {
            relics[dtUp]->setNode("images/Relics/Color/Clothing.png", 0, 7);
        }
        else if (relics[dtUp]->lvl == 2) {
            relics[dtUp]->setNode("images/Relics/Color/Clothing.png", 4, 8);
        }
        else if (relics[dtUp]->lvl == 3) {
            relics[dtUp]->setNode("images/Relics/Color/Clothing.png", 3, 7);
        }
    }
    else if (cls == 1) {
        if (relics[clsPot]->lvl > 0) {
            relics[clsPot]->setNode("images/Relics/Color/Potions.png", 1, 0);
        }
        if (relics[dmgUp]->lvl == 1) {
            relics[dmgUp]->setNode("images/Relics/Color/Weapons.png", 4, 0);
        }
        else if (relics[dmgUp]->lvl == 2) {
            relics[dmgUp]->setNode("images/Relics/Color/Weapons.png", 0, 0);
        }
        else if (relics[dmgUp]->lvl == 3) {
            relics[dmgUp]->setNode("images/Relics/Color/Weapons.png", 12, 0);
        }
        if (relics[clsUp]->lvl == 1) {
            relics[clsUp]->setNode("images/Relics/Color/Clothing.png", 6, 0);
        }
        else if (relics[clsUp]->lvl == 2) {
            relics[clsUp]->setNode("images/Relics/Color/Clothing.png", 8, 0);
        }
        else if (relics[clsUp]->lvl == 3) {
            relics[clsUp]->setNode("images/Relics/Color/Clothing.png", 8, 1);
        }
        if (relics[dtUp]->lvl == 1) {
            relics[dtUp]->setNode("images/Relics/Color/Clothing.png", 1, 8);
        }
        else if (relics[dtUp]->lvl == 2) {
            relics[dtUp]->setNode("images/Relics/Color/Clothing.png", 2, 8);
        }
        else if (relics[dtUp]->lvl == 3) {
            relics[dtUp]->setNode("images/Relics/Color/Clothing.png", 3, 8);
        }
    }
    else if (cls == 2) {
        if (relics[clsPot]->lvl > 0) {
            relics[clsPot]->setNode("images/Relics/Color/Potions.png", 1, 0);
        }
        if (relics[dmgUp]->lvl == 1) {
            relics[dmgUp]->setNode("images/Relics/Color/Weapons.png", 0, 1);
        }
        else if (relics[dmgUp]->lvl == 2) {
            relics[dmgUp]->setNode("images/Relics/Color/Weapons.png", 4, 1);
        }
        else if (relics[dmgUp]->lvl == 3) {
            relics[dmgUp]->setNode("images/Relics/Color/Weapons.png", 12, 1);
        }
        if (relics[clsUp]->lvl == 1) {
            relics[clsUp]->setNode("images/Relics/Color/Clothing.png", 2, 1);
        }
        else if (relics[clsUp]->lvl == 2) {
            relics[clsUp]->setNode("images/Relics/Color/Clothing.png", 0, 2);
        }
        else if (relics[clsUp]->lvl == 3) {
            relics[clsUp]->setNode("images/Relics/Color/Clothing.png", 0, 1);
        }
        if (relics[dtUp]->lvl == 1) {
            relics[dtUp]->setNode("images/Relics/Color/Clothing.png", 0, 7);
        }
        else if (relics[dtUp]->lvl == 2) {
            relics[dtUp]->setNode("images/Relics/Color/Clothing.png", 4, 8);
        }
        else if (relics[dtUp]->lvl == 3) {
            relics[dtUp]->setNode("images/Relics/Color/Clothing.png", 3, 7);
        }
    }

    float x = -0.1825;
    float y = 0.0725;


    for (int i = 0; i < 8; i++) {
        switch (i) {
            case 1:
            case 5:
                x = -0.0605;
                break;
            case 2:
            case 6:
                x = 0.0605;
                break;
            case 3:
                x = 0.1825;
                break;
            case 0:
            case 4:
                x = -0.1825;
                break;
            case 7:
                x = 0.1895;
                break;
        }

        glPushMatrix();
        glTranslatef(x, y, -1.0);
        if (cls > 0) {
            glScalef(0.1, 0.1, 1.0);
        }
        else {
            glScalef(0.1, 0.1, 0.1);
        }

        glColor3f(1.0, 1.0, 1.0);
        relics[i]->tex->bindTexture();

        glBegin(GL_QUADS);
            glTexCoord2f(relics[i]->xMin, relics[i]->yMax); glVertex3f(vert[0].x,vert[0].y, vert[0].z);
            glTexCoord2f(relics[i]->xMax, relics[i]->yMax); glVertex3f(vert[1].x,vert[1].y, vert[1].z);
            glTexCoord2f(relics[i]->xMax, relics[i]->yMin); glVertex3f(vert[2].x,vert[2].y, vert[2].z);
            glTexCoord2f(relics[i]->xMin, relics[i]->yMin); glVertex3f(vert[3].x,vert[3].y, vert[3].z);
        glEnd();
        glPopMatrix();

        if (i == 3) {
            y *= -1.0;
        }
    }

/*
    if (clock() - tmr->startTime > 270){
        relics[0]->lvl = (relics[0]->lvl + level) % 2;
        relics[1]->lvl = (relics[1]->lvl + level) % 2;
        relics[2]->lvl = (relics[2]->lvl + level) % 4;
        relics[3]->lvl = (relics[3]->lvl + level) % 4;
        relics[4]->lvl = (relics[4]->lvl + level) % 4;
        relics[5]->lvl = (relics[5]->lvl + level) % 4;
        relics[6]->lvl = (relics[6]->lvl + level) % 4;
        relics[7]->lvl = (relics[0]->lvl + level) % 3;
        level += 1;
        tmr->startTime = clock();
    }
    */
}

void GLInventory::awardRelic()
{
    int randNum = rand() % 10;

    if (randNum <= 10 + relics[goldUp]->lvl * 2) {
        if (randNum <= 2) {
            relics[rand() % 2]->lvl += 1;
        }
        else {
            randNum = drops.at(rand() % drops.size());
            relics[randNum]->lvl += 1;
            if (relics[randNum]->lvl == relics[randNum]->maxLvl){
                removeRelic(randNum);
            }
        }
    }

}

void GLInventory::removeRelic(int relic)
{
    for (int i = 0; i < drops.size(); i++) {
        if (drops.at(i) == relic) drops.erase(drops.begin() + i);
    }
}


