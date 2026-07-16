# v0.2.0 - Game Loop

## Overview

In the previous version, we introduced Systems and separated data from logic. However, the systems were executed manually and only once.

In this version, we introduce the concept of a **Game Loop**.

A game engine or simulation does not run its systems a single time. It continuously updates the world over time. The Game Loop is responsible for repeatedly executing systems while the application is running.

---

## Goal

The goal of this version is to introduce:

- A continuous execution loop
- Updating systems every frame
- The concept of frame-based simulation
- Delta Time for time-based movement

---

# New Concept: Game Loop

A simple program normally follows this structure:

```
Start Program
      |
      v
Execute Code
      |
      v
Exit Program
```

A game or simulation follows a different structure:

```
Start Program
      |
      v
+----------------+
|   Game Loop    |
|                |
| Update Systems |
| Calculate Time |
| Repeat         |
+----------------+
      |
      v
Stop Program
```

The loop continues until the application is closed.

---

# Why Do We Need a Loop?

Without a loop, a system runs only once:

```cpp
MovementSystem.Update();
```

The world cannot change over time.

With a game loop:

```cpp
while (true)
{
    MovementSystem.Update();
}
```

The system updates continuously, creating the behavior of a simulation.

---

# Delta Time

The speed of computers is not constant. One frame may take longer or shorter than another.

Instead of moving objects by a fixed amount:

```cpp
position += speed;
```

we use elapsed time:

```cpp
position += speed * deltaTime;
```

This makes movement independent from the frame rate.

Example:

- Fast computer: 200 FPS
- Slow computer: 30 FPS

Both simulations can move at the same speed.

---

# Project Structure

```
v0.2.0-game-loop
│
├── oop
│   └── cars.cpp
│
├── dod
│   └── entities.cpp
│
└── README.md
```

---

# OOP Version

The OOP version continues using the `Car` class.

Each car contains:

- Position
- Speed
- Driver information
- Technical specifications
- Other data

The movement logic is inside the class:

```cpp
car.Move(deltaTime);
```

The main loop repeatedly updates every car.

---

# Data-Oriented Design Version

The DOD version separates data into independent arrays.

Example:

```cpp
std::vector<float> positions;
std::vector<float> speeds;
```

The Movement System only processes the data it needs:

```cpp
positions[i] += speeds[i] * deltaTime;
```

This improves memory locality because related data is stored together.

---

# Main Difference

## OOP

```
Car
|
├── Position
├── Speed
├── Driver Data
├── Technical Data
└── Move()
```

The object contains both data and behavior.

---

## ECS / DOD

```
Entity

Components:
├── Position
└── Speed


System:
└── MovementSystem
```

Data and logic are separated.

---

# Running the Project

Compile using CMake:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Run the executable:

```bash
./heartbeat_car
```

or:

```bash
./heartbeat_system
```

---

# Learning Outcome

After completing this version, you should understand:

- Why simulations need a continuous loop
- How systems are executed every frame
- Why delta time is important
- The relationship between entities, components, systems, and the game loop

---

# Exercise

## EX-0003 - Pause and Resume the Game Loop

### Goal

Modify the game loop so that it can be paused while the program is running and continue again after receiving another command.

### Requirements

- Add a pause state to the game loop.
- When the loop is paused, systems should stop updating.
- The program should continue running and wait for a command.
- When resumed, systems should continue updating normally.

Example behavior:

```
Game Running...
Movement System Updating...

Press P to pause

Game Paused

Press P again to resume

Game Running...
Movement System Updating...
```

### Concepts Practiced

- Game loop control
- Runtime state management
- Separating program execution from system updates

---

# Next Version

The next version will focus on introducing an **Entity Manager**.

Currently, entities are represented using simple IDs and manually managed arrays. The Entity Manager will provide a dedicated way to create, store, and manage entities.