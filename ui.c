#include "ui.h"

void drawFrame(PlayArea playArea)
{
    DrawRectangleLinesEx(playArea.frame, playArea.thickness, playArea.frameColor);
}

void resetScreen (Player *player, PlayArea playArea)
{
    ClearBackground(BLACK);
    drawFrame(playArea);

    player->head.posX = 40;
    player->head.posY = 40;
}