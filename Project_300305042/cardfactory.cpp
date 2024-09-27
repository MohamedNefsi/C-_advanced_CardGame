#include "headers/CardFactory.h"




// on initialise l'instance static pour pouvoire l'acceder 
CardFactory *CardFactory::internal = new CardFactory();

Deck *CardFactory::deck = nullptr;


CardFactory::CardFactory()
{
  delete deck; // on reinsialise le deck et on le remplis
  deck = new Deck();

  for (int i = 0; i < 104; i++) {
        if (i < 20) {
            (*deck).push_back(new Blue());
        } else if (i < 38) {
            (*deck).push_back(new Chili());
        } else if (i < 54) {
            (*deck).push_back(new Stink());
        } else if (i < 68) {
            (*deck).push_back(new Green());
        } else if (i < 80) {
            (*deck).push_back(new Soy());
        } else if (i < 90) {
            (*deck).push_back(new Black());
        } else if (i < 98) {
            (*deck).push_back(new Red());
        } else {
            (*deck).push_back(new Garden());
        }
  }
}

CardFactory *CardFactory::getFactory()
{

  return CardFactory::internal;
}


Deck CardFactory::getDeck()
{
  Deck deckCopy = *deck;

  shuffle(begin(deckCopy), end(deckCopy), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));

  return deckCopy;
}
