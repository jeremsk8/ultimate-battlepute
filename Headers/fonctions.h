#ifndef FONCTIONS_H
#define FONCTIONS_H
#include "define.h"

void setup_game(char ***map, Player *player, Config *config);

void player_spawn(char ***map, Player *player, Config *config);

void girflfriend_spawn(char ***map, Config * config);

void ft_range(int ***tab, int min, int max);

void print_tab(int *tab);

void game(char **map);

#endif