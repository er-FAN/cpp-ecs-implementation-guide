#include <string>
#include <unordered_map>
#include <iostream>

// ============================================================
// Entity ID
// ============================================================
// In ECS, an Entity does not represent an object.
//
// It does not contain:
// - Data
// - Behavior
// - Functions
//
// It is only an identifier that connects different Components.
//
// Example:
//
// Entity 0
//      |
//      +---- Owner Component
//      +---- Color Component
//      +---- Model Component
//      +---- Speed Component
//
// ============================================================

using Entity = unsigned int;


// ============================================================
// Component Data Storage
// ============================================================
// Components store only data.
//
// They do not know:
// - How they should change.
// - Who should use them.
// - What behavior they represent.
//
// Systems are responsible for processing this data.
// ============================================================


// ------------------------------------------------------------
// Owner Component
// ------------------------------------------------------------
// Stores the owner name.
//
// Example:
//
// Entity 0 -> "Erfan"
// Entity 1 -> "Ali"
//
// ------------------------------------------------------------

std::unordered_map<Entity, std::string> owners;


// ------------------------------------------------------------
// Color Component
// ------------------------------------------------------------
// Stores the color information.
//
// Example:
//
// Entity 0 -> "Red"
// Entity 1 -> "Blue"
//
// ------------------------------------------------------------

std::unordered_map<Entity, std::string> colors;


// ------------------------------------------------------------
// Model Component
// ------------------------------------------------------------
// Stores the car model year.
//
// Example:
//
// Entity 0 -> 2020
// Entity 1 -> 2022
//
// ------------------------------------------------------------

std::unordered_map<Entity, int> models;


// ------------------------------------------------------------
// Speed Component
// ------------------------------------------------------------
// Stores movement-related data.
//
// In the previous version, speed was only data.
//
// Now, a System can use this data to create behavior.
//
// Example:
//
// Entity 0 -> 50 km/h
// Entity 1 -> 80 km/h
//
// ------------------------------------------------------------

std::unordered_map<Entity, float> speeds;


// ------------------------------------------------------------
// Position Component
// ------------------------------------------------------------
// Stores the current position of each entity.
//
// This component only contains data.
//
// It does not know how to move.
//
// The Movement System will modify this data.
//
// Example:
//
// Entity 0 -> position 10
// Entity 1 -> position 25
//
// ------------------------------------------------------------

std::unordered_map<Entity, float> positions;


// ============================================================
// System
// ============================================================
// In ECS, behavior is separated from data.
//
// A System is responsible for processing Components.
//
// Example:
//
// Movement System:
//
// Input:
//      Speed Component
//      Position Component
//
// Process:
//      Update position based on speed
//
// Output:
//      Modified Position Component
//
// The Entity itself does not move.
// The System moves the data belonging to that Entity.
//
// ============================================================


void MovementSystem(float deltaTime)
{
    // ========================================================
    // Process all entities that have movement-related data.
    //
    // In this simple example, we manually check the Speed
    // component container.
    //
    // Later versions can introduce queries to find entities
    // that contain specific component combinations.
    // ========================================================

    for (auto& speed : speeds)
    {
        Entity entity = speed.first;


        // ====================================================
        // Check if this entity also has a Position Component.
        //
        // A Movement System needs both:
        //
        // Speed + Position
        //
        // Without position data, movement is impossible.
        // ====================================================

        if (positions.find(entity) != positions.end())
        {
            positions[entity] += speed.second * deltaTime;
        }
    }
}


// ============================================================
// Example Usage
// ============================================================
// This example demonstrates the ECS execution flow:
//
// 1. Create Entities.
// 2. Add Components.
// 3. Run Systems.
// 4. Systems modify Components.
//
// The Entity itself never performs an action.
// ============================================================


int main()
{
    // ========================================================
    // Create two entities.
    //
    // Entity creation is still manual.
    //
    // No Entity Manager exists yet.
    // ========================================================

    Entity erfanCar = 0;
    Entity aliCar = 1;


    // ========================================================
    // Assign components to the first entity.
    // ========================================================

    owners[erfanCar] = "Erfan";
    colors[erfanCar] = "Red";
    models[erfanCar] = 2020;

    speeds[erfanCar] = 50.0f;
    positions[erfanCar] = 0.0f;


    // ========================================================
    // Assign components to the second entity.
    // ========================================================

    owners[aliCar] = "Ali";
    colors[aliCar] = "Blue";
    models[aliCar] = 2022;

    speeds[aliCar] = 80.0f;
    positions[aliCar] = 0.0f;



    // ========================================================
    // Print the data before The Movement System run.
    // ========================================================

    std::cout << "Owner: " << owners[erfanCar] << '\n';
    std::cout << "Color: " << colors[erfanCar] << '\n';
    std::cout << "Model: " << models[erfanCar] << '\n';
    std::cout << "Speed: " << speeds[erfanCar] << "\n\n";

    std::cout << "Owner: " << owners[aliCar] << '\n';
    std::cout << "Color: " << colors[aliCar] << '\n';
    std::cout << "Model: " << models[aliCar] << '\n';
    std::cout << "Speed: " << speeds[aliCar] << '\n';



    // ========================================================
    // Run the Movement System.
    //
    // Imagine one second has passed.
    //
    // deltaTime = 1 second
    //
    // Entity 0:
    // position = 0 + 50 * 1
    //
    // Entity 1:
    // position = 0 + 80 * 1
    //
    // ========================================================

    MovementSystem(1.0f);
    std::cout << "Cars moved for one second" << '\n';


    // ========================================================
    // Print the updated data.
    //
    // Notice that the Entity did not move.
    //
    // The System changed the Position Component.
    // ========================================================


    std::cout << "Owner: " << owners[erfanCar] << '\n';
    std::cout << "Position: " << positions[erfanCar] << "\n\n";


    std::cout << "Owner: " << owners[aliCar] << '\n';
    std::cout << "Position: " << positions[aliCar] << '\n';


    return 0;
}