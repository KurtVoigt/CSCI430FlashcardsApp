#ifndef EDITDECKFRAME_H
#define EDITDECKFRAME_H

#include <QFrame>
#include "flashcards.h"

/*
 * editDeckFrame, this class allows the user to add cards to a deck, delete
 * cards from a deck, and delete a deck entirely
 *
 */
namespace Ui {
class editDeckFrame;
}

class editDeckFrame : public QFrame
{
    Q_OBJECT

public:
    explicit editDeckFrame(QMainWindow *parent = 0);
    ~editDeckFrame();

private slots:
    void on_selectDeckButton_clicked();

    void on_deleteCardButton_clicked();

    void on_mainMenuButton_clicked();

    void on_addCardButton_clicked();

private:
    Ui::editDeckFrame *ui;
    std::vector<std::string> getDeckNames();
    std::vector<card> getCards(QString deckName);
    QMainWindow *par;
    std::vector<std::string> deckNames;
    QString currentDeckName;

    void deleteCard(QString cardName, QString deckName);
    void populateListWithDecks();
    void populateListWithCards(std::vector<card> cv);
    void cardEditState(bool b);
    std::vector<card> cv;
    startFrame * sf;
    void insertCard(card c);
};

#endif // EDITDECKFRAME_H
