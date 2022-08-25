#pragma once

#include <string>
#include <vector>
#include "Player.h"
#include "Card.h"

class Game {
	const int size = 5;
	Card * table [5];
	std::vector <Player *> players;
	int diler;
	int who_walk;
	int step;
	int last;
	int flag;
	bool card_status [5];
	void show ();
	void input();
public:
	Game (Player **, int);
	void update ();
	~Game ();
};
