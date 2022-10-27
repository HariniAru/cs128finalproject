#pragma once

#include "location.hpp"
#include <map>
#include <string>
using namespace std;
class player
{
private:
    int arrows;
    int coins;
    location* loc;
public:
    player();
    ~player();
    void setLocation(location* l);
    void playerMove();
    location* getLocation();
    int getArrows();
    void setArrows(int a);
    int getCoins();
    void setCoins(int c);
    location* shoot();
};