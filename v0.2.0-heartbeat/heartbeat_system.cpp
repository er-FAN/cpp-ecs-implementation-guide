#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <random>

using Entity = unsigned int;

// ============================================================================
// HEAVY DATA STRUCTURES
// Identical bulky structures to keep the comparison perfectly fair.
// ============================================================================
struct DriverInfo
{
    std::string firstName;
    std::string lastName;
    std::string nationalID;
    std::string homeAddress;
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
// REPRESENTATION: Structure of Arrays (SoA)
// Component attributes are split into distinct flat, contiguous memory blocks.
// ============================================================================

// 1. Light and Compact Components (Used frequently together by the Movement System)
std::vector<float> positions;
std::vector<float> speeds;

// 2. Bulky and Static Components (Untouched during movement simulation)
std::vector<std::string> owners;
std::vector<DriverInfo> driverDetails;
std::vector<TechnicalSpecs> technicalDetails;
std::vector<std::string> bodyColors;
std::vector<float> currentFuels;
std::vector<float> engineTemps;
std::vector<float> bodyHealths;

std::vector<Entity> activeEntities;

void SpawnRandomEntities(int count)
{
    // Resize all arrays to ensure contiguous memory buffers for each component
    positions.resize(count);
    speeds.resize(count);
    owners.resize(count);
    driverDetails.resize(count);
    technicalDetails.resize(count);
    bodyColors.resize(count);
    currentFuels.resize(count);
    engineTemps.resize(count);
    bodyHealths.resize(count);
    
    activeEntities.reserve(count);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> posDist(0.0f, 1000.0f);
    std::uniform_real_distribution<float> speedDist(5.0f, 50.0f);

    DriverInfo dummyDriver = { "Alexander", "Gorgonzola-Smith", "9876543210-USA", "1234 Emerald Forest Boulevard, Suite 500, Sector 7" };
    TechnicalSpecs dummySpecs = { "CHAS-992831-XYZ-88", "ENG-88122-V8-TWIN", 1650.5f, 75.0f, 5, 2026 };

    for (int i = 0; i < count; ++i)
    {
        Entity entity = i; 
        activeEntities.push_back(entity);

        positions[entity] = posDist(gen);
        speeds[entity] = speedDist(gen);
        
        // Populate bulky data in parallel arrays
        owners[entity] = "Car_" + std::to_string(entity);
        driverDetails[entity] = dummyDriver;
        technicalDetails[entity] = dummySpecs;
        bodyColors[entity] = "Metallic Dark Graphite Gray";
        currentFuels[entity] = dummySpecs.fuelCapacity;
        engineTemps[entity] = 90.0f;
        bodyHealths[entity] = 100.0f;
    }
}

// ============================================================================
// SYSTEM: Parallel Array Movement Processor
// Extremely high speed. The CPU never touches the driverDetails, technicalDetails,
// or colors. Only positions and speeds are streamed into the CPU Cache.
// ============================================================================
void MovementSystem(float deltaTime)
{
    const size_t total = activeEntities.size();
    for (size_t i = 0; i < total; ++i)
    {
        positions[i] += speeds[i] * deltaTime;
    }
}

int main()
{
    int carCount = 0;
    std::cout << "Enter the number of HEAVY entities to spawn: ";
    if (!(std::cin >> carCount) || carCount <= 0)
    {
        std::cout << "Invalid input. Defaulting to 10,000 cars.\n";
        carCount = 10000;
    }

    SpawnRandomEntities(carCount);
    std::cout << "Spawned " << carCount << " heavy entities (SoA) successfully.\n\n";

    bool isRunning = true;
    int frameCount = 0;
    float fpsTimer = 0.0f;

    auto previousTime = std::chrono::high_resolution_clock::now();

    std::cout << "Starting ECS Parallel Array Performance Test...\n";

    while (isRunning)
    {
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsedTime = currentTime - previousTime;
        previousTime = currentTime;
        float deltaTime = elapsedTime.count();

        // Process movement
        MovementSystem(deltaTime);

        frameCount++;
        fpsTimer += deltaTime;
        if (fpsTimer >= 1.0f) 
        {
            std::cout << "[Heavy ECS] FPS: " << frameCount 
                      << " | Entities: " << carCount
                      << " | Frame Time: " << (deltaTime * 1000.0f) << "ms\n";
            frameCount = 0;
            fpsTimer = 0.0f;
        }
    }

    return 0;
}