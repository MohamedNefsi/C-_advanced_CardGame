#include "headers/Chain.h"


Chain_Base::Chain_Base(istream &, const CardFactory *)
{
}

template <typename T>

int Chain<T>::getSize(){


  return cards.size();
}

template <typename T>
Chain_Base &Chain<T>::operator+=(Card *c)
{
  if (typeid(*c) == typeid(T))
  {
    cards.push_back(dynamic_cast<T *>(c));
    return *this;
  }
  else
    throw IllegalType();
}

template <typename T>
int Chain<T>::sell()
{
  unsigned int size = cards.size();
  if (size > 0)
  {
    unsigned int coins = 4; 
    unsigned int min_cards = 0;

    
    while (coins >= 1)
    {
      try
      {


        min_cards = cards[0]->getCardsPerCoin(coins);

        if (size >= min_cards)

          return coins;
      }
      catch (CoinValueNotFound &e)
      {
      };

      coins--;
    }
  }
  return 0;
}

template <typename T>

Card* Chain<T>::getExampleItem(){
  return new T;
}

template <typename T>

void Chain<T>::print(ostream &out)
{
  if (!cards.empty())
  {
    T *first = cards.at(0);

    out << first->getName() << "  ";

    for (long unsigned int i = 0; i < cards.size(); i++)
    {
      out << " ";


      first->print(out);
    }
    return;
  }

  T s = T();
  out << s.getName();
}

ostream &operator<<(ostream &out, Chain_Base &chain)

{
  chain.print(out);
  return out;
}
