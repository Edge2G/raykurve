#pragma once

#include <raylib.h>
#include <raymath.h>

#include <stdlib.h>
#include <string.h>

#include "shapes.h"

typedef __uint32_t u32;

typedef struct Player {
    Circle      head;
    Vector2     tail[10000];
    u32         tailSize;

    Color       color;
    Color       eraser;

    float       speed;
    float       turnSpeed;
    float       direction;

    bool        shouldDraw;
    double      timeTillErase;
    double      eraseDuration;
    double      dtCounter;
} Player;

#include "ui.h"

void resetPlayer(Player *player);
void initializePlayer(Player *player, u32 playerCount, PlayArea *playArea);
void increaseTailSize(Player *player);
void setEraseTimers(Player *player);
bool shouldErase(Player *player, double dt);