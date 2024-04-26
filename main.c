
#include  "Headers/fonctions.h"
#include  "Headers/define.h"

int	main(void)
{
	char **map = NULL;
    Entity *entity = malloc(sizeof(Entity));
    Config *config = malloc(sizeof(Config));
    setup_game(&map, entity, config);
    game(map);
    free(map);
    free(entity);
    free(config);
}