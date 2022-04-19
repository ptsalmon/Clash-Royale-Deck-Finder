#include "CardUMap.h"

void CardUMap::addWin(std::string card, std::string deckStr)
{
	if (mp.count(card) == 1)
		mp.find(card)->second->addDeckWin(deckStr);
	else {
		DecksWCard* deck = new DecksWCard(deckStr, true);
		mp.insert({ card, deck });
	}
}

void CardUMap::addLoss(std::string card, std::string deckStr)
{
	if (mp.count(card) == 1)
		mp.find(card)->second->addDeckLoss(deckStr);
	else {
		DecksWCard* deck = new DecksWCard(deckStr, false);
		mp.insert({ card, deck });
	}
}

std::string CardUMap::bestDeckID(std::string card)
{
	if (mp.empty())
		return "";

	auto found = mp.find(card);
	if (found != mp.end())
		return found->second->getBestDeckID();
	return "";
}

double CardUMap::bestDeckWinrate(std::string card)
{
	if (mp.empty())
		return 0.0;

	auto found = mp.find(card);
	if (found != mp.end())
		return found->second->getBestDeckWinrate();
	return 0.0;
}

int CardUMap::bestDeckGameCount(std::string card)
{
	if (mp.empty())
		return 0;

	auto found = mp.find(card);
	if (found != mp.end())
		return found->second->getBestDeckGameCount();
	return 0;
}
