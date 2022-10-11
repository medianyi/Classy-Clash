#ifndef CHARACTER
#define CHARACTER
#include "raylib.h"
#include "BaseCharacter.h" 

class Character : public BaseCharacter
{
public:
    Character(int winWidth, int winHeight);
    virtual void tick(float deltaTime) override;
    virtual Vector2 GetScreenPos() { return screenPos; };
private:
    int windowWidth{};
    int windowHeight{};
};
#endif