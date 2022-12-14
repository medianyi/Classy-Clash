#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"
#include "BaseCharacter.h"
#include <string>

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

    Prop props[2]{
        Prop{Vector2{600.f, 300.f}, LoadTexture("./nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("./nature_tileset/Log.png")}};

    Enemy goblin{
        Vector2{500.f, 300.f},
        LoadTexture("./characters/goblin_idle_spritesheet.png"),
        LoadTexture("./characters/goblin_run_spritesheet.png")};

    Enemy slime{
        Vector2{500.f, 700.f},
        LoadTexture("./characters/slime_idle_spritesheet.png"),
        LoadTexture("./characters/slime_run_spritesheet.png")};

    Enemy *enemies[]{
        &goblin,
        &slime};
    for (auto enemy : enemies)
    {
        enemy->setTaret(&knihgt);
    }

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knihgt.getWorldPos(), -1.f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

        // draw the props
        for (auto prop : props)
        {
            prop.Render(knihgt.getWorldPos());
        }

        knihgt.tick(GetFrameTime());
        // check map bounds
        if (knihgt.getWorldPos().x < 0.f ||
            knihgt.getWorldPos().y < 0.f ||
            knihgt.getWorldPos().x + windowDimension[0] > map.width * mapScale ||
            knihgt.getWorldPos().y + windowDimension[1] > map.height * mapScale)
        {
            knihgt.undoMovement();
        }

        for (auto prop : props)
        {
            if (CheckCollisionRecs(prop.getCollisionRec(knihgt.getWorldPos()), knihgt.getCollisionRec()))
            {
                knihgt.undoMovement();
            }
        }

        if (!knihgt.getAlive()) // Character is not live
        {
            DrawText("Game Over!", 55.f, 45.f, 40, RED);
            EndDrawing();
            continue;
        }
        else // Character is alive
        {
            std::string knihgtsHealth = "Health: ";
            knihgtsHealth.append(std::to_string(knihgt.getHealth()), 0, 5);
            DrawText(knihgtsHealth.c_str(), 55.f, 45.f, 40, RED);
        }

        for (auto enemy : enemies)
        {
            enemy->tick(GetFrameTime());
        }

        for (auto enemy : enemies)
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                if (CheckCollisionRecs(enemy->getCollisionRec(), knihgt.getWeaponCollisionRec()))
                {

                    enemy->setAlive(false);
                }
            }
        }

        EndDrawing();
    }
    UnloadTexture(map);
}