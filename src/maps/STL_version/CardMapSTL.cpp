#include "pch.h"
#include "CardMapSTL.h"

bool CardMapSTL::hasCard(string cardName)
{
	return mp.count(cardName);
}

void CardMapSTL::addWin(std::string card, std::string deckStr)
{
	if (mp.count(card) == 1)
		mp.find(card)->second->addDeckWin(deckStr);
	else {
		DecksWCard* deck = new DecksWCard(deckStr, true);
		mp.insert({ card, deck });
	}
}

void CardMapSTL::addLoss(std::string card, std::string deckStr)
{
	if (mp.count(card) == 1)
		mp.find(card)->second->addDeckLoss(deckStr);
	else {
		DecksWCard* deck = new DecksWCard(deckStr, false);
		mp.insert({ card, deck });
	}
}

std::string CardMapSTL::bestDeckID(std::string card)
{
	if (mp.empty())
		return "";

	auto found = mp.find(card);
	if (found != mp.end())
		return found->second->getBestDeckID();
	return "";
}

double CardMapSTL::bestDeckWinrate(std::string card)
{
	if (mp.empty())
		return 0.0;

	auto found = mp.find(card);
	if (found != mp.end())
		return found->second->getBestDeckWinrate();
	return 0.0;
}

int CardMapSTL::bestDeckGameCount(std::string card)
{
	if (mp.empty())
		return 0;

	auto found = mp.find(card);
	if (found != mp.end())
		return found->second->getBestDeckGameCount();
	return 0;
}