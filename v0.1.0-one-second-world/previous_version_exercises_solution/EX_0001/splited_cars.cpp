#include <string>
#include <unordered_map>
#include <iostream>

using Entity = unsigned int;

// Global Component Storages
std::unordered_map<Entity, std::string> owners;
std::unordered_map<Entity, std::string> colors;
std::unordered_map<Entity, int> models;
std::unordered_map<Entity, float> speeds;

// ============================================================
// EX-0001: New Flying Speed Component
// ============================================================
// In DOD/ECS, we do not use inheritance or alter existing types.
// We simply introduce a brand new isolated component array.
// Entities that can fly will have an entry here. Others won't.
// ============================================================
std::unordered_map<Entity, float> flyingSpeeds;

int main()
{
    Entity erfanCar = 0;
    Entity aliCar = 1;

    // Assign standard components to Erfan
    owners[erfanCar] = "Erfan";
    colors[erfanCar] = "Red";
    models[erfanCar] = 2020;
    speeds[erfanCar] = 0.0f;
    // EX-0001: Dynamically attaching the Flying Component to Erfan's entity
    flyingSpeeds[erfanCar] = 150.0f; 

    // Assign standard components to Ali (Ali does not get a flyingSpeeds entry)
    owners[aliCar] = "Ali";
    colors[aliCar] = "Blue";
    models[aliCar] = 2022;
    speeds[aliCar] = 0.0f;

    // ========================================================
    // Print Data Helper Lambda
    // Dynamically checks if an entity possesses a Flying Component
    // before attempting to print it.
    // ========================================================
    auto printEntityInfo = [](Entity entity) {
        std::cout << "Owner: " << owners[entity] << '\n';
        std::cout << "Color: " << colors[entity] << '\n';
        std::cout << "Model: " << models[entity] << '\n';
        std::cout << "Speed: " << speeds[entity] << '\n';
        
        // EX-0001: Safe component look-up at runtime
        if (flyingSpeeds.find(entity) != flyingSpeeds.end()) {
            std::cout << "Flying Speed: " << flyingSpeeds[entity] << '\n';
        } else {
            std::cout << "Flying Speed: N/A (This car cannot fly)\n";
        }
        std::cout << '\n';
    };

    // Print both entities
    printEntityInfo(erfanCar);
    printEntityInfo(aliCar);

    return 0;
}