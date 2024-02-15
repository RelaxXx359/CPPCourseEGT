#include "Player.h"


Player::Player() {}

	
void Player::addCard(Card & card) {
		hand.push_back(card);
}

void Player::getHandValue() {
	int value = 0;
	for (auto& card : hand) {
		value = card.getValue();






}
