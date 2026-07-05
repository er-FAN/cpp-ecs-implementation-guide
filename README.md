# C++ Data-Oriented ECS Implementation Guide

Persian Version: For the Persian documentation, please refer to README.fa.md.

This repository is a practical, version-controlled guide to understanding and building an Entity Component System (ECS) in C++. In this project, we use the Raylib library for graphical rendering to visualize the system's output tangibly.

---

## What is the goal of this project?

The goal of this repository is to teach and demonstrate the step-by-step implementation of an ECS system. We start the project from a very simple and basic structure (version v0.1.0) and gradually add new features and concepts in subsequent versions to observe the progressive evolution of a data-oriented system in practice.

---

## What is an ECS System?

The ECS (Entity Component System) architecture is a software design pattern specifically used in video game development and computer simulations. 

This architecture is based on the principles of Data-Oriented Design (DOD). Unlike the traditional Object-Oriented Programming (OOP) approach, which combines data and behavior within classes, ECS completely separates raw data from the program's logic and processing. This helps organize large projects and manage game features more easily.

Further Reading: Since this project focuses on practical implementation, it is recommended to read specialized articles on these patterns for a deeper understanding of the underlying theory and a detailed comparison between OOP and DOD.

---

## Prerequisites and Execution

This project is developed version by version. The code for each version resides in its own dedicated directory as an independent project. To run any of the versions, you will need the following tools:

* A compiler with C++17 support or higher (MSVC, GCC, or Clang)
* CMake build tool (version 3.16 or higher)
* Raylib graphical library (dependency management is handled automatically via CMake)

### Compilation Commands in the Terminal:

To run each version, first open the terminal in the root directory of the project and enter the following commands (replace v0.1.0-basic-collision with the name of your target version folder):

```bash
# 1. Navigate to the target version directory
cd v0.1.0-basic-collision

# 2. Create the build directory, configure, and compile the project
mkdir build && cd build
cmake ..
cmake --build .
