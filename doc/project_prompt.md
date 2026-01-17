# 贪吃蛇游戏项目提示词

**语言/Language:**

- [中文](project_prompt.md)
- [English](project_prompt_en.md)

## 项目概述

创建一个基于 C 语言的贪吃蛇游戏，使用 ncurses 库实现控制台界面。

## 核心功能需求

1. **游戏规则**：

   - 使用方向键或 WASD 键控制蛇的移动方向
   - 蛇吃到食物(\*)后会变长，分数增加
   - 蛇撞到边界或自己的身体时游戏结束
   - 按 Q 键可以退出游戏

2. **游戏特性**：

   - 支持中文显示，解决文字乱码问题
   - 蛇头和蛇身需要明显区分
   - 蛇上下左右移动速度需要保持一致
   - 游戏结束时显示最终分数

3. **构建系统**：

   - 同时支持 Makefile 和 CMake 两种构建方式
   - 确保编译过程中不留下多余文件在根目录
   - 中间文件应放在 build 或 obj 目录中
   - 可执行文件放在 bin 目录中

4. **文档要求**：

   - 清晰的 README.md 文件，包含游戏规则、编译运行说明和文件结构
   - 添加适当的徽章显示项目信息（语言、库、构建工具、平台）
   - 说明项目由 AI 辅助生成

5. **测试要求**：

   - 编写单元测试测试核心功能
   - 支持使用 make test 命令运行测试
   - 测试覆盖初始化、食物生成、碰撞检测和移动功能

6. **CI/CD 要求**：
   - 配置 GitHub Actions 实现自动化构建
   - 支持 Linux、macOS 和 Windows 平台
   - 支持 x86_64 和 arm64 架构
   - 自动运行 CMake 和 Makefile 构建
   - 实现构建产物的自动打包和发布

## 技术栈

- 语言：C
- 库：ncurses
- 构建工具：CMake 和 Makefile
- 测试：自定义测试框架
- CI/CD：GitHub Actions
- 平台：Linux、macOS、Windows
- 架构：x86_64、arm64

## 项目结构

```
Snake/
├── src/              # 源代码目录
│   ├── main.c        # 主函数和游戏循环
│   └── snake.c       # 游戏逻辑实现
├── include/          # 头文件目录
│   └── snake.h       # 数据结构和函数声明
├── bin/              # 可执行文件目录
├── build/            # CMake构建目录
├── obj/              # Makefile构建目录
├── test/             # 测试文件目录
├── doc/              # 文档目录
│   └── project_prompt.md  # 项目开发提示词
├── CMakeLists.txt    # CMake配置文件
├── Makefile          # Makefile配置文件
├── README.md         # 项目说明文档
└── .github/workflows/build.yml  # GitHub Actions配置
```

## 实现要点

1. **中文支持**：在初始化 ncurses 前添加 setlocale(LC_ALL, "")
2. **蛇头蛇身区分**：使用不同的字符表示蛇头和蛇身（如@和 O）
3. **移动速度平衡**：通过调整垂直移动的延迟来平衡视觉速度
4. **随机种子管理**：将 srand 调用放在初始化函数中，避免重复种子
5. **内存管理**：确保蛇移动时正确释放和分配内存
6. **测试设计**：针对核心功能设计独立的测试用例
7. **构建配置**：确保两种构建方式生成的文件路径一致

## 编译和运行

### Linux/macOS x86_64/arm64

```bash
# 使用CMake
mkdir -p build
cd build
cmake ..
make
cd ..
./bin/snake

# 使用Makefile
make
./bin/snake

# 运行测试
make test
```

### Windows x86_64/arm64 (MSYS2)

```bash
# 使用CMake
mkdir -p build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
cd ..
./bin/snake.exe

# 使用Makefile
mingw32-make
./bin/snake.exe

# 运行测试
mingw32-make test
```

## 清理命令

```bash
# 使用CMake
rm -rf build
rm -f bin/snake  # Linux/macOS
rm -f bin/snake.exe  # Windows

# 使用Makefile
make clean  # Linux/macOS
mingw32-make clean  # Windows

# 通用清理
rm -rf build obj
rm -f bin/snake  # Linux/macOS
rm -f bin/snake.exe  # Windows
```
