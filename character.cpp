#pragma once
#include "entity.h"
#include <iostream>

class Character : public Entity {
protected:
    int health;
    int maxHealth;
    int attackPower;
    bool isAlive;
public:
    Character(const std::string& n, const std::string& d, int hp, int atk)
        : Entity(n, d), health(hp), maxHealth(hp), attackPower(atk), isAlive(true) {}
    virtual ~Character() {}
    int getHealth() const { return health; }
    bool alive() const { return isAlive; }
    void takeDamage(int dmg) {
        health -= dmg;
        if (health <= 0) { health = 0; isAlive = false; }
        std::cout << name << " takes " << dmg << " damage! (" << health << "/" << maxHealth << ")\n";
    }
    void heal(int amt) {
        health += amt;
        if (health > maxHealth) health = maxHealth;
        std::cout << name << " heals " << amt << " HP! (" << health << "/" << maxHealth << ")\n";
    }
    virtual void attack(Character& target) = 0;
};
