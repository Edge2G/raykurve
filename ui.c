#include "ui.h"

void initializeMainMenu(MainMenu *mainMenu)
{
    //mainMenu->options[1] = "Instructions";
    //mainMenu->options[2] = "Exit";
    //mainMenu->options[0] = "Play";

    mainMenu->currentOption = 0;
}

void drawMainMenu(MainMenu *mainMenu)
{
    ClearBackground(BLACK);
    DrawText("Raykurve", SCREEN_WIDTH/8, SCREEN_HEIGHT/8, 120, BLUE);
    DrawText("Play", SCREEN_WIDTH/8, SCREEN_HEIGHT/2, 40, WHITE);
    DrawText("How to play", SCREEN_WIDTH/8, SCREEN_HEIGHT/2 + 100, 40, WHITE);
    DrawText("Exit", SCREEN_WIDTH/8, SCREEN_HEIGHT/2 + 200, 40, WHITE);
}

void drawPlayer(Player *player)
{
    DrawCircle(player->head.posX, player->head.posY, player->head.radius, player->color);
}

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

    player->head.posX = GetRandomValue(playArea->innerFrame.x + 20, playArea->innerFrame.x + 80);
    player->head.posY = GetRandomValue(playArea->innerFrame.y + 20, playArea->innerFrame.y + 80);
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