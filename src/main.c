#include "../include/snake.h"

int main()
{
    // 设置locale，确保支持中文
    setlocale(LC_ALL, "");

    // 初始化ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(100); // 设置键盘输入超时时间

    // 创建游戏对象
    Game game;
    init_game(&game);

    // 游戏循环
    while (!game.game_over)
    {
        draw_game(&game);
        handle_input(&game);
        update_game(&game);
        usleep(100000); // 控制游戏速度
    }

    // 游戏结束
    clear();
    mvprintw(HEIGHT / 2, (WIDTH - 10) / 2, "游戏结束!");
    mvprintw(HEIGHT / 2 + 1, (WIDTH - 15) / 2, "最终分数: %d", game.score);
    mvprintw(HEIGHT / 2 + 3, (WIDTH - 20) / 2, "按任意键退出...");
    refresh();

    // 等待用户输入
    timeout(-1);
    getch();

    // 清理资源
    free_snake(&game);
    endwin();

    return 0;
}