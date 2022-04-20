#include "CardUMap.h"

void CardUMap::addWin(std::string card, std::string deckStr)
{
	if (mp.hasKey(card))
		mp.value(card)->addDeckWin(deckStr);
	else {
		DecksWCard* deck = new DecksWCard(deckStr, true);
		mp.insert({ card, deck });
	}
}

void CardUMap::addLoss(std::string card, std::string deckStr)
{
	if (mp.hasKey(card))
		mp.value(card)->addDeckLoss(deckStr);
	else {
		DecksWCard* deck = new DecksWCard(deckStr, false);
		mp.insert({ card, deck });
	}
}

std::string CardUMap::bestDeckID(std::string card)
{
	if (mp.empty())
		return "";

	if (mp.hasKey(card))
		return mp.value(card)->getBestDeckID();
	return "";
}

double CardUMap::bestDeckWinrate(std::string card)
{
	if (mp.empty())
		return 0.0;

	if (mp.hasKey(card))
		return mp.value(card)->getBestDeckWinrate();
	return 0.0;
}

int CardUMap::bestDeckGameCount(std::string card)
{
	if (mp.empty())
		return 0;

	if (mp.hasKey(card))
		return mp.value(card)->getBestDeckGameCount();
	return 0;
}
