#include "Card.h"


Card::Card(int value, const char* suit) :value(value), suit(suit){}

int Card::getValue()const {
	return value;
}

const char* Card::getSuit() const {
	return suit;
}