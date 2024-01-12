#include "movement.h"

void checkPlayerDirection (Player *player)
{
    if (player->direction >= 360)
    {
        player->direction = 0;
    }

    if (player->direction < 0)
    {
        player->direction = 360;
    }
}

void moveWarp (Player *player, PlayArea *playArea)
{
    if (player->head.posX > playArea->innerXend)
    {
        player->head.posX = playArea->innerFrame.x;
    }
    if (player->head.posX < playArea->innerFrame.x)
    {
        player->head.posX = playArea->innerXend;
    }

    if (player->head.posY > playArea->innerYend)
    {
        player->head.posY = playArea->innerFrame.y;
    }
    if (player->head.posY < playArea->innerFrame.y)
    {
        player->head.posY = playArea->innerYend;
    }
}

void movePlayer (Player *player, double delta, PlayArea *playArea)
{
    checkPlayerDirection(player);

    moveWarp(player, playArea);

    Vector2 movementVect = {
        .x = cos( DEG2RAD * player->direction ),
        .y = sin( DEG2RAD * player->direction )
    };

    Vector2 normalVector = Vector2Normalize(movementVect);

    player->head.posX += normalVector.y * delta * player->speed;
    player->head.posY += normalVector.x * delta * player->speed;
}

bool isColliding (Player *player)
{
    Vector2 head = {
        .x = player->head.posX,
        .y = player->head.posY
    };
    
    if (player->tailSize > 10)
    {
        for (u32 i = 0; i < player->tailSize-10; i++)
        {
            Vector2 tail = {
                .x = player->tail[i].x,
                .y = player->tail[i].y
            };

            if (CheckCollisionCircles(head, player->head.radius, tail, player->head.radius))
            {
                return true;
            }
        }
    }

    return false;
}

void initializePlayer(Player *player, u32 playerCount, PlayArea *playArea)
{
    player->color = GREEN;

    player->head.posX = GetRandomValue(playArea->innerFrame.x + 20, playArea->innerFrame.x + 80);
    player->head.posY = GetRandomValue(playArea->innerFrame.y + 20, playArea->innerFrame.y + 80);
    player->head.radius = 3;

    //player->tail = {{0}};
    player->tailSize = 0;

    player->speed = 1;
    player->turnSpeed = 5;
    player->direction = GetRandomValue(0, 360);
}

void changeSpawnPoint(Player *player, u32 playerCount, PlayArea *playArea)
{
    player->head.posX = GetRandomValue(playArea->innerFrame.x + 40, playArea->innerFrame.x + 120);
    player->head.posY = GetRandomValue(playArea->innerFrame.y + 40, playArea->innerFrame.y + 120);
}