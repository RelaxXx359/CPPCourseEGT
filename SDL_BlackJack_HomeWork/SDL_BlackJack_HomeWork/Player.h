#pragma once
#include <vector>
#include "Card.h"

class Player {
public:
	Player();

	//metod za dobavqne na karta
	void addCard(Card& card);

	void getHandValue();
	void printHand() ;



private:
	std::vector<Card> hand;
};