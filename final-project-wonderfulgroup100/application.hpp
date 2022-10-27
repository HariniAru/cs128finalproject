#pragma once

#include "location.hpp"
#include <vector>
#include "player.hpp"
using namespace std;
class application
{
private:
    vector<location*> allLoc;
    int status; //whether win or lose
    player p;
    location* bossLoc;
public:
    application(/* args */);
    ~application();
    void initAllLoc();
    vector<location*> getAllLoc();
    int getStatus();
    void beingCarriedByBats(); // if the player meets a bats, the player will be taken to a random position.
    location* getBossLoc();
    void runningGame();
    int checklost(); 
    void printStatus();
    bool checkBossNearby();
};

