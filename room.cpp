#pragma once
#include <string>
#include <vector>
#include <memory>
#include "entity.h"
#include "enemy.h"
#include "item.h"

class Room {
    std::string name, description;
    std::vector<std::shared_ptr<Item>> items;
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<Room*> connections; // Can refine to map<string, Room*> for directions
public:
    Room(const std::string& n, const std::string& d): name(n), description(d) {}
    void addItem(std::shared_ptr<Item> item) { items.push_back(item); }
    void addEnemy(std::shared_ptr<Enemy> enemy) { enemies.push_back(enemy); }
    void connect(Room* room) { connections.push_back(room); }
    void describe() const;
};
