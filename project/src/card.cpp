
#include "card.h"


card::card(std::string data, std::string answer, std::string sentence){
    this->data = data;
    this->answer = answer;
    this->weight = 0;
    this->sentence = sentence;
}
//updates weight of card based off of user assment given in displayAswer()
void card::updateWeight(assesments rating){
    if(rating == great)
        weight = weight + .4;
    if(rating == good)
        weight = weight + .2;
    if(rating == neutral)
        weight = weight + .1;
    if(rating == bad)
        weight = weight - .2;
    if(rating == terrible)
        weight = weight - .4;

    if(weight > 1.0)
        weight = 1.0;
    if(weight < 0.0)
        weight = 0.0;
}
  







