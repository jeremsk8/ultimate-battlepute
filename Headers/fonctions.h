#ifndef FONCTIONS_H
#define FONCTIONS_H
#include "define.h"

void setup_game(char ***map, Entity *entity, Config *config);

struct Player *player_spawn(char ***map, Config *config);

void setup_map_struct(char ***map, Config *config);

void girflfriend_spawn(char ***map, Config * config);

void bush_spawn(char ***map, Config *config);

void pute_spawn(char ***map, struct Pute **pute, Config *config);

void coord_generator (char ***map, int *x, int *y, Config *config);

void pushPute (Pute **head, int x, int y, int id);

void ft_range(int ***tab, int min, int max);

int ft_strcmp(char *s1, char*s2);

void print_tab(int *tab);

int check(char c, int is_player);

void game(char **map, Entity *entity, Config *config);

void case_move(char ***map, int *x, int *y, int direction, int is_col);

#endif