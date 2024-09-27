#ifndef CardFactory_h
#define CardFactory_h

#include "Deck.h"
#include "Card.h"
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "Hand.h"
#include <typeinfo>
#include <chrono>

#include <list>


class Deck;


class CardFactory
{
private:
    // // variable pour initialiser les tableaux de cardfactory
    // const int BLUE_CARDS = 20;
    // const int CHILI_CARDS = 18;
    // const int STINK_CARDS = 16;
    // const int GREEN_CARDS = 14;
    // const int SOY_CARDS = 12;
    // const int BLACK_CARDS = 10;
    // const int RED_CARDS = 8;
    // const int GARDEN_CARDS = 6;
    // const int DECK_SIZE = BLUE_CARDS + CHILI_CARDS + STINK_CARDS + GREEN_CARDS + SOY_CARDS + BLACK_CARDS + RED_CARDS + GARDEN_CARDS;

    CardFactory(const CardFactory &); 

    ~CardFactory() = default;

    static CardFactory *internal;
    static Deck *deck;

public:

    CardFactory();

    static CardFactory *getFactory(); //renvoie un pointeur à l’unique instance de CardFactory
    Deck getDeck(); //renvoie un jeu avec toutes les 104 cartes haricots
    
};




#endif