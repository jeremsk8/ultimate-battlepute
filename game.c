#include  "Headers/fonctions.h"
#include  "Headers/define.h"

void display_map(char **map)
{
    int i = 0;
    int y = 0; 
    clear(); 
    while (map[i] != NULL) {
        int j = 0;
        int x = 0; 

        while (map[i][j] != '\0') {
            mvprintw(y, x, "%c", map[i][j]);
            x+=2; 
            j++;
        }

        y++; 
        i++;
    }
    refresh();
}

void *player_move(void *args)
{
    Player_Args *player_args = (Player_Args *)args;
    Player *player = player_args->player;
    char ***map = player_args->map;
    Config *config = player_args->config;
    int ch;
    while (1)
    {
        ch = getch();
        if (ch == 'a')
            pthread_exit(NULL);
        (*map)[player->coord_x][player->coord_y] = ' ';
        setup_map_struct(map, config);
        switch (ch)
        {
        case UP:
            player->coord_x--;
            if (check((*map)[player->coord_x][player->coord_y], 1))
                player->coord_x++;
            break;
        case DOWN:
            player->coord_x++;
            if (check((*map)[player->coord_x][player->coord_y], 1))
                player->coord_x--;
            break;
        case LEFT:
            player->coord_y--;
            if (check((*map)[player->coord_x][player->coord_y], 1))
                player->coord_y++;
            break;
        case RIGHT:
            player->coord_y++;
            if (check((*map)[player->coord_x][player->coord_y], 1))
                player->coord_y--;
            break;
        }
        (*map)[player->coord_x][player->coord_y] = PLAYER;
    }
    free(player_args);
}

void *pute_move(void *args)
{
    char ***map;
    int x;
    int y;
    Pute_args *putes_args = (Pute_args *)args;
    Pute *current = putes_args->pute;
    Pute *head = putes_args->pute;
    map = putes_args->map;
    while (1)
    {
        while (current != NULL)
        {
            if ((*map)[current->coord_x][current->coord_y] != PLAYER)
                (*map)[current->coord_x][current->coord_y] = ' ';
            int direction = rand() % 4;
            x = current->coord_x;
            y = current->coord_y;
            switch (direction)
            {
            case 0: // haut
                case_move(map, &x, &y, 0, 1);
                break;
            case 1: // bas
                case_move(map, &x, &y, 1, 1);
                break;
            case 2: // gauche
                case_move(map, &x, &y, 0, 0);
                break;
            case 3: // droite
                case_move(map, &x, &y, 1, 0);
                break;
            default:
                break;
            }
            current->coord_x = x;
            current->coord_y = y;
            (*map)[x][y] = PUTE;
            current = current->next;
        }
        current = head;
        usleep(600000);
    }
    free(putes_args);
}

void create_player_thread(Entity *entity, char ***map, Config *config) {
    pthread_t player_thread;
    Player_Args *player_args = (Player_Args *)malloc(sizeof(Player_Args));
    player_args->player = entity->player;
    player_args->map = map;
    player_args->config = config;
    pthread_create(&player_thread, NULL, player_move, (void *)player_args);
}

void create_pute_thread(Entity *entity, char ***map)
{
    pthread_t putes_thread;
    Pute_args *putes_args = (Pute_args *)malloc(sizeof(Pute_args));
    putes_args->pute = entity->pute;
    putes_args->map = map;
    pthread_create(&putes_thread, NULL, pute_move,(void *)putes_args);
}

int checkpos(Player *player, char **map)
{
    int x;
    int y;

    x = player->coord_x;
    y = player->coord_y;
    if (map[x][y] == PUTE)
        return 0;
    else    
        return 1;
}

void game(char **map, Entity *entity, Config *config) {
    //int check = 1;
    create_player_thread(entity, &map, config);
    create_pute_thread(entity,&map);
    while (checkpos(entity->player, map)) {
        //check = checkpos(entity->player, map);
        display_map(map);
        usleep(10000);
    } 

    clear();
}