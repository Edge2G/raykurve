#include "main.h"
#include "player.h"

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

void moveWarp (Player *player)
{
    if (player->head.posX > SCREEN_WIDTH)
    {
        player->head.posX = 0;
    }
    if (player->head.posX < 0)
    {
        player->head.posX = SCREEN_WIDTH;
    }

    if (player->head.posY > SCREEN_HEIGHT)
    {
        player->head.posY = 0;
    }
    if (player->head.posY < 0)
    {
        player->head.posY = SCREEN_HEIGHT;
    }
}

void movePlayer (Player *player, double delta)
{
    checkPlayerDirection(player);

    moveWarp(player);

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

void initializePlayer(Player *player, u32 playerCount)
{
    player->color = GREEN;

    player->head.posX = GetRandomValue(20,80);
    player->head.posY = GetRandomValue(20,80);
    player->head.radius = 3;

    //player->tail = {{0}};
    player->tailSize = 0;

    player->speed = 1;
    player->turnSpeed = 5;
    player->direction = GetRandomValue(0, 360);
}