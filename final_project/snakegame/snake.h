#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#ifndef SNAKE_H
#define SNAKE_H

struct snakebody
{
    int x, y;
    snakebody(int col, int row);
    snakebody();
};

class snakeclass
{
    int points, del, maxwidth, maxheight, fruitTime, poisonTime, fruitcnt, poisoncnt;
    char direction, partchar, oldalchar, fruitG, poisonR;
    bool getFruit, getPoison, gameover;
    snakebody fruit, poison;
    std::vector<snakebody> snake;

    void putfruit();
    void putpoison();
    bool collision();
    void movesnake();
    void itemTime();
    void scoreboard();

public:
    snakeclass();
    ~snakeclass();
    void gamestart();
};

#endif