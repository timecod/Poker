#include "CircleInt.h"

CircleInt::CircleInt () : value(0), board(0) {}

CircleInt::CircleInt (int value, int board) : value(value % board), board(board) {}

CircleInt & CircleInt::operator++ () { value = ++value % board; return *this; }

int CircleInt::operator- (CircleInt A) {
	int x = value - A.value;
	x = x < 0 ? -x : x;
	int y = board - x;
	return x < y ? x : y;
}

void CircleInt::operator= (int value) {
	this->value = value % board;
}

CircleInt CircleInt::operator+ (CircleInt A) {
	CircleInt R(A.value + value, board);
	return R;
}

CircleInt CircleInt::operator+ (int A) {
	CircleInt R(value + A, board);
	return R;
}

CircleInt::operator int () {
	return value;
}

