#ifndef MY_CARD_H
#define MY_CARD_H
#define str(s) stri(s)
#define stri(s) #s
#define DBNAME flashcarddatabase.db
#include<string>
#include<iostream>
enum assesments{great, good, neutral, bad, terrible};
class card
{
    private:
        //the main word/string that will be displayed
        std::string data;
        //the answer found on the back of the card
        std::string answer;
        //The assesment of user knowledge of this card
        double weight;
        //an optional subphrase that will appear under data as an aside or hint of the card
        std::string sentence;
         //void updateWeight(assesments rating);
    public:
        void updateWeight(assesments rating);
        card(std::string data, std::string answer, std::string sentence);
       // ~card();
        std::string getData() const {return data;}
        std::string getAnswer() const {return answer;}
        std::string getSentence() const{return sentence;}
        double getWeight() const {return weight;}
        void setWeight(double w){weight = w; return;}
        void displayQuestion();
        void displayAnswer(bool userAnswer);

};

struct compare{
     bool operator()(const card a, card b){return a.getWeight() > b.getWeight();}
};

#endif 
