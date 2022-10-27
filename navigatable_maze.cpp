#include <ncurses.h>
#include <iostream>
#include "mazegenerator.cpp"
using namespace std;

WINDOW *create_window(int height, int width, int starty, int startx);
void delete_window(WINDOW *local_win);
void run_game();
bool you_won = false;
void run_navigatable_maze();
void print_instructions();
char to_check = ' ';
bool game_over = false;
bool kl, kr, ku, kd = false;

//Maze template - needs to be randomized
const int ROW = 30;
const int COL = 80;
// const int END_ROW = ROW - 2;
// const int END_COL = COL - 2;
std::vector<std::vector<char>> maze = generatemaze(ROW, COL);

// char maze[ROW][COL] = {
// {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
// {'#',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ','#'},
// {'#',' ','#',' ','#','#','#',' ',' ',' ',' ','#','#',' ','#',' ',' ',' ',' ','#'},
// {'#',' ','#',' ','#',' ','#',' ','#',' ','#','#',' ',' ',' ','#',' ','#','#','#'},
// {'#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ','#',' ','#',' ',' ',' ','#'},
// {'#','#',' ','#',' ','#','#','#','#',' ','#',' ','#','#',' ',' ',' ','#',' ','#'},
// {'#',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#',' ','#','#',' ','#'},
// {'#',' ','#','#','#',' ','#',' ',' ',' ','#','#','#',' ',' ',' ',' ','#',' ','#'},
// {'#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#','#',' ',' ',' ','#'},
// {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
// };
int x = ROW/2, y = COL/2;

//runs the navigatable maze game
void run_navigatable_maze()
{
    run_game();
	endwin();
}

//creates a new window
WINDOW *create_window(int height, int width, int starty, int startx)
{	
    WINDOW *local_win;
    starty = 0;
    startx = 0;
	local_win = newwin(height, width, 0, 0);
	return local_win;
}

//displays the maze and tracks user keyboard events
void run_game()
{
    WINDOW *my_win;
	int startx, starty, width, height;
    height = 0;
    width = 0;
	int ch = 0;

    
    you_won = true;

    //setting up window screen
	initscr();			
	cbreak();			
	keypad(stdscr, TRUE);		
	starty = 1;	
	startx = 1;	
	//printw("Press F1 to exit");
	refresh();
	my_win = newwin(20, 10, 0, 0);
    // maze[END_ROW][END_COL] = 'X';
    maze[x][y] = '@';

    //printing instructions
    int spacing = 0;
    mvprintw(0, spacing, "Welcome to the Maze Runner Game!");
    mvprintw(1, spacing, "Use the arrow keys to move through the maze.");
    mvprintw(2, spacing, "To win, exit the maze through any of its four borders.");
    mvprintw(3, spacing, "Press 'b' to begin. Good luck!");
    refresh();

    while((ch = getch()) != 'b')
    {
        to_check = ch;
        if (ch == 'q')
        {
            game_over = true;
            you_won = false;
            return;
        }
    }
    wclear(my_win); //clears window

    //printing out maze
    for(int i = 0; i < ROW; i++)
    {
        int j;
        for(j = 0; j < COL; j++)
        {
            mvprintw(i, j, &maze[i][j]);
        }
        mvprintw(i, j, "\n");
    }
    move(x, y);

    //keyboard input - moving the player
    while((ch = getch()) != 'q')
	{	 
        to_check = ch;
        if (ch == KEY_LEFT)
        {
            kl = true;
            if(y - 1 >= 0 && maze[x][y - 1] != '#')
            {
                int prevy = y;
                y--;
                maze[x][prevy] = ' ';
                if ((x == 0 || y == 0) || (x == ROW-1 || y == COL-1)) 
                    return;
            }
        }
		else if (ch == KEY_RIGHT)
        {
            kr = true;
            if(y + 1 >= 0 && maze[x][y + 1] != '#')
            {
                int prevy = y;
                y++;
                maze[x][prevy] = ' ';
                if ((x == 0 || y == 0) || (x == ROW-1 || y == COL-1))
                    return;
            }
        }
        else if (ch == KEY_UP)
        {
            ku = true;
            if(x - 1 >= 0 && maze[x - 1][y] != '#')
            {
                int prevx = x;
                x--;
                maze[prevx][y] = ' ';
                if ((x == 0 || y == 0) || (x == ROW-1 || y == COL-1))
                    return;
            }
        }
		else if (ch == KEY_DOWN)
        {
            kd = true;
            if(x + 1 >= 0 && maze[x + 1][y] != '#')
            {
                int prevx = x;
                x++;
                maze[prevx][y] = ' ';
                if ((x == 0 || y == 0) || (x == ROW-1 || y == COL-1))
                    return;
            }
		}

        //reprinting maze window
        my_win = newwin(20, 10, 0, 0);
        maze[x][y] = '@';
        for(int i = 0; i < ROW; i++)
        {
            int j;
            for(j = 0; j < COL; j++)
            {
                mvprintw(i, j, &maze[i][j]);
            }
            mvprintw(i, j, "\n");
        }
        move(x, y);
	}
    to_check = ch;
    game_over = true;

    //didn't return/break out
    you_won = false;
}

// void print_instructions()
// {
//     WINDOW *instructions_window;
// 	int startx, starty, width, height;
//     startx = 0;
//     starty = 0;
//     width = 0;
//     height = 0;


//     //setting up window screen
// 	initscr();			
// 	cbreak();			
// 	keypad(stdscr, TRUE);		
// 	// starty = 1;	
// 	// startx = 1;	
// 	//printw("Press F1 to exit");
// 	refresh();
// 	instructions_window = newwin(20, 10, 0, 0);
//     // maze[END_ROW][END_COL] = 'X';
//     // maze[x][y] = '@';

//     //printing instructions
//     int spacing = 0;
//     mvprintw(0, spacing, "Welcome to Maze Runner!");
//     mvprintw(1, spacing, "Use the arrow keys to move through the maze.");
//     mvprintw(2, spacing, "To win, find the end of the maze. This position is marked with an X.");
//     mvprintw(3, spacing, "Press ENTER to begin. Good luck!");
//     refresh();

    
//     // endwin();
//     // wclear(instructions_window);
//     // delete_window(instructions_window);

//     run_game();
// }

//deletes window
void delete_window(WINDOW *local_win)
{	
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}
