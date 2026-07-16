#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <random>

// ============================================================================
// HEAVY DATA STRUCTURES
// These structures simulate realistic, bulky data fields for a complete game.
// ============================================================================
struct DriverInfo
{
    std::string firstName;
    std::string lastName;
    std::string nationalID;
    std::string homeAddress; // Long string allocation
};

struct TechnicalSpecs
{
    std::string chassisNumber;
    std::string engineNumber;
    float weightInKg;
    float fuelCapacity;
    int seatingCapacity;
    int manufactureYear;
};

// ============================================================================
// REPRESENTATION: Array of Structures (AoS) - Heavy Object Version
// Every Car object in memory now takes over 200 bytes of space.
// ============================================================================
class Car
{
public:
    Car(std::string carOwner, float startPosition, float carSpeed, 
        DriverInfo driver, TechnicalSpecs specs)
    {
        owner = carOwner;
        position = startPosition;
        speed = carSpeed;
        driverDetails = driver;
        technicalDetails = specs;
        
        // Secondary state values
        bodyColor = "Metallic Dark Graphite Gray";
        currentFuel = specs.fuelCapacity;
        engineTemp = 90.0f;
        bodyHealth = 100.0f;
    }

    // This system only uses position and speed, but the CPU is forced to
    // load all the other massive structs into the Cache Line anyway!
    void Move(float deltaTime)
    {
        position += speed * deltaTime;
    }

    // Active movement components
    float position;
    float speed;

    // Bulky/Static data members causing Cache Pollution during movement updates
    std::string owner;
    DriverInfo driverDetails;
    TechnicalSpecs technicalDetails;
    std::string bodyColor;
    float currentFuel;
    float engineTemp;
    float bodyHealth;
};

std::vector<Car> cars;

void SpawnRandomCars(int count)
{
    cars.reserve(count);

    std::random_device rd;                             
    std::mt19937 gen(rd());                            
    std::uniform_real_distribution<float> posDist(0.0f, 1000.0f);   
    std::uniform_real_distribution<float> speedDist(5.0f, 50.0f);   

    // Simulated bulky nested data
    DriverInfo dummyDriver = { "Alexander", "Gorgonzola-Smith", "9876543210-USA", "1234 Emerald Forest Boulevard, Suite 500, Sector 7" };
    TechnicalSpecs dummySpecs = { "CHAS-992831-XYZ-88", "ENG-88122-V8-TWIN", 1650.5f, 75.0f, 5, 2026 };

    for (int i = 0; i < count; ++i)
    {
        std::string name = "Car_" + std::to_string(i);
        cars.emplace_back(name, posDist(gen), speedDist(gen), dummyDriver, dummySpecs);
    }
}

int main()
{
    int carCount = 0;
    std::cout << "Enter the number of HEAVY cars to spawn: ";
    if (!(std::cin >> carCount) || carCount <= 0)
    {
        std::cout << "Invalid input. Defaulting to 10,000 cars.\n";
        carCount = 10000;
    }

    SpawnRandomCars(carCount);
    std::cout << "Spawned " << carCount << " heavy objects (AoS) successfully.\n\n";

    bool isRunning = true;
    int frameCount = 0;
    float fpsTimer = 0.0f;

    auto previousTime = std::chrono::high_resolution_clock::now();

    std::cout << "Starting OOP Heavy Object Performance Test...\n";

    while (isRunning)
    {
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsedTime = currentTime - previousTime;
        previousTime = currentTime;
        float deltaTime = elapsedTime.count();

        // --------------------------------------------------------------------
        // PERFORMANCE BOTTLENECK HERE:
        // Processing each car is slow because of continuous Cache Misses.
        // The CPU is mostly waiting for RAM to load the heavy 200+ byte objects.
        // --------------------------------------------------------------------
        for (auto& car : cars)
        {
            car.Move(deltaTime);
        }

        frameCount++;
        fpsTimer += deltaTime;
        if (fpsTimer >= 1.0f) 
        {
            std::cout << "[Heavy OOP] FPS: " << frameCount 
                      << " | Entities: " << carCount
                      << " | Frame Time: " << (deltaTime * 1000.0f) << "ms\n";
            frameCount = 0;
            fpsTimer = 0.0f;
        }
    }
    return 0;
}