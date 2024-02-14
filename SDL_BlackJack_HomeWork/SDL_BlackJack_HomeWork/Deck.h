#pragma once

struct Card {
	const char* face;
	const char* suit;
};

class Deck {
public:
	Deck();
	void shuffle();
	void deal();

private:
	Card deck[52];
};