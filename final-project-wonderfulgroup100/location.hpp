#pragma once

#include <vector>
#include <map>
#include <string>
using namespace std;
class location
{
private:
    map<string, location*> neighbors;
    int coins;
    int type;
public:
    location();
    ~location();
    void addNeighbor(location* l, string direction);
    void setCoins(int c);
    void setType(int t);
    int getType();
    map<string, location*> getNeighbors();
    int getCoins();
    location* escape(); // if there is a boss, the boss escape to other position if the player missed a shot
};

