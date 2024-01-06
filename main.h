#pragma once

#include <stdio.h>
#include <string.h>

#include <raylib.h>
#include <raymath.h>

#define WINDOW_TITLE "Raykurve"
#define SCREEN_WIDTH       900
#define SCREEN_HEIGHT      600
#define MAX_FPS             60
#define N_PLAYERS            1
#define PIXEL_COUNT    SCREEN_WIDTH * SCREEN_HEIGHT

#define GAME_AREA_PADDING_X     10
#define GAME_AREA_PADDING_Y     10

typedef __uint32_t u32;

static const double FRAMETIME = 1/MAX_FPS;

#include "shapes.h"
#include "player.h"
#include "ui.h"