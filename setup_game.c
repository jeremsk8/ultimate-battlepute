#include  "Headers/fonctions.h"
#include  "Headers/define.h"

int ft_strcmp(char *s1, char*s2)
{
    while (*s1 ==*s2 && *s1)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

void setup_map_struct(char ***map, Config *config)
{
    int x;
    int y;

    x = 0;
    while (x < config->size_x)
    {
        y = 0;
        while (y < config->size_y)
        {
            (*map)[0][y ] = MAP_LIMITE;            // haut
            (*map)[config->size_x - 1][y] = MAP_LIMITE; // bas
            (*map)[x][0] = MAP_LIMITE;            // gauche 
            (*map)[x][config->size_y-1] = MAP_LIMITE; // droite 
            y++;
        }
        x++;
    }
    x = 0;
    while (x <= 4) 
    {
        y = 0;
        while (y <= 2) 
        {
            (*map)[config->size_x / 2 - 2][x + config->size_y - 9] = MAP_LIMITE; // haut
            (*map)[config->size_x / 2 - 2][y + config->size_y - 8] = SAFE_ZONE;
            (*map)[config->size_x / 2 - 1][y + config->size_y - 8] = SAFE_ZONE;

            (*map)[config->size_x / 2 + 2][x + config->size_y - 9] = MAP_LIMITE; // bas
            (*map)[config->size_x / 2 + 2][y + config->size_y - 8] = SAFE_ZONE;
            (*map)[config->size_x / 2 + 1][y + config->size_y - 8] = SAFE_ZONE;

            (*map)[x + config->size_x / 2 - 2][config->size_y - 9] = MAP_LIMITE; // gauche x
            (*map)[y + config->size_x / 2 - 1][config->size_y - 9] = SAFE_ZONE;
            (*map)[y + config->size_x / 2 - 1][config->size_y - 8] = SAFE_ZONE;

            (*map)[x + config->size_x / 2 - 2][config->size_y - 5] = MAP_LIMITE; // droite x
            (*map)[y + config->size_x / 2 - 1][config->size_y - 5] = SAFE_ZONE;
            (*map)[y + config->size_x / 2 - 1][config->size_y - 6] = SAFE_ZONE;
            y++;
        }
        x++;
    }
    x = 0;
    while (x <= 2)
    {
        (*map)[config->size_x / 2 + 1][x+3] = SAFE_ZONE;
        (*map)[config->size_x / 2 - 1][x+3] = SAFE_ZONE;
        (*map)[x + config->size_x/ 2 - 1][5] = SAFE_ZONE;
        (*map)[x + config->size_x/ 2 -1][3] = SAFE_ZONE;
        x++;
    }
}

void setup_map_memory(char ***map, Config *config)
{
    int i = 0;

    *map = malloc(sizeof(char*) * config->size_x);
    if (*map == NULL) {
        fprintf(stderr, "Erreur lors de l'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }

    while (i < config->size_x) {
        (*map)[i] = malloc(sizeof(char) * config->size_y + 1);
        if ((*map)[i] == NULL) {
            fprintf(stderr, "Erreur lors de l'allocation de mémoire.\n");
            exit(EXIT_FAILURE);
        }

        int j = 0;
        while (j < config->size_y) {
            (*map)[i][j] = ' ';
            j++;
        }
        (*map)[i][j] = '\0'; 
        i++;
    }
    setup_map_struct(map, config);
}

void setup_config(Config *config)
{
    config->size_x = 26;
    config->size_y = 42;
    int check = 0;
    char rep[6];
    while (check == 0)
    {
        printf("quel mode de difficulté maggle? [easy,normal,hard] || tapez [size] pour donner une taille de map perso. pair uniquement, et pas en dessous de 20 sur 20\n");
        scanf("%s", rep);
    
        if(ft_strcmp(rep,"size") == 0)
        {
            {
                printf("Entrez la taille x : ");
                scanf("%d", &(config->size_x));
                printf("Entrez la taille y : ");
                scanf("%d", &(config->size_y));
            }
            printf("quel mode de difficulté maggle? [easy,normal,hard] || tapez [size] pour donner une taille de map perso. pair uniquement, et pas en dessous de 20 sur 20\n");
            scanf("%s", rep);
        }
    
        if(ft_strcmp(rep,"easy") == 0)
        {
            config->numb_of_pute = 40;
            check = 1;
        }
    }
    printf("pute :%d taille x %d y %d\n", config->numb_of_pute, config->size_x, config->size_y);
}

void setup_game(char ***map, Player *player, Config *config)
{
    setup_config(config);
    setup_map_memory(map, config);
    player_spawn(map, player, config);
    girflfriend_spawn(map, config);
}