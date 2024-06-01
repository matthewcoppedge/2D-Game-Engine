#include "GLRogue.h"

GLRogue::GLRogue()
{
    //ctor
    vert[0].x = -0.5f; vert[0].y = -0.5f; vert[0].z = -1.0f;
    vert[1].x =  0.5f; vert[1].y = -0.5f; vert[1].z = -1.0f;
    vert[2].x =  0.5f; vert[2].y =  0.5f; vert[2].z = -1.0f;
    vert[3].x = -0.5f; vert[3].y =  0.5f; vert[3].z = -1.0f;

    plAccel.x = 0.0;
    plAccel.y = -1.0;

    plVelocity.x = 0.0;
    plVelocity.y = 0.0;

    oneSec = 0;

    for (int i = 0; i < 7; i++){
        texture[i] = new GLTexture;
    }
}

GLRogue::~GLRogue()
{
    //dtor
}

void GLRogue::initPlayer()
{
    plPosition.x =  -1.0f;                 //Initialize player x pos
    plPosition.y = -0.85f;                //Initialize player y pos
    plPosition.z = -1.0f;                 //Initialize player z pos


    plScale.x    =  0.25f;                 //Initialize player scale x
    plScale.y    =  0.25f;                 //Initialize player scale y
    plScale.z    =  1.0f;                 //Initialize player scale z

    actionTrigger[STAND]        = true;   //Initialize action trigger to stand
    actionTrigger[WALKLEFT]     = false;
    actionTrigger[WALKRIGHT]    = false;
    actionTrigger[RUN]          = false;
    actionTrigger[JUMP]         = false;
    actionTrigger[ATTACK]       = false;
    actionTrigger[SPECIAL]      = false;

    hb->createCircle(0.025f);
    hb->name = "rogue";

    maxHealth = 20.0;
    maxStam = 10.0;
    health = maxHealth;
    stamina = maxStam;

    inventory->initInventory(2);

    inventory->relics[inventory->hpUp]->lvl = 2;

    float xMin = 0.0;
    float xMax = 1.0 / 10.0;
    float yMin = 0.0;
    float yMax = 1.0;


    texture[0]->loadTexture("images/Rogue/Idle.png");
    texture[1]->loadTexture("images/Rogue/Run.png");
    texture[2]->loadTexture("images/Rogue/Dash.png");
    texture[4]->loadTexture("images/Rogue/Attack.png");
    texture[5]->loadTexture("images/Rogue/Death.png");


    faceRight = true;
    animFrame = 0;

    myTime->startTime = clock();
}

void GLRogue::drawPlayer(float time)
{
    glTranslatef(plPosition.x, plPosition.y, plPosition.z);
    glScalef(plScale.x, plScale.y, plScale.z);




    glColor4f(r, g, b, a);                           //White   Rectangle

    hb->updateCenter(plPosition.x, plPosition.y + 0.45f);

    actions(time);

    maxHealth = 15.0 + inventory->relics[inventory->hpUp]->lvl * 5.0;
    maxStam = 15.0 + inventory->relics[inventory->clsUp]->lvl * 7.5;

    if (stamina < maxStam) {
        stamina += 0.05 * (1.0 + (float)inventory->relics[inventory->clsUp]->lvl);
    }
    if (health < maxHealth) {
        health += 0.01 * (1.0 + (float)inventory->relics[inventory->hpUp]->lvl);
    }


    glBegin(GL_QUADS);
        glTexCoord2f(xMin, yMax); glVertex3f(vert[0].x,vert[0].y, vert[0].z);
        glTexCoord2f(xMax, yMax); glVertex3f(vert[1].x,vert[1].y, vert[1].z);
        glTexCoord2f(xMax, yMin); glVertex3f(vert[2].x,vert[2].y, vert[2].z);
        glTexCoord2f(xMin, yMin); glVertex3f(vert[3].x,vert[3].y, vert[3].z);
    glEnd();
}

void GLRogue::actions(float time)
{
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
				framesX = 5;
				if (faceRight) {
					xMin = 0.0; xMax = 1.0 / (float)framesX;
				}
				else {
					xMax = 0.0; xMin = 1.0/(float)framesX;
				}
				//r = 0.15; g = 0.15; b = 0.15;
				animFrame += 1;
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			    r = 0.15; g = 0.15; b = 0.15;
				xMin += 1.0 / framesX; xMax += 1.0 / framesX;
				animFrame += 1;
				break;
			case 6:
                //r = 0.15; g = 0.15; b = 0.15;
				//xMin += 1.0 / 5.0; xMax += 1.0 / 5.0;
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
                if (framesX != 6){
                    xMin = 0.0; xMax = 1.0/6.0;
                    framesX = 6;
                }

            if (!faceRight) {
                xMin = 0.0; xMax = 1.0/(float)framesX;
            }

            if (clock() - myTime->startTime >= 90) {
                xMin += 1.0f / (float)framesX; xMax += 1.0f / (float)framesX;
                myTime->startTime = clock();
                faceRight = true;
            }

            plVelocity.x = 0.0055;
        }
        if (actionTrigger[WALKLEFT] && !actionTrigger[ATTACK] && !actionTrigger[SPECIAL])
        {
                texture[1]->bindTexture();
                if (framesX != 6){
                    xMax = 0.0; xMin = 1.0/6.0;
                    framesX = 6;
                }

            if (faceRight) {
                xMax = 0.0; xMin = 1.0/(float)framesX;
            }

            if (clock() - myTime->startTime >= 90) {
                xMin += 1.0f / (float)framesX; xMax += 1.0f / (float)framesX;
                myTime->startTime = clock();
                faceRight = false;
            }
            plVelocity.x = -0.0055;
        }
        if (actionTrigger[STAND] && !actionTrigger[ATTACK] && !actionTrigger[SPECIAL])
        {
                texture[0]->bindTexture();
                if (framesX != 4){
                    if (faceRight) {
                        xMin = 0.0; xMax = 1.0/4.0;
                    }
                    else {
                        xMax = 0.0; xMin = 1.0/4.0;
                    }
                    framesX = 4;
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
                plVelocity.x = 0;
        }
        if (actionTrigger[ATTACK]) {
            texture[4]->bindTexture();

            if (clock() - myTime->startTime >= 90) {
                switch(animFrame) {
                    case 0:
                        if (faceRight){
                            framesX = 10;
                            xMin = 0.0; xMax = 1.0 / (float)framesX;
                        }
                        else {
                            framesX = 10;
                            xMax = 0.0; xMin = 1.0 / (float)framesX;
                        }
                        animFrame += 1;
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                        xMin += 1.0 / (float)framesX; xMax += 1.0 / (float)framesX;
                        animFrame += 1;
                        break;
                    case 7:
                        xMin += 1.0 / (float)framesX; xMax += 1.0 / (float)framesX;
                        animFrame = 0;
                        actionTrigger[ATTACK] = false;
                        break;
                }
                myTime->startTime = clock();
            }
        }
        if (actionTrigger[SPECIAL] && !actionTrigger[ATTACK]) {
            texture[2]->bindTexture();
            if (clock() - myTime->startTime >= 60) {
                switch(animFrame) {
                    case 0:
                        if (faceRight){
                            framesX = 5;
                            xMin = 0.0; xMax = 1.0 / (float)framesX;
                            plVelocity.x = 0.03;
                        }
                        else {
                            framesX = 5;
                            xMax = 0.0; xMin = 1.0 / (float)framesX;
                            plVelocity.x = -0.03;
                        }
                        animFrame += 1;
                        break;
                    case 1:
                    case 2:
                    case 3:
                        xMin += 1.0 / (float)framesX; xMax += 1.0 / (float)framesX;
                        animFrame += 1;
                        break;
                    case 4:
                        xMin += 1.0 / (float)framesX; xMax += 1.0 / (float)framesX;
                        animFrame = 0;
                        actionTrigger[SPECIAL] = false;
                        plVelocity.x = 0;
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

void GLRogue::movement()
{
    if (plPosition.y > pos)
    {
        pos = plPosition.y;
        //cout << pos << endl;
    }

    if (plPosition.x <= -1.35f) {
        plPosition.x = -1.35f;
    }
    if (plPosition.x >= 1.35f) {
        plPosition.x = 1.35f;
    }


    plPosition.x += plVelocity.x;
    plPosition.y += plVelocity.y;
    if (plPosition.y > -0.25) plVelocity.y -= 0.000009;
    else plPosition.y = -0.25;

}
