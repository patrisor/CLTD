#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>

/* * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * *  HEADER * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * */

#define GRID_HEIGHT 15
#define GRID_WIDTH 15

typedef struct s_player
{
  int x;
  int y;
  int id;
  char *name;
}              t_player;

/* * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * AUX * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * */

void garbage_collect(int ***g, t_player **p)
{
  for(int i = 0; i < GRID_HEIGHT; i++)
    free((*g)[i]);
  free(*g);
  free(*p);
}

int strlen(char *str)
{
  int ret;

  ret = 0;
  while(str[ret])
    ret++;
  return(ret);
}

/* * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * MAP * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * */

int **initGrid()
{
  int **ret;

  if ((ret = (int **)malloc(sizeof(int*) * GRID_HEIGHT)) == NULL)
    return(NULL);
  for(int i = 0; i < GRID_HEIGHT; i++)
  {
    ret[i] = (int *)malloc(sizeof(int) * GRID_WIDTH);
    for (int j = 0; j < GRID_WIDTH; j++)
      ret[i][j] = 0;
  }
  return(ret);
}

// TODO: Update
void printGrid(int **grid)
{
  for(int r = 0; r < GRID_HEIGHT; r++)
  {
    for(int c = 0; c < GRID_WIDTH; c++)
      printf("%d ", grid[r][c]);
    printf("\n");
  }
}

/* * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * *  PLAYER * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * */

t_player *initPlayer(char *name)
{
  t_player *ret;

  ret = (t_player *)malloc(sizeof(t_player));
  ret->x = GRID_WIDTH / 2;
  ret->y = GRID_HEIGHT / 2;
  ret->id = 1;
  ret->name = name;
  return(ret);
}

static char *promptName()
{
  static char ret[20];

  printf("Hello, what is your player's name?\n");
  fgets(ret, 20, stdin);
  return(ret);
}

/* * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * MAIN* * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * */

static char *input(char *prompt)
{
  static char ret[20];

  printf("%s\n", prompt);
  fgets(ret, 20, stdin);
  return(ret);
}

static char *processInput(char *prompt)
{
  static char ret[20];

  while(1)
  {
    ret = input(prompt);
    break
  }
  return(ret);
}

int render(int **grid, t_player *player)
{
  char *inp;

  while(1)
  {
    printGrid(grid);
    inp = processInput("Move with W, A, S, and D");

    printf("SIZE: %d", strlen(inp));
    break;
  }
  return(0);
}

int main(void) 
{
  int **grid;
  t_player *player;

  if (((grid = initGrid()) == NULL) || ((player = initPlayer(promptName())) == NULL))
    return(-1);
  render(grid, player);
  garbage_collect(&grid, &player);
  return 0;
}
