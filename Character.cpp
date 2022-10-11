#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight) : windowWidth(winWidth),
                                                    windowHeight(winHeight)
{
    width = texture.width / maxFrame;
    height = texture.height;

    screenPos = {
        static_cast<float>(winWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(winHeight) / 2.0f - scale * (0.5f * height)};
}

Vector2 Character::getScreenPos()
{
    return Vector2{
        tatic_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
        static_cast<float>(windowHeight) / 2.0f - scale *(0.5f * height)}
        };

void Character::tick(float deltaTime)
{
    if (IsKeyDown(KEY_A))
        velocity.x -= speed;
    if (IsKeyDown(KEY_D))
        velocity.x += speed;
    if (IsKeyDown(KEY_W))
        velocity.y -= speed;
    if (IsKeyDown(KEY_S))
        velocity.y += speed;
    BaseCharacter::tick(deltaTime);
}
