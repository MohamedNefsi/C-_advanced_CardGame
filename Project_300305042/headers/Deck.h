#ifndef Deck_h
#define Deck_h


#include <cstdlib> 

using namespace std;

#include <iostream>
#include <vector>
#include "Card.h"
#include "CardFactory.h"
#include "IllegalTypeException.h"

class CardFactory;

class Deck : public vector<Card *>
{
public:
  Deck();
  Deck(istream &, const CardFactory *);  //constructeur qui accepte un istream et construit un objet de type Deck à partir du fichier
  Card *draw();  //retourne et supprime la carte supérieure du Deck

 
  void print(ostream &);  //opérateur d'insertion pour insérer toutes les cartes du jeu dans un fichier
  friend ostream &operator<<(ostream &, Deck &);
  friend ostream &operator<<(ostream &, Deck *);

 
  void status(); 
};




#endif