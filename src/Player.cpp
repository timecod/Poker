#include "Player.h"
#include <string>

Player::Player (char name []) {
    coins = 1000;
    this->name = name;
}
void Player::change_coins (int value) {
    if (coins + value < 0)
        throw "No coins";
    coins += value;
}
int Player::get_coins () { return coins; }

Card * Player::get_card (int id) { return cards[id]; }

bool Player::is_playing () { return playing; }
void Player::set_cards (Card * cards []) { for (int i = 0; i < 2; ++i) this->cards.push_back(cards[i]); }

Player::~Player () {
    for (int i = 0; i < cards.size(); ++i) delete cards[i];
}

std::string Player::get_name () { return name; }
