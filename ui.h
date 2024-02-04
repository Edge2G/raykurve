#pragma once

#include <raylib.h>

#include <stdio.h>

#define WINDOW_TITLE "Raykurve"
#define SCREEN_WIDTH       900
#define SCREEN_HEIGHT      600
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

#include "player.h"

void drawPlayer(Player *player);
void drawShadow(Player *player);
void drawFrame(PlayArea *playArea);
void drawMoveArea(PlayArea *playArea);
void resetScreen (Player *player, PlayArea *playArea);
void initializePlayArea(PlayArea *playArea);