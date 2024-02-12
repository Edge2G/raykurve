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
                if (p1.dtCounter >= p1.timeTillErase)
                {
                    p1.shouldDraw = false;
                    p1.dtCounter = 0;
                    setEraseTimers(&p1);
                }

                drawPlayer(&p1);
                increaseTailSize(&p1);
                movePlayer(&p1, frameDelta, &playArea);
                p1.dtCounter += frameDelta;
            }            
            if (!p1.shouldDraw)
            {
                if (p1.dtCounter >= p1.eraseDuration)
                {
                    p1.shouldDraw = true;
                    p1.dtCounter = 0;
                }
                
                drawMoveArea(&playArea);
                for (u32 i = 0; i < p1.tailSize; i++)
                {
                    DrawCircle(p1.tail[i].x, p1.tail[i].y, p1.head.radius, p1.color);
                }
                drawPlayer(&p1);
                movePlayer(&p1, frameDelta, &playArea);
                p1.dtCounter += frameDelta;
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