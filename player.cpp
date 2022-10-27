#include "player.hpp"
#include <iostream>
using namespace std;
player::player() {
    coins = 3;
    arrows = 3;
}
player::~player() {

}
void player::setLocation(location* l) {
    loc = l;
}
void player::playerMove() {
    cout << "choose your direction to move:" << endl;
    map<string, location*> mp = loc->getNeighbors();
    map<string, location*> :: iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " ";
    }
    cout << endl;
    string direction;
    cin >> direction;
    coins--;
    loc = mp[direction];
    int newcoins = loc->getCoins();
    coins += newcoins;
    loc->setCoins(0);
}

location* player::shoot() {
    cout << "choose your direction to shoot:" << endl;
    map<string, location*> mp = loc->getNeighbors();
    map<string, location*> :: iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " ";
    }
    cout << endl;
    string direction;
    cin >> direction;
    arrows--;
    return mp[direction];
}

location* player::getLocation() {
    return loc;
}
int player::getArrows() { // know how many arrows the player has
    return arrows;
}
void player::setArrows(int a) { // after shooting, minus 1 arrow
    arrows = a;
}
int player::getCoins() { // know how many coins the player has
    return coins;
}
void player::setCoins(int c) { // arrive some locations, pick up some coins.
    coins = c;
}

