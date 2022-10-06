#include "raylib.h"
#include "raymath.h"
#include "Character.h"
 
int main()
{
    // array with window dimensions
    int windowDimension[2];
    windowDimension[0] = 384;
    windowDimension[1] = 384;

    // initialialize the window
    InitWindow(windowDimension[0], windowDimension[1], "Classy Clash");

    Texture2D map = LoadTexture("./nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.0f};

    Character knihgt(windowDimension[0], windowDimension[1]);


    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knihgt.getWorldPos(), -1.f);
        
        // draw the map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);
        knihgt.tick(GetFrameTime());

        // check map bounds
        if (knihgt.getWorldPos().x < 0.f ||
            knihgt.getWorldPos().y < 0.f ||
            knihgt.getWorldPos().x + windowDimension[0] > map.width * mapScale ||
            knihgt.getWorldPos().y + windowDimension[1] > map.height * mapScale
        )
        {
            knihgt.undoMovement();
        }
        

        EndDrawing();
    }
    UnloadTexture(map);
}