#ifndef DEFINE_H
#define DEFINE_H
#pragma once
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUSH 'o'
#define PUTE 'p'
#define SMART_PUTE 'P'
#define PLAYER 'Q'
#define GIRLFRIEND 'g'
#define PUTE_PLAYER 49
#define SAFE_ZONE 'x'
#define MAP_LIMITE '0'


#define LEFT 'q'
#define RIGHT 'd'
#define UP 'z'
#define DOWN 's'

#define WON 0
#define LOST -1
#define CONTINUE 1
#define CONTAMINE - 2
#define PUTE_NUM 60
#define PIERRE_NUM 80
#define NUM_PUTE_PLAYER 0
#define NUM_SMART_PUTE 4

typedef struct
{
    int coord_x;
    int coord_y;
} Player;

typedef struct
{
    int size_x;
    int size_y;
    int numb_of_pute;
    int numb_of_bush;
} Config;

#endif