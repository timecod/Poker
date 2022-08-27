#pragma once

#include <string>
#include <vector>
#include "Player.h"
#include "Card.h"
#include "CircleInt.h"

class Game {
	const int size = 5;
	Card * table [5];
	std::vector <Player *> players;
	CircleInt diler;
	CircleInt who_walk;
	int step;
	int last;
	bool card_status [5];
	void show ();
	void input();
public:
	Game (Player **, int, int);
	void update ();
	~Game ();
};
