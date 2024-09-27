#ifndef table_h
#define table_h

#include "Player.h"
#include "TradeArea.h"
#include "DiscardPile.h"
#include "deck.h"

class Table
{

    const string IJOUEURS = "JOUEURS",
                 IDECK = "DECK",
                 ITRADEAREA = "TRADE AREA",
                 IDISCARDPILE = "DISCARD PILE",
                 TYPESPACER = "||";
    
public:
  Player *player1;
  Player *player2;
  Deck deck;
  DiscardPile *discardPile;
  TradeArea *tradeArea;

  Table() = default;
  ~Table() = default;
  Table(istream &, const CardFactory *);
  Table(string player1Name, string player2Name);

  bool win(string &); //renvoie true si le joueur a gagné.
  void printHand(bool); // False : affiche la première carte de la main du joueur.  True : u l'ensemble de la main du joueur


  void prettyPrint(ostream &);
  void print(ostream &);
  friend ostream &operator<<(ostream &out, Table &table);
  friend ostream &operator<<(ostream &out, Table *table);  
};


#endif