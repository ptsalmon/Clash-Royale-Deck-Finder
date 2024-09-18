#pragma once
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

class CardUMapSTL {
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
				return (double)numOfWins / numOfGames;
			}

			inline int getNumGames()
			{
				return numOfGames;
			}

			inline bool stats::operator>(const stats& rhs) const {
				if (this->getWinrate() == rhs.getWinrate())
					return this->numOfGames > rhs.numOfGames;

				return this->getWinrate() > rhs.getWinrate();
			}

			inline bool DecksWCard::stats::operator<(const stats& rhs) const {
				if (this->getWinrate() == rhs.getWinrate())
					return this->numOfGames < rhs.numOfGames;

				return this->getWinrate() < rhs.getWinrate();
			}

			inline bool DecksWCard::stats::operator==(const stats& rhs) const {
				return this->getWinrate() == rhs.getWinrate();
			}
		};


		std::unordered_map<std::string, stats*> deckList;
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
			if (deckList.count(deckStr) == 1)
				deckList.find(deckStr)->second->addWin();
			else {
				stats* deckStats = new stats(true);
				deckList.insert({ deckStr, deckStats });
			}
		}

		inline void addDeckLoss(std::string deckStr)
		{
			if (deckList.count(deckStr) == 1)
			{
				deckList.find(deckStr)->second->addLoss();
			}
			else {
				stats* deckStats = new stats(false);
				deckList.insert({ deckStr, deckStats });
			}
		}

		inline std::string CardUMapSTL::DecksWCard::getBestDeckID()
		{
			if (deckList.empty())
				return "";

			if (bestDeck == "")
			{
				auto iter = deckList.begin();
				stats max = (*iter->second);
				auto maxIt = deckList.begin();
				++iter;
				while (iter != deckList.end())
				{
					if ((*iter->second) > max)
					{
						max = (*iter->second);
						maxIt = iter;
					}
					++iter;
				}
				return maxIt->first;
			}

			return bestDeck;
		}

		inline double CardUMapSTL::DecksWCard::getBestDeckWinrate()
		{
			std::string best;
			if (bestDeck == "")
				best = this->getBestDeckID();

			auto found = deckList.find(best);
			if (found != deckList.end())
			{
				return found->second->getWinrate();
			}
			return 0.0;
		}

		inline int CardUMapSTL::DecksWCard::getBestDeckGameCount()
		{
			std::string best;
			if (bestDeck == "")
				best = this->getBestDeckID();

			auto found = deckList.find(best);
			if (found != deckList.end())
			{
				return found->second->getNumGames();
			}
			return 0;
		}
	};


	std::unordered_map<std::string, DecksWCard*> mp;
	std::string bestDeck;

public:

	CardUMapSTL() {};

	bool hasCard(string card);

	void addWin(std::string card, std::string deckStr);
	void addLoss(std::string card, std::string deckStr);

	std::string bestDeckID(std::string card);
	double bestDeckWinrate(std::string card);
	int bestDeckGameCount(std::string card);

};