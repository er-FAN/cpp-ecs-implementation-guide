# ECS Implementation Guide - Version v0.0.0 (Static Circle)

Persian Version: For the Persian documentation, please refer to README.fa.md.

This sub-project represents the absolute foundational layer of our custom C++ Data-Oriented Entity Component System (ECS). The goal of this version is to demonstrate the decoupling of data from logic by rendering a single static red circle using the Raylib library.

---

## Architectural Layout

The code in this version perfectly aligns with pure ECS principles:

* **Entity:** A pure mathematical identifier (`uint32_t`). It carries no structural weight, no behavior, and no preset component allocations upfront.
* **Components (`Position`, `RenderComponent`):** Contiguous structures holding pure raw data. They contain absolutely no logic or execution methods.
* **Registry:** A centralized component database utilizing the Structure of Arrays (SoA) layout. Memory is allocated on-demand, and dynamic vector resizing is implemented to completely eliminate out-of-bounds pointer crashes when adding components to clean entities.
* **Systems (`RenderSystem`):** Standalone global functions with no internal state. They query the registry using component presence masks, filter out qualified entities, and execute the rendering pipeline.

---

## Requirements

* A compiler supporting C++17 or higher (MSVC, GCC, or Clang)
* CMake (Version 3.16 or higher)
* VS Code Editor (Recommended)

---

## Step-by-Step Execution Guide

To build and run this version, you must avoid compiling from the root repository folder. Follow these precise setup pipelines:

### Method A: Using the VS Code CMake Tools Extension (Recommended)

This method avoids terminal environment path errors by delegating the build cycle to the IDE interface.

1. **Isolate the Folder:** Open VS Code. Go to `File > Open Folder` and select ONLY the `v0.0.0-static-circle` directory. Do not open the root of the whole repository.
2. **Select Compiler Kit:** Press `Ctrl + Shift + P` to open the Command Palette. Type `CMake: Select a Kit` and select your installed compiler (e.g., Visual Studio Community Release - amd64 or GCC).
3. **Configure the Project:** Press `Ctrl + Shift + P`, type `CMake: Configure` and press Enter. This tells CMake to automatically parse the configurations and download the Raylib 6.0 source files into a hidden build directory. Wait until you see `Configuring done`.
4. **Compile and Run:** Look at the bottom status bar of VS Code. Click the **Build** button to compile, then click the **Play** button (triangle icon) to run the executable. Alternatively, run `CMake: Run Without Debugging` from the Command Palette.

### Method B: Using the Command Line Interface (CLI)

If you type `cmake ..` in a standard terminal and get the error: *"The term 'cmake' is not recognized..."*, it means CMake is not registered in your Windows System PATH. Use one of these solutions:

* **Solution 1 (Visual Studio Environment):** Open the Start Menu, search for **Developer PowerShell for VS**, navigate (`cd`) to your `v0.0.0-static-circle/build` folder, and execute the commands there.
* **Solution 2 (CMake Terminal Extension):** Inside VS Code, press `Ctrl + Shift + P`, search for `CMake: Open CMake Tools Extension Terminal`. This terminal has all system paths pre-injected by the extension.

Once inside the correct terminal environment, run these commands sequentially:

```bash
# 1. Create a build directory and enter it
mkdir build
cd build

# 2. Configure the project and trigger the automated download of Raylib 6.0
cmake ..

# 3. Compile the executable target
cmake --build .

# 4. Launch the binary application
# On Windows (MSVC default):
.\Debug\ecs_static_circle.exe
# On Linux / macOS:
./ecs_static_circle

---

## Exercise

To test your understanding of this foundational ECS structure, try completing the following challenge:
* **Challenge:** Create a second entity that renders a **Blue** circle with a radius of **30** pixels at a different position on the screen (e.g., `x: 200.0f, y: 150.0f`).
* **Goal:** Notice how you can add completely new objects to the screen simply by creating a new Entity ID and assigning components, without changing a single line of code inside the `RenderSystem`.