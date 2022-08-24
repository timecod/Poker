#include <iostream>
#include <vector>
#include "Card.h"

class Coloda {
	const int size = 52;
	std::vector <int> cards;
public:
	Coloda ();
	Card * take_card ();
};
