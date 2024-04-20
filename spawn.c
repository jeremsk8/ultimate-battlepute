#include  "Headers/fonctions.h"
#include  "Headers/define.h"

void player_spawn(char ***map, Player *player, Config *config)
{
    int x, y;

    player->coord_x =  config->size_x / 2;
    player->coord_y = 4;
    (*map)[player->coord_x][player->coord_y ] = PLAYER;
}

void girflfriend_spawn(char ***map, Config * config)
{
     (*map)[config->size_x  / 2][config->size_y - 7] = GIRLFRIEND;
}
