#include "GLWizard.h"

GLWizard::GLWizard()
{
    //ctor
    vert[0].x = -0.5f; vert[0].y = -0.5f; vert[0].z = -1.0f;
    vert[1].x =  0.5f; vert[1].y = -0.5f; vert[1].z = -1.0f;
    vert[2].x =  0.5f; vert[2].y =  0.5f; vert[2].z = -1.0f;
    vert[3].x = -0.5f; vert[3].y =  0.5f; vert[3].z = -1.0f;

    firstTime = false;
}

GLWizard::~GLWizard()
{
    //dtor
}

void GLWizard::initWizard(int x, int y)
{

    inventoryOpened = false;
    inventory->initInventory(0);

    wizPosition.x = -1.0f;                 //Initialize player x pos
    wizPosition.y = -0.55f;                //Initialize player y pos
    wizPosition.z = -1.0f;                 //Initialize player z pos

    wizScale.x    =   0.45f;                 //Initialize player scale x
    wizScale.y    =   0.45f;                 //Initialize player scale y
    wizScale.z    =   1.0f;                 //Initialize player scale z

    faceRight = true;

    framesX = 8;                          //Record x frames
    framesY = 1;                          //Record y frames
    animFrame = 0;

    inventory->relics[inventory->clsUp]->lvl = 3;


    hb->createCircle(0.15f);
    hb->name = "wizard";

    actionTrigger[IDLE]         = true;   //Initialize action trigger to stand
    actionTrigger[WALKLEFT]     = false;
    actionTrigger[WALKRIGHT]    = false;
    actionTrigger[RUN]          = false;
    actionTrigger[JUMP]         = false;
    actionTrigger[ATTACK]       = false;
    actionTrigger[FALL]         = false;
    actionTrigger[SPECIAL]      = false;

    for (int i = 0; i < 6; i++) {
        texture[i] = new GLTexture;
    }

    texture[0]->loadTexture("images/Wizard/Idle.png");       //Load my texture
    texture[1]->loadTexture("images/Wizard/Run.png");        //Load my texture
    texture[2]->loadTexture("images/Wizard/Jump.png"); 		 //Load my texture
    texture[3]->loadTexture("images/Wizard/Fall.png");    	 //Load my texture
    texture[4]->loadTexture("images/Wizard/Attack1.png");
    texture[5]->loadTexture("images/Wizard/Death.png");
    texture[6]->loadTexture("images/Wizard/Attack2.png");

    maxHealth = 15.0;
    health = maxHealth;
    maxMana = 10.0;
    mana = maxMana;


    xMin = 0.0f;
    yMin = 0.0f;
    xMax = 1.0f / (float)framesX;
    yMax = 1.0f;

    initproj();
    myTime->startTime = clock();
    attackTiming = false;
}

void GLWizard::drawWiz(float time)
{
    glTranslatef(wizPosition.x, wizPosition.y, wizPosition.z);
    glScalef(wizScale.x, wizScale.y, wizScale.z);

    glColor3f(r, g, b);                        //White   Rectangle

    actions(time);

    maxHealth = 20.0 + inventory->relics[inventory->hpUp]->lvl * 5.0;
    maxMana = 10.0 + inventory->relics[inventory->clsUp]->lvl * 2.5;



    glBegin(GL_QUADS);
        glTexCoord2f(xMin, yMax); glVertex3f(vert[0].x,vert[0].y, vert[0].z);
        glTexCoord2f(xMax, yMax); glVertex3f(vert[1].x,vert[1].y, vert[1].z);
        glTexCoord2f(xMax, yMin); glVertex3f(vert[2].x,vert[2].y, vert[2].z);
        glTexCoord2f(xMin, yMin); glVertex3f(vert[3].x,vert[3].y, vert[3].z);
    glEnd();
}

void GLWizard::actions(float time)
{

    if (projAlive)
    {
        blastTex->bindTexture();
        if(faceRight) blast->blast(true,clock() - myTime->startTime);
        else blast->blast(false,clock() - myTime->startTime);
        if (!blast->isAlive) projAlive = false;
    }


    if (health <= 0.0) {
        if (inventory->relics[inventory->revive]->lvl > 0) {
            health = maxHealth * 0.5 * inventory->relics[inventory->revive]->lvl;
            inventory->relics[inventory->revive]->lvl = 0;
        }
        else {
        texture[5]->bindTexture();
		if (clock() - myTime->startTime >= 90) {
			switch (animFrame) {
			case 0:
			    wizVelocity.x = 0;
				framesX = 7;
				if (faceRight) {
					xMin = 0.0; xMax = 1.0 / (float)framesX;
				}
				else {
					xMax = 0.0; xMin = 1.0/(float)framesX;
				}
				animFrame += 1;
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				xMin += 1.0 / 7.0; xMax += 1.0 / 7.0;
				animFrame += 1;
				break;
			case 6:
				xMin += 1.0 / 7.0; xMax += 1.0 / 7.0;
                animFrame = -1;
                break;

		}
		 myTime->startTime = clock();
        }
        }
        return;
    }

        if (actionTrigger[WALKRIGHT] && !actionTrigger[ATTACK] && !actionTrigger[SPECIAL])
        {
            texture[1]->bindTexture();
                if (framesX != 8){
                    xMin = 0.0; xMax = 1.0/8.0;
                    framesX = 8;
                }
            if (!faceRight) {
                xMin = 0.0; xMax = 1.0/(float)framesX;
            }

            if (clock() - myTime->startTime >= 90) {
                xMin += 1.0f / (float)framesX; xMax += 1.0f / (float)framesX;
                myTime->startTime = clock();
                faceRight = true;
            }

            wizVelocity.x = 0.0055;
        }
        if (actionTrigger[WALKLEFT] && !actionTrigger[ATTACK] && !actionTrigger[SPECIAL])
        {
            texture[1]->bindTexture();
                if (framesX != 8){
                    xMax = 0.0; xMin = 1.0/8.0;
                    framesX = 8;
                }

            if (faceRight) {
                xMax = 0.0; xMin = 1.0/(float)framesX;
            }

            if (clock() - myTime->startTime >= 90) {
                xMin += 1.0f / (float)framesX; xMax += 1.0f / (float)framesX;
                myTime->startTime = clock();
                faceRight = false;
            }
            wizVelocity.x = -0.0055;
        }

        if (actionTrigger[IDLE] && !actionTrigger[ATTACK] && !actionTrigger[SPECIAL])
        {
                texture[0]->bindTexture();
                if (framesX != 6){
                    if (faceRight) {
                        xMin = 0.0; xMax = 1.0/6.0;
                    }
                    else {
                        xMax = 0.0; xMin = 1.0/6.0;
                    }
                    framesX = 6;
                }

            if(clock() - myTime->startTime > 90){

            xMin += 1.0 / (float)framesX;
            xMax += 1.0 / (float)framesX;
            yMin = 0;
            yMax = 1;

            myTime->startTime = clock();
            //cout << xMin << ", " << xMax << endl;
            //cout << yMin << ", " << yMax << endl << endl;
        }
        }
        if (actionTrigger[ATTACK]) {
            texture[4]->bindTexture();
            if (clock() - myTime->startTime >= 90) {
                //cout << animFrame << " chk 1\n";
                switch(animFrame) {
                    case 0:
                        //cout << "chk 2\n" << endl;
                        framesX = 8;
                        if (faceRight){
                            xMin = 0.0; xMax = 1.0 / (float)framesX;
                        }
                        else {
                            xMax = 0.0; xMin = 1.0 / (float)framesX;
                        }
                        animFrame += 1;
                        //cout << animFrame << "\n";
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                        xMin += 1.0 / (float)framesX; xMax += 1.0 / (float)framesX;
                        animFrame += 1;
                        //cout << animFrame << "\n";
                        attackTiming = true;
                        break;
                    case 8:
                        // += 1.0 / (float)framesX; xMax += 1.0 / (float)framesX;
                        if (faceRight) {
                            xMin = 0.0; xMax = 1.0 / 6.0;
                            texture[0]->bindTexture();
                        }
                        else {
                            xMax = 0.0; xMin = 1.0 / 6.0;
                        }
                        animFrame = 0;
                        actionTrigger[ATTACK] = false;
                        attackTiming = false;
                        //cout << "attack finished\n";
                        break;
                }
                myTime->startTime = clock();
            }
        }
        if (actionTrigger[SPECIAL]) {

            if (!projAlive)
            {
                if (faceRight)blast->spawn(wizPosition.x+1.25,wizPosition.y+0.45);
                else blast->spawn(wizPosition.x,wizPosition.y+0.55);
                //mana -=2.5;
            }

            texture[6]->bindTexture();

            if (clock() - myTime->startTime >= 90) {
                //cout << animFrame << " chk 1\n";
                switch(animFrame) {
                    case 0:
                        //cout << "chk 2\n" << endl;
                        framesX = 8;
                        if (faceRight){
                            xMin = 0.0; xMax = 1.0 / (float)framesX;
                        }
                        else {
                            xMax = 0.0; xMin = 1.0 / (float)framesX;
                        }
                        animFrame += 1;
                        //cout << animFrame << "\n";
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 6:
                    case 7:
                        xMin += 1.0 / (float)framesX; xMax += 1.0 / (float)framesX;
                        animFrame += 1;

                        //cout << animFrame << "\n";
                        break;
                    case 5:
                        projAlive = true;
                        animFrame+=1;
                        break;
                    case 8:
                        // += 1.0 / (float)framesX; xMax += 1.0 / (float)framesX;
                        if (faceRight) {
                            xMin = 0.0; xMax = 1.0 / 6.0;
                            texture[0]->bindTexture();
                        }
                        else {
                            xMax = 0.0; xMin = 1.0 / 6.0;
                        }
                        animFrame = 0;
                        actionTrigger[SPECIAL] = false;
                        //cout << "attack finished\n";
                        break;
                }
                myTime->startTime = clock();
            }
        }

    //cout << xMin << ", " << xMax << endl;
    oneSec +=time;
    if (oneSec >= 100)
    {
        movement();
    }
}

void GLWizard::movement()
{
    cout << wizPosition.x << endl;

    if (wizPosition.y > pos)
    {
        pos = wizPosition.y;
    }
    if (wizPosition.x <= -1.35f) {
        wizPosition.x = -1.35f;
    }
    if (wizPosition.x >= 1.35f) {
        wizPosition.x = 1.35f;
    }



    wizPosition.x += wizVelocity.x;
    wizPosition.y += wizVelocity.y;
    if (wizPosition.y > -0.25) wizVelocity.y -= 0.000009;
    else wizPosition.y = -0.25;

}


void GLWizard :: initproj()
{
    blastTex ->loadTexture("images/Wizard/eldritchblast.png");
    blast->speed = 0.01;
    blast->eScale.x = .3;
    blast->eScale.y = .3;
    blast->hb->radius = 0.15;
    blast->framesX = 3;
    projAlive = false;
}

