#include "Game.h"
#include "Card.h"
#include "Coloda.h"
#include <iostream>
#include <string>
#include <vector>

Game::Game (Player ** players) {
	who_walk = 0;
	//for (Player ** ptr = &players[0]; *ptr > 0; ++ptr) this->players.push_back(*ptr);
    for (int i = 0; i < 3; ++i) this->players.push_back(players[i]);
	Coloda C;
	for (int i = 0; i < size; ++i) {
		table[i] = C.take_card();
	}
	for (int i = 0; i < this->players.size(); ++i) {
		Card * cards [2] = { C.take_card(), C.take_card() };
		this->players[i]->set_cards(cards);
	}
	std::cout << "Constructor finished \n";
	show();
}

Game::~Game () {
	for (int i = 0; i < size; ++i) delete table[i];
}

void Game::update () {

}

std::string multyple (std::string A, int B) {
	std::string res("");
	for (int i = 0; i < B; ++i) res += A;
	return res;
}

std::string int_to_str (int value) {
	std::string res("");
	char * alphavit [10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	while(value > 0) { res = alphavit[value % 10] + res; value /= 10; }
	return res;
}
void Game::show () {
	typedef std::string S;


	//   /-----\
	//   |X    |
	//   |     |
	//   |     |
	//   |    M|
	//   \-----/
    const int count = 6;
	// Names, coins, plays or not (p/n):
	//                                         table

	std::system("clear");
	std::vector <std::vector <S>> strings(3);
	for (int i = 0; i < players.size(); ++i) {
		S str_name = players[i]->get_name();
		S str_status = " (" + S(players[i]->is_playing() ? "p" : "n") + "): ";
		S str_coins = int_to_str(players[i]->get_coins());
		strings[0].push_back(str_name);
		strings[2].push_back(str_status);
		strings[1].push_back(str_coins);
	}

	int symvols_max [2] = {strings[0][0].size(), strings[1][0].size()};
	for (int i = 1; i < players.size(); ++i) {
		for (int j = 0; j < 2; ++j) {
			symvols_max[j] = strings[j][i].size() > symvols_max[j] ? strings[j][i].size() : symvols_max[j];
		}
	}

	for (int i = 0; i < players.size(); ++i) {
		for (int j = 0; j < 2; ++j) {
			strings[j][i] = multyple(" ", symvols_max[j] - strings[j][i].size()) + strings[j][i];
		}
	}

	std::vector <S> str_out(players.size() > count ? players.size() : count);
	for (int i = 0; i < players.size(); ++i) {
		str_out[i] = strings[0][i] + strings[2][i] + strings[1][i];
	}

	S space = multyple(" ", str_out[0].size());
	for (auto i = str_out.begin() + players.size(); i < str_out.end(); ++i) {
		*i = space;
	}

		str_out[0] += "    " + multyple(" /-----\\", size) + " |" + multyple(" /-----\\", 2);
		str_out[1] += "    ";
		str_out[2] += "    " + multyple(" |     |", size) + " |" + multyple(" |     |", 2);
		str_out[3] += "    " + multyple(" |     |", size) + " |" + multyple(" |     |", 2);
		str_out[4] += "    ";
		str_out[5] += "    " + multyple(" \\-----/", size) + " |" + multyple(" \\-----/", 2);
		for (int i = 0; i < size; ++i) {
			str_out[1] += S(" |") + (card_status[i] ? table[i]->get_number() : "X ") + "   |";
			str_out[4] += S(" |    ") + (card_status[i] ? table[i]->get_suit() : 'M') + "|";
		}

		str_out[1] += " |";
		str_out[4] += " |";

		for (int i = 0; i < 2; ++i) {
			str_out[1] += S(" |") + players[who_walk]->get_card(i)->get_number() + "   |";
			str_out[4] += S(" |    ") + players[who_walk]->get_card(i)->get_suit() + "|";
		}

		for (int i = 0; i < str_out.size(); ++i) {
			std::cout << str_out[i] << "\n";
		}
}
