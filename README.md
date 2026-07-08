Persian Version: For the Persian documentation, please refer to [README.fa.md](README.fa.md).

<div dir="ltr">

## Conceptual Prerequisites

To better understand the ECS architecture, it is recommended to become familiar with the following fundamental concepts before starting the implementation:

* Object-Oriented Programming (OOP)
* Data-Oriented Design (DOD)
* Memory management concepts, data structures, and data access patterns in C++

Understanding these concepts will make it easier to understand why each part of ECS exists and how it differs from traditional architectures.

---

## When is ECS used?

ECS is commonly used when an application needs to manage a large number of similar entities and efficient data processing becomes important.

Some common use cases of ECS include:

* Game engines and gameplay systems
* Computer simulations
* Applications with a large number of active objects or entities
* Systems that require fast and optimized data processing

For example, in a game there may be thousands of entities active at the same time, such as players, enemies, bullets, environmental objects, and visual effects. Each of these entities may have a different combination of features.

Instead of creating complex classes for every type of entity, ECS allows data to be separated into independent Components:

* Position for location data
* Velocity for movement speed
* Health for health-related data
* RenderData for rendering information

Then different Systems process these data:

* Movement System for moving entities
* Rendering System for displaying entities
* Physics System for physics simulation

---

## ECS in Game Engines

ECS-related ideas have been used in many modern game engines and game development tools.

For example, Unity introduced a data-oriented architecture called **Unity DOTS (Data-Oriented Technology Stack)**, which includes technologies such as Entity Component System, Job System, and Burst Compiler. The goal of this architecture is to improve performance in projects with a large number of entities.

In Unreal Engine, although the core architecture is mainly based on classes and Actors, some data-oriented techniques and systems with similar goals are used in different parts of the engine to improve performance.

Besides large game engines, many smaller engines and game development libraries also choose ECS because of its simplicity, flexibility, and performance benefits.

---

## Building and Running the Project

First, clone the repository and navigate to the folder of the desired version.

For example:

```bash
cd v0.0.0-project-name

// Create a directory for generated build files:
mkdir build
cd build

// At this stage, CMake generates the required build system files:
cmake ..

// After successful configuration, compile the project:
cmake --build .
```

After the compilation is complete, the generated executable file will be located inside the build directory.

</div>