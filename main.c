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

    while (!WindowShouldClose())
    {
        frameDelta = GetFrameTime();
        
        BeginDrawing();
            handleInput(&p1, &playArea);

            if (p1.shouldDraw)
            {
                drawPlayer(&p1);
                increaseTailSize(&p1);
                movePlayer(&p1, frameDelta, &playArea);
            }
            else
            {
                p1.shadowDelay += frameDelta;
                if (p1.shadowDelay >= 0.1)
                {
                    p1.prevHeadPos.x = p1.head.posX;
                    p1.prevHeadPos.y = p1.head.posY;
                    drawPlayer(&p1);
                    drawShadow(&p1);
                    movePlayer(&p1, frameDelta, &playArea);
                }
            }

            if (isColliding(&p1))
            {
                resetScreen(&p1, &playArea);
                resetPlayer(&p1);
                drawMoveArea(&playArea);
                changeSpawnPoint(&p1, 1, &playArea);
            }

        EndDrawing();
    }

    CloseWindow();

    printf("Raylib end...\n");
    return 0;
}