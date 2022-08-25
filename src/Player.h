#pragma once

#include "Card.h"
#include <vector>
#include <string>
class Player {
    std::string name;
    unsigned int coins;
    unsigned int coins_in_game;
    std::vector <Card *> cards;
    bool status;
    public:
    Player (char *);
    Player ();
    ~Player ();
    std::string get_name ();
    void change_coins (int);
    int get_coins ();
    int get_coins_in_game ();
    void game_over ();
    void set_status (bool);
    bool is_playing ();
    Card * get_card (int);
    void set_cards (Card **, int);
    operator char ();
};
