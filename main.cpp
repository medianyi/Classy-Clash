#include "raylib.h"

int main()
{
    // array with window dimensions
    int windowDimension[2];
    windowDimension[0] = 384;
    windowDimension[1] = 384;

    // initialialize the window
    InitWindow(windowDimension[0], windowDimension[1], "Classy Clash");

    SetTargetFPS(60);

    Texture2D map = LoadTexture("./nature_tileset/OpenWorldMap24x24.png");
    float bgX{};

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        //draw background
        Vector2 bgPos{0.0, 0.0};
        DrawTextureEx(map, bgPos, 0.0, 4.0, WHITE);

        EndDrawing();
    }
    UnloadTexture(map);
}