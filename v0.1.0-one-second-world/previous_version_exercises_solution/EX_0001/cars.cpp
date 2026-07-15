#include <string>
#include <iostream>

class Car
{
public:
    Car(std::string carOwner, std::string carColor, int year)
    {
        owner = carOwner;
        color = carColor;
        modelYear = year;
        speed = 0;
    }

    std::string owner;
    std::string color;
    int modelYear;
    float speed;
};

// ============================================================
// EX-0001: FlyingCar Derived Class
// ============================================================
// In OOP, to extend an object's attributes without modifying 
// the base class, we use Inheritance. 
// FlyingCar inherits all attributes of Car and adds flyingSpeed.
// ============================================================
class FlyingCar : public Car
{
public:
    FlyingCar(std::string carOwner, std::string carColor, int year, float initialFlyingSpeed)
        : Car(carOwner, carColor, year) // Initialize base Car attributes
    {
        flyingSpeed = initialFlyingSpeed;
    }

    // New unique attribute belonging ONLY to FlyingCar objects
    float flyingSpeed; 
};

int main()
{
    // ========================================================
    // EX-0001: Object Creation
    // erfanCar is instantiated as a FlyingCar to access flyingSpeed.
    // aliCar remains a standard base Car.
    // ========================================================
    FlyingCar erfanCar("Erfan", "Red", 2020, 150.0f);
    Car aliCar("Ali", "Blue", 2022);

    // Print Erfan's Flying Car Data
    std::cout << "Owner: " << erfanCar.owner << '\n';
    std::cout << "Color: " << erfanCar.color << '\n';
    std::cout << "Model: " << erfanCar.modelYear << '\n';
    std::cout << "Speed: " << erfanCar.speed << '\n';
    // EX-0001: Printing the newly added unique attribute
    std::cout << "Flying Speed: " << erfanCar.flyingSpeed << "\n\n";

    // Print Ali's Standard Car Data
    std::cout << "Owner: " << aliCar.owner << '\n';
    std::cout << "Color: " << aliCar.color << '\n';
    std::cout << "Model: " << aliCar.modelYear << '\n';
    std::cout << "Speed: " << aliCar.speed << '\n';
    // Note: Printing aliCar.flyingSpeed here would cause a compilation error 
    // because standard Car instances do not possess this attribute.

    return 0;
}