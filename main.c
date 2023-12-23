#include<stdio.h>
#include<raylib.h>
#include<raymath.h>

typedef __uint8_t u32;

#define SCREEN_WIDTH     900
#define SCREEN_HEIGHT    600
#define MAX_FPS           60
#define WINDOW_TITLE "Raykurve"

typedef struct Circle {
    int         posX;
    int         posY;
    u32         radius;
} Circle;

typedef struct Player {
    Circle      head;
    Circle*     tail;
    Color       color;
    u32         speed;
    u32         turnSpeed;
    int         direction;
} Player;

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

void movePlayer (Player *player)
{
    checkPlayerDirection(player);

    moveWarp(player);

    Vector2 movementVect = {
        .x = cos( DEG2RAD * player->direction ),
        .y = sin( DEG2RAD * player->direction )
    };

    Vector2 normalVector = Vector2Normalize(movementVect);
    
    player->head.posX += normalVector.x * player->speed;
    player->head.posY += normalVector.y * player->speed;
}

int main()
{
    SetTraceLogLevel(LOG_ERROR);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(MAX_FPS);
    SetRandomSeed(30000);

    Player p1 = {
        .head =         {.posX = 40, .posY = 40, .radius = 10},
        .tail =         NULL,
        .color =        DARKBLUE,
        .speed =        3,
        .turnSpeed =    4,
        .direction =    /*GetRandomValue(0, 360)*/ 0,
    };

    ClearBackground(RAYWHITE);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            DrawCircle(p1.head.posX, p1.head.posY, p1.head.radius, p1.color);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

            if (IsKeyDown(KEY_LEFT))
            {
                p1.direction -= 4;
            }

            if (IsKeyDown(KEY_RIGHT))
            {
                p1.direction += 4;
            }

            movePlayer(&p1);

        EndDrawing();
    }

    CloseWindow();

    printf("Raylib end...\n");
    return 0;
}