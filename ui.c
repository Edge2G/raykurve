#include "ui.h"

void drawFrame(PlayArea *playArea)
{
    DrawRectangleRec(playArea->outerFrame, playArea->outerColor);
}

void drawMoveArea(PlayArea *playArea)
{
    DrawRectangleRec(playArea->innerFrame, playArea->innerColor);
}

void resetScreen (Player *player, PlayArea *playArea)
{
    ClearBackground(BLACK);
    drawFrame(playArea);

    player->head.posX = 40;
    player->head.posY = 40;
}

void initializePlayArea(PlayArea *playArea)
{
    playArea->outerColor = GRAY;
    playArea->outerFrame.x = 0.25 * SCREEN_WIDTH;
    playArea->outerFrame.y = 10;
    playArea->outerFrame.width = 0.75 * SCREEN_WIDTH - 10;
    playArea->outerFrame.height = SCREEN_HEIGHT - 20;

    playArea->innerColor = BLACK;
    playArea->innerFrame.x = playArea->outerFrame.x + 10;
    playArea->innerFrame.y = playArea->outerFrame.y + 10;
    playArea->innerFrame.width = playArea->outerFrame.width - 20;
    playArea->innerFrame.height = playArea->outerFrame.height - 20;

    playArea->innerXend = SCREEN_WIDTH - 20;
    playArea->innerYend = SCREEN_HEIGHT - 20;
}