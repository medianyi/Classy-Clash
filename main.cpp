#include "raylib.h"
#include "raymath.h"

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

    float speed{4.0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 direction{};
        if (IsKeyDown(KEY_A)) direction.x -= speed;
        if (IsKeyDown(KEY_D)) direction.x += speed;
        if (IsKeyDown(KEY_W)) direction.y -= speed;
        if (IsKeyDown(KEY_S)) direction.y += speed;
        if (Vector2Length(direction) != 0.0)
        {   
            // set mapPos = mapPos-direction
            
            mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
        }
        
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        EndDrawing();
    }
    UnloadTexture(map);
}