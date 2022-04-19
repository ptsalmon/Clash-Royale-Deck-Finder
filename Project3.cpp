// Project3.cpp : Defines the entry point for the application.
//

#include "Project3.h"
using namespace std;
using namespace std::chrono;


void getDataUMap(ifstream& dataFile, CardUMap& cardSet);
void getDataMap(ifstream& dataFile, CardMap& cardSet);

string getBestDeck(string card, bool mapChoice, CardMap& cardset, CardUMap& cardSetU);
double getBestDeckWinrate(string card, bool mapChoice, CardMap& cardset, CardUMap& cardSetU);
int getBestDeckGameCount(string card, bool mapChoice, CardMap& cardset, CardUMap& cardSetU);

int main()
{

	ifstream dataFile;
	dataFile.open("data.txt");

	if(!dataFile)
		cout << "Data File not found";

	string line;

	int choice = 0;
	cin >> choice;

	CardMap cardSet;
	CardUMap cardSetU;
	bool mapChoice = true;

	auto start = high_resolution_clock::now();

	if (choice == 0)
		getDataMap(dataFile, cardSet);
	else
	{
		getDataUMap(dataFile, cardSetU);
		mapChoice = false;
	}
	
	auto stop = high_resolution_clock::now();
	auto loadDuration = duration_cast<microseconds>(stop - start);



	return 0;
}

void getDataUMap(ifstream& dataFile, CardUMap& cardSet)
{
	string line;
	while (getline(dataFile, line))
	{
		istringstream str(line);

		string matchID;
		string Player1;
		string Player2;
		string Winner;
		string deck;

		getline(str, matchID, ' ');
		getline(str, Player1, ' ');
		getline(str, Player2, ' ');
		getline(str, Winner, ' ');

		auto pos1 = str.tellg();
		getline(str, deck, ']');
		string deck1 = deck.substr(1); //remove brackets

		getline(str, deck);
		string deck2 = deck.substr(2); //remove brackets
		deck2.pop_back();

		if (Player1 == Winner) //player 1 wins
		{
			//Player1
			str.seekg(pos1);

			string cardF;
			string card;
			getline(str, cardF, ',');
			card = cardF.substr(1);
			cardSet.addWin(card, deck1);

			for (int i = 0; i < 6; i++)
			{
				getline(str, card, ',');
				cardSet.addWin(card, deck1);
			}
			getline(str, card, ']');
			cardSet.addWin(card, deck1);



			//player 2
			getline(str, cardF, ',');
			card = cardF.substr(2);
			cardSet.addLoss(card, deck2);
			for (int i = 0; i < 6; i++)
			{
				getline(str, card, ',');
				cardSet.addLoss(card, deck2);
			}
			getline(str, card, ']');
			cardSet.addLoss(card, deck2);


		}
		else //player 2 wins
		{
			//Player1
			str.seekg(pos1);

			string cardF;
			string card;


			getline(str, cardF, ',');
			card = cardF.substr(1);
			cardSet.addLoss(card, deck1);
			for (int i = 0; i < 6; i++)
			{
				getline(str, card, ',');
				cardSet.addLoss(card, deck1);
			}
			getline(str, card, ']');
			cardSet.addLoss(card, deck1);

			//player 2
			getline(str, cardF, ',');
			card = cardF.substr(2);
			cardSet.addWin(card, deck2);
			for (int i = 0; i < 6; i++)
			{
				getline(str, card, ',');
				cardSet.addWin(card, deck2);
			}
			getline(str, card, ']');
			cardSet.addWin(card, deck2);
		}
	}
}

void getDataMap(ifstream& dataFile, CardMap& cardSet)
{
	string line;
	while (getline(dataFile, line))
	{
		istringstream str(line);

		string matchID;
		string Player1;
		string Player2;
		string Winner;
		string deck;

		getline(str, matchID, ' ');
		getline(str, Player1, ' ');
		getline(str, Player2, ' ');
		getline(str, Winner, ' ');

		auto pos1 = str.tellg();
		getline(str, deck, ']');
		string deck1 = deck.substr(1); //remove brackets

		getline(str, deck);
		string deck2 = deck.substr(2); //remove brackets
		deck2.pop_back();

		if (Player1 == Winner) //player 1 wins
		{
			//Player1
			str.seekg(pos1);

			string cardF;
			string card;
			getline(str, cardF, ',');
			card = cardF.substr(1);
			cardSet.addWin(card, deck1);

			for (int i = 0; i < 6; i++)
			{
				getline(str, card, ',');
				cardSet.addWin(card, deck1);
			}
			getline(str, card, ']');
			cardSet.addWin(card, deck1);



			//player 2
			getline(str, cardF, ',');
			card = cardF.substr(2);
			cardSet.addLoss(card, deck2);
			for (int i = 0; i < 6; i++)
			{
				getline(str, card, ',');
				cardSet.addLoss(card, deck2);
			}
			getline(str, card, ']');
			cardSet.addLoss(card, deck2);


		}
		else //player 2 wins
		{
			//Player1
			str.seekg(pos1);

			string cardF;
			string card;


			getline(str, cardF, ',');
			card = cardF.substr(1);
			cardSet.addLoss(card, deck1);
			for (int i = 0; i < 6; i++)
			{
				getline(str, card, ',');
				cardSet.addLoss(card, deck1);
			}
			getline(str, card, ']');
			cardSet.addLoss(card, deck1);

			//player 2
			getline(str, cardF, ',');
			card = cardF.substr(2);
			cardSet.addWin(card, deck2);
			for (int i = 0; i < 6; i++)
			{
				getline(str, card, ',');
				cardSet.addWin(card, deck2);
			}
			getline(str, card, ']');
			cardSet.addWin(card, deck2);
		}
	}
}

string getBestDeck(string card, bool mapChoice, CardMap& cardSet, CardUMap& cardSetU)
{
	if (mapChoice)
		return cardSet.bestDeckID(card);
	return cardSetU.bestDeckID(card);
}

double getBestDeckWinrate(string card, bool mapChoice, CardMap& cardSet, CardUMap& cardSetU)
{
	if (mapChoice)
		return cardSet.bestDeckWinrate(card);
	return cardSetU.bestDeckWinrate(card);
}

int getBestDeckGameCount(string card, bool mapChoice, CardMap& cardSet, CardUMap& cardSetU)
{
	if (mapChoice)
		return cardSet.bestDeckGameCount(card);
	return cardSetU.bestDeckGameCount(card);
}
