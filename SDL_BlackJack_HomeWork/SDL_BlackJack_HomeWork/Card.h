#pragma once


class Card {

public:
	Card(int, const char*);

	//metod za poluchavane na stoinost
	int getValue() const;

	//metod za poluchavane na boqta
	const char* getSuit() const;

private:
	int value;
	const char* suit;
};