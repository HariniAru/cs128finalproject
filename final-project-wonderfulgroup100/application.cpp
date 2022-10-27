#include "application.hpp"
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;

void application::runningGame() {
    initAllLoc();
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Game Start!" << endl;
    cout << "There are 16 locations, there are two traps, three bats and one boss." << endl;
    cout << "You will lose when you meet trap or boss." << endl;
    cout << "You will be taken to a random location if you meet a bat." << endl;
    cout << "You can shoot arrows to the location near you." << endl;
    cout << "You will win if your arrows hit the boss." << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Here is a map you can reference:" << endl;
    cout << "o9- o7  -  o8 - o11" << endl;
    cout << "| / | \\   / | / |" << endl;
    cout << "o5  o4- o6-o15- o10" << endl;
    cout << "| / | \\ |   |   |" << endl;
    cout << "o1  o2  o3-o12- o13" << endl;
    cout << " \\  |  /    |  /" << endl;
    cout << "    o0  -  o14" << endl;
    cout << "You are now in position o0" << endl;
    vector<location*> vec = getAllLoc();
    p.setLocation(vec[0]);
    while (getStatus() == 0) {
        printStatus();
        bool isNearBoss = checkBossNearby();
        if (isNearBoss) {
            cout << "Do you want to shoot the boss or move to other position?" << endl;
            cout << "Shoot (S) or Move (M)" << endl;
            string choice;
            cin >> choice;
            if (choice == "S") {
                location* l = p.shoot();
                if (l == bossLoc) {
                    cout << "Your arrow hit the boss! You win!" << endl;
                    status = 1;
                    break;
                } else {
                    cout << "You missed the shot! Boss escaped to another place!" << endl;
                    bossLoc = bossLoc->escape();
                    if (!bossLoc) {
                        bossLoc = vec[0];
                    }
                }
            } else if (choice == "M") {
                p.playerMove();
            }
        } else {
            p.playerMove();
        }
        status = checklost();
    }
}

bool application::checkBossNearby() {
    location* loc = p.getLocation();
    map<string, location*> mp = loc->getNeighbors();
    map<string, location*> :: iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        if (it->second == bossLoc) {
            cout << "Boss is near you!" << endl;
            return true;
        }
    }
    return false;
}

void application::printStatus() {
    cout << "--------------------------------------------------------------------" << endl;
    //cout << "You are now in Position" << p.getLocation() << endl;
    cout << "left coins: " << p.getCoins() << endl;
    cout << "left arrows: " << p.getArrows() << endl;
    cout << "--------------------------------------------------------------------" << endl;
}

int application::checklost() {
    if (p.getCoins() <= 0) {
        cout << "You lost! You run out of coins!" << endl;
        return 2; // 2 is lost
    }
    if (p.getArrows() <= 0) {
        cout << "You lost! You run out of arrows!" << endl;
        return 2; // 2 is lost
    }
    location* l = p.getLocation();
    if (l->getType() == 3 || l->getType() == 4 || l->getType() == 5) {
        cout << "You lost! You meet a boss!" << endl;
        return 2;
    }
    if (l->getType() == 1) {
        cout << "You lost! You meet a trap!" << endl;
        return 2;
    }
    if (l->getType() == 2) {
        beingCarriedByBats();
        return checklost();
    }
    return 0;
}
// there are 6 types:
//0- normal location
//1- traps
//2- bats
//3- boss
//4- traps and boss
//5- bats and boss

// if the player meets a bats, the player will be taken to a random position.
void application::beingCarriedByBats() {
    srand(time(NULL));
    int index = rand() % 7;
    location* loc = allLoc[index];
    p.setLocation(loc);
    cout << "A bat takes you to location" << index << endl;
} 

application::application() {
    //cout << "11111" << endl;
    status = 0;
    //cout << "2222" << endl;
}

application::~application() {}
            // o7 is bat
            // o4 is boss
            // o6 is trap
            // o1 has one coin
            // o2 has one coin
            // 
            //  o9- o7  -  o8 - o11
            //  | / | \   / | / |
            //  o5  o4- o6-o15- o10
            //  | / | \ |   |   |
            //  o1  o2  o3-o12- o13
            //   \  |  /    |  /
            //      o0  -  o14

void application::initAllLoc() {
    for (int i = 0; i < 16; i++) {
        location* L = new location();
        allLoc.push_back(L);
    }
    allLoc[0]->addNeighbor(allLoc[1], "NW");
    allLoc[0]->addNeighbor(allLoc[2], "N");
    allLoc[0]->addNeighbor(allLoc[3], "NE");
    allLoc[0]->addNeighbor(allLoc[14], "E");

    allLoc[1]->addNeighbor(allLoc[4], "NE");
    allLoc[1]->addNeighbor(allLoc[5], "N");
    allLoc[1]->addNeighbor(allLoc[0], "SE");

    allLoc[2]->addNeighbor(allLoc[0], "S");
    allLoc[2]->addNeighbor(allLoc[4], "N");

    allLoc[3]->addNeighbor(allLoc[4], "NW");
    allLoc[3]->addNeighbor(allLoc[6], "N");
    allLoc[3]->addNeighbor(allLoc[0], "SW");
    allLoc[3]->addNeighbor(allLoc[12], "E");

    allLoc[4]->addNeighbor(allLoc[1], "SW");
    allLoc[4]->addNeighbor(allLoc[7], "N");
    allLoc[4]->addNeighbor(allLoc[3], "SE");
    allLoc[4]->addNeighbor(allLoc[2], "S");
    
    allLoc[5]->addNeighbor(allLoc[1], "S");
    allLoc[5]->addNeighbor(allLoc[7], "NE");
    allLoc[5]->addNeighbor(allLoc[9], "N");

    allLoc[6]->addNeighbor(allLoc[3], "S");
    allLoc[6]->addNeighbor(allLoc[7], "NW");
    allLoc[6]->addNeighbor(allLoc[4], "W");
    allLoc[6]->addNeighbor(allLoc[8], "NE");
    allLoc[6]->addNeighbor(allLoc[15], "E");

    allLoc[7]->addNeighbor(allLoc[6], "SE");
    allLoc[7]->addNeighbor(allLoc[4], "S");
    allLoc[7]->addNeighbor(allLoc[5], "SW");
    allLoc[7]->addNeighbor(allLoc[9], "W");
    allLoc[7]->addNeighbor(allLoc[8], "E");

    allLoc[8]->addNeighbor(allLoc[6], "SW");
    allLoc[8]->addNeighbor(allLoc[15], "S");
    allLoc[8]->addNeighbor(allLoc[11], "E");
    allLoc[8]->addNeighbor(allLoc[7], "W");

    allLoc[9]->addNeighbor(allLoc[7], "E");
    allLoc[9]->addNeighbor(allLoc[5], "S");

    allLoc[10]->addNeighbor(allLoc[11], "N");
    allLoc[10]->addNeighbor(allLoc[15], "W");
    allLoc[10]->addNeighbor(allLoc[13], "S");

    allLoc[11]->addNeighbor(allLoc[8], "W");
    allLoc[11]->addNeighbor(allLoc[10], "S");
    allLoc[11]->addNeighbor(allLoc[15], "SW");

    allLoc[12]->addNeighbor(allLoc[15], "N");
    allLoc[12]->addNeighbor(allLoc[3], "W");
    allLoc[12]->addNeighbor(allLoc[13], "E");
    allLoc[12]->addNeighbor(allLoc[14], "S");

    allLoc[13]->addNeighbor(allLoc[10], "N");
    allLoc[13]->addNeighbor(allLoc[12], "W");
    allLoc[13]->addNeighbor(allLoc[14], "SW");

    allLoc[14]->addNeighbor(allLoc[12], "N");
    allLoc[14]->addNeighbor(allLoc[13], "NE");
    allLoc[14]->addNeighbor(allLoc[0], "W");

    allLoc[15]->addNeighbor(allLoc[8], "N");
    allLoc[15]->addNeighbor(allLoc[6], "W");
    allLoc[15]->addNeighbor(allLoc[12], "S");
    allLoc[15]->addNeighbor(allLoc[10], "E");
    allLoc[15]->addNeighbor(allLoc[11], "NE");
    // there are 6 types:
    //0- normal location
    //1- traps
    //2- bats
    //3- boss
    //4- traps and boss
    //5- bats and boss
    allLoc[1]->setCoins(1);
    allLoc[2]->setCoins(1);
    allLoc[14]->setCoins(2);
    allLoc[13]->setCoins(1);
    allLoc[15]->setCoins(2);
    allLoc[11]->setCoins(1);

    allLoc[4]->setType(3);
    allLoc[6]->setType(1);
    allLoc[7]->setType(2);
    allLoc[12]->setCoins(2);
    allLoc[10]->setCoins(2);
    bossLoc = allLoc[4];
}

location* application::getBossLoc() {
    return bossLoc;
}

vector<location*> application::getAllLoc() {
    return allLoc;
}

int application::getStatus() {
    return status;
}
