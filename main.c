
#include  "Headers/fonctions.h"
#include  "Headers/define.h"

int	main(void)
{
	char **map = NULL;
    char d;
    Entity *entity = malloc(sizeof(Entity));
    Config *config = malloc(sizeof(Config));
    setup_game(&map, entity, config);
    game(map, entity, config);
    printf("\nappuyer sur une touche pour terminer");
    scanf("%c", &d);
    endwin();
    free(map);
    free(entity);
    free(config);
    return 0;

}