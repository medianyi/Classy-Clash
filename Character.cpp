#include "Character.h"
#include "raymath.h"


Character::Character(int winWidth, int winHeight)
{
    width = texture.width/maxFrame;
    height = texture.height;
    screenPos = {
            static_cast<float>(winWidth) / 2.0f - scale * (0.5f * width ),
            static_cast<float>(winHeight) / 2.0f - scale * (0.5f * height)
     };
}


void Character::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;

    Vector2 direction{};
    if (IsKeyDown(KEY_A))
        direction.x -= speed;
    if (IsKeyDown(KEY_D))
        direction.x += speed;
    if (IsKeyDown(KEY_W))
        direction.y -= speed;
    if (IsKeyDown(KEY_S))
        direction.y += speed;
    if (Vector2Length(direction) != 0.0)
    {
        // set worldPos = worldPos + direction
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
        texture = run;
    }
    else
    {
        texture = idle;
    }
    // update animation frame
    runningTime += deltaTime;
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
    Rectangle source{frame * width, 0.f, rightLeft * width, height};
    Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}


