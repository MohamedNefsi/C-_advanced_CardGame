#include "headers/Chain.h"

Hand::Hand(istream &, const CardFactory *)
{
  throw Unimplemented();
}

Hand &Hand::operator+=(Card *c)
{
  reserve(1);
  push_back(c);
  return *this;
}

Card *Hand::top()
{
  if (empty())
    throw HandEmpty();

  Card *x = back();
  return x;
}

Card *Hand::play()
{
  if (empty())
    throw HandEmpty();

  Card *x = back();
  pop_back();
  return x;
}

Card *Hand::operator[](int position)
{
  if (position < 0)
    return nullptr;
  if (empty())
    return nullptr;
  if (static_cast< int>(position) >= size())
    return nullptr;

  Card *returnedCard = at(position);
  erase(begin() + position);
  return returnedCard;
}

void Hand::print(ostream &out)
{
  if (!empty())
  {
    out << "HAND" << endl; 
    for ( int i = 0; i < size(); i++)
      out << (i == 0 ? "" : " ") << at(i);
    out << endl; 
  }
}

ostream &operator<<(ostream &out, Hand &hand)
{
  hand.print(out);
  return out;
}

ostream &operator<<(ostream &out, Hand *hand)
{
  hand->print(out);
  return out;
}

