#ifndef DiscardPile_h
#define DiscardPile_h

#include <iostream>
#include <vector>
#include <string>
#include "Card.h"
#include "IllegalTypeException.h"

#include "CardFactory.h"

using namespace std;

class DiscardPile : public vector<Card *>
{
public:
  DiscardPile() = default;
  ~DiscardPile() = default;
  DiscardPile(istream &, const CardFactory *);
  DiscardPile &operator+=(Card *);  //jette la carte dans la pile
  
  Card *pickUp();  //renvoie et supprime la carte supérieure de la pile au rebut.
  Card *top();  //renvoie mais ne supprime pas la carte supérieure de la pile au rebut.
  void print(ostream &);   //pour insérer toutes les cartes de DiscardPile dans std::ostream

  friend ostream &operator<<(ostream &, DiscardPile &);
  friend ostream &operator<<(ostream &, DiscardPile *);
   
};

#endif