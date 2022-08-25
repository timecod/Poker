#include "Game.h"
#include "Card.h"
#include "Coloda.h"
#include <iostream>
#include <string>
#include <vector>

Game::Game (Player ** players, int n) {
	flag = 0;
	diler = 0;
	step = 0;
	last = 0;
	who_walk = 1;
	for (int i = 0; i < size; ++i) card_status[i] = 0;
	this->players.resize(n);
	for (int i = 0; i < n; ++i) this->players[i] = players[i];
	Coloda C;
	for (int i = 0; i < size; ++i) {
		table[i] = C.take_card();
	}
	for (int i = 0; i < this->players.size(); ++i) {
		Card * cards [2] = { C.take_card(), C.take_card() };
		this->players[i]->set_cards(cards, 2);
	}
}

Game::~Game () {
	for (int i = 0; i < size; ++i) delete table[i];
}

void Game::update () {
	int count = 0;
	for (int i = 0; i < players.size(); ++i) count += players[i]->is_playing();
	if (count == 0) throw "End";

	show();

	if (step == 0 && who_walk - diler == 1) { players[who_walk]->change_coins(-50); }
	else if (step == 0 && who_walk - diler == 2) { players[who_walk]->change_coins(-100); step = 1; last = 100;}
	else { input(); }

	int equals = 1;
	int base = players[0]->get_coins_in_game();
	for (int i = 1; i < players.size(); ++i) equals += (base == players[i]->get_coins_in_game());
	if (step > 0 && equals == players.size()) {
		step++;
		if (step == 2) card_status[0] = card_status[1] = card_status[2] = 1;
		if (step == 3) card_status[3] = 1;
		if (step == 4) card_status[4] = 1;
	}

	who_walk = ++who_walk % players.size();

}

void Game::input () {
	if (!players[who_walk]->is_playing()) return;

	int command, value;
	bool next = 0;
	while (!next) {
		try {
			std::cout << "Your step: (1 - give custom, 2 - exit)\n";
			std::cin >> command;
			if (command > 2 || command < 0) throw "Incorrect value, try again";
			switch (command) {
				case 1:
				std::cin >> value;
				if (value < last - players[who_walk]->get_coins_in_game() || value > players[who_walk]->get_coins())
					throw "Incorrect value, try again";
				players[who_walk]->change_coins(-value);
				last = players[who_walk]->get_coins_in_game();
				break;
				case 2:
				players[who_walk]->set_status(0);
				break;
			};
			next = 1;
		} catch (const char * str) { std::cout << str << "\n"; }
	}
}

std::string multyple (std::string A, int B) {
	std::string res("");
	for (int i = 0; i < B; ++i) res += A;
	return res;
}

std::string int_to_str (int value) {
	std::string res("");
	const char * alphavit [10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
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
	std::vector <std::vector <S>> strings(4);
	for (int i = 0; i < players.size(); ++i) {
		S str_name = players[i]->get_name();
		S str_status = " (" + S(players[i]->is_playing() ? "p" : "n") + "): ";
		S str_coins = int_to_str(players[i]->get_coins());
		S str_coins_in_game = int_to_str(players[i]->get_coins_in_game());
		strings[0].push_back(str_name);
		strings[1].push_back(str_coins);
		strings[2].push_back(str_coins_in_game);
		strings[3].push_back(str_status);
	}

	int symvols_max [3] = {strings[0][0].size(), strings[1][0].size(), strings[2][0].size()};
	for (int i = 1; i < players.size(); ++i) {
		for (int j = 0; j < 3; ++j) {
			symvols_max[j] = strings[j][i].size() > symvols_max[j] ? strings[j][i].size() : symvols_max[j];
		}
	}

	for (int i = 0; i < players.size(); ++i) {
		for (int j = 0; j < 3; ++j) {
			strings[j][i] = multyple(" ", symvols_max[j] - strings[j][i].size()) + strings[j][i];
		}
	}

	std::vector <S> str_out(players.size() > count ? players.size() : count);
	for (int i = 0; i < players.size(); ++i) {
		str_out[i] = strings[0][i] + strings[3][i] + strings[1][i] + " | " + strings[2][i];
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
