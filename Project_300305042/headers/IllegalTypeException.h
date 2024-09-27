

#ifndef illegalTypeException_h
#define illegalTypeException_h

#include <iostream>
#include <exception>
#include "chain.h"
using namespace std;



class IllegalType : public exception
{
public:
  const char *what() const throw()
  {
    return "Illegal type exception.";
  }
};

class CoinValueNotFound : public exception
{
public:
  const char *what() const throw()
  {
    return "Une valeur de piece pour ce nombre de pieces n'a pas été trouvée.";
  }
};

class CardNotFound : public exception
{
public:
  const char *what() const throw()
  {
    return "La carte demandee n'a pas ete trouvee.";
  }
};

class ChainAtIndexNotFound : public exception
{
public:
  const char *what() const throw()
  {
    return "Une chaine n'existe pas a l'index indique.";
  }
};

class HandEmpty : public exception
{
public:
  const char *what() const throw()
  {
    return "La main est vide";
  }
};

class DeckEmpty : public exception
{
public:
  const char *what() const throw()
  {
    return "Le Deck est vide";
  }
};

class Unimplemented : public exception
{
public:
  const char *what() const throw()
  {
    return "Cette fonction n'a pas encore été implementee.";
  }
};

class PlayerChainsFull : public exception
{
public:
  const char *what() const throw()
  {
    return "Impossible d'ajouter une nouvelle chaine.";
  }
};

#endif