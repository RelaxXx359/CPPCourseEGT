#pragma once
#include <vector>
struct Card{
	 const char* face;
	 const char* suit;
};

class DeckOfCards {
public:
	// constructor
	DeckOfCards();
	// method shuffle
	void shuffle();
	// deals cards
	void dealtCard();

private:
	//deck of cards
	//std::vector<Cards> card;
	Card deck[52];
};
