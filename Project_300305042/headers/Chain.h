#ifndef Chain_h
#define Chain_h


#include <iostream>
#include "CardFactory.h"
#include <vector>
#include <stdio.h>

#include "Card.h"

class CardFactory;

class Chain_Base
{
public:

  Chain_Base() = default;
  ~Chain_Base() = default;

  Chain_Base(istream &, const CardFactory *);

  virtual Chain_Base &operator+=(Card *) = 0;
  virtual int sell() = 0;
  virtual void print(ostream &) = 0;
  virtual Card *getExampleItem() = 0;
  virtual int getSize() = 0;

  friend ostream &operator<<(ostream &, Chain_Base &);

};

template <typename T>

class Chain : public Chain_Base

{
public:
  vector<T *> cards;
  Chain_Base &operator+=(Card *);
  int sell();
  void print(ostream &);
  Card *getExampleItem();
  int getSize();
};




template class Chain<Blue>;
template class Chain<Chili>;
template class Chain<Stink>;
template class Chain<Green>;
template class Chain<Soy>;
template class Chain<Black>;
template class Chain<Red>;
template class Chain<Garden>;

#endif