#include "pch.h"
#include "MapCreator.h"

void MapCreator::getDataUMap(ifstream& dataFile, CardUMap& cardSet)
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

void MapCreator::getDataMap(ifstream& dataFile, CardMap& cardSet)
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

bool MapCreator::hasCard(string cardName, bool mapChoice)
{
	if (mapChoice)
		return cardSet.hasCard(cardName);
	else
		return cardSetU.hasCard(cardName);
}
