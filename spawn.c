#include  "Headers/fonctions.h"
#include  "Headers/define.h"

void player_spawn(char ***map, Player *player, Config *config)
{
    player = malloc(sizeof(Player));
    player->coord_x =  config->size_x / 2;
    player->coord_y = 4;
    (*map)[player->coord_x][player->coord_y ] = PLAYER;
}

void girflfriend_spawn(char ***map, Config * config)
{
     (*map)[config->size_x  / 2][config->size_y - 7] = GIRLFRIEND;
}


void bush_spawn(char ***map, Config *config)
{
    int x;
    int y;
    int i;

    i = 0;
    srand(time(NULL));
    while ( i < config->numb_of_bush)
    {
    do
    {
        x = rand() % (config->size_x- 2) + 1;
        y = rand() % (config->size_y -2) + 1;
    }
    while((*map)[x][y] != ' ');
    (*map)[x][y] = BUSH;
    i++;
   }     
}

void pute_spawn(char ***map, Pute **pute, Config *config)
{
    int x;
  int y;

  for (int i = 0; i < config->numb_of_pute; i++)
	{
	  coord_generator (map, &x, &y, config);
	  pushPute (pute, x, y, i);
	  (*map)[x][y] = PUTE;
	}
}