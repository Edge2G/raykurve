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

    player->shadowDelay = 0.0;

    //player->tail = {{0}};
    //memset(player->tail, 0, sizeof(Vector2));
    //player->tail = malloc(sizeof(Vector2) * 10000);
    player->tailSize = 0;

    player->speed = 1;
    player->turnSpeed = 5;
    player->direction = GetRandomValue(0, 360);

    player->shouldDraw = true;

    player->timeTillErase = 3.0;
    player->eraseDuration = 1.0;
}

void increaseTailSize(Player *player)
{
    u32 i = player->tailSize;

    player->tail[i].x = player->head.posX;
    player->tail[i].y = player->head.posY;
    player->tailSize++;
}

/*void setBodyTimer(Player *player)
{
    if (player->shouldDraw)
    {
        player->shouldDraw = GetRandomValue(0, 1);
    }
    else
    {
        player->timeTillErase = GetRandomValue(2, 4);
    }
}

void updateBodyTimer(Player *player, double deltaTime)
{
    if (player->shouldDraw && player->timeTillErase > 0)
    {
        player->timeTillErase -= deltaTime;
    }

    if (!player->shouldDraw && player->eraseDuration > 0)
    {
        player->eraseDuration -= deltaTime;
    }
}

bool isEraseTimerDone(Player *player)
{
    if (player->eraseDuration <= 0)
    {
        return true;
    }

    return false;
}

void checkEraseTimers(Player *player)
{

}*/