#include "main.h"

int main()
{
    SetTraceLogLevel(LOG_ERROR);
    SetRandomSeed(30000);

    Player p1;
    initializePlayer(&p1, 1);

    Rectangle areaFrame = {
        .height =       SCREEN_HEIGHT - (2*GAME_AREA_PADDING_Y),
        .width =        0.75 * SCREEN_WIDTH,
        .x =            0.25 * SCREEN_WIDTH - GAME_AREA_PADDING_X,
        .y =            GAME_AREA_PADDING_Y
    };

    PlayArea playArea = {
        .frame =        areaFrame,
        .frameColor =   GRAY,
        .thickness =    10,
    };
    playArea.frameXend = areaFrame.x + areaFrame.width - playArea.thickness;
    playArea.frameYend = areaFrame.y + areaFrame.height - playArea.thickness;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    double frameDelta;
    double currentFrame;
    double lastFrame = GetTime();
    char buf[30];
    SetTargetFPS(MAX_FPS);

    ClearBackground(BLACK);
    drawFrame(playArea);

    u32 frameCount = 0;
    u32 fps = GetFPS();

    while (!WindowShouldClose())
    {
        currentFrame = GetTime();
        frameDelta = 100 * (currentFrame - lastFrame);
        lastFrame = currentFrame;
        sprintf(buf, "%f", frameDelta);

        BeginDrawing();

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
                resetScreen(&p1, playArea);
            }

            if (isColliding(&p1))
            {
                resetScreen(&p1, playArea);
                memset(p1.tail, 0, sizeof(Vector2) * p1.tailSize);
                p1.tailSize = 0;
            }

            DrawCircle(p1.head.posX, p1.head.posY, p1.head.radius, p1.color);
            p1.tail[p1.tailSize].x = p1.head.posX;
            p1.tail[p1.tailSize].y = p1.head.posY;
            movePlayer(&p1, frameDelta);
            frameCount++;
            p1.tailSize++;

        EndDrawing();
    }

    CloseWindow();

    printf("Raylib end...\n");
    return 0;
}