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
    Vector2     prevHeadPos;
    float       shadowDelay;

    Color       color;
    Color       eraser;

    float       speed;
    float       turnSpeed;
    float       direction;

    bool        shouldDraw;
    float       timeTillErase;
    float       eraseDuration;
} Player;

#include "ui.h"

void resetPlayer(Player *player);
void initializePlayer(Player *player, u32 playerCount, PlayArea *playArea);
void increaseTailSize(Player *player);
void setBodyTimer(Player *player);
void updateBodyTimer(Player *player, double deltaTime);
bool isEraseTimerDone(Player *player);
void checkEraseTimers(Player *player);