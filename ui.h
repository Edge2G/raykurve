#pragma once

#include <raylib.h>

#include "player.h"

#define WINDOW_TITLE "Raykurve"
#define SCREEN_WIDTH      1600
#define SCREEN_HEIGHT      900
#define MAX_FPS             60
#define N_PLAYERS            1
#define PIXEL_COUNT    SCREEN_WIDTH * SCREEN_HEIGHT

#define GAME_AREA_PADDING_X     10
#define GAME_AREA_PADDING_Y     10

typedef struct PlayArea {
    Rectangle   innerFrame;
    Color       innerColor;
    Rectangle   outerFrame;
    Color       outerColor;
    float       innerXend;
    float       innerYend;
} PlayArea;

void drawFrame(PlayArea *playArea);
void drawMoveArea(PlayArea *playArea);
void resetScreen (Player *player, PlayArea *playArea);
void initializePlayArea(PlayArea *playArea);