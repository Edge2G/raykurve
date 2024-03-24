#pragma once

#include <raylib.h>

#include <stdio.h>

#define WINDOW_TITLE "Raykurve"
#define SCREEN_WIDTH       1920
#define SCREEN_HEIGHT      1080
#define MAX_FPS             60
#define N_PLAYERS            1
#define PIXEL_COUNT    SCREEN_WIDTH * SCREEN_HEIGHT

#define GAME_AREA_PADDING_X     10
#define GAME_AREA_PADDING_Y     10

typedef struct MainMenu {
    char        *options[3];
    int         currentOption;
} MainMenu;


typedef struct PlayArea {
    Rectangle   innerFrame;
    Color       innerColor;
    Rectangle   outerFrame;
    Color       outerColor;
    float       innerXend;
    float       innerYend;
} PlayArea;

#include "player.h"

void initializeMainMenu(MainMenu *mainMenu);
void drawMainMenu(MainMenu *mainMenu);

void drawPlayer(Player *player);
void drawFrame(PlayArea *playArea);
void drawMoveArea(PlayArea *playArea);
void resetScreen (Player *player, PlayArea *playArea);
void initializePlayArea(PlayArea *playArea);