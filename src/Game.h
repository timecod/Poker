#pragma once

#include <string>
#include <vector>
#include "Player.h"
#include "Card.h"

class Game {
	const int size = 5;
	Card * table [5];
	std::vector <Player *> players;
	int who_walk;
	bool card_status [5];
	void update ();
	void show ();
	void input_base ();
	void input_first ();
	void input_second ();
public:
	Game (Player ** players);
	~Game ();
};
