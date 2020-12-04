
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
  

//displays question, right now to output stream but modify to GUI
void card::displayQuestion(){
    std::string attempt = "";
    std::cout << data << std::endl << '>';
    bool userAnswer = false;
    for(int i=1; i <4; i++){
        std::cout << data << std::endl << '>';
        std::cin >> attempt;
        if(attempt == answer){
            userAnswer = true;
            break;
        }
        else{
            std::cout << "Incorrect. Attempts remaning: "<< 3-i << std::endl << '>';
        }
    }
     card::displayAnswer(userAnswer);

}
    //if parameter is true answer was correct, get feedback at this stage and updateWeight
void card::displayAnswer(bool userAnswer){
    std::string rating;
    assesments assesment;
    if(userAnswer){
        std::cout << "Correct, how do you feel about this card?" << std::endl << "(Great, good, neutral, bad, very bad)" << std::endl << '>';
        std::cin >> rating;
        if(rating == "great")
            assesment = great;
        if(rating == "good")
            assesment = good;
        if(rating == "neutral")
            assesment = neutral;
        if(rating == "bad")
            assesment = bad;
        if(rating == "terrible")
            assesment = terrible;
        card::updateWeight(assesment);
    }
   else{
        std::cout << "Incorrect, how do you feel about this card?" << std::endl << "(Great, good, neutral, bad, very bad)" << std::endl << '>';
        std::cin >> rating;
        if(rating == "great")
            assesment = great;
        if(rating == "good")
            assesment = good;
        if(rating == "neutral")
            assesment = neutral;
        if(rating == "bad")
            assesment = bad;
        if(rating == "terrible")
            assesment = terrible;
        card::updateWeight(assesment);
    }
        
}






