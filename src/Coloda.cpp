#include "Coloda.h"
#include "Card.h"
#include <vector>
#include <ctime>

Coloda::Coloda () { cards.resize(size); for (int i = 0; i < size; ++i) cards[i] = i; }

Card * Coloda::take_card () {
	std::srand(std::time(nullptr));
	int number_card = std::rand() % (cards.size());
	Card * result = new Card(cards[number_card]);
	cards.erase(cards.begin() + number_card);
	return result;
}

