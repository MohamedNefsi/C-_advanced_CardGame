#include "headers/DiscardPile.h"


DiscardPile::DiscardPile(istream &, const CardFactory *)
{
  
  throw Unimplemented();
}

DiscardPile &DiscardPile::operator+=(Card *c)
{
  push_back(c);
  return *this;
}


Card *DiscardPile::top()
{
  if (empty())
    return nullptr;

  Card *x = back();
  return x;
}


Card *DiscardPile::pickUp()
{
  if (empty())
    return nullptr;

  Card *x = back();
  pop_back();
  return x;
}

void DiscardPile::print(ostream &out)
{
  if (!empty())
  {
    for (long unsigned int i = 0; i < size(); i++)
      out << at(i);
    out << endl;
  }
}

ostream &operator<<(ostream &out, DiscardPile &pile)
{
  if (!pile.empty())
    out << pile.back();
  return out;
}

ostream &operator<<(ostream &out, DiscardPile *pile)
{
  if (!pile->empty())
    out << pile->back();
  return out;
}