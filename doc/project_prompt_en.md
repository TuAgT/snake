# Snake Game Project Requirements

**语言/Language:**

- [中文](project_prompt.md)
- [English](project_prompt_en.md)

## Project Overview

Create a Snake game based on C language, using the ncurses library to implement a console interface.

## Core Functional Requirements

1. **Game Rules**:

   - Use arrow keys or WASD keys to control the snake's movement direction
   - The snake grows longer and score increases when eating food (\*)
   - Game ends when the snake hits the boundary or its own body
   - Press Q to exit the game

2. **Game Features**:

   - Support Chinese display, resolve text garbled issues
   - Clearly distinguish between snake head and body
   - Maintain consistent movement speed in all directions
   - Display final score when game ends

3. **Build System**:

   - Support both Makefile and CMake build methods
   - Ensure no redundant files are left in the root directory during compilation
   - Intermediate files should be placed in build or obj directory
   - Executable files should be placed in bin directory

4. **Documentation Requirements**:

   - Clear README.md file, including game rules, compilation and running instructions, and file structure
   - Add appropriate badges to display project information (language, library, build tools, platforms)
   - Explain that the project was AI-assisted generated

5. **Testing Requirements**:

   - Write unit tests to test core functionalities
   - Support running tests using make test command
   - Test coverage should include initialization, food generation, collision detection, and movement functions

6. **CI/CD Requirements**:
   - Configure GitHub Actions for automated building
   - Support Linux, macOS, and Windows platforms
   - Support x86_64 and arm64 architectures
   - Automatically run CMake and Makefile builds
   - Implement automatic packaging and release of build artifacts

## Technology Stack
