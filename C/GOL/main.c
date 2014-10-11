#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>
#include <time.h>

struct coordinates
{
  int x,y;
};

void draw_borders(WINDOW *screen)
{
  int x, y, i;
  getmaxyx(screen, y, x);

  // 4 corners
  mvwprintw(screen, 0, 0, "+");
  mvwprintw(screen, y - 1, 0, "+");
  mvwprintw(screen, 0, x - 1, "+");
  mvwprintw(screen, y - 1, x - 1, "+");
  
  // sides
  for (i = 1; i < (y - 1); i++) {
    mvwprintw(screen, i, 0, "|");
    mvwprintw(screen, i, x - 1, "|");
  }
  
  // top and bottom
  for (i = 1; i < (x - 1); i++) {
    mvwprintw(screen, 0, i, "-");
    mvwprintw(screen, y - 1, i, "-");
  }
}

void draw_game_field(WINDOW* screen, short **game_field, struct coordinates game_field_size, struct coordinates cursor, int show_cursor)
{
  int i,j;
  for(i = 0; i < game_field_size.x; i++)
  {
    for(j = 0; j < game_field_size.y; j++)
    {
      if(game_field[j][i] == 0)
        wattron(screen, COLOR_PAIR(1));
      else
        wattron(screen, COLOR_PAIR(2));
      mvwprintw(screen, j+1, i+1, " ");
    }
  }

  if (show_cursor)
  {
    wattron(screen, COLOR_PAIR(3));
    mvwprintw(screen, cursor.y,cursor.x, " ");
  }
  wrefresh(screen);
}

void generate_initial_field(short** game_field, struct coordinates size)
{
  int max = (size.x * size.y)/10;
  int i, rand_x, rand_y;

  srand(time(NULL));
  for(i = 0; i < max; i++)
  {
    rand_x = rand() % size.x;
    rand_y = rand() % size.y;
    if (rand_x == 0 || rand_x == size.x-1 || rand_y == 0 || rand_y == size.y-1)
      continue;
    game_field[rand_y][rand_x] = 1;
  }
}

void calc_next_gen(short** game_field, short** game_field_2, struct coordinates game_field_size)
{
  int i,j,x,y, count;

  for(i = 1; i < game_field_size.x-1; i++)
  {
    for(j = 1; j < game_field_size.y-1; j++)
    {
      count = 0;
      for (x=-1;x<=1;x++)
      {
        for (y=-1;y<=1;y++)
        {
          if (y==0 && x==0)
            continue;
          if(game_field[j+x][i+y] == 1)
            count++;
        }
      }
      game_field_2[j][i] = (count == 3 || (count == 2 && game_field[j][i]));
    }
  }
}

int main(int argc, char **argv)
{
  // Initialize variables
  int i, custom_game = 0;
  int c;
  struct coordinates cursor;
  struct coordinates screen_size;
  struct coordinates game_field_size;
  short **game_field;
  short **game_field_2;
  short **game_field_swap;

  // Initialize ncurses stuff
  initscr();
  noecho();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_BLACK);
  init_pair(2, COLOR_BLACK, COLOR_YELLOW);
  init_pair(3, COLOR_BLACK, COLOR_RED);

  getmaxyx(stdscr, screen_size.y, screen_size.x);
  game_field_size.x = screen_size.x-2;
  game_field_size.y = screen_size.y-5;

  game_field = (short**)calloc(game_field_size.y, sizeof(short*));
  for(i = 0; i<game_field_size.y; i++)
  {
    game_field[i] = (short*)malloc(game_field_size.x*sizeof(short));
    memset(game_field[i], 0, sizeof(short)*game_field_size.x);
  }

  game_field_2 = (short**)calloc(game_field_size.y, sizeof(short*));
  for(i = 0; i<game_field_size.y; i++)
  {
    game_field_2[i] = (short*)malloc(game_field_size.x*sizeof(short));
    memset(game_field_2[i], 0, sizeof(short)*game_field_size.x);
  }


  // set up initial windows
  WINDOW *field = newwin(screen_size.y - 3, screen_size.x, 0, 0);
  WINDOW *score = newwin(3, screen_size.x, screen_size.y - 3, 0);

  // draw borders on each window
  draw_borders(field);
  draw_borders(score);
  
  // refresh each window
  refresh();
  wrefresh(field);
  wrefresh(score);

  timeout(-1);
  cursor.x = 1;
  cursor.y = 1;
  // game of life loop
  while(1)
  {
     draw_game_field(field, game_field, game_field_size, cursor, 1);
     c = getch();
     if (c == KEY_UP && cursor.y > 1)
       cursor.y--;
     else if (c == KEY_DOWN && (cursor.y < game_field_size.y))
       cursor.y++;
     else if (c == KEY_LEFT && cursor.x > 1)
       cursor.x--;
     else if (c == KEY_RIGHT && (cursor.x < game_field_size.x))
       cursor.x++;
     else if (c == KEY_BACKSPACE)
     {
       game_field[cursor.y-1][cursor.x-1] = 1;
       custom_game = 1;
     }
     else if (c == 27) 
       break;
  }

  if (!custom_game)
    generate_initial_field(game_field, game_field_size);

  timeout(200);
  while(1)
  {
    c = getch();
    if (c==27)
        break;

    draw_game_field(field, game_field, game_field_size, cursor, 0);
    calc_next_gen(game_field,game_field_2, game_field_size);
    game_field_swap = game_field_2;
    game_field_2 = game_field;
    game_field = game_field_swap;
  }

  for(i = 0; i < game_field_size.y; i++)
  {
    free(game_field[i]);
  }
  free(game_field);
  for(i = 0; i < game_field_size.y; i++)
  {
    free(game_field_2[i]);
  }
  free(game_field_2);
  delwin(field);
  delwin(score);
  endwin();

  return 0;
}
