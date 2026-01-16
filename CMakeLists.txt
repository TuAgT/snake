cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(SnakeGame C)

# 设置 C 标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# 添加编译选项
add_compile_options(-Wall -Wextra -g)

# 确保所有中间文件都放在 build 目录中
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 查找 ncurses 库
find_package(Curses REQUIRED)

# 包含头文件目录
include_directories(include ${CURSES_INCLUDE_DIR})

# 添加可执行文件
add_executable(snake src/main.c src/snake.c)

# 链接 ncurses 库
target_link_libraries(snake ${CURSES_LIBRARIES})

# 设置可执行文件输出到项目根目录的 bin 目录
set_target_properties(snake PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)