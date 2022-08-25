#include "Card.h"

Card::Card(int number, int suit) : number(number), suit(suit) {};

const char * Card::get_number() {
	const char * alphavit [13] = {"2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10", "J ", "D ", "K ", "A "};
	return alphavit[number]; 
}

char Card::get_suit() {return suit == 0 ? '^' : suit == 1 ? '>' : suit == 2 ? '<' : '+'; }

Card::Card(int numer) { suit = numer / 13; number = numer % 13; }
