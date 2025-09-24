# Maze Game

## Overview

This project is a command-line maze game with two distinct modes:

1. Hidden Maze – a graph-based maze where the map is invisible, filled with coins, traps, bats, and a boss.
2. Navigable Maze (Maze Runner) – a randomly generated maze the player must escape using arrow-key navigation.

The game combines randomness, resource management, and strategy, making each playthrough unique.

## How to Run

Compile and run with:

```sh
clang++ -std=c++20 ./maze_game.cpp -lncurses
./a.out
```

The menu will appear, allowing the player to choose between Hidden Maze and Maze Runner using the arrow keys and Enter.

## Game Modes

### Hidden Maze

* The maze is represented as a hidden graph with 8 nodes and 11 edges.
* The player starts at node `o0` and can only move along valid edges.
* Each move costs 1 coin. Players start with 3 coins.
* Nodes may contain:

  * Coins (collect to win)
  * Traps (instant loss)
  * Bats (teleport to a random node)
  * A boss (encountering it = death unless killed with arrows)

Win conditions:

* Collect at least 5 coins in total.
* Kill the boss by correctly shooting arrows in its direction (3 arrows available).

Lose conditions:

* Run out of coins.
* Step on a trap.
* Enter the boss’s node without killing it.

### Navigable Maze (Maze Runner)

* The maze is generated at runtime using a modified Prim’s algorithm, ensuring a new layout each playthrough.
* The player navigates using arrow keys.
* The goal is to reach any border of the maze to escape.
* The player can quit anytime by pressing `q`.

Example mini-maze (spaces shown as `+` here):

```
|+++++++##++++++##+|
|+#+###++++##+#++++|
|+#+#+#+#+##+++#+##|
|+++++++#@#++#+#+++|
```

`@` = player’s position

## Implementation Details

* Data Structures: arrays, vectors, maps
* Libraries Used:

  * `<iostream>`, `<string>`, `<vector>`, `<map>`
  * `<cstdlib>`, `<time.h>`, `<math.h>`, `<sstream>`
  * `<ncurses.h>` – used for windows, rendering, and handling key events

### Key Classes

* Player: manages coins, arrows, movement, and shooting
* Application: handles game state, locations, bats, and win/lose checks
* Location: represents maze nodes with types (normal, trap, bat, boss)
* Navigable Maze: generates and displays the maze using ncurses
* Game Options: builds the interactive menu

## Team Contributions

* Yu He implemented the Hidden Maze logic using maps and vectors.
* Harini Arumugam built the ncurses-based UI and implemented the foundation for the Navigable Maze.
* Kirk Shen Leck created the randomizer algorithm for generating maze layouts.
* Yu and Harini also wrote Catch2 test cases to validate functionality.
