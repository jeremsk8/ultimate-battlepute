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

struct Pute *creatPute (int x, int y, int id)
{
  Pute *newPute = malloc (sizeof (Pute));
  newPute->coord_x = x;
  newPute->coord_y = y;
  newPute->id = id;
  newPute->next = NULL;
  return newPute;
}

void pushPute (Pute **head, int x, int y, int id)
{
  Pute *newpute = creatPute (x, y, id);
  if (*head == NULL)
	{
	  *head = newpute;
	  return;
	}
  Pute *current = *head;
  while (current->next != NULL)
	{
	  current = current->next;
	}
  current->next = newpute;
}

void coord_generator(char ***map, int *x, int *y, Config *config)
{
  srand (time (NULL));
  do
	{
	  *x = rand () %  (config->size_x - 2) + 1;		
	  *y = rand () % (config->size_y - 2) + 1;
	}
  while ((*map)[*x][*y] != ' ');
}