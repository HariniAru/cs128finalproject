## Maze Game - Wonderful Group 100

### How the game works

Our game can be compiled with the command "clang++ -std=c++20 ./maze_game.cpp -lncurses" and run with "./a.out".

Our maze game has 2 game options: a hidden maze (Hidden Maze) and a navigatable maze (Maze Runner). The player will first be shown a menu displaying these two options and be asked to choose by using the up and down arrow keys to make a selection and pressing 'enter' when they have done so. The player will then be taken to a window displaying the game that they have chosen.

**Hidden Maze**
There is a map (graph) for the game, but it's hidden, and the player cannot see it. There are 8 nodes, connects with 11 edges. The player can move from one node to another through edges. If there is no edge between two nodes, the player cannot move between these two nodes.

Below is a map of our game (the player cannot see it!):
1. Each 'o' represents the position the player can move to, which is a node. At the start, the play will be at o0. The player can only travel through the edge.
             
             o9- o7  -  o8 - o11
             | / | \\   / | / |
             o5  o4- o6-o15- o10
             | / | \\ |   |   |
             o1  o2  o3-o12- o13
              \\  |  /    |  /
                 o0  -  o14
                     
2. There will be some coins at some nodes, some traps on some nodes, a boss at a node who can kill the player, and some bats on some nodes which can take the player to a random node.
3. The player has 3 arrows, which are used to kill the boss. Because the graph is hidden, the player doesn't know exactly where the boss will be. If the player shoots an arrow and hits the boss, the boss will die; if the player missed the shot, then the boss will escape to other nodes at random. (The player has to shoot in the correct direction where the boss stays. One arrow can kill the boss, but the player has three chances)

Two ways to win the game:
1. Having 5 coins in total to win the game. In the beginning, the player has 3 coins at the start. To win the game, the player must have 5 coins in total.  Each move will cost the player 1 coin! On some nodes, there will be some coins. If the player has 5 coins in total, the player wins! So the player has to be wiser at every move!
2. Kill the boss. if the player uses arrows to shoot the boss and accurately hit the boss, the boss dies and the player wins! I use "accurate hit" because there are different directions the player can choose to shoot. If the player missed the shot, the boss will not die and will flee to other nodes at random.

Three ways to lose:
1. If the player uses up his coins, the player loses! 
2. If the player goes to a node where the boss stays, the boss will eat the player and the player lose!
3. if the player goes to a node that has a trap on it, the player will lose!

Other features:

There will be some bats on some nodes. If the player meets a bat, a bat can take the player to a random node (may take the player to a node with a trap, or take the player to a node with some coins).

**Navigable Maze (Maze Runner)**
If the player selects the 'Maze Runner' option, the player will be instructed on how to play the game and then be prompted to press 'b' to begin the game. The game itself basically allows the player to move through a maze using arrow keys. The goal is to exit the large maze, by reaching any of the four borders.

The maze layout is generated randomly (we implemented a randomizer maze algorithm using a modified Prim's algorithm common in maze generation) so that each time the player clicks on the Navigable Maze option, they get to explore a different maze generated instantly. Here is an example maze layout (very simple, larger in the real game): 


|+++++++##++++++##+|

|+#+###++++##+#++++|

|+#+#+#+#+##+++#+##|

|+++++++#@#++#+#+++|

|#+#+####+#+##+++#+|

|++#++++#+#+++#+##+|

|+###+#+++###++++#+|

|+++++#+#+++++##+++|


*Note that the '+' character represents a space, but in the actual game the actual space character ' ' is used so it would look more like a maze.

The player would be notified that they successfully navigated the maze only if they were able to move their character ('@') to reach any of the four borders of the maze. 

### Executive summary of the proposed project

How does the player interact with the game?
This is a command-line game, so all of the game is played within the console itself. 

For Hidden Maze:
- When the player is trying the next move, there will be options for the player prompted out in the command line, which asks the player which direction to go. The player only needs to type the directions in the command line, and the player will go to the next position.
- When the player gets closer to a boss, the command line will prompt out "there is a boss around, which direction do you want to shoot arrows?" Then the player can type in which directions to shoot the boss.

For Navigable Maze:
- As the player must use arrow keys to move through the maze, our program makes use of keyboard events. 
The player can press 'q' at any point to quit the game. 

Data Structure and Libraries:
1. We will mainly utilize arrays, vectors, and maps to store our maze templates. 
2. We will use the libraries:
<iostream> <string> <vector> <map> <cstdlib> <time.h> <math.h> <sstream> <ncurses.h> <stdio.h>
  
  The <ncurses.h> library is particularly important to our project as it allows us to display windows and draw our game on these windows. It also helps us handle key events. Throughout the process of project development, we have discovered that this library allows us to implement console and audio interfaces which display our game in a more visually appealing fashion, and to make the playing experience more intuitive. 
 
### Functions and variables needed to implement
  
player class:
1. player()
    the default constructor. we set the coins to 3, set the arrows to 3.
2. ~player()
    destructor
3. void setLocation(location* l)
    set the location of the player
4. void playerMove()
    in the command line we type in which directions to move, and this function will manipulate the player's position.
5. location* getLocation()
    return the current location
6. int getArrows()
    know how many arrows the player has
7. void setArrows(int a)
    after shooting, minus 1 arrow
8. int getCoins()
    know how many coins the player has
9. void setCoins(int c)
    arrive some locations, pick up some coins.
10. location* shoot()
    the player uses his arrows to shoot the boss. The arrow number minus 1.

application class:
1. application()
    default constuctor.
2. ~application()
    default destructor.
3. void initAllLoc()
    initial the location.
4. vector<location*> getAllLoc()
    get all locations.
5. int getStatus()
    get the status of win or lose
6. void beingCarriedByBats()
    if the player meets a bats, the player will be taken to a random position.

location class:
1. location()
    default constructor
2. ~location()
    default destuctor
3. void addNeighbor(location* l, string direction)
    add a node to another. This are mainly used in driver.cc
4. void setCoins(int c)
    coins pick up by player, and the coins in this position become 0.
5. void setType(int t)
    set the types of the node.
    there are 6 types:
    0- normal location
    1- traps
    2- bats
    3- boss
    4- traps and boss
    5- bats and boss
6. map<string, location*> getNeighbors()
    return the neighbor nodes of the current nodes.
7. int getCoins()
    return the coin number
8. void escape()
    if there is a boss, the boss escape to other position if the player missed a shot
  
navigable maze class:
1. WINDOW *create_window(int height, int width, int starty, int startx);
  to create windows for game
2. void delete_window(WINDOW *local_win);
  deletes the window
3. void run_game();
  runs the navigable maze game
4. bool you_won = false;
  determines whether the player won or not at the end
5. void run_navigatable_maze();
  displays the navigatable maze
void print_instructions();
  prints out instructions for the player on how to play the navigable maze game

game options class:
1. int startx, starty = 0;
  determines the starting x and y positions of the window
2. char *choices[] = { (char*)"Hidden Maze", (char*)"Navigatable Maze"};
  contains the array of game choices that will be displayed to the player 
3. int n_choices = sizeof(choices) / sizeof(char *);
  stores the number of game choices
4. void print_menu(WINDOW *menu_win, int highlight);
  prints the menu with the game options for the user to choose
  
### Team plan for completing the work

Our team will first work on the fundamental implementation of a maze structure in C++, likely a multidimensional array that represents the possible positions players can take. 

Yu He will implement the Hidden Maze game using maps and vectors.
Harini Arumugam will utilize the ncurses library to develop the visual structure of the game as well as implement the basic structure of the nagivatable maze game.
Kirk Shen Leck will implement a maze randomizer algorithm to randomize the maze layout for the navigable maze game. 

Yu and Harini will write catch2 test cases for our game.
