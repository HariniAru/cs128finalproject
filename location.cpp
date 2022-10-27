#include "location.hpp"
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;
location::location() {
    type = 0;
    coins = 0;
}

int location::getType() {
    return type;
}

location::~location() {}

void location::addNeighbor(location* l, string direction) {
    neighbors[direction] = l;
}

void location::setCoins(int c) { // coins pick up by player, and the coins in this position become 0.
    this->coins = c;
}

location* location::escape() {
    srand(time(NULL));
    int index = rand() % neighbors.size();
    map<string, location*> :: iterator it;
    for (it = neighbors.begin(); it != neighbors.end(); it++) {
        if (index == 0) {
            return it->second;
        }
        index--;
    }
    return nullptr;
}
// there are 6 types:
//0- normal location
//1- traps
//2- bats
//3- boss
//4- traps and boss
//5- bats and boss

void location::setType(int t) { 
    this->type = t;
}

map<string, location*> location::getNeighbors() {
    return neighbors;
}
int location::getCoins() { 
  return coins;
}