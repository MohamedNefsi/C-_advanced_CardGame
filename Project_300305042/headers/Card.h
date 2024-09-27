#ifndef Card_h
#define Card_h



#include <iostream> 

#include <cstdlib> 

using namespace std;



class Card{
    protected:
        
        string name;
    public:
        virtual int getCardsPerCoin(int coins) const =0;
        virtual string getName()const =0;
        virtual void print(ostream& out)const =0;
        friend std::ostream& operator<<(std::ostream&, const Card&);
        friend ostream &operator<<(ostream &, Card *);
};

//Blue 
class Blue : public Card{
        string name = "Blue";
    public:
        int getCardsPerCoin(int coins) const ; 
        string getName() const;
        void print(ostream& out) const;
       
    
};



//Chili
class Chili : public Card{
    string name = "Chili";
    public:
        int getCardsPerCoin(int coins) const ; 
        string getName() const;
        void print(ostream& out) const;
        
    
};


//Stink
class Stink : public Card{
    string name = "Stink";
    public:
        int getCardsPerCoin(int coins) const ; 
        string getName() const;
        void print(ostream& out) const;
        
};


//Green
class Green : public Card{
    string name = "Green";
    public:
        int getCardsPerCoin(int coins) const ; 
        string getName() const;
        void print(ostream& out) const;
        
    
};


//soy
class Soy : public Card{
    string name = "soy";
    public:
        int getCardsPerCoin(int coins) const ; 
        string getName() const;
        void print(ostream& out) const;
       
    
};


//black
class Black : public Card{
    string name = "black";
    public:
        int getCardsPerCoin(int coins) const ; 
        string getName() const;
        void print(ostream& out) const;
        
    
};


//Red
class Red : public Card{
    string name = "Red";
    public:
        int getCardsPerCoin(int coins) const ; 
        string getName() const;
        void print(ostream& out) const;
        
    
};


//garden
class Garden : public Card{
    string name = "garden";
    public:
        int getCardsPerCoin(int coins) const ; 
        string getName() const;
        void print(ostream& out) const;
        
    
};





#endif