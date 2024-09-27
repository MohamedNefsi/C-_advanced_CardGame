#include "headers/Table.h"


Table::Table(istream &i, const CardFactory *factory)
{
}

Table::Table(string player1Name, string player2Name)
{
  player1 = new Player(player1Name);
  player2 = new Player(player2Name);

  CardFactory *factory = factory->getFactory();

  deck = (factory->getDeck());

  discardPile = new DiscardPile();
  tradeArea = new TradeArea();
}

bool Table::win(string &str)
{
  if (deck.empty())
  {
    if (player1->getNumCoins() > player2->getNumCoins())
      str = player1->getName();
    else
      str = player2->getName();

    return true;
  }
  return false;
};

void Table::prettyPrint(ostream &out)
{
  out << player1;
  out << player2;
  out<<endl;
  out << "Trade Area:\t" << tradeArea;
  out<<endl;
  out << "discard Pile:\t" << discardPile;
}


void Table::print(ostream &out)
{



  out << IJOUEURS << endl;
  out << player1;
  out << player2;
  out << IDECK << endl;
  out << deck;
  out << TYPESPACER << endl;
  out << ITRADEAREA << endl;
  out << tradeArea;
  out << TYPESPACER << endl;
  out << IDISCARDPILE << endl;
  out << discardPile;
  out << TYPESPACER << endl;

}

ostream &operator<<(ostream &out, Table &table)
{
  table.print(out);
  return out;
};

ostream &operator<<(ostream &out, Table *table)
{
  table->print(out);
  return out;
};