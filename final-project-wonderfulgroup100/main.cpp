#include "location.hpp"
#include "player.hpp"
#include "application.hpp"
#include <vector>
using namespace std;
#include <iostream>

// void run_hidden_maze();
// int main() {
//     //cout << "hello world" << endl;
//     application app;
//     app.runningGame();
//     return 0;
// }

// void run_hidden_maze()
// {
//     application app;
//     app.runningGame();
//     //return;
// }


// #include "location.hpp"
// #include "player.hpp"
// #include "application.hpp"
// #include <vector>
// using namespace std;
// #include <iostream>

// int main() {
//     //cout << "hello world" << endl;
//     application app;
//     app.runningGame();
//     return 0;
// }

//////////////////////////////////////
// #include <ncurses.h>
// #include <time.h>
// #include <iostream>
// #include <string>

// #include "location.cpp"
// #include "player.cpp"
// #include "application.cpp"

// #include "game_options.cpp"
// #include "navigatable_maze.cpp"
// //#include "main.cpp"

// #include <vector>
// using namespace std;
// #include <iostream>

// enum class GameType { GAME1, GAME2 };

// const char WIDTH = 20, HEIGHT = 10;

// //method definitions
// void PrintMaze(WINDOW* menu_win);
// void PlayerAction(char action, WINDOW* menu_win);
// void RandomizePlayerStartingLocation();
// int randomgen(int max, int min);  // Pass in range
// //void render(WINDOW* win);
// void prompt_game_type(WINDOW* menu_win);
// void draw_maze(GameType d);
// void draw_game(GameType g);

// //main method
// int main() 
// {
//   WINDOW* options_window;

//   //initializes window 
//   initscr();
//   clear();
//   noecho();
//   cbreak(); 

//   //setting up window size
//   startx = (80 - WIDTH) / 2;
//   starty = (24 - HEIGHT) / 2;
//   options_window = newwin(HEIGHT, WIDTH, starty, startx);
//   keypad(options_window, TRUE);

//   //prints out intro message
//   mvprintw(0, 0, "Welcome to the Maze Game!"); 
//   mvprintw(1, 0, "Please choose a game to play.");
//   mvprintw(2, 0, "Press 'q' at any point to quit the game.");
//   refresh();

//   prompt_game_type(options_window);

//   endwin();

//     //if user successfully navigated maze
//     if (you_won == true)
//         std::cout << "\n\nYou successfully navigated the maze.";
//     //ending message
//     std::cout << "\n\nThanks for playing!\n\n" << std::endl;

//   return 0;
// }

// //asks user to choose game type
// void prompt_game_type(WINDOW* menu_window) 
// {
//   int highlight = 1;
//   int choice = 0;
//   int key_pressed;

//   print_menu(menu_window, highlight);

//   GameType game_choice = GameType::GAME1;
//   while ((key_pressed = wgetch(menu_window)) != 10) //while user's key input is not enter
//   {
//     if (key_pressed == 113)
//       return;
//     if (key_pressed == KEY_UP)  // up arrow
//     {
//       if (highlight == 1)
//         highlight = n_choices;
//       else
//         --highlight;
//     } 
//     else if (key_pressed == KEY_DOWN)  // down arrow
//     {
//       if (highlight == n_choices)
//         highlight = 1;
//       else
//         ++highlight;
//     } 
//     print_menu(menu_window, highlight);
//   }

//   //setting user's game choice
//   choice = highlight;
//   if (choice == 1)
//     game_choice = GameType::GAME1;
//   else if (choice == 2)
//     game_choice = GameType::GAME2;

//   //erase menu window
//   wclear(menu_window);
//   delete_window(menu_window);

//   draw_game(game_choice);
// }

// void draw_game(GameType g)
// {
//   if (g == GameType::GAME1) //hidden maze
//   {
//     endwin();
//     application app;
//     app.runningGame();
    
//   }
//   else //navigatable maze
//   {
//     run_navigatable_maze();
//   }
// }

