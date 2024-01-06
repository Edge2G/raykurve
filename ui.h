#pragma once

#include "main.h"

typedef struct PlayArea {
    Rectangle   frame;
    float       frameXend;
    float       frameYend;
    Color       frameColor;
    float       thickness;
} PlayArea;

void drawFrame(PlayArea playArea);
void resetScreen (Player *player, PlayArea playArea);