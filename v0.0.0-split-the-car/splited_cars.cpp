#include <string>
#include <unordered_map>
#include <iostream>

// ============================================================
// Entity ID
// ============================================================
// In Data-Oriented Design, an object is represented by an ID.
//
// The Entity does not contain data.
// It only identifies a group of related data.
//
// Example:
//
// Entity 0
//      |
//      +---- Owner Component
//      +---- Color Component
//      +---- Model Component
//
// ============================================================

using Entity = unsigned int;

// ============================================================
// Component Data Storage
// ============================================================
// Instead of storing all data together inside one object,
// we separate data into independent components.
//
// Each component stores one specific type of information.
//
// The Entity ID connects these separate pieces of data.
// ============================================================

// ------------------------------------------------------------
// Owner Component
// ------------------------------------------------------------
// Stores the owner name of each entity.
//
// Example:
//
// Entity 0 -> "Erfan"
// Entity 1 -> "Ali"
//
// The key is the Entity ID.
// The value is the component data.
// ------------------------------------------------------------

std::unordered_map<Entity, std::string> owners;

// ------------------------------------------------------------
// Color Component
// ------------------------------------------------------------
// Stores the color information of each entity.
//
// Example:
//
// Entity 0 -> "Red"
// Entity 1 -> "Blue"
//
// Each entity that has a Color Component will have an entry
// inside this container.
// ------------------------------------------------------------

std::unordered_map<Entity, std::string> colors;

// ------------------------------------------------------------
// Model Component
// ------------------------------------------------------------
// Stores the model year of each entity.
//
// Example:
//
// Entity 0 -> 2020
// Entity 1 -> 2022
//
// The Entity ID tells us which car owns this model value.
// ------------------------------------------------------------

std::unordered_map<Entity, int> models;

// ------------------------------------------------------------
// Speed Component
// ------------------------------------------------------------
// Stores the speed data of each entity.
//
// Example:
//
// Entity 0 -> 120
// Entity 1 -> 80
//
// In this stage, Speed is only a data value.
// We are not implementing any behavior related to it.
// ------------------------------------------------------------

std::unordered_map<Entity, float> speeds;

// ============================================================
// Example Usage
// ============================================================
// This example creates two entities, assigns components to
// them, and prints the stored data.
// ============================================================

int main()
{
    // ========================================================
    // Create two entities.
    // ========================================================

    Entity erfanCar = 0;
    Entity aliCar = 1;

    // ========================================================
    // Assign components to the first entity.
    // ========================================================

    owners[erfanCar] = "Erfan";
    colors[erfanCar] = "Red";
    models[erfanCar] = 2020;
    speeds[erfanCar] = 0.0f;

    // ========================================================
    // Assign components to the second entity.
    // ========================================================

    owners[aliCar] = "Ali";
    colors[aliCar] = "Blue";
    models[aliCar] = 2022;
    speeds[aliCar] = 0.0f;

    // ========================================================
    // Print the data of the first entity.
    // ========================================================

    std::cout << "Owner: " << owners[erfanCar] << '\n';
    std::cout << "Color: " << colors[erfanCar] << '\n';
    std::cout << "Model: " << models[erfanCar] << '\n';
    std::cout << "Speed: " << speeds[erfanCar] << "\n\n";

    // ========================================================
    // Print the data of the second entity.
    // ========================================================

    std::cout << "Owner: " << owners[aliCar] << '\n';
    std::cout << "Color: " << colors[aliCar] << '\n';
    std::cout << "Model: " << models[aliCar] << '\n';
    std::cout << "Speed: " << speeds[aliCar] << '\n';

    return 0;
}