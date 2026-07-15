# ECS Implementation Guide - Version 0.1.0

## Overview

Version **0.1.0** introduces the concept of **Systems**, completing the three fundamental building blocks of a basic ECS architecture.

In the previous version, we introduced **Entities** and **Components** and showed how data can be separated from objects. In this version, we take the next step by moving **behavior** out of the data and into **Systems**.

In ECS:

- **Entity** is only an identifier.
- **Component** stores data only.
- **System** contains the logic that processes Components.

---

## Project Structure

- **one_second_car.cpp**  
  Demonstrates the Object-Oriented approach where both data and behavior belong to the `Car` object.

- **one_second_system.cpp**  
  Demonstrates the ECS approach where behavior is implemented as a separate `MovementSystem`.

---

## What's Included

- Introduction to Systems.
- Separation of behavior from data.
- Manual execution of a System.
- Comparison between OOP and ECS.

---

## What's Not Included Yet

To keep the implementation simple and educational, the following concepts are intentionally postponed:

- Entity Manager
- Component Manager
- System Manager
- Queries
- Game Loop

These concepts will be introduced gradually in future versions when their necessity naturally becomes apparent.

---

## Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Run the Object-Oriented example:

```bash
./one_second_car
```

Run the ECS example:

```bash
./one_second_system
```

---

## Exercises
## Exercise EX-0002 :
Extend both examples by adding a **Fuel** property to each car.

Then implement the following behavior:

- Every car starts with a certain amount of fuel.
- For every unit of movement, a fixed amount of fuel is consumed.
- Print the remaining fuel after the movement has been performed.

```