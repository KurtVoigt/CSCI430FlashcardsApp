#include "newDeckFrame.h"
#include "ui_newDeckFrame.h"
#include <QDebug>
NewDeckFrame::NewDeckFrame(QMainWindow *parent) :
    par(parent),
    QFrame(parent),
    newDeckui(new Ui::NewDeckFrame)
{

    newDeckui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}


NewDeckFrame::~NewDeckFrame()
{
    delete newDeckui;
}

void NewDeckFrame::on_createCardButton_clicked()
{
    QString data = newDeckui->dataLineEdit->text();
    QString ans = newDeckui->answerLineEdit->text();
    QString sent = newDeckui->sentenceLineEdit->text();
    card c(data.toStdString(),ans.toStdString(), sent.toStdString());
    //qDebug() << "card object made with: " << data << ans << sent;
    holdingpen.push_back(c);
    newDeckui->dataLineEdit->clear();
    newDeckui->answerLineEdit->clear();
    newDeckui->sentenceLineEdit->clear();
}


void NewDeckFrame::on_exitButton_clicked()
{//takes you back to start screen and stores the deck into memory
    std::string deckName = newDeckui->deckNameLineEdit->text().toStdString();
    newDeck = new deck(deckName, true);
    for(std::size_t i = 0; i < holdingpen.size(); i++)
    {
        newDeck->pushCard(holdingpen[i]);
    }
    holdingpen.clear();
    newDeck->writeDeck();
    //deck is now pushed on to the database, go back to start screen
    FlashCards* hopeThisWorks = qobject_cast<FlashCards*>(par);
    sf = new startFrame(par);
    hopeThisWorks->centralWidget()->close();
    this->close();
    hopeThisWorks->setCentralWidget(sf);
}

void NewDeckFrame::on_pushButton_clicked()
{
    FlashCards* hopeThisWorks = qobject_cast<FlashCards*>(par);
    sf = new startFrame(par);
    hopeThisWorks->centralWidget()->close();
    this->close();
    hopeThisWorks->setCentralWidget(sf);
}
