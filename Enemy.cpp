#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    worldPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;

    width = texture.width / maxFrame;
    height = texture.height;
    speed = 3.5f;
};


void Enemy::tick(float deltaTime)
{
    //Get tp target
    Vector2 toTarget = Vector2Subtract(target->GetScreenPos(), screenPos);
    //Normalize toTarget
    toTarget = Vector2Normalize(toTarget);
    //Multiply toTarget by speed
    toTarget = Vector2Scale(toTarget, speed);
    //Move Enemy (set worldPos)
    worldPos = Vector2Add(worldPos, toTarget);
    screenPos = Vector2Subtract(worldPos, target->getWorldPos());
    BaseCharacter::tick(deltaTime);
};