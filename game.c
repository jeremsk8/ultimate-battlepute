#include  "Headers/fonctions.h"
#include  "Headers/define.h"

void display_map(char **map)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (map[i])
    {
        while (map[i][j])
        {
             printf("%c ", map[i][j]);
             j++;
        }
        printf("\n");
        j = 0;
        i++;
    }
}

void game(char **map)
{
    display_map(map);
}