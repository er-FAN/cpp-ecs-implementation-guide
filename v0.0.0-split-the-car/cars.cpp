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
// In this example, we only focus on data representation.
// Behaviors are intentionally omitted.
// ============================================================

class Car
{

public:
    // ========================================================
    // Constructor
    // ========================================================
    // The constructor creates a car object and initializes
    // its internal data.
    // ========================================================

    Car(std::string carOwner, std::string carColor, int year)
    {
        owner = carOwner;
        color = carColor;
        modelYear = year;
        speed = 0;
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
    // }
    //
    // ========================================================

    std::string owner;

    std::string color;

    int modelYear;

    float speed;
};

// ============================================================
// Example Usage
// ============================================================
// This example creates two Car objects, initializes their data,
// and prints their contents.
// ============================================================

int main()
{
    // ========================================================
    // Create and initialize the first car object.
    // ========================================================

    Car erfanCar("Erfan", "Red", 2020);

    // ========================================================
    // Create and initialize the second car object.
    // ========================================================

    Car aliCar("Ali", "Blue", 2022);

    // ========================================================
    // Print the data of the first car.
    // ========================================================

    std::cout << "Owner: " << erfanCar.owner << '\n';
    std::cout << "Color: " << erfanCar.color << '\n';
    std::cout << "Model: " << erfanCar.modelYear << '\n';
    std::cout << "Speed: " << erfanCar.speed << "\n\n";

    // ========================================================
    // Print the data of the second car.
    // ========================================================

    std::cout << "Owner: " << aliCar.owner << '\n';
    std::cout << "Color: " << aliCar.color << '\n';
    std::cout << "Model: " << aliCar.modelYear << '\n';
    std::cout << "Speed: " << aliCar.speed << '\n';

    return 0;
}