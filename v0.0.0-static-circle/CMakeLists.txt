# ============================================================================
# CMAKE CONFIGURATION FOR ECS STATIC CIRCLE PROJECT
# ============================================================================

# Define the minimum version of CMake required to parse this script.
# Version 3.16 introduces stable FetchContent features used for dependency management.
cmake_minimum_required(VERSION 3.16)

# Set the project name and specify that it uses the C++ programming language (CXX).
project(ecs_static_circle CXX)

# Enforce the C++17 standard for compiling this target.
# C++17 is required for standard modern features and clean structure definitions.
set(CMAKE_CXX_STANDARD 17)

# Ensure that the compiler must support C++17; if not, the configuration process will fail immediately.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================================================
# DEPENDENCY MANAGEMENT (Automated Raylib Fetching)
# ============================================================================

# Include the FetchContent module, which allows CMake to download dependencies at configure time.
include(FetchContent)

# Declare the properties of the external Raylib repository.
# We fetch the release package for version 6.0 directly from the official GitHub repository tags.
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/6.0.tar.gz
)

# Download, extract, and integrate Raylib into the current build tree as a sub-project.
# This makes Raylib targets (like the static library) available to link against automatically.
FetchContent_MakeAvailable(raylib)

# ============================================================================
# TARGET DEFINITIONS AND LINKING
# ============================================================================

# Create the primary executable target from the main C++ source code file.
add_executable(ecs_static_circle static-circle.cpp)

# Link the compiled Raylib library to our executable target.
# PRIVATE specifies that dependency compilation properties are confined strictly to this target.
target_link_libraries(ecs_static_circle PRIVATE raylib)