#include "snake.h"
#include <unistd.h>
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
    getmaxyx(stdscr, maxheight, maxwidth);
    partchar = 'x';
    oldalchar = (char)219;
    fruitG = '+';
    poisonR = '-';
    fruit.x = 0;
    fruit.y = 0;
    for (int i = 0; i < 3; i++)
        snake.push_back(snakebody(40 + i, 10));
    points = 0;
    del = 110000;
    getFruit = false;
    getPoison = false;
    direction = 'l';
    srand(time(NULL));
    for (int i = 0; i < maxwidth - 1; i++)
    {
        move(0, i);
        addch(oldalchar);
    }
    for (int i = 0; i < maxheight - 1; i++)
    {
        move(i, 0);
        addch(oldalchar);
    }
    for (int i = 0; i < maxwidth - 1; i++)
    {
        move(maxheight - 2, i);
        addch(oldalchar);
    }

    for (int i = 0; i < maxheight - 1; i++)
    {
        move(i, maxwidth - 2);
        addch(oldalchar);
    }
    for (int i = 0; i < snake.size(); i++)
    {
        move(snake[i].y, snake[i].x);
        addch(partchar);
    }
    move(maxheight - 1, 0);
    printw("%d", points);
    putfruit();
    putpoison();
    refresh();
}

snakeclass::~snakeclass()
{
    nodelay(stdscr, false); //turn back
    getch();                //wait until a key is pressed
    endwin();
}

void snakeclass::putfruit()
{
    while (1)
    {
        int fruitx = rand() % maxwidth + 1;
        int fruity = rand() % maxheight + 1;
        for (int i = 0; i < snake.size(); i++)
            if (snake[i].x == fruitx && snake[i].y == fruity)
                continue;
        if (fruitx >= maxwidth - 2 || fruity >= maxheight - 3)
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
    while (1)
    {
        int poisonX = rand() % maxwidth + 1;
        int poisonY = rand() % maxheight + 1;
        for (int i = 0; i < snake.size(); i++)
            if (snake[i].x == poisonX && snake[i].y == poisonY)
                continue;
        if (poisonX >= maxwidth - 2 || poisonY >= maxheight - 3)
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
    if (snake[0].x == 0 || snake[0].x == maxwidth - 1 || snake[0].y == 0 || snake[0].y == maxheight - 2)
        return true;
    for (int i = 2; i < snake.size(); i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            return true;
    }
    //collision with the fruit
    if (snake[0].x == fruit.x && snake[0].y == fruit.y)
    {
        getFruit = true;
        putfruit();
        points += 10;
        move(maxheight - 1, 0);
        printw("%d", points);
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
        move(maxheight - 1, 0);
        printw("%d", points);
        if ((points % 100) == 0)
            del += 10000;
    }
    else
        getPoison = false;
    return false;
}

void snakeclass::movesnake()
{
    //detect key
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
    if (getPoison)
    {
        move(snake[snake.size() - 1].y, snake[snake.size() - 1].x);
        printw(" ");
        refresh();
        snake.pop_back();
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

void snakeclass::gamestart()
{
    while (1)
    {
        if (collision() || gameover)
        {
            move(12, 36);
            printw("game_over");
            break;
        }
        movesnake();
        if (direction == 'q')
            break;
        usleep(del);
    }
}
