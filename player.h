#pragma once

#include <raylib.h>
#include <raymath.h>

#include "shapes.h"

typedef __uint32_t u32;

typedef struct Player {
    Circle      head;
    Vector2     tail[10000];
    u32         tailSize;
    Color       color;
    float       speed;
    float       turnSpeed;
    double      direction;
    bool        createHole;
} Player;