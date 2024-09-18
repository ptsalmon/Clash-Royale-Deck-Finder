#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <chrono>
#include "CardMap.h"
#include "CardMapSTL.h"
#include "CardUMap.h"
#include "CardUMapSTL.h"

using namespace std;
using namespace std::chrono;

class MapCreator
{
private:
	CardMap cardSet;
	CardUMap cardSetU;
	string timeElapsed;

	void getDataUMap(ifstream& dataFile, CardUMap& cardSet);
	void getDataMap(ifstream& dataFile, CardMap& cardSet);
public:
	MapCreator(bool mapChoice) {
		ifstream dataFile;
		dataFile.open("data.txt");

		if (!dataFile)
			cout << "Data File not found";

		string line;

		auto start = high_resolution_clock::now();

		if (mapChoice) {
			getDataMap(dataFile, cardSet);
		}
		else
		{
			getDataUMap(dataFile, cardSetU);
		}

		auto stop = high_resolution_clock::now();
		auto loadDuration = duration_cast<milliseconds>(stop - start);
		float secondsElapsed = loadDuration.count() / 1000.0;

		timeElapsed = to_string(secondsElapsed);
	}

	bool hasCard(string cardName, bool mapChoice);

	string getTimeElapsed() { return timeElapsed; }

	string getBestDeck(string card, bool mapChoice)
	{
		return (mapChoice) ? cardSet.bestDeckID(card) : cardSetU.bestDeckID(card);
	}

	double getBestDeckWinrate(string card, bool mapChoice)
	{
		return (mapChoice) ? cardSet.bestDeckWinrate(card) : cardSetU.bestDeckWinrate(card);
	}

	int getBestDeckGameCount(string card, bool mapChoice)
	{
		return (mapChoice) ? cardSet.bestDeckGameCount(card) : cardSetU.bestDeckGameCount(card);
	}
};

