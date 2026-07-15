Persian Version: For the Persian documentation, please refer to [README.fa.md](README.fa.md).

# Version 0.0.0 - Split-The-Car

## Introduction

In the first stage of this project, our goal is to become familiar with two of the fundamental concepts of ECS: **Entity** and **Component**.

To understand these concepts, we must first examine the difference between Object-Oriented Programming (OOP) and Data-Oriented Design (DOD).

In OOP, real-world concepts are usually modeled as **Objects**. An object is defined by a **Class**, which stores all of its related data.

For example, to model a car, we might create a `Car` class and store information such as its color, model year, and owner as data members.

In this approach, each object keeps all of its data in one place and is managed through the object itself.

---

## The DOD Perspective

In Data-Oriented Design (DOD), the focus shifts to the data and the way it is organized and processed.

Instead of storing all information about an entity inside a single large object, the data is divided into smaller parts. Each part is responsible for only one specific type of information.

For example, the data of a car that would be stored inside a `Car` object in OOP is split into separate Components in DOD. Color, model year, owner, and other attributes each become their own Component.

In ECS, this separation gives rise to two main concepts:

- **Entity**, which represents the identity of an object.
- **Component**, which stores the data associated with that object.

As a result, a car is no longer a self-contained object. Instead, it is an Entity associated with several Components.

## What is an Entity?

In ECS, an Entity is typically just a simple identifier used to distinguish one object from another.

Unlike an object in OOP, an Entity does not store information such as color or model year.

Its sole purpose is to indicate which pieces of data belong together.

In simple terms:

An Entity answers the question, “Whose data is this?”, while a Component answers, “What data is this?”

## What is a Component?

Components are pieces of data that have been separated from the original object.

Each Component stores only one specific kind of information. For example, there may be separate Components for color, model year, and owner.

This separation makes the data more independent and easier to manage and process in later stages.

## From Object to Entity and Components

In OOP, a car is usually modeled as a single object containing all of its attributes.

In ECS, that same car becomes an Entity, while its attributes are moved into separate Components.

Thus, the Entity provides identity, and the Components hold the actual data.

This is the central idea of ECS: separating identity from data.

## Code Comparison

To better understand the difference between the two approaches, this version includes two code examples that implement the same concept: one using OOP and the other using a data-oriented approach. Reading both examples is highly recommended.

## Behaviors and Systems

In addition to Entities and Components, ECS also introduces the important concept of a **System**.

In OOP, an object's behavior is usually implemented as member functions inside the class itself.

In ECS, behavior is separated from data, and Systems are responsible for processing Components.

In version 0.0.0, we intentionally focus only on understanding Entities and Components and on learning how to separate data from objects.

The concept of Systems and the management of behavior will be introduced and implemented in future versions.

## Build and Run

From the `v0.0.0-split-the-car` directory, run:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

The executables `cars` and `splited_cars` (or `cars.exe` and `splited_cars.exe` on Windows) will be generated. Depending on the compiler and generator, they may be located in subdirectories such as `Debug` or `Release`.

Run them as follows:

```bash
./cars
./splited_cars
```

On Windows PowerShell:

```powershell
.\cars.exe
.\splited_cars.exe
```

## Exercises
## Exercise EX-0001 :
Assume that Erfan's car can fly, while Ali's car cannot. Add a new attribute representing flying speed that belongs only to Erfan's car. Implement this change in both `cars.cpp` and `splited-cars.cpp`, and print the information of both cars.