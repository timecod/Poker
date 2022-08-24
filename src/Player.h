#pragma once

#include "Card.h"
#include <vector>
#include <string>
class Player {
    std::string name;
    unsigned int coins;
    std::vector <Card *> cards;
    bool status;
    public:
    Player (char *);
    ~Player ();
    std::string get_name ();
    void change_coins (int);
    int get_coins ();
    void set_status (bool);
    bool is_playing ();
    Card * get_card (int);
    void set_cards (Card **);
};
