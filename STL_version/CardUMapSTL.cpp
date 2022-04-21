#include "pch.h"
#include "CardUMapSTL.h"


bool CardUMapSTL::hasCard(string card)
{
	return mp.count(card);
}

void CardUMapSTL::addWin(std::string card, std::string deckStr)
{
	if (mp.count(card))
		mp.find(card)->second->addDeckWin(deckStr);
	else {
		DecksWCard* deck = new DecksWCard(deckStr, true);
		mp.insert({ card, deck });
	}
}

void CardUMapSTL::addLoss(std::string card, std::string deckStr)
{
	if (mp.count(card))
		mp.find(card)->second->addDeckLoss(deckStr);
	else {
		DecksWCard* deck = new DecksWCard(deckStr, false);
		mp.insert({ card, deck });
	}
}

std::string CardUMapSTL::bestDeckID(std::string card)
{
	if (mp.empty())
		return "";

	auto found = mp.find(card);
	if (found != mp.end())
		return found->second->getBestDeckID();
	return "";
}

double CardUMapSTL::bestDeckWinrate(std::string card)
{
	if (mp.empty())
		return 0.0;

	auto found = mp.find(card);
	if (found != mp.end())
		return found->second->getBestDeckWinrate();
	return 0.0;
}

int CardUMapSTL::bestDeckGameCount(std::string card)
{
	if (mp.empty())
		return 0;

	auto found = mp.find(card);
	if (found != mp.end())
		return found->second->getBestDeckGameCount();
	return 0;
}