#include "input.h"

void handleInput(Player *player, PlayArea *playArea)
{
    if (IsKeyDown(KEY_LEFT))
    {
        player->direction -= player->turnSpeed;
    }

    if (IsKeyDown(KEY_RIGHT))
    {
        player->direction += player->turnSpeed;
    }

    if (IsKeyPressed(KEY_UP))
    {
        if (player->shouldDraw) player->shouldDraw = false;
        else player->shouldDraw = true;
    }
}