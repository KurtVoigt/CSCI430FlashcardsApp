#include "editDeckFrame.h"
#include "ui_editDeckFrame.h"


int deckNamescallback(void *ret, int argc, char **argv, char **azColName);
int editcardcallback(void *ret, int argc, char **argv, char **azColName);
editDeckFrame::editDeckFrame(QMainWindow *parent) :
    par(parent),
    QFrame(parent),
    ui(new Ui::editDeckFrame)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    deckNames = getDeckNames();
    ui->deckList->setFont(QFont("Noto Sans", 12));
    //populate list with decknames
    populateListWithDecks();
    cardEditState(false);

}



void editDeckFrame::cardEditState(bool b){
    ui->answerLineEdit->setEnabled(b);
    ui->addCardButton->setEnabled(b);
    ui->questionLineEdit->setEnabled(b);
    ui->sentenceLineEdit->setEnabled(b);
   // ui->deleteCardButton->setEnabled(b);
}

editDeckFrame::~editDeckFrame()
{
    delete ui;
}
void editDeckFrame::on_addCardButton_clicked()
{
    QString data = ui->questionLineEdit->text();
    QString ans = ui->answerLineEdit->text();
    QString sent = ui->sentenceLineEdit->text();
    card c(data.toStdString(),ans.toStdString(), sent.toStdString());
    insertCard(c);
    ui->questionLineEdit->clear();
    ui->answerLineEdit->clear();
    ui->sentenceLineEdit->clear();
}

void editDeckFrame::on_selectDeckButton_clicked()
{
    if(ui->selectDeckButton->text() == "Back to Deck Selection"){
        ui->deckList->clear();
        ui->selectDeckButton->setText("Select Deck");
        cardEditState(false);
        populateListWithDecks();
        currentDeckName = "";


    }
    else{
        currentDeckName = ui->deckList->currentItem()->text();
        ui->selectDeckButton->setText("Back to Deck Selection");
        cv = getCards(currentDeckName);
        ui->deckList->clear();
        cardEditState(true);
        populateListWithCards(cv);

    }


}

void editDeckFrame::on_deleteCardButton_clicked()
{
    if(ui->selectDeckButton->text() == "Back to Deck Selection"){//in a deck, delete specified card

         QString s = ui->deckList->currentItem()->text().section('|',0,0);
         s.chop(1);
         deleteCard(s, currentDeckName);
         ui->deckList->currentItem()->setHidden(true);
    }

    else{//delete specified deck
        deleteCard("", ui->deckList->currentItem()->text());
        ui->deckList->currentItem()->setHidden(true);
    }
}

void editDeckFrame::on_mainMenuButton_clicked()
{
    FlashCards* hopeThisWorks = qobject_cast<FlashCards*>(par);
    sf = new startFrame(par);
    hopeThisWorks->centralWidget()->close();
    this->close();
    hopeThisWorks->setCentralWidget(sf);
}

std::vector<std::string> editDeckFrame::getDeckNames(){
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

std::vector<card> editDeckFrame::getCards(QString deckName){
    std::string sql;
    int rc;
    sqlite3 *db;
    char *zErrMsg = 0;
    std::string name = deckName.toStdString();
    rc = sqlite3_open(str(DBNAME), &db);
    std::vector<card> ret;
    std::vector<card> *ptr = &ret;
    if(rc) {//if rc == 1 that means that whatever sqlite operation failed, 0 is good!
      std::cerr << "DB Error: " << sqlite3_errmsg(db) << std::endl;
    }

    sql = "SELECT WEIGHT, DATA, ANSWER, SENTENCE FROM 'CARDS' WHERE DECK = '"+name+"';";
    rc = sqlite3_exec(db, sql.c_str(), editcardcallback, ptr, &zErrMsg);

    return ret;
}

//




void editDeckFrame::populateListWithCards(std::vector<card> cv){
    QString x = " | ";
    for(std::size_t i = 0; i < cv.size(); i++){

        QString s = QString::fromStdString(cv[i].getData()) + x + QString::fromStdString(cv[i].getAnswer()) + x + QString::fromStdString(cv[i].getSentence());
        ui->deckList->addItem(s);
    }
}

void editDeckFrame::populateListWithDecks(){
    for(std::size_t i = 0; i < deckNames.size(); i++){
       // QListWidgetItem * label = new QListWidgetItem;
        QString s = QString::fromStdString(deckNames[i]);
       // label->setText(s);
        ui->deckList->addItem(s);
    }
}

int editcardcallback(void *ret, int argc, char **argv, char **azColName){
    std::vector<card> *cards = reinterpret_cast< std::vector<card> *>(ret);
    //order is WEIGHT, DATA, ANSWER, SENTENCE
    card c = card(std::string(argv[1]), std::string(argv[2]), std::string(argv[3]));
    c.setWeight(atof(argv[0]));
    //card is now made, push into deck's prio queue
    cards->push_back(c);
    return 0;
}






void editDeckFrame::deleteCard(QString cardName, QString deckName){
    std::string sql;
    int rc;
    sqlite3 *db;
    char *zErrMsg = 0;
    std::string dname = deckName.toStdString();\
    std::string cname = cardName.toStdString();
    rc = sqlite3_open(str(DBNAME), &db);

    if(rc) {//if rc == 1 that means that whatever sqlite operation failed, 0 is good!
      std::cerr << "DB Error: " << sqlite3_errmsg(db) << std::endl;
    }
    if(cardName == ""){
        sql = "DELETE FROM CARDS WHERE DECK = '"+dname+"';";
        rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
        if(rc) {//if rc == 1 that means that whatever sqlite operation failed, 0 is good!
          std::cerr << "DB Error: " << sqlite3_errmsg(db) << std::endl;
        }
        sql = "DELETE FROM DECKS WHERE NAME = '"+dname+"';";
        rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
        if(rc) {//if rc == 1 that means that whatever sqlite operation failed, 0 is good!
          std::cerr << "DB Error: " << sqlite3_errmsg(db) << std::endl;
        }

    }
    else{
        sql = "DELETE FROM CARDS WHERE DECK = '"+dname+"' AND DATA = '"+cname+"';";
        rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
        if(rc) {//if rc == 1 that means that whatever sqlite operation failed, 0 is good!
          std::cerr << "DB Error: " << sqlite3_errmsg(db) << std::endl;
        }
    }
}




void editDeckFrame::insertCard(card c){
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    std::string sql;

    rc = sqlite3_open(str(DBNAME), &db);

    if( rc ) {
      std::cout << "DB Error: " << sqlite3_errmsg(db) << std::endl;
    }
    sql = "INSERT INTO CARDS ('ID', 'WEIGHT', 'DATA', 'ANSWER', 'SENTENCE', 'DECK') VALUES (NULL, '"+std::to_string(c.getWeight())+
    "', '"+c.getData()+"', '"+c.getAnswer()+"', '"+c.getSentence()+"', '"+currentDeckName.toStdString()+"');";
     rc = sqlite3_exec(db, sql.c_str(), NULL, 0, &zErrMsg);
     if( rc ) {
       std::cout << "DB Error: " << sqlite3_errmsg(db) << std::endl;
     }
}


