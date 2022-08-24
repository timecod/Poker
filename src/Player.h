#pragma once

#include "Card.h"
#include <vector>
#include <string>
class Player {
    std::string name;
    unsigned int coins;
    std::vector <Card *> cards;
    bool playing;
    public:
    Player (char name []);
    ~Player ();
    std::string get_name ();
    void change_coins (int value);
    int get_coins ();
    bool is_playing ();
    Card * get_card (int id);
    void set_cards (Card * cards []);
};
