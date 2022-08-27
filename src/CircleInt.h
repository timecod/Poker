#pragma once

class CircleInt {
	int value;
	int board;
public:
	CircleInt ();
	CircleInt (int, int);
	void operator= (int value);
	CircleInt& operator++ ();
	int operator- (CircleInt);
	CircleInt operator+ (CircleInt);
	CircleInt operator+ (int);
	operator int ();
};
