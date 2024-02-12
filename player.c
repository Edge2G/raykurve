#include "player.h"

void resetPlayer(Player *player)
{
    memset(player->tail, 0, sizeof(Vector2) * player->tailSize);
    player->tailSize = 0;
}

void initializePlayer(Player *player, u32 playerCount, PlayArea *playArea)
{
    player->color = GREEN;
    player->eraser = BLACK;

    player->head.posX = GetRandomValue(playArea->innerFrame.x + 20, playArea->innerFrame.x + 80);
    player->head.posY = GetRandomValue(playArea->innerFrame.y + 20, playArea->innerFrame.y + 80);
    player->head.radius = 3;

    //player->tail = {{0}};
    //memset(player->tail, 0, sizeof(Vector2));
    //player->tail = malloc(sizeof(Vector2) * 10000);
    player->tailSize = 0;

    player->speed = 1;
    player->turnSpeed = 5;
    player->direction = GetRandomValue(0, 360);

    player->shouldDraw = true;

    player->timeTillErase = GetRandomValue(200, 500)/100.0;
    player->eraseDuration = GetRandomValue(30, 100)/100.0;
}

void increaseTailSize(Player *player)
{
    u32 i = player->tailSize;

    player->tail[i].x = player->head.posX;
    player->tail[i].y = player->head.posY;
    player->tailSize++;
}

void setEraseTimers(Player *player)
{
    player->timeTillErase = GetRandomValue(200, 500)/100.0;
    player->eraseDuration = GetRandomValue(30, 100)/100.0; 
}

bool shouldErase(Player *player, double dt)
{
    if (player->dtCounter < player->timeTillErase)
    {
        player->dtCounter += dt;
        return false;  
    } 
    else
    {
        player->dtCounter = 0;
        return true;
    }
}