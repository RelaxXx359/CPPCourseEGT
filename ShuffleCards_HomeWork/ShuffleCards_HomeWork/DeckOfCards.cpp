#include <iostream>
using std::cout;
using std::left;
using std::right;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

#include <string>
using namespace std;

#include "DeckOfCards.h"

DeckOfCards::DeckOfCards()
{
	// Инициализиране на цвят и лица на картите
	static const char* suit[4] = { "Hearts","Diamonds", "Clubs", "Spades" };
	static const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };


	// Запълване на тестето с карти
	for (int i = 0; i < 52; i++)
	{
		deck[i].face = face[i & 13];
		deck[i].suit = suit[i / 13];
	}
	srand(time(0));
}

// Метод за разбъркване на картите
void DeckOfCards::shuffle() {
	for (size_t i = 0; i < 52; i++) {
		int j = rand() % 52;
		Card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
	srand(time(0));
}

// Метод за раздаване на картите от тестето
void DeckOfCards::dealtCard()
{
	for (size_t i = 0; i < 52; i++) {
		cout << right << setw(5) << deck[i].face <<" of "
			<< left << setw(8) << deck[i].suit 
			<< ((i + 1) % 2 ? '\t' : '\n');

	}


}

