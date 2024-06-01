#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED


#include <windows.h>
#include <iostream>
#include <chrono>
#include <gl/gl.h>
#include <thread>
#include <GL/glut.h>
#include <SOIL.h>
#include <time.h>

#include<SNDS/irrKlang.h>

#define GRAVITY 9.81
#define PI 3.14159

using namespace irrklang;


using namespace std;

static float fade = 0.0f;
static float adj  = 0.0095f;

typedef struct {              //Shader Positioning in 3D
    float x, y, z, w;
} vec4;

typedef struct {              //Position in 3D Graphics
    float x, y, z;
} vec3;

typedef struct {              //Position in 2D Graphics
    float x, y;
} vec2;

typedef struct{                //used to hold hitbox edge placements
    vec2 v1;
    vec2 v2;
    vec2 v3;
    vec2 v4;
}box;

#endif // COMMON_H_INCLUDED
