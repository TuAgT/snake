#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/snake.h"

// 测试初始化游戏
void test_init_game()
{
    Game game;
    init_game(&game);

    printf("Testing init_game...");

    // 检查游戏是否正确初始化
    if (game.head != NULL && game.tail != NULL)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n");
    }

    // 清理内存
    free_snake(&game);
}

// 测试生成食物
void test_generate_food()
{
    Game game;
    init_game(&game);

    int old_food_x = game.food_x;
    int old_food_y = game.food_y;

    // 生成多个食物，只要有一个不同就通过测试
    bool positions_are_different = false;
    for (int i = 0; i < 10; i++)
    {
        generate_food(&game);
        if (game.food_x != old_food_x || game.food_y != old_food_y)
        {
            positions_are_different = true;
            break;
        }
    }

    printf("Testing generate_food...");

    // 检查食物位置是否改变
    if (positions_are_different)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n");
    }

    // 清理内存
    free_snake(&game);
}

// 测试碰撞检测
void test_check_collision()
{
    Game game;
    init_game(&game);

    printf("Testing check_collision...");

    // 检查初始位置是否没有碰撞
    if (!check_collision(&game))
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n");
    }

    // 清理内存
    free_snake(&game);
}

// 测试蛇的移动
void test_snake_movement()
{
    Game game;
    init_game(&game);

    int old_x = game.head->x;

    // 设置方向为右
    game.dir = RIGHT;
    update_game(&game);

    printf("Testing snake_movement...");

    // 检查蛇是否移动
    if (game.head->x != old_x)
    {
        printf("PASS\n");
    }
    else
    {
        printf("FAIL\n");
    }

    // 清理内存
    free_snake(&game);
}

int main()
{
    printf("Running Snake Game Tests...\n");
    printf("============================\n");

    test_init_game();
    test_generate_food();
    test_check_collision();
    test_snake_movement();

    printf("============================\n");
    printf("All tests completed.\n");

    return 0;
}