#include "snake.h"
#include <unistd.h>
#define height 21
#define width 40
using namespace std;
snakebody::snakebody(int col, int row)
{
    x = col;
    y = row;
}

snakebody::snakebody()
{
    x = 0;
    y = 0;
}
snakeclass::snakeclass()
{
    initscr();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    partchar = 'x';
    oldalchar = (char)219;
    fruitG = '+';
    poisonR = '-';
    fruit.x = 0;
    fruit.y = 0;
    fruitcnt = 0;
    poisoncnt = 0;
    for (int i = 0; i < 3; i++)
        snake.push_back(snakebody(10 + i, 10));
    points = 0;
    del = 100000;
    getFruit = false;
    getPoison = false;
    direction = 'l';
    for (int i = 0; i < width - 1; i++)
    {
        move(0, i);
        addch(oldalchar);
    }
    for (int i = 0; i < height - 1; i++)
    {
        move(i, 0);
        addch(oldalchar);
    }
    for (int i = 0; i < width - 1; i++)
    {
        move(height - 2, i);
        addch(oldalchar);
    }

    for (int i = 0; i < height - 1; i++)
    {
        move(i, width - 2);
        addch(oldalchar);
    }
    for (int i = 0; i < snake.size(); i++)
    {
        move(snake[i].y, snake[i].x);
        addch(partchar);
    }
    for (int i = width; i < width + 30; i++)
    {
        move(0, i);
        addch(oldalchar);
    }
    for (int i = 0; i < 10; i++)
    {
        move(i, width);
        addch(oldalchar);
    }
    for (int i = width; i < width + 30; i++)
    {
        move(10, i);
        addch(oldalchar);
    }
    for (int i = 0; i < 11; i++)
    {
        move(i, width + 30);
        addch(oldalchar);
    }
    putfruit();
    putpoison();
    refresh();
}

snakeclass::~snakeclass()
{
    nodelay(stdscr, false);
    getch();
    endwin();
}

void snakeclass::putfruit()
{
    fruitTime = 0;
    while (1)
    {
        int fruitx = rand() % width + 1;
        int fruity = rand() % height + 1;
        for (int i = 0; i < snake.size(); i++)
            if (snake[i].x == fruitx && snake[i].y == fruity)
                continue;
        if (fruitx >= width - 2 || fruity >= height - 3)
            continue;
        fruit.x = fruitx;
        fruit.y = fruity;
        break;
    }
    move(fruit.y, fruit.x);
    addch(fruitG);
    refresh();
}

void snakeclass::putpoison()
{
    poisonTime = 0;
    while (1)
    {
        int poisonX = rand() % width + 1;
        int poisonY = rand() % height + 1;
        for (int i = 0; i < snake.size(); i++)
            if (snake[i].x == poisonX && snake[i].y == poisonY)
                continue;
        if (poisonX >= width - 2 || poisonY >= height - 3)
            continue;
        poison.x = poisonX;
        poison.y = poisonY;
        break;
    }
    move(poison.y, poison.x);
    addch(poisonR);
    refresh();
}

bool snakeclass::collision()
{
    if (snake[0].x == 0 || snake[0].x == width - 1 || snake[0].y == 0 || snake[0].y == height - 2)
        return true;
    for (int i = 2; i < snake.size(); i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            return true;
    }

    if (snake[0].x == fruit.x && snake[0].y == fruit.y)
    {
        getFruit = true;
        putfruit();
        points += 10;
        move(height - 1, 0);
        if ((points % 100) == 0)
            del -= 10000;
    }
    else
        getFruit = false;
    if (snake[0].x == poison.x && snake[0].y == poison.y)
    {
        getPoison = true;
        putpoison();
        points -= 10;
        if (points < 0)
            return true;
        move(height - 1, 0);
        if ((points % 100) == 0)
            del += 10000;
    }
    else
        getPoison = false;
    return false;
}

void snakeclass::movesnake()
{
    int tmp = getch();
    switch (tmp)
    {
    case KEY_LEFT:
        if (direction != 'r')
            direction = 'l';
        else
            gameover = true;
        break;
    case KEY_UP:
        if (direction != 'd')
            direction = 'u';
        else
            gameover = true;
        break;
    case KEY_DOWN:
        if (direction != 'u')
            direction = 'd';
        else
            gameover = true;
        break;
    case KEY_RIGHT:
        if (direction != 'l')
            direction = 'r';
        else
            gameover = true;
        break;
    }

    if (!getFruit)
    {
        move(snake[snake.size() - 1].y, snake[snake.size() - 1].x);
        printw(" ");
        refresh();
        snake.pop_back();
    }
    if (getFruit)
    {
        fruitcnt++;
    }

    if (getPoison)
    {
        move(snake[snake.size() - 1].y, snake[snake.size() - 1].x);
        printw(" ");
        refresh();
        snake.pop_back();
        poisoncnt++;
    }

    if (fruitTime == 50)
    {
        move(fruit.y, fruit.x);
        printw(" ");
        refresh();
        putfruit();
    }
    if (poisonTime == 50)
    {
        move(poison.y, poison.x);
        printw(" ");
        refresh();
        putpoison();
    }

    if (direction == 'l')
    {
        snake.insert(snake.begin(), snakebody(snake[0].x - 1, snake[0].y));
    }
    else if (direction == 'r')
    {
        snake.insert(snake.begin(), snakebody(snake[0].x + 1, snake[0].y));
    }
    else if (direction == 'u')
    {
        snake.insert(snake.begin(), snakebody(snake[0].x, snake[0].y - 1));
    }
    else if (direction == 'd')
    {
        snake.insert(snake.begin(), snakebody(snake[0].x, snake[0].y + 1));
    }

    move(snake[0].y, snake[0].x);
    addch(partchar);
    refresh();
}

void snakeclass::scoreboard()
{
    move(4, width + 11);
    printw("score: %d", points);
    move(5, width + 11);
    printw("fruit: %d", fruitcnt);
    move(6, width + 10);
    printw("poison: %d", poisoncnt);
}

void snakeclass::gamestart()
{
    while (1)
    {
        if (collision() || gameover)
        {
            move(9, 15);
            printw("Game over");
            break;
        }
        movesnake();
        scoreboard();
        fruitTime++;
        poisonTime++;
        usleep(del);
    }
}
