#ifndef Hand_h
#define Hand_h


#include "CardFactory.h"
#include "Card.h"


class CardFactory;


class Hand : public vector<Card *>
{
public:
  Hand() = default;
  ~Hand() = default;
  
  Hand(istream &, const CardFactory *);


  Hand &operator+=(Card *);
  Card *play();
  Card *top();
  Card *operator[](int);

  void print(ostream &);


  friend ostream &operator<<(ostream &, Hand &);
  friend ostream &operator<<(ostream &, Hand *);
  
};



#endif