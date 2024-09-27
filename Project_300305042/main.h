#ifndef MAINPROG
#define MAINPROG

#include <cstdlib>
#include <typeinfo>
#include <algorithm>
#include <random>
#include <list>
#include <string>
#include <limits>
#include <iterator>
#include <chrono>
#include <sstream>
#include <fstream>
#include <iostream>

#include "headers/Card.h"
#include "headers/DiscardPile.h"
#include "headers/CardFactory.h"
#include "headers/Deck.h"
#include "headers/Player.h"
#include "headers/Hand.h"
#include "headers/TradeArea.h"
#include "headers/Table.h"

using namespace std;

Chain_Base *makeNewChain(Card *card);


void chainCard(Card *card, Player *currentPlayer, vector<Chain_Base *> *chains);


void playCard(Player *currentPlayer, vector<Chain_Base *> *chains);

bool handContainsCard(Hand hand, string str, long unsigned &index);

bool topCardisInTradeArea(DiscardPile discardPile, TradeArea trade);

void pauseGame();
void runGame(string player1, string player2, ostream &outputStream, istream &inputStream);
void loadPreviousGame();

#endif