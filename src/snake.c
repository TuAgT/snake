#include "../include/snake.h"

// 初始化游戏
void init_game(Game *game)
{
    // 设置随机种子
    srand(time(NULL));

    // 初始化蛇
    game->head = (SnakeNode *)malloc(sizeof(SnakeNode));
    game->head->x = WIDTH / 2;
    game->head->y = HEIGHT / 2;
    game->head->next = NULL;
    game->tail = game->head;

    // 初始方向向右
    game->dir = RIGHT;

    // 生成初始食物
    generate_food(game);

    // 初始分数和游戏状态
    game->score = 0;
    game->game_over = 0;
}

// 绘制游戏界面
void draw_game(Game *game)
{
    // 清屏
    clear();

    // 绘制边界
    for (int i = 0; i < WIDTH + 2; i++)
    {
        mvprintw(0, i, "#");
        mvprintw(HEIGHT + 1, i, "#");
    }
    for (int i = 0; i < HEIGHT + 2; i++)
    {
        mvprintw(i, 0, "#");
        mvprintw(i, WIDTH + 1, "#");
    }

    // 绘制蛇
    SnakeNode *current = game->head;
    while (current != NULL)
    {
        if (current == game->head)
        {
            // 蛇头使用不同的字符，便于区分
            mvprintw(current->y, current->x, "@");
        }
        else
        {
            mvprintw(current->y, current->x, "O");
        }
        current = current->next;
    }

    // 绘制食物
    mvprintw(game->food_y, game->food_x, "*");

    // 显示分数
    mvprintw(HEIGHT + 3, 0, "分数: %d", game->score);

    // 刷新屏幕
    refresh();
}

// 处理用户输入
void handle_input(Game *game)
{
    int ch = getch();

    switch (ch)
    {
    case 'w':
    case 'W':
    case KEY_UP:
        if (game->dir != DOWN)
        {
            game->dir = UP;
        }
        break;
    case 's':
    case 'S':
    case KEY_DOWN:
        if (game->dir != UP)
        {
            game->dir = DOWN;
        }
        break;
    case 'a':
    case 'A':
    case KEY_LEFT:
        if (game->dir != RIGHT)
        {
            game->dir = LEFT;
        }
        break;
    case 'd':
    case 'D':
    case KEY_RIGHT:
        if (game->dir != LEFT)
        {
            game->dir = RIGHT;
        }
        break;
    case 'q':
    case 'Q':
        game->game_over = 1;
        break;
    }
}

// 更新游戏状态
void update_game(Game *game)
{
    if (game->game_over)
    {
        return;
    }

    // 移动蛇头
    int new_x = game->head->x;
    int new_y = game->head->y;

    switch (game->dir)
    {
    case UP:
        new_y--;
        usleep(50000); // 增加垂直移动延迟以平衡视觉速度差异
        break;
    case DOWN:
        new_y++;
        usleep(50000); // 增加垂直移动延迟以平衡视觉速度差异
        break;
    case LEFT:
        new_x--;
        break;
    case RIGHT:
        new_x++;
        break;
    }

    // 检查碰撞
    if (check_collision(game))
    {
        game->game_over = 1;
        return;
    }

    // 创建新的蛇头
    SnakeNode *new_head = (SnakeNode *)malloc(sizeof(SnakeNode));
    new_head->x = new_x;
    new_head->y = new_y;
    new_head->next = game->head;
    game->head = new_head;

    // 检查是否吃到食物
    if (new_x == game->food_x && new_y == game->food_y)
    {
        game->score++;
        generate_food(game);
    }
    else
    {
        // 移除蛇尾
        SnakeNode *temp = game->tail;
        SnakeNode *current = game->head;

        // 找到倒数第二个节点
        while (current->next != game->tail)
        {
            current = current->next;
        }

        current->next = NULL;
        game->tail = current;
        free(temp);
    }
}

// 生成食物
void generate_food(Game *game)
{

    // 随机生成食物位置，确保不在蛇身上
    int x, y;
    int on_snake;

    do
    {
        x = rand() % WIDTH + 1;
        y = rand() % HEIGHT + 1;

        on_snake = 0;
        SnakeNode *current = game->head;
        while (current != NULL)
        {
            if (current->x == x && current->y == y)
            {
                on_snake = 1;
                break;
            }
            current = current->next;
        }
    } while (on_snake);

    game->food_x = x;
    game->food_y = y;
}

// 检查碰撞
int check_collision(Game *game)
{
    int x = game->head->x + (game->dir == RIGHT ? 1 : game->dir == LEFT ? -1
                                                                        : 0);
    int y = game->head->y + (game->dir == DOWN ? 1 : game->dir == UP ? -1
                                                                     : 0);

    // 检查边界碰撞
    if (x <= 0 || x > WIDTH || y <= 0 || y > HEIGHT)
    {
        return 1;
    }

    // 检查自身碰撞
    SnakeNode *current = game->head;
    while (current != NULL)
    {
        if (current->x == x && current->y == y)
        {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

// 释放蛇的内存
void free_snake(Game *game)
{
    SnakeNode *current = game->head;
    while (current != NULL)
    {
        SnakeNode *temp = current;
        current = current->next;
        free(temp);
    }
}