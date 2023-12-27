#include<stdio.h>
#include<string.h>
#include<raylib.h>
#include<raymath.h>

typedef __uint32_t u32;

#define SCREEN_WIDTH     900
#define SCREEN_HEIGHT    600
#define MAX_FPS           60
#define N_PLAYERS          2
#define WINDOW_TITLE "Raykurve"
#define PIXEL_COUNT    SCREEN_WIDTH * SCREEN_HEIGHT

static const double FRAMETIME = 1/MAX_FPS;

typedef struct Circle {
    float         posX;
    float         posY;
    u32         radius;
} Circle;

typedef struct Player {
    Circle      head;
    Vector2     tail[ (int)(PIXEL_COUNT / (2*N_PLAYERS)) ];
    u32         tailSize;
    Color       color;
    float       speed;
    float       turnSpeed;
    double      direction;
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

void movePlayer (Player *player, double delta)
{
    checkPlayerDirection(player);

    moveWarp(player);

    Vector2 movementVect = {
        .x = cos( DEG2RAD * player->direction ),
        .y = sin( DEG2RAD * player->direction )
    };

    Vector2 normalVector = Vector2Normalize(movementVect);
    printf("move vect x: %f\n", normalVector.y * delta * player->speed);
    printf("move vect y: %f\n", normalVector.x * delta * player->speed);
    
    player->head.posX += normalVector.y * delta * player->speed;
    player->head.posY += normalVector.x * delta * player->speed;
}

void resetScreen (Player *player)
{
    ClearBackground(RAYWHITE);

    player->head.posX = 40;
    player->head.posY = 40;
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
            /*if (player->head.posX == player->tail[i].posX &&
                player->head.posY == player->tail[i].posY)
            {
                printf("Collide!\n");
                return true;
            }*/

            Vector2 tail = {
                .x = player->tail[i].x,
                .y = player->tail[i].y
            };

            if (CheckCollisionCircles(head, player->head.radius, tail, player->head.radius))
            {
                printf("Collide!\n");
                return true;
            }
        }
    }

    return false;
}

int main()
{
    SetTraceLogLevel(LOG_ERROR);

    Player p1 = {
        .head =         {.posX = 40, .posY = 40, .radius = 3},
        .tail =         {0},
        .tailSize =     0,
        .color =        DARKBLUE,
        .speed =        1,
        .turnSpeed =    5,
        .direction =    /*GetRandomValue(0, 360)*/ 0,
    };

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    double frameDelta;
    double currentFrame;
    double lastFrame = GetTime();
    char buf[30];
    SetTargetFPS(MAX_FPS);
    //SetRandomSeed(30000);

    ClearBackground(RAYWHITE);

    u32 frameCount = 0;
    u32 fps = GetFPS();

    while (!WindowShouldClose())
    {
        currentFrame = GetTime();
        frameDelta = 100 * (currentFrame - lastFrame);
        lastFrame = currentFrame;
        sprintf(buf, "%f", frameDelta);
        //printf("%s\n", buf);
        printf("Direction: %f\n", p1.direction);

        BeginDrawing();

            DrawCircle(p1.head.posX, p1.head.posY, p1.head.radius, p1.color);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            DrawFPS(SCREEN_WIDTH/2, SCREEN_HEIGHT-20);

            if (IsKeyDown(KEY_LEFT))
            {
                p1.direction += p1.turnSpeed;
            }

            if (IsKeyDown(KEY_RIGHT))
            {
                p1.direction -= p1.turnSpeed;
            }

            if (IsKeyDown(KEY_UP))
            {
                resetScreen(&p1);
            }

            p1.tail[p1.tailSize].x = p1.head.posX;
            p1.tail[p1.tailSize].y = p1.head.posY;
            //printf("TAIL %d --- PosX: %d,   PosY: %d\n", p1.tailSize, p1.tail[p1.tailSize].posX, p1.tail[p1.tailSize].posY);
            movePlayer(&p1, frameDelta);
            frameCount++;
            p1.tailSize++;
            //ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    printf("Raylib end...\n");
    return 0;
}