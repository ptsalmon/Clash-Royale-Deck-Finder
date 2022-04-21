#include "CardMap.h"

void CardMap::addWin(std::string card, std::string deckStr)
{
	if (mp.hasKey(card))
		mp.getValue(card)->addDeckWin(deckStr);
	else {
		DecksWCard* deck = new DecksWCard(deckStr, true);
		mp.insert(card, deck );
	}
}

void CardMap::addLoss(std::string card, std::string deckStr)
{
	if (mp.hasKey(card))
		mp.getValue(card)->addDeckLoss(deckStr);
	else {
		DecksWCard* deck = new DecksWCard(deckStr, false);
		mp.insert( card, deck );
	}
}

std::string CardMap::bestDeckID(std::string card)
{
	if (mp.empty())
		return "";

	if (mp.hasKey(card))
		return mp.getValue(card)->getBestDeckID();
	return "";
}

double CardMap::bestDeckWinrate(std::string card)
{
	if (mp.empty())
		return 0.0;

	if (mp.hasKey(card))
		return mp.getValue(card)->getBestDeckWinrate();
	return 0.0;
}

int CardMap::bestDeckGameCount(std::string card)
{
	if (mp.empty())
		return 0;

	if (mp.hasKey(card))
		return mp.getValue(card)->getBestDeckGameCount();
	return 0;
}
