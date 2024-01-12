#include "main.h"

int main()
{
    SetTraceLogLevel(LOG_ERROR);
    SetRandomSeed((unsigned)time(NULL));

    PlayArea playArea;
    initializePlayArea(&playArea);

    Player p1;
    initializePlayer(&p1, 1, &playArea);

    //SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(MAX_FPS);

    double frameDelta;
    double actionTime;

    ClearBackground(BLACK);
    drawFrame(&playArea);
    drawMoveArea(&playArea);

    u32 frameCount = 0;
    u32 fps = GetFPS();

    while (!WindowShouldClose())
    {
        frameDelta = 100 * GetFrameTime();
        actionTime = GetTime();

        BeginDrawing();
            handleInput(&p1, &playArea);

            if (isColliding(&p1))
            {
                resetScreen(&p1, &playArea);
                memset(p1.tail, 0, sizeof(Vector2) * p1.tailSize);
                p1.tailSize = 0;
                drawMoveArea(&playArea);
                changeSpawnPoint(&p1, 1, &playArea);
            }

            DrawCircle(p1.head.posX, p1.head.posY, p1.head.radius, p1.color);
            p1.tail[p1.tailSize].x = p1.head.posX;
            p1.tail[p1.tailSize].y = p1.head.posY;
            movePlayer(&p1, frameDelta, &playArea);
            frameCount++;
            p1.tailSize++;

        EndDrawing();
    }

    CloseWindow();

    printf("Raylib end...\n");
    return 0;
}