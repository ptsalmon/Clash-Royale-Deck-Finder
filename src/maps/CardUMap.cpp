#include "pch.h"
#include "CardUMap.h"


bool CardUMap::hasCard(string cardName)
{
	return mp.hasKey(cardName);
}

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
	if (mp.empty() || !mp.hasKey(card))
		return 0;
	return mp.value(card)->getBestDeckWinrate();
}

int CardUMap::bestDeckGameCount(std::string card)
{
	if (mp.empty() || !mp.hasKey(card))
		return 0;
	return mp.value(card)->getBestDeckGameCount();
}