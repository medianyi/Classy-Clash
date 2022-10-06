#include "raylib.h"
#include "raymath.h"

class Charcter 
{
    public:
     Vector2 getWorldPos() { return worldPos; }

    private:
        Texture2D texture;
        Texture2D idle;
        Texture2D run;
        Vector2 screenPos;
        Vector2 worldPos;
        // 1 : facing right, -1 : facing left
        float rightLeft{1.f};
        // animation variable
        float runningTime{};
        int frame{};
        const int maxFrame{6};
        const float updateTime{1.f/12.f};
};

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

    Texture2D knight_run = LoadTexture("./characters/knight_run_spritesheet.png");
    Texture2D knight_idle = LoadTexture("./characters/knight_idle_spritesheet.png");
    Texture2D knight = LoadTexture("./characters/knight_idle_spritesheet.png");
    Vector2 knightPos{
        windowDimension[0]/2.0f - 4.0f * (0.5f * (float)knight.width/6.0f),
        windowDimension[1]/2.0f - 4.0f * (0.5f * (float)knight.height)
    };
    

    // 1 : facing right, -1 : facing left
    float rightLeft{1.f};

    // animation variable
    float runningTime{};
    int frame{};
    const int maxFrame{6};
    const float updateTime{1.f/12.f};


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
            direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
            knight = knight_run;
        }
        else
        {
            knight = knight_idle;
        }
        
        // draw the map 
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        // update animation frame
        runningTime += GetFrameTime();
        if (runningTime >= updateTime)
        {
            frame++;
            runningTime = 0.f;
            if (frame > maxFrame)
            {
                frame = 0;
            }
            
        }
        

        // draw the character
        Rectangle source{frame * (float)knight.width/6.f, 0.f, rightLeft * (float)knight.width/6.f, (float)knight.height}; 
        Rectangle dest{knightPos.x, knightPos.y, 4.0f * (float)knight.width/6, 4.0f * (float)knight.height};
        DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);

        


        EndDrawing();
    }
    UnloadTexture(map);
}