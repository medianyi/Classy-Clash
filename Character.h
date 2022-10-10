#ifndef CHARACTER
#define CHARACTER
#include "raylib.h"
#include "BaseCharacter.h" 

class Character : public BaseCharacter
{
public:
    Character(int winWidth, int winHeight);
    virtual void tick(float deltaTime) override;
    Vector2 GetScreenPos() { return screenPos; };
private:
 
};
#endif