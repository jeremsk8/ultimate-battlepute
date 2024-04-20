
#include  "Headers/fonctions.h"
#include  "Headers/define.h"


int	main(void)
{
	char **map = NULL;
    Player *player  = malloc(sizeof(Player));
    Config *config = malloc(sizeof(Config));
    setup_game(&map, player, config);
    game(map);
}