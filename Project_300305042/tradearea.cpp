#include "headers/TradeArea.h"

/**
 * TradeArea implementation.
 */

TradeArea::TradeArea(istream &in, const CardFactory *cf)
{
    throw Unimplemented();
}

TradeArea &TradeArea::operator+=(Card *c)
{
    push_back(c);
    return *this;
}

bool TradeArea::legal(Card *newCard)
{
    const string newCardName = newCard->getName();

    for (list<Card *>::iterator it = this->begin(); it != this->end(); ++it)

        if ((*it)->getName() == newCardName)
            return true;

    
    return false;
}

Card *TradeArea::trade(string removeCardName)
{
    for (list<Card *>::iterator it = this->begin(); it != this->end(); ++it)
    {
        if ((*it)->getName() == removeCardName)
        {
            remove(*it);
            return *it;
        }
    }

    throw CardNotFound();
}

int TradeArea::numCards()
{
    return size();
}



void TradeArea::print(ostream &out)
{
    for (list<Card *>::iterator it = this->begin(); it != this->end(); ++it)
        (*it)->print(out);
}

ostream &operator<<(ostream &out, TradeArea &ta)
{
    ta.print(out);
    return out;
}

ostream &operator<<(ostream &out, TradeArea *ta)
{
    ta->print(out);
    return out;
}



void TradeArea::discardAll(DiscardPile &discard)
{
    if(discard.empty()){
        cout<<"DiscardPile est vide"<<endl;
    }
    else{
        for (list<Card *>::iterator it = this->begin(); it != this->end(); ++it)
        discard += *it;

        
        clear();
    }
    
}