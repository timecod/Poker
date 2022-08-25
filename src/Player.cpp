#include "Player.h"

Player::Player (char * name) {
    coins_in_game = 0;
    status = 1;
    coins = 1000;
    this->name = name;
}

Player::Player () {}

void Player::change_coins (int value) {
    if (coins + value < 0)
        throw "No coins";
    coins += value;
    coins_in_game -= value;
}
int Player::get_coins () { return coins; }

Card * Player::get_card (int id) { return cards[id]; }

void Player::set_status (bool status) { this->status = status; }

bool Player::is_playing () { return status; }

void Player::set_cards (Card ** cards, int n) { this->cards.resize(n); for (int i = 0; i < n; ++i) this->cards[i] = cards[i];}

Player::~Player () {
    for (int i = 0; i < cards.size(); ++i) delete cards[i];
}

std::string Player::get_name () { return name; }

void Player::game_over () { coins_in_game = 0; }

int Player::get_coins_in_game () { return coins_in_game; }
