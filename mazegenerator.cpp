#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <unistd.h>

std::vector<std::vector<char>> generatemaze(int height, int width);
void PrintMaze(std::vector<std::vector<char>> inp);
size_t check_h, check_w = 0;

// int main() {

//    std::vector<std::vector<char>> omaze = generatemaze(40, 20);
//     PrintMaze(omaze);
    
// }

// Reference: https://stackoverflow.com/questions/23843197/maze-generating-algorithm-in-grid

//Randomized Prim's algorithm:
//
//Start with a grid of filled cells.
//Pick a cell, mark it as part of the maze. Add the surrounding filled cells of the cell to the cell list.
//While there are cells in the list:
    //Pick a random cell from the list. If the cell doesn't have 2 cleared neighbours:
        //Clear the cell.
        //Add the neighbouring filled cells to the cell list.
    //Remove the cell from the list.

std::vector<std::vector<char>> generatemaze(int height, int width) {
    
    // height -= 2;
    // width -= 2;
    
    std::vector<std::vector<char>> maze;

    for (int i = 0; i < height; ++i) {
        std::vector<char> row;
        for (int i = 0; i < width; ++i) {
            row.push_back('#');
        }
        maze.push_back(row);
    }
    
    std::vector<std::pair<int, int>> ls;
    std::vector<std::pair<int, int>> seenls;
    std::vector<std::pair<int, int>> lscell;
   
    
    // Start first opening cell as cell (0, 0)
    maze[0][0] = ' ';
    lscell = {std::make_pair(0,1), std::make_pair(1,0)};
    for (auto a : lscell) {
        ls.push_back(a);
        seenls.push_back(a);
    }
    
    // Start second opening cell as cell (height-1, width-1)
    maze[height-1][width-1] = ' ';
    lscell = {std::make_pair(height-1,width-2), std::make_pair(height-2,width-1)};
    for (auto a : lscell) {
        ls.push_back(a);
        seenls.push_back(a);
    }
    
    
    int rh;
    int rw;
    int ctr;
    int ridx;
    std::string cstr;
    
    while (!ls.empty()) {
        
        ridx = rand() % ls.size();
        
        rh = ls[ridx].first;
        rw = ls[ridx].second;
        
        lscell = {};
        cstr = "";
        
//        PrintMaze(maze);
//        sleep(1);
//        std::cout << std::endl;
        
        if (rh == 0 && rw == 0) {  // TL Corner
            
            lscell = {std::make_pair(0,1), std::make_pair(1,0)};
            cstr += maze[0][1];
            cstr += maze[1][0];
            
        } else if (rh == 0 && rw == width - 1) { // TR Corner
            
            lscell = {std::make_pair(0,width-2), std::make_pair(1,width-1)};
            cstr += maze[0][width-2];
            cstr += maze[1][width-1];
            
        } else if (rh == height - 1 && rw == 0) {  // BL Corner
            
            lscell = {std::make_pair(height-2,0), std::make_pair(height-1,1)};
            cstr += maze[height-2][0];
            cstr += maze[height-1][1];
            
        } else if (rh == height - 1 && rw == width - 1) {  // BR Corner
            
            lscell = {std::make_pair(height-1,width-2), std::make_pair(height-2,width-1)};
            cstr += maze[height-2][width-1];
            cstr += maze[height-1][width-2];
            
        } else if (rh == 0) {  // T Edge
        
            lscell = {std::make_pair(0,rw-1), std::make_pair(0,rw+1), std::make_pair(1,rw)};
            cstr += maze[0][rw-1];
            cstr += maze[0][rw+1];
            cstr += maze[1][rw];
            
        } else if (rw == 0) {  // L Edge
            
            lscell = {std::make_pair(rh-1,0), std::make_pair(rh+1,0), std::make_pair(rh,1)};
            cstr += maze[rh-1][0];
            cstr += maze[rh+1][0];
            cstr += maze[rh][1];
            
        } else if (rh == height - 1) {  // B Edge
            
            lscell = {std::make_pair(height-1,rw-1), std::make_pair(height-1,rw+1), std::make_pair(height-2,rw)};
            cstr += maze[height-1][rw-1];
            cstr += maze[height-1][rw+1];
            cstr += maze[height-2][rw];
            
        } else if (rw == width - 1) {  // R Edge
            
            lscell = {std::make_pair(rh-1,width-1), std::make_pair(rh+1,width-1), std::make_pair(rh,width-2)};
            cstr += maze[rh-1][width-1];
            cstr += maze[rh+1][width-1];
            cstr += maze[rh][width-2];
            
        } else {
            
            lscell = {std::make_pair(rh-1,rw), std::make_pair(rh+1,rw), std::make_pair(rh,rw-1), std::make_pair(rh,rw+1)};
            cstr += maze[rh-1][rw];
            cstr += maze[rh+1][rw];
            cstr += maze[rh][rw-1];
            cstr += maze[rh][rw+1];

        }
        
        ctr = std::count(cstr.begin(), cstr.end(), ' ');
        
        ls.erase(ls.begin() + ridx);
        
        if (ctr < 2) {
            maze[rh][rw] = ' ';
            for (auto a : lscell) {
                if (std::count(seenls.begin(), seenls.end(), a) == 0) {
                    ls.push_back(a);
                    seenls.push_back(a);
                }
            }
        }
        
        
    }

    // for (size_t i = 0; i < maze.size(); ++i) {
    //     maze[i].insert(maze[i].begin(), '#');
    //     maze[i].push_back('#');
    // }

    // std::vector<char> toins = {};

    // for (int i = 0; i < width + 2; ++i) {
    //     toins.push_back('#');
    // }

    // maze.insert(maze.begin(), toins);
    // maze.insert(maze.end(), toins);
    
    return maze;

}

void PrintMaze(std::vector<std::vector<char>> inp) {
    
    size_t h = inp.size();
    size_t w = inp[0].size();

    check_h = h;
    check_w = w;
    
    for (size_t row = 0; row < h; row++)
    {
        for (size_t col = 0; col < w; col++)
        {
            std::cout << inp[row][col];
        }
        std::cout << std::endl;
    }
}
