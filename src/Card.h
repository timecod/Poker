#pragma once

// Класс карты
class Card {
    int suit; //масть
    int number;
    public:
    Card (int number, int suit);
    Card (int numer);
    const char * get_number ();
    char get_suit ();
};
