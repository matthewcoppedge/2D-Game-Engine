#include "GLPlayer.h"

GLPlayer::GLPlayer()
{
    //ctor
    vert[0].x = -0.5f; vert[0].y = -0.5f; vert[0].z = -1.0f;
    vert[1].x =  0.5f; vert[1].y = -0.5f; vert[1].z = -1.0f;
    vert[2].x =  0.5f; vert[2].y =  0.5f; vert[2].z = -1.0f;
    vert[3].x = -0.5f; vert[3].y =  0.5f; vert[3].z = -1.0f;
}

GLPlayer::~GLPlayer()
{
    //dtor
}

void GLPlayer::initPlayer(int x, int y, char* fileName)
{
    plPosition.x =  0.0f;                 //Initialize player x pos
    plPosition.y = -0.25f;                //Initialize player y pos
    plPosition.z = -1.0f;                 //Initialize player z pos

    plScale.x    =  0.35f;                 //Initialize player scale x
    plScale.y    =  0.35f;                 //Initialize player scale y
    plScale.z    =  0.5f;                 //Initialize player scale z

    actionTrigger = 0;                    //Initialize action trigger to stand

    framesX = x;                          //Record x frames
    framesY = y;                          //Record y frames

    texture->loadTexture(fileName);       //Load my texture

    xMin = 0.0f;
    yMin = 1.0f - yMax - (1.0 / (float)framesY);
    xMax = 1.0f / (float)framesX;
    yMax = 1.0f;

    myTime->startTime = clock();
}

void GLPlayer::drawPlayer()
{
    glTranslatef(plPosition.x, plPosition.y, plPosition.z);
    glScalef(plScale.x, plScale.y, plScale.z);

    glColor3f(1.0f, 1.0f, 1.0f);                        //White   Rectangle
    texture->bindTexture();                             //Binding Player sprite sheet

    glBegin(GL_QUADS);
        glTexCoord2f(xMin, yMax); glVertex3f(vert[0].x,vert[0].y, vert[0].z);
        glTexCoord2f(xMax, yMax); glVertex3f(vert[1].x,vert[1].y, vert[1].z);
        glTexCoord2f(xMax, yMin); glVertex3f(vert[2].x,vert[2].y, vert[2].z);
        glTexCoord2f(xMin, yMin); glVertex3f(vert[3].x,vert[3].y, vert[3].z);
    glEnd();
}

void GLPlayer::actions()
{
    if (clock() - myTime->startTime > 100) {
        switch(actionTrigger)
        {
            case STAND:
                //yMax = 2.0 / (float)framesY;
                //yMin = 1.0f - yMax - (1.0 / (float)framesY);
                xMin = 0.0f; xMax = 1.0f / (float)framesX;
                break;
            case WALKLEFT:
                yMax = 2.0 / (float)framesY;
                yMin = 1.0f - yMax - (1.0 / (float)framesY);
                xMin += 1.0f / (float)framesX; xMax += 1.0f / (float)framesX;
                break;
            case WALKRIGHT:
                yMax = 4.0 / (float)framesY;
                yMin = yMax - (1.0 / (float)framesY);
                xMin += 1.0f / (float)framesX; xMax += 1.0f / (float)framesX;
                break;
            case RUN:
                xMin += xMax = 1.0f / (float)framesX; xMax += 1.0f / (float)framesX;
                break;
            case JUMP:
                xMin += xMax = 1.0f / (float)framesX; xMax += 1.0f / (float)framesX;
                break;
            case ATTACK:
                xMin += xMax = 1.0f / (float)framesX; xMax += 1.0f / (float)framesX;
                break;
            default:
                break;
        }
        myTime->startTime = clock();
    }
}
