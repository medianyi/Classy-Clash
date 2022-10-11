#ifndef CHARACTER
#define CHARACTER

#include "raylib.h"
#include "BaseCharacter.h" 

class Character : public BaseCharacter
{
public:
    Character(int winWidth, int winHeight);
    virtual void tick(float deltaTime) override;
    virtual Vector2 getScreenPos() override;
    Rectangle getWeaponCollisionRec() { return weaponCollisionRec;}
    float tgetHealth() const { return health; }
    void takeDamage(float damage);
private:
    int windowWidth{};
    int windowHeight{};
    Texture2D weapon {LoadTexture("./characters/weapon_sword.png")};
    Rectangle weaponCollisionRec{};
    float health{100.f};
};
#endif