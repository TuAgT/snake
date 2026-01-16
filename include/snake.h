#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <locale.h>

#define WIDTH 20
#define HEIGHT 20

// 方向枚举
typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

// 蛇节点结构体
typedef struct SnakeNode
{
    int x;
    int y;
    struct SnakeNode *next;
} SnakeNode;

// 游戏状态结构体
typedef struct
{
    SnakeNode *head;
    SnakeNode *tail;
    Direction dir;
    int food_x;
    int food_y;
    int score;
    int game_over;
} Game;

// 函数声明
void init_game(Game *game);
void draw_game(Game *game);
void update_game(Game *game);
void handle_input(Game *game);
void generate_food(Game *game);
int check_collision(Game *game);
void add_snake_node(Game *game);
void free_snake(Game *game);

#endif // SNAKE_H