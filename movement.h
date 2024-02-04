#pragma once

#include <stdio.h>

#include "player.h"
#include "ui.h"

typedef __uint32_t u32;

void checkPlayerDirection (Player *player);
void moveWarp (Player *player, PlayArea *playArea);
void movePlayer (Player *player, double delta, PlayArea *playArea);
bool isColliding (Player *player);
void initializePlayer(Player *player, u32 playerCount, PlayArea *playArea);
void changeSpawnPoint(Player *player, u32 playerCount, PlayArea *playArea);