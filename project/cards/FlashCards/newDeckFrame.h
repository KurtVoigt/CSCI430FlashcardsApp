#ifndef NEWDECKFRAME_H
#define NEWDECKFRAME_H

#include <QFrame>
#include "../../src/deck.h"
#include <QMainWindow>
#include "flashcards.h"
//creates a new deck and stores it in the database
//when deck is saved, puts a new start frame on to parent frame (FlashCards) and deletes itself
class startFrame;
namespace Ui {
class NewDeckFrame;
}

class NewDeckFrame : public QFrame
{
    Q_OBJECT

public:
    explicit NewDeckFrame(QMainWindow *parent = 0);
    ~NewDeckFrame();

private slots:
    void on_createCardButton_clicked();



    void on_exitButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::NewDeckFrame *newDeckui;
    deck* newDeck;
    std::vector<card> holdingpen;
    QMainWindow* par;
    startFrame * sf;
};

#endif // NEWDECKFRAME_H
