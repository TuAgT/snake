# Snake

[![Socialify](https://socialify.git.ci/TuAgT/snake/image?description=1&font=Rokkitt&language=1&name=1&owner=1&pattern=Circuit%20Board&stargazers=1&theme=Dark)](https://github.com/TuAgT/snake)

[![Language](https://img.shields.io/badge/Language-C-blue)](<https://en.wikipedia.org/wiki/C_(programming_language)>)
[![Library](https://img.shields.io/badge/Library-ncurses-green)](https://en.wikipedia.org/wiki/Ncurses)
[![Build](https://img.shields.io/badge/Build-CMake%20%26%20Makefile-orange)](https://cmake.org/)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%26%20macOS%20%26%20Windows-lightgrey)](https://github.com/)
[![Trae AI](https://img.shields.io/badge/IDE-Trae%20AI-brightgreen)](https://trae.ai/)

This is a Snake game implemented in C language using the ncurses library for the console interface. This project is generated and developed with AI assistance.

## Game Rules

- Use arrow keys or WASD keys to control the snake's movement direction
- The snake grows longer and score increases when eating food (\*)
- Game ends when the snake hits the boundary or its own body
- Press Q to exit the game

## Features

- Supports Chinese display, resolving text garbled issues on some systems
- Uses locale settings to ensure correct character encoding
- Supports both CMake and Makefile build methods

## How to Compile and Run

### Prerequisites

Install ncurses library:

```bash
sudo apt-get install libncurses5-dev libncursesw5-dev  # Ubuntu/Debian
brew install ncurses  # macOS
# Windows using MSYS2
pacman -S mingw-w64-x86_64-ncurses mingw-w64-arm64-ncurses  # MSYS2
```

Install CMake:

```bash
sudo apt-get install cmake  # Ubuntu/Debian
brew install cmake  # macOS
# Windows using MSYS2
pacman -S mingw-w64-x86_64-cmake mingw-w64-arm64-cmake  # MSYS2
```

### Compile and Run with CMake

**Linux/macOS:**

```bash
# Create build directory
mkdir -p build

# Enter build directory and generate Makefile
cd build
cmake ..

# Compile project
make

# Return to root directory and run game
cd ..
./bin/snake
```

**Windows (MSYS2):**

```bash
# Create build directory
mkdir -p build

# Enter build directory and generate Makefile
cd build
cmake .. -G "MinGW Makefiles"

# Compile project
mingw32-make

# Return to root directory and run game
cd ..
./bin/snake.exe
```

### Compile and Run with Traditional Makefile

**Linux/macOS:**

```bash
# Compile project
make

# Run game
./bin/snake
```

**Windows (MSYS2):**

```bash
# Compile project
mingw32-make

# Run game
./bin/snake.exe
```
