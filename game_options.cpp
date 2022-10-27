#include <stdio.h>
#include <ncurses.h>

int startx = 0;
int starty = 0;

//METHOD DEFINITIONS
//choices array (for menu)
char *choices[] = { (char*)"Hidden Maze", (char*)"Maze Runner"};
int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);

void print_menu(WINDOW *menu_win, int highlight)
{
	int x = 2, y = 2, i;	
	box(menu_win, 0, 0); //draws box

	for(i = 0; i < n_choices; ++i)
	{	
		if(highlight == i + 1) //highlights the current choice
		{	
			wattron(menu_win, A_REVERSE); 
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else //prints out the choice
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}

	wrefresh(menu_win); //refreshes window
}
