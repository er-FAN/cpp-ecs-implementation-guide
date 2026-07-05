#include "raylib.h" // Include the Raylib graphics library for window management and rendering
#include <vector>   // Include the standard vector container for contiguous memory allocation

// Define a type alias for the Entity.
// An Entity is now purely a unique numerical identifier counter.
using Entity = uint32_t;

// ============================================================================
// 1. COMPONENTS (Pure Data Layouts)
// ============================================================================

// The Position component represents the spatial location of an entity.
struct Position {
    float x; // Coordinate on the horizontal axis
    float y; // Coordinate on the vertical axis
};

// The RenderComponent represents the visual appearance of an entity.
struct RenderComponent {
    float radius; // The radius of the circle
    Color color;  // The RGBA color structure from Raylib
};

// ============================================================================
// 2. REGISTRY / DATA STORAGE (Dynamic Structure of Arrays)
// ============================================================================

class Registry {
private:
    Entity nextEntityId = 0; // A counter to guarantee a unique ID for every newly created entity

public:
    // Dynamic parallel vectors where components are allocated on-demand.
    std::vector<Position> positions;
    std::vector<RenderComponent> renders;

    // Component masks/flags to keep track of which entity owns what component.
    std::vector<bool> hasPosition;
    std::vector<bool> hasRender;

    // Creates a new entity by simply incrementing the ID counter.
    // This is a pure ECS approach: creating an entity does not allocate component memory upfront.
    Entity CreateEntity() {
        Entity id = nextEntityId; // Assign the current available ID to the new entity
        nextEntityId++;          // Increment the counter for the next entity request
        return id;               // Return the clean numerical identifier
    }

    // A helper function to let external systems know how many entities have been generated.
    Entity GetTotalEntities() const {
        return nextEntityId;
    }

    // Attaches a Position component to a specific entity.
    // It safely resizes the underlying vectors if the entity ID exceeds the current capacity.
    void AddPosition(Entity entity, float x, float y) {
        // Check if the vector is too small to hold this entity's index.
        if (entity >= positions.size()) {
            // Resize vectors to fit the entity ID (size must be ID + 1).
            positions.resize(entity + 1);
            // Resize the boolean flags vector and initialize new elements to false.
            hasPosition.resize(entity + 1, false);
        }
        
        positions[entity] = {x, y}; // Assign the spatial data to the correct slot
        hasPosition[entity] = true; // Set the flag to true to validate component ownership
    }

    // Attaches a RenderComponent to a specific entity.
    // It safely resizes the vectors on-demand just like the position function.
    void AddRender(Entity entity, float radius, Color color) {
        // Check if the vector capacity is smaller than the requested entity index.
        if (entity >= renders.size()) {
            // Expand the component array size to accommodate the entity ID.
            renders.resize(entity + 1);
            // Expand the boolean flag array and default new slots to false.
            hasRender.resize(entity + 1, false);
        }
        
        renders[entity] = {radius, color}; // Store the visual properties
        hasRender[entity] = true;          // Mark the flag as true
    }
};

// ============================================================================
// 3. SYSTEMS (Pure Logic and Behavior)
// ============================================================================

// The RenderSystem iterates over entities and draws them if they match the query requirements.
void RenderSystem(const Registry& registry) {
    // Loop through every single entity ID that has been created in the registry database.
    for (Entity i = 0; i < registry.GetTotalEntities(); ++i) {
        
        // Safe Boundary Check: Verify if the entity ID falls within the bounds of the flag vectors,
        // and then check if the entity actually possesses both the Position and Render components.
        bool positionValid = (i < registry.hasPosition.size()) && registry.hasPosition[i];
        bool renderValid   = (i < registry.hasRender.size())   && registry.hasRender[i];

        // Process query filter: If the entity satisfies both criteria, render it.
        if (positionValid && renderValid) {
            DrawCircle(
                static_cast<int>(registry.positions[i].x), 
                static_cast<int>(registry.positions[i].y), 
                registry.renders[i].radius,                
                registry.renders[i].color                 
            );
        }
    }
}

// ============================================================================
// 4. APPLICATION ENTRY POINT
// ============================================================================

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "ECS v0.0.0 - Static Circle");

    Registry registry;

    // Create an entity. It returns ID 0. No component memory is forced upon it yet.
    Entity staticCircle = registry.CreateEntity();

    // Dynamically allocate and assign components to Entity 0.
    registry.AddPosition(staticCircle, 400.0f, 300.0f);
    registry.AddRender(staticCircle, 50.0f, RED);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Run the render system to draw qualified entities
        RenderSystem(registry);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}