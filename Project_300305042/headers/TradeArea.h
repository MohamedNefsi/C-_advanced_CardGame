#ifndef TradeArea_h
#define TradeArea_h

#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include "Card.h"
#include "CardFactory.h"
#include "DiscardPile.h"

class TradeArea : public list<Card *>
{
public:
  TradeArea() = default;
  ~TradeArea() = default;
  TradeArea(istream &, const CardFactory *);


  TradeArea &operator+=(Card *); //ajoute une carte à l’échange mais ne vérifie pas si c'est légal de placer la carte.

  bool legal(Card *);  //renvoie true si la carte peut être légalement ajouté à l’échange, i.e., une carte du même haricot est déjà en échange
  Card *trade(string); // supprime de l’échange une carte du correspondant nom
  int numCards(); //renvoie le nombre courant de cartes en échange


  void print(ostream &);
  friend ostream &operator<<(ostream &, TradeArea &);
  friend ostream &operator<<(ostream &, TradeArea *);

  void discardAll(DiscardPile &);
};


#endif