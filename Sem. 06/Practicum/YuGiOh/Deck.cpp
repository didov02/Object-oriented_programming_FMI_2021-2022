#include<cstring>
#include "Deck.h"

Deck::Deck() : magicCardsSize(0), monsterCardsSize(0) {
	for (size_t i = 0; i <  MAX_DECK_SIZE / 2; i++)
	{
		MonsterCardUsedPositions[i] = MagicCardUsedPositions[i] = false;
	}
}

size_t Deck::getMagicCardsSize() const{
	return magicCardsSize;
}

size_t Deck::getMonsterCardsSize() const{
	return monsterCardsSize;
}

bool Deck::addMagicCardToDeck(const MagicCard& magicCard) {
	for (size_t i = 0; i < MAX_DECK_SIZE / 2; i++)
	{
		if (!MagicCardUsedPositions[i])
		{
			magicCards[i] = magicCard;
			MagicCardUsedPositions[i] = true;
			magicCardsSize++;
			return true;
		}
	}
	return false;
}

bool Deck::addMonsterCardToDeck(const MonsterCard& monsterCard) {
	for (size_t i = 0; i < MAX; i++)
	{
		if (!MonsterCardUsedPositions[i])
		{
			monsterCards[i] = monsterCard;
			MonsterCardUsedPositions[i] = true;
			monsterCardsSize++;
			return true;
		}
	}
	return false;
}

bool Deck::addMagicCardToDeckAtIndex(const MagicCard& magicCard, const int index) {
	if(index < 0 || index >= magicCardsSize)
		return false;

	magicCards[index] = magicCard;
	return true;
}

bool Deck::addMonsterCardToDeckAtIndex(const MonsterCard& monsterdrCard, const int index) {
	if(index < 0 || index >= monsterCardsSize)
		return false;

	monsterCards[index] = monsterdrCard;
	return true;
}
