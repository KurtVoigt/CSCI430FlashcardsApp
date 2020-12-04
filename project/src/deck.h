#ifndef MY_DECK_H
#define MY_DECK_H
#include "card.h"
#include <vector>
#include <queue>
#include <stdio.h>
#include<iostream>
#include <sqlite3.h>
#include <stdlib.h>
//#include "../cards/FlashCards/loadDeckFrame.h"
class loadDeckFrame;
class deck{
    private:
        //deck of card objects, a priority queue in the form of a min heap, lowest weighted card will be at top
        std::priority_queue<card, std::vector<card>, compare> deckInstance;
        //std::priority_queue<card, std::vector<card>, compare> deckInstance;
        double weight;
        std::string name;
        //construct deck from information already in database, used by readDeck()


    public:
        deck(std::string deckName);
        std::string getName(){return name;}
        card *displayDeck();
        //construct new deck from scratch and record it in database
        deck(std::string newName, bool flag);
        void writeDeck();
        void updateDeck();
        void readDeck();
        double getWeight() const{return weight;}
        void setWeight(double w){weight = w; return;}
        void pushCard(card c);
        std::vector<std::string> randomAnswers(std::string name);

};

#endif 
