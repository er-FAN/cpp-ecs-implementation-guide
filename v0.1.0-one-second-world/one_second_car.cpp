#include <string>
#include <iostream>

// ============================================================
// Car Class
// ============================================================
// In OOP, a class represents a real-world object.
//
// A class usually contains:
// 1. Data (attributes / properties)
// 2. Behaviors (methods)
//
// In this example, the Car object owns both:
// - Its own data.
// - Its own behavior.
//
// The object knows how to change itself.
//
// ============================================================

class Car
{

public:

    // ========================================================
    // Constructor
    // ========================================================
    // The constructor creates a car object and initializes
    // its internal data.
    //
    // Each Car object receives its own copy of the data.
    // ========================================================

    Car(std::string carOwner, std::string carColor, int year)
    {
        owner = carOwner;
        color = carColor;
        modelYear = year;
        speed = 0;
        position = 0;
    }


    // ========================================================
    // Move Behavior
    // ========================================================
    // In OOP, behavior usually belongs to the object itself.
    //
    // The Car object knows:
    // - Its current speed.
    // - Its current position.
    // - How to update itself.
    //
    // Example:
    //
    // erfanCar.Move(1 second)
    //
    // The object modifies its own internal data.
    //
    // ========================================================

    void Move(float deltaTime)
    {
        position += speed * deltaTime;
    }


    // ========================================================
    // Object Data
    // ========================================================
    // All data related to one car is stored together inside
    // the same object.
    //
    // Every Car object owns its own copy of these variables.
    //
    // Example:
    //
    // Car erfanCar
    // {
    //      owner = "Erfan"
    //      color = "Red"
    //      modelYear = 2020
    //      speed = 50
    //      position = 0
    // }
    //
    // ========================================================

    std::string owner;

    std::string color;

    int modelYear;

    float speed;

    float position;
};


// ============================================================
// Example Usage
// ============================================================
// This example creates two Car objects, initializes their data,
// executes their behaviors, and prints their contents.
//
// In OOP:
// Object -> Data + Behavior
//
// ============================================================

int main()
{

    // ========================================================
    // Create and initialize the first car object.
    // ========================================================

    Car erfanCar("Erfan", "Red", 2020);

    erfanCar.speed = 50;


    // ========================================================
    // Create and initialize the second car object.
    // ========================================================

    Car aliCar("Ali", "Blue", 2022);

    aliCar.speed = 80;



    // ========================================================
    // Print the updated data of the first car.
    // ========================================================

    std::cout << "Owner: " << erfanCar.owner << '\n';
    std::cout << "Color: " << erfanCar.color << '\n';
    std::cout << "Model: " << erfanCar.modelYear << '\n';
    std::cout << "Speed: " << erfanCar.speed << '\n';
    std::cout << "Position: " << erfanCar.position << "\n\n";



    // ========================================================
    // Print the updated data of the second car.
    // ========================================================

    std::cout << "Owner: " << aliCar.owner << '\n';
    std::cout << "Color: " << aliCar.color << '\n';
    std::cout << "Model: " << aliCar.modelYear << '\n';
    std::cout << "Speed: " << aliCar.speed << '\n';
    std::cout << "Position: " << aliCar.position << '\n';



    // ========================================================
    // Execute object behavior.
    //
    // Each object moves itself.
    //
    // The behavior is inside the Car class.
    //
    // ========================================================

    erfanCar.Move(1.0f);

    aliCar.Move(1.0f);

    std::cout << "Cars moved for one second" << '\n';


    // ========================================================
    // Print the updated data of the first car after move.
    // ========================================================

    std::cout << "Owner: " << erfanCar.owner << '\n';
    std::cout << "Position: " << erfanCar.position << "\n\n";



    // ========================================================
    // Print the updated data of the second car after move.
    // ========================================================

    std::cout << "Owner: " << aliCar.owner << '\n';
    std::cout << "Position: " << aliCar.position << '\n';


    return 0;
}