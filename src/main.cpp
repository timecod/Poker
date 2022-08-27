#include <iostream>
#include "Game.h"
#include "Player.h"
using namespace std;

int main() {
    Player * players [5] = {
        new Player("Anna"),
        new Player("Elza"),
        new Player("Violet"),
        new Player("Kara"),
        new Player("Maya")
    };
    Game A(players, 5, 4);
    try {
        while (true) { A.update(); }
    } catch (const char * str) { cout << str << endl; }
    for( int i = 0; i < 5; ++i) delete players[i];
    return 0;
}
