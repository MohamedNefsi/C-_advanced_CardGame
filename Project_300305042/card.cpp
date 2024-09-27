#include "headers/Card.h"

std::ostream& operator<<(std::ostream& _os, const Card& _c) {
	_c.print(_os);
	return _os;
}

ostream &operator<<(ostream &out, Card *card)
{

  card->print(out);
  return out;
}

int Blue::getCardsPerCoin(int coins) const {
	int nCards;
    if (coins==1){
        nCards = 4 ; 
    }
    if (coins==2){
        nCards = 6 ; 
    }
    if (coins==3){
        nCards = 8 ; 
    }
    if (coins==4){
        nCards = 10 ; 
    }
    return nCards; 
}


string Blue::getName() const {
	return name;
}

void Blue::print(std::ostream& out) const {
	out << "B";
	return;
}

//Chili
int Chili::getCardsPerCoin(int coins) const {
	int nCards;
    if (coins==1){
        nCards = 3 ; 
    }
    if (coins==2){
        nCards = 6 ; 
    }
    if (coins==3){
        nCards = 8 ; 
    }
    if (coins==4){
        nCards = 9 ; 
    }
    return nCards; 

}

string Chili::getName() const {
	return name;
}

void Chili::print(std::ostream& out) const {
	out << "C";
	return;
}

//Stink
int Stink::getCardsPerCoin(int coins) const {
	int nCards;
    if (coins==1){
        nCards = 3 ; 
    }
    if (coins==2){
        nCards = 5 ; 
    }
    if (coins==3){
        nCards = 7 ; 
    }
    if (coins==4){
        nCards = 8 ; 
    }
    return nCards; 
}

string Stink::getName() const {
	return name;
}

void Stink::print(std::ostream& out) const {
	out << "S";
	return;
}


//Green
int Green::getCardsPerCoin(int coins) const {
	int nCards;
    if (coins==1){
        nCards = 3 ; 
    }
    if (coins==2){
        nCards = 5 ; 
    }
    if (coins==3){
        nCards = 6 ; 
    }
    if (coins==4){
        nCards = 7 ; 
    }
    return nCards; 
}

string Green::getName() const {
	return name;
}

void Green::print(std::ostream& out) const {
	out << "G";
	return;
}


//soy
int Soy::getCardsPerCoin(int coins) const {
	int nCards;
    if (coins==1){
        nCards = 2 ; 
    }
    if (coins==2){
        nCards = 4 ; 
    }
    if (coins==3){
        nCards = 6 ; 
    }
    if (coins==4){
        nCards = 7 ; 
    }
    return nCards; 
}

string Soy::getName() const {
	return name;
}

void Soy::print(std::ostream& out) const {
	out << "s";
	return;
}


//black
int Black::getCardsPerCoin(int coins) const {
	int nCards;
    if (coins==1){
        nCards = 2 ; 
    }
    if (coins==2){
        nCards = 4 ; 
    }
    if (coins==3){
        nCards = 5 ; 
    }
    if (coins==4){
        nCards = 6 ; 
    }
    return nCards; 
}

string Black::getName() const {
	return name;
}

void Black::print(std::ostream& out) const {
	out << "b";
	return;
}


//Red
int Red::getCardsPerCoin(int coins) const {
	int nCards;
    if (coins==1){
        nCards = 2 ; 
    }
    if (coins==2){
        nCards = 3 ; 
    }
    if (coins==3){
        nCards = 4 ; 
    }
    if (coins==4){
        nCards = 5 ; 
    }
    return nCards; 
}

string Red::getName() const {
	return name;
}

void Red::print(std::ostream& out) const {
	out << "R";
	return;
}



//Stink
int Garden::getCardsPerCoin(int coins) const {
	int nCards;

    if (coins==2){
        nCards = 2 ; 
    }
    if (coins==3){
        nCards = 3 ; 
    }
    return nCards; 

}

string Garden::getName() const {
	return name;
}

void Garden::print(std::ostream& out) const {
	out << "g";
	return;
}