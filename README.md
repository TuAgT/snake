# Snake

[![Language](https://img.shields.io/badge/Language-C-blue)](<https://en.wikipedia.org/wiki/C_(programming_language)>)
[![Library](https://img.shields.io/badge/Library-ncurses-green)](https://en.wikipedia.org/wiki/Ncurses)
[![Build](https://img.shields.io/badge/Build-CMake%20%26%20Makefile-orange)](https://cmake.org/)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%26%20macOS-lightgrey)](https://github.com/)

这是一个基于 C 语言的贪吃蛇游戏，使用 ncurses 库实现控制台界面。本项目由 AI 辅助生成和开发。

## 游戏规则

- 使用方向键或 WASD 键控制蛇的移动方向
- 蛇吃到食物(\*)后会变长，分数增加
- 蛇撞到边界或自己的身体时游戏结束
- 按 Q 键可以退出游戏

## 特性说明

- 支持中文显示，解决了在部分系统上的文字乱码问题
- 采用 locale 设置确保正确的字符编码
- 同时支持 CMake 和 Makefile 两种构建方式

## 如何编译和运行

### 前提条件

需要安装 ncurses 库：

```bash
sudo apt-get install libncurses5-dev libncursesw5-dev  # Ubuntu/Debian
brew install ncurses  # macOS
```

需要安装 CMake：

```bash
sudo apt-get install cmake  # Ubuntu/Debian
brew install cmake  # macOS
```

### 使用 CMake 编译和运行

```bash
# 创建构建目录
mkdir -p build

# 进入构建目录并生成 Makefile
cd build
cmake ..

# 编译项目
make

# 返回根目录并运行游戏
cd ..
./bin/snake
```

### 使用传统 Makefile 编译和运行

```bash
# 编译项目
make

# 运行游戏
./bin/snake
```

### 清理构建文件

**使用 CMake 时：**

```bash
rm -rf build
rm -f bin/snake
```

**使用传统 Makefile 时：**

```bash
make clean
```

或者手动清理：

```bash
rm -rf build obj
rm -f bin/snake
```

## 文件结构

- `src/` - 源代码目录
  - `main.c` - 主函数，处理游戏初始化和主循环
  - `snake.c` - 游戏逻辑实现
- `include/` - 头文件目录
  - `snake.h` - 头文件，定义数据结构和函数声明
- `test/` - 测试文件目录
  - `snake_test.c` - 游戏逻辑测试用例
- `bin/` - 可执行文件目录
  - `snake` - 编译后的游戏可执行文件
- `build/` - 构建临时文件目录（可删除）
- `obj/` - 对象文件目录（可删除）
- `doc/` - 文档目录
  - `project_prompt.md` - 项目开发提示词
- `.github/workflows/` - GitHub Actions 配置目录
  - `build.yml` - 自动构建和测试配置
- `.gitignore` - Git 忽略文件配置
- `CMakeLists.txt` - CMake 构建配置文件
- `Makefile` - 传统 Makefile 构建配置
- `README.md` - 项目说明文档
