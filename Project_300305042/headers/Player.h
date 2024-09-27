#ifndef player_h
#define player_h

#include <string>
#include "chain.h"

#include "hand.h" 

using namespace std;

class Player
{
private:
  string name;
  int coins;
  int maxNumChains;

public:
  vector<Chain_Base *> *chains;
  Hand *hand;

  Player();
  ~Player();

  Player(string &); //constructeur qui crée un objet de type Player avec un nom donné
  Player(istream &, const CardFactory *);

  string getName(); //obtenir le nom du joueur
  int getNumCoins(); //obtenir le nombre de pièces actuellement détenues par le joueur
  Player &operator+=(int); //ajoute un nombre de pièces 
  int getMaxNumChains(); //renvoie 2 ou 3.
  int getNumChains(); //renvoie la chaîne en position i


  Chain_Base &operator[](int i);

  void buyThirdChain(); //ajoute une troisième chaîne vide au joueur pour deux pièces...

  void printHand(ostream &, bool);
  Chain_Base *getChain(int);


  void print(ostream &);
  friend ostream &operator<<(ostream &, Player &);
  friend ostream &operator<<(ostream &, Player *);

  void addChain(Chain_Base *);
};



#endif