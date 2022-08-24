#include <iostream>
#include "Game.h"
#include "Player.h"
using namespace std;

int main() {
    Player * pls[3]  = {
        new Player("Anna"),
        new Player("Elza"),
        new Player("Violet")
    };
    Game A(pls);
    for (int i = 0; i < 3; ++i) delete pls[i];
    return 0;
}
