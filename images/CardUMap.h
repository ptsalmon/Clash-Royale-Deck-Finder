#pragma once
#include <set>
#include <string>
#include "unorderedMap.h"

using namespace std;

class CardUMap {
	struct DecksWCard {
		struct stats {
			int numOfWins;
			int numOfGames;
			stats() : numOfWins(0), numOfGames(0) {};
			stats(int numOfWins_, int numOfGames_) : numOfWins(numOfWins_), numOfGames(numOfGames_) {};
			stats(bool win)
			{
				numOfWins = 0;
				numOfGames = 0;
				if (win)
					this->addWin();
				else
					this->addLoss();
			};


			inline void DecksWCard::stats::addWin() {
				numOfWins++;
				numOfGames++;
			}
			inline void addLoss() {
				numOfGames++;
			}
			inline double getWinrate() const {
				return (double) this->numOfWins / this->numOfGames;
			}

			inline int getNumGames()
			{
				return this->numOfGames;
			}

			inline bool stats::operator>(const stats& rhs) const
			{
				if (this->getWinrate() == rhs.getWinrate())
					return this->numOfGames > rhs.numOfGames;

				return this->getWinrate() > rhs.getWinrate();
			}

			inline bool DecksWCard::stats::operator<(const stats& rhs) const
			{
				if (this->getWinrate() == rhs.getWinrate())
					return this->numOfGames < rhs.numOfGames;

				return this->getWinrate() < rhs.getWinrate();
			}

			inline bool DecksWCard::stats::operator==(const stats& rhs) const
			{
				return this->getWinrate() == rhs.getWinrate();
			}

			inline bool stats::compare(const stats* rhs) const
			{
				if (this->getWinrate() == rhs->getWinrate())
					return this->numOfGames > rhs->numOfGames;

				return this->getWinrate() > rhs->getWinrate();
			}
		};


		unorderedMap<stats*> deckList;
		std::string bestDeck = "";

		DecksWCard() {}

		DecksWCard(std::string deck, bool win)
		{
			if (win)
				this->addDeckWin(deck);
			else
				this->addDeckLoss(deck);
		}

		inline void addDeckWin(std::string deckStr)
		{
			if (deckList.hasKey(deckStr))
				deckList.value(deckStr)->addWin();
			else {
				stats* deckStats = new stats(true);
				deckList.insert({ deckStr, deckStats });
			}
		}

		inline void addDeckLoss(std::string deckStr)
		{
			if (deckList.hasKey(deckStr))
			{
				deckList.value(deckStr)->addLoss();
			}
			else {
				stats* deckStats = new stats(false);
				deckList.insert({ deckStr, deckStats });
			}
		}

		inline std::string CardUMap::DecksWCard::getBestDeckID()
		{
			if (deckList.empty())
				return "";

			if (bestDeck == "")
			{
				bestDeck = deckList.getMax().first;
				return bestDeck;
			}

			return bestDeck;
		}

		inline double CardUMap::DecksWCard::getBestDeckWinrate()
		{
			std::string best = this->getBestDeckID();

			if (best == "")
				return 0;
			else
				return deckList.getMax().second->getWinrate();
		}

		inline int CardUMap::DecksWCard::getBestDeckGameCount()
		{
			std::string best = this->getBestDeckID();

			if (best == "")
				return 0;
			else
				return deckList.getMax().second->getWinrate();
		}
	};

	unorderedMap<DecksWCard*> mp;
	std::string bestDeck;

public:

	CardUMap() {};

	bool hasCard(string cardName);

	void addWin(std::string card, std::string deckStr);
	void addLoss(std::string card, std::string deckStr);

	std::string bestDeckID(std::string card);
	double bestDeckWinrate(std::string card);
	int bestDeckGameCount(std::string card);

};