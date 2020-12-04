#include "loadDeckFrame.h"
#include "ui_loadDeckFrame.h"
#include "flashcards.h"
#include <QDebug>
#include <time.h>
loadDeckFrame::loadDeckFrame(QMainWindow *parent) :
    par(parent),
    QFrame(parent),
    ui(new Ui::loadDeckFrame)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    deckNames = getDeckNames();
    ui->deckList->setFont(QFont("Noto Sans", 12));
    //populate list with decknames
    for(std::size_t i = 0; i < deckNames.size(); i++){
       // QListWidgetItem * label = new QListWidgetItem;
        QString s = QString::fromStdString(deckNames[i]);
       // label->setText(s);
        ui->deckList->addItem(s);
    }

}

loadDeckFrame::~loadDeckFrame()
{
    delete ui;
}

void loadDeckFrame::updateCard(card *c, assesments a){
    c->updateWeight(a);
    displayDeck->pushCard(*c);
    qDebug() << c->getWeight();
    delete c;
    displayQuestion();
}

void loadDeckFrame::graftQAFrame(QFrame *f){
    QLayoutItem *widge;
    while( (widge = ui->verticalLayout->takeAt(0)) != NULL){
        delete widge->widget();
        delete widge;
    }
    ui->verticalLayout->addWidget(f);
}

int deckNamescallback(void *ret, int argc, char **argv, char **azColName){
    std::vector<std::string> *names = reinterpret_cast<std::vector<std::string> *>(ret);
    names->push_back(std::string(argv[0]));
    return 0;
}

//returns all of the deck names in a vector of strings
std::vector<std::string> loadDeckFrame::getDeckNames(){
    std::string sql;
    int rc;
    sqlite3 *db;
    char *zErrMsg = 0;
    //std::vector<char*> *ret;
    std::vector<std::string> ret;
    std::vector<std::string> *ptr = &ret;

    rc = sqlite3_open(str(DBNAME), &db);
    if(rc) {//if rc == 1 that means that whatever sqlite operation failed, 0 is good!
      std::cerr << "DB Error: " << sqlite3_errmsg(db) << std::endl;
    }
    sql = "SELECT NAME FROM 'DECKS';";

    rc = sqlite3_exec(db, sql.c_str(), deckNamescallback, ptr, &zErrMsg);
    //have to error check is there are no decks?
    return ret;
}

void loadDeckFrame::on_displayDeckButton_clicked()
{
    QListWidgetItem *item = ui->deckList->currentItem();
    //qDebug() << "Selected " + item->text();
    displayDeck = new deck(item->text().toStdString());
    //deck is now loaded into main memory, time to display question
   /* ui->backButton->close();
    ui->deckList->close();
    ui->displayDeckButton->close();
    ui->label->close();*/
    //delete ui->verticalLayout;

    displayQuestion();


}


//refactor d to displaydeck member
void loadDeckFrame::displayQuestion(){
    deck * d = displayDeck;
    card *c = displayDeck->displayDeck();
    std::vector<std::string> answers = displayDeck->randomAnswers(displayDeck->getName());
    std::vector<int> buttons{0,1,2,3};
    srand(time(NULL));
    //choose which button will be the true button
    c->getData();

    if(c->getWeight() != 1.0){
        //make question window
        qf = new questionFrame(this);
        qf->setQuestionTag(QString::fromStdString(c->getData()));
        qf->setSentenceTag(QString::fromStdString(c->getSentence()));
        //choose which button will get the correct answer
        int index = rand() % buttons.size();
        switch (buttons[index]) {
        case 0:
            qf->setUpLeftButton(QString::fromStdString(c->getAnswer()));
            break;
         case 1:
            qf->setUpRightButton(QString::fromStdString(c->getAnswer()));
            break;
         case 2:
            qf->setBotLeftButton(QString::fromStdString(c->getAnswer()));
            break;
         case 3:
            qf->setBotRightButton(QString::fromStdString(c->getAnswer()));
            break;
        default:
            qDebug() << "Something went wrong with display question switch statement" << index;
            break;
        }
        buttons.erase(buttons.begin() + index);

        //assign random answers to other buttons
        for(std::size_t y = 0; y < buttons.size(); y++){
            index = rand() % answers.size();
            if(answers[index] == c->getAnswer())
                y--;//THIS COULD TECHNICALLY BE AN INFINITE LOOP
            else{
                switch (buttons[y]) {
                    case 0:
                        qf->setUpLeftButton(QString::fromStdString(answers[index]));
                       // buttons.erase(buttons.begin() + y);
                        break;
                     case 1:
                        qf->setUpRightButton(QString::fromStdString(answers[index]));
                        // buttons.erase(buttons.begin() + y);
                        break;
                     case 2:
                        qf->setBotLeftButton(QString::fromStdString(answers[index]));
                        // buttons.erase(buttons.begin() + y);
                        break;
                     case 3:
                        qf->setBotRightButton(QString::fromStdString(answers[index]));
                       //  buttons.erase(buttons.begin() + y);
                        break;
                    default:
                        qDebug() << "Something went wrong with display question switch in for loop statement";
                        break;
                    }
            }
        }

        qf->setCurrentCard(c);
        //gui objects are now set up with apprpriate objects, put question frame into load deck frame
        //ui->verticalLayout->addWidget(qf);
        graftQAFrame(qf);
        //QUESTION FRAME WILL REPLACE ITSELF WITH ANSWER FRAME PASSING OFF TO EACH OTHER UNTIL THIS TOP IF STATEMENT FAILS

    }

    //ELSE GO BACK TO MAIN MENU
    else{
        displayDeck->updateDeck();
        delete displayDeck;//might not work
        sf = new startFrame(par);
        this->close();
        par->setCentralWidget(sf);
    }
}


void loadDeckFrame::on_backButton_clicked()
{
    sf = new startFrame(par);
    this->close();
    par->setCentralWidget(sf);
}
