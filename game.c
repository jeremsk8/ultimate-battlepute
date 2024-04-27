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

    //refresh(); 
}

void player_move(Player *player, char ***map, Config *config)
{
   
    int ch = getch();
    (*map)[player->coord_x][player->coord_y] = ' ';
    setup_map_struct(map, config);
     switch (ch) {
            case UP:
                    player->coord_x--;
                    if (check((*map)[player->coord_x][player->coord_y]))
                        player->coord_x++;
                break;
            case DOWN:
                    player->coord_x++;
                    if (check((*map)[player->coord_x][player->coord_y]))
                        player->coord_x--;
                break;
            case LEFT:
                    player->coord_y--;
                    if (check((*map)[player->coord_x][player->coord_y]))
                        player->coord_y++;
                break;
            case RIGHT:
                    player->coord_y++;
                    if (check((*map)[player->coord_x][player->coord_y]))
                        player->coord_y--;
                break;
        }
        (*map)[player->coord_x][player->coord_y] = PLAYER;

}

void pute_move(Pute *pute, Config *config, char ***map)
{
    Pute *current = pute;
    int x;
    int y;
    int tmp = 0;
    while (current != NULL)
    {
        (*map)[current->coord_x][current->coord_y] = ' ';
        int direction = rand() % 4;
        x = current->coord_x;
        y = current->coord_y;
        switch (direction)
        {
        case 0: // haut

            current->coord_x--;
            x--;
            if ((*map)[x][y] == PUTE || (*map)[x][y] == SAFE_ZONE || (*map)[x][y] == MAP_LIMITE || (*map)[x][y] == SMART_PUTE)
            {
                current->coord_x++;
                x++;
            }
            else if ((*map)[x][y] == BUSH)
            {
                while ((*map)[x][y] == BUSH)
                {
                    current->coord_x--;
                    x--;
                    tmp++;
                    if ((*map)[x][y] == SAFE_ZONE || (*map)[x][y] == MAP_LIMITE || (*map)[x][y] == PUTE || (*map)[x][y] == SMART_PUTE)
                    {
                        current->coord_x += (tmp + 1);
                        x += (tmp + 1);
                    }
                }
            }
            tmp = 0;

            break;
        case 1: // bas

            current->coord_x++;
            x++;
            if ((*map)[x][y] == PUTE || (*map)[x][y] == SAFE_ZONE || (*map)[x][y] == MAP_LIMITE || (*map)[x][y] == SMART_PUTE)
            {
                current->coord_x--;
                x--;
            }
            else if ((*map)[x][y] == BUSH)
            {
                while ((*map)[x][y] == BUSH)
                {
                    current->coord_x++;
                    x++;
                    tmp++;
                    if ((*map)[x][y] == SAFE_ZONE || (*map)[x][y] == MAP_LIMITE || (*map)[x][y] == PUTE || (*map)[x][y] == SMART_PUTE)
                    {
                        current->coord_x -= (tmp + 1);
                        x -= (tmp + 1);
                    }
                }
            }
            tmp = 0;

            break;
        case 2: // gauche

            current->coord_y--;
            y--;
            if ((*map)[x][y] == PUTE || (*map)[x][y] == SAFE_ZONE || (*map)[x][y] == MAP_LIMITE || (*map)[x][y] == SMART_PUTE)
            {
                current->coord_y++;
                y++;
            }
            else if ((*map)[x][y] == BUSH)
            {
                while ((*map)[x][y] == BUSH)
                {
                    current->coord_y--;
                    y--;
                    tmp++;
                    if ((*map)[x][y] == SAFE_ZONE || (*map)[x][y] == MAP_LIMITE || (*map)[x][y] == PUTE || (*map)[x][y] == SMART_PUTE)
                    {
                        current->coord_y += (tmp + 1);
                        y += (tmp + 1);
                    }
                }
            }
            tmp = 0;

            break;
        case 3: // droited
            current->coord_y++;
            y++;
            if ((*map)[x][y] == PUTE || (*map)[x][y] == SAFE_ZONE || (*map)[x][y] == MAP_LIMITE || (*map)[x][y] == SMART_PUTE)
            {
                current->coord_y--;
                y--;
            }
            else if ((*map)[x][y] == BUSH)
            {
                while ((*map)[x][y] == BUSH)
                {
                    current->coord_y++;
                    y++;
                    tmp++;
                    if ((*map)[x][y] == SAFE_ZONE || (*map)[x][y] == MAP_LIMITE || (*map)[x][y] == PUTE || (*map)[x][y] == SMART_PUTE)
                    {
                        current->coord_y -= (tmp + 1);
                        y -= (tmp + 1);
                    }
                }
            }
            tmp = 0;

            break;
        default:
            break;
        }
        (*map)[current->coord_x][current->coord_y] = PUTE;
        current = current->next;
    }
}

void game(char **map, Entity *entity, Config *config)
{
    while (map[2][2] != PLAYER)
    {
        display_map(map);
        printf("\n %d %d\n", entity->player->coord_x, entity->player->coord_y);
         player_move(entity->player, &map, config);
         pute_move(entity->pute,config,&map);
    }
}