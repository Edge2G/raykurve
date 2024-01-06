#pragma once

#include <raylib.h>
#include <raymath.h>

typedef struct Player {
    Circle      head;
    Vector2     tail[10000];
    u32         tailSize;
    Color       color;
    float       speed;
    float       turnSpeed;
    double      direction;
} Player;

void checkPlayerDirection (Player *player);
void moveWarp (Player *player);
void movePlayer (Player *player, double delta);
bool isColliding (Player *player);
void initializePlayer(Player *player, u32 playerCount);