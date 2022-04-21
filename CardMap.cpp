#include "pch.h"
#include "CardMap.h"

bool CardMap::hasCard(string card) {
	return mp.hasKey(card);
}

void CardMap::addWin(std::string card, std::string deckStr)
{
	if (mp.hasKey(card))
		mp.getValue(card)->addDeckWin(deckStr);
	else {
		DecksWCard* deck = new DecksWCard(deckStr, true);
		mp.insert(card, deck);
	}
}

void CardMap::addLoss(std::string card, std::string deckStr)
{
	if (mp.hasKey(card))
		mp.getValue(card)->addDeckLoss(deckStr);
	else {
		DecksWCard* deck = new DecksWCard(deckStr, false);
		mp.insert(card, deck);
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
	if (mp.empty() || !mp.hasKey(card))
		return 0;
	return mp.getValue(card)->getBestDeckWinrate();
}

int CardMap::bestDeckGameCount(std::string card)
{
	if (mp.empty() || !mp.hasKey(card))
		return 0;
	return mp.getValue(card)->getBestDeckGameCount();
}

