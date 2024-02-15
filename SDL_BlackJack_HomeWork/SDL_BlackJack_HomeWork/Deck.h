#pragma once
#include <vector>
struct Card {
	const char* face;
	const char* suit;
};

class Deck {
public:
	// kostruktor teste
	Deck(int numberDeck);
	// metod za razburkvane 
	void shuffle();
	// metod za razdavane
	Card dealtCard();

private:
	//karti v testeto
	std::vector<Card> cards;
};