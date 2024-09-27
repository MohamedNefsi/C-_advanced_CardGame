#include "main.h"


bool promptAOrB();
bool promptYesOrNo();




int main()
{
  
  bool onwards = true;        //Debut du programme

  string userInput = "";
  string player1Name;
  string player2Name;
  CardFactory *factory = factory->getFactory();

  
  while (onwards)
  {
    
    cout << "Bienvenue. Pour jouer a un nouveau jeu, entrez : A . Pour charger un ancien a partir du fichier, entrez B";
    
    bool play_newgame = promptAOrB();

    if (play_newgame)   //Si le joueur ne veut pas jouer une nouvelle partie, on l'invite a charger une. 
    {
      onwards = false;
      cout << "Veuillez saisir un nom pour le joueur 1 :";
      cin >> player1Name ;
      cout<<endl;
      cout << "Veuillez saisir un nom pour le joueur 2 :";
      cin >> player2Name ;
      cout<<endl;
      runGame(player1Name, player2Name, cout, cin);
    }
    else
    {
      //pas implementer
      cout<<"Non disponible ";
    }


  }
}




bool promptAOrB()
{
  string input;
  do
  {
    cout << " (A/B) ?> ";
    cin >> input;
    
    input = tolower(input[0]);
  } while (input != "a" && input != "b");
  cout << endl;
  return input == "a";
}



Chain_Base *makeNewChain(Card *card)
{
  if (card->getName() == "Blue")
    return new Chain<Blue>;
  else if (card->getName() == "Chili")
    return new Chain<Chili>;
  else if (card->getName() == "Black")
    return new Chain<Black>;
  else if (card->getName() == "Green")
    return new Chain<Green>;
  else if (card->getName() == "Stink")
    return new Chain<Stink>;
  else if (card->getName() == "Soy")
    return new Chain<Soy>;
  else if (card->getName() == "Red")
    return new Chain<Red>;
  else if (card->getName() == "Garden")
    return new Chain<Garden>;
  else
    throw CardNotFound();
}

// ajoute une carte a une chaine, vend une chaine pre-existante et cree une nouvelle
void chainCard(Card *card, Player *currentPlayer,
               vector<Chain_Base *> *chains)
{
  if (card == nullptr)
  {
    return;
  }

  Card *currentPlay = card;
  bool playable = false;


  for (int i = 0; i < currentPlayer->getNumChains(); i++)
  {
    Chain_Base *currChain = currentPlayer->getChain(i);

    if (currChain->getExampleItem()->getName() == currentPlay->getName())
    {
      playable = true;

      if (currChain->getSize() >= 4)
      {


        currentPlayer += currChain->sell();

        chains->push_back(makeNewChain(currChain->getExampleItem()));

        currChain = chains->back();

        chains->erase(chains->begin() + i);
      }

      currChain->operator+=(currentPlay);
      playable = true;
      break;
    };
  }

  
  if (playable == false)
  {
    int maxChainLength = 0;
    Chain_Base *maxChain;
    if (currentPlayer->getNumChains() <= 0)
    {
      chains->push_back(makeNewChain(currentPlay));
      (*chains)[0]->operator+=(currentPlay);
      return;
    }



    for (int i = 0; i < currentPlayer->getNumChains(); i++)
    {
      Chain_Base *currChain = currentPlayer->getChain(i);
     
      
      if (currChain->getSize() > maxChainLength && currChain->getSize() <= 4)
      {
        maxChainLength = currChain->getSize();
        maxChain = currChain;
      }
    }

  
    currentPlayer->operator+=(maxChain->sell());
    
    (void)remove(chains->begin(), chains->end(), maxChain);

   
    chains->push_back(makeNewChain(currentPlay));
    chains->back()->operator+=(currentPlay);
  }
}

void playCard(Player *currentPlayer, vector<Chain_Base *> *chains)
{
  Card *currentPlay =
      currentPlayer->hand->play();               
  chainCard(currentPlay, currentPlayer, chains); 
}

bool handContainsCard(Hand hand, string str, long  &index)
{
  for (long  i = 0; i < hand.size(); i++)
  {
    if (hand[i]->getName() == str)
    {
      index = i;
      return true;
    }
  }
  return false;
}

bool topCardisInTradeArea(DiscardPile discardPile, TradeArea trade)
{
  if (discardPile.empty())
  {
    return false;
  }

  for (auto card : trade)
  {
    if (discardPile.top()->getName() == card->getName())
    {
      return true;
    }
  }
  return false;
}

void pauseGame() { throw Unimplemented(); }

void runGame(string player1, string player2, ostream &outputStream,
             istream &inputStream)
{
  Table *table = new Table(player1, player2);
  string winner;
  string input = "";
  Player *currentPlayer;

  for (int i = 0; i < 5; i++)
  {
    table->player1->hand->push_back(table->deck.draw());
    table->player2->hand->push_back(table->deck.draw());
  }

  while (!table->win(winner))
  {
    outputStream << "Voudriez vous mettre le jeu en pause :";
    bool pause_choice = promptYesOrNo();
    if (pause_choice)
      pauseGame();

    input = "";
    for (int i = 0; i < 2; i++)
    {

      if (i == 0)
      {
        currentPlayer = table->player1;
      }
      else
      {
        currentPlayer = table->player2;
      }
      outputStream << endl;
      outputStream << endl;
      outputStream << "C'est le tour de :  " << currentPlayer->getName()  << endl;
      vector<Chain_Base *> *chains = currentPlayer->chains;
      table->prettyPrint(outputStream);
      currentPlayer->hand->operator+=(table->deck.draw());

      if (table->tradeArea->numCards() >= 0)
      {
        outputStream << endl;
        outputStream << "Trade Area: " << table->tradeArea;

        outputStream << "\nVoudriez vous ajoutez les cartes de 'trade area' dans votre chaine? (A) Ou les supprimez? (B)";

        bool add_to_chains = promptAOrB();

        if (add_to_chains)
        {
          
          if ((*chains).size() <= 0)
          {
            outputStream << "\n Vous n'avez aucune chaine disponible\n!";

            table->tradeArea->discardAll(*table->discardPile);
          }
          for (int i = 0; i < currentPlayer->getNumChains(); i++)
          {
            Chain_Base *chain = currentPlayer->getChain(i);

            if (table->tradeArea->legal(chain->getExampleItem()))
            {
              table->tradeArea->trade(chain->getExampleItem()->getName());

              if (chain->getSize() >= 4)
              {
                currentPlayer += chain->sell();
               

                chains->push_back(makeNewChain(chain->getExampleItem()));
                chain = chains->back();
                
                chains->erase(chains->begin() + i);
              }

              *chain += chain->getExampleItem();
            }
          }
        }
        else
        {
          table->tradeArea->discardAll(*table->discardPile);
        }
      }
      
      playCard(currentPlayer, chains);
      outputStream << currentPlayer->getName()
                   << " a joue une carte";

      outputStream << "\nVotre premiere carte est : "
                   << (*currentPlayer->hand->top()) << endl;
      outputStream << "Vos chaines sont :";
      for (auto chain : *chains)
      {
        outputStream << *chain;
        outputStream << endl;
      }
      outputStream << endl;
      input = "";
      outputStream << "Voulez vous jouer votre premiere carte? y/n\n";
      while (input != "n" && input != "y")
      {
        inputStream >> input;
      }
      if (input == "y")
      {
        playCard(currentPlayer, chains);
      }
      outputStream
          << "Voulez vous ontrez votre mains et supprimer une carte y/n\n";
      input = "";
      while (input != "n" && input != "y")
      {
        inputStream >> input;
      }
      Hand *hand = currentPlayer->hand;
      if (input == "y")
      {
        currentPlayer->hand->print(outputStream);
        outputStream
            << "\nQuelle carte vous voulez enlever?Veuillez entrer son nom coplet (ex : Red) : \n";
        input = "";
        bool validCardNotPicked = true;
        while (validCardNotPicked)
        {
          inputStream >> input;
          long  index;

          if (handContainsCard(*hand, input, index))
          {
            table->discardPile->push_back(hand->at(index));
            hand->erase(hand->begin() + index);
            validCardNotPicked = false;
          }
        }
      }
      
      for (int i = 0; i < 3; i++)
      {
        table->tradeArea->push_back(table->deck.draw());
      }

      while (topCardisInTradeArea(*table->discardPile, *table->tradeArea))
      {
        Card *tradeCard = table->discardPile->back();
        table->tradeArea->push_back(tradeCard);
        table->discardPile->pop_back();
      }

      outputStream << "Veux tu prendre des cartes de 'trade area'?\n";
      outputStream << "trade area:\n";
      table->tradeArea->print(outputStream);
      outputStream << endl;
      outputStream << "Chains: ";
      for (auto chain : *chains)
      {
        chain->print(outputStream);
        outputStream << endl;
      }
      outputStream << endl;
      for (auto card : *table->tradeArea)
      {
        outputStream << card << endl;
        outputStream << "Veux tu enchainer cette carte? y/n";
        input = "";
        inputStream >> input;
        while (input != "y" && input != "n")
        {
          inputStream >> input;
        }

        if (input == "y")
        {
          chainCard(card, currentPlayer, chains);
          (void)remove(table->tradeArea->begin(), table->tradeArea->end(), card);
        }
      }
      currentPlayer->hand->push_back(table->deck.draw());
    }
  }
}

void loadPreviousGame(string filename)
{
  throw Unimplemented();
}

bool promptYesOrNo()
{
  string input;
  do
  {
    cout << " (Y/n) ?> ";
    cin >> input;
    input = tolower(input[0]);
  } while (input != "y" && input != "n");
  
  cout << endl;
  return input == "y";
}