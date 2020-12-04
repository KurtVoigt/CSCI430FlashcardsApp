#ifndef LOADDECKFRAME_H
#define LOADDECKFRAME_H
#include "../../src/deck.h"
#include <QFrame>
#include "flashcards.h"
#include "startFrame.h"
#include "questionFrame.h"
#include "answerFrame.h"
#include <vector>
#include <string>
#include <sqlite3.h>
#include <QString>
class startFrame;
class questionFrame;
class answerFrame;

/*
 * loadDeckFrame, this frame is used to select a deck that you would like to
 * review. If the user selects a deck to review,It will clear its UI and acts as the parent (in the qt sense) of both questionFrame and
 * answerFrame so that these two children can both access the pointer to the card
 * that is currently being reviewed. else the user goes back to the main menu, which will delete
 * this loadDeckFrame and put a new startframe on to FlashCards.
 */
namespace Ui {
class loadDeckFrame;
}

class loadDeckFrame : public QFrame
{
    Q_OBJECT

public:
    explicit loadDeckFrame(QMainWindow *parent = 0);
    ~loadDeckFrame();
    std::vector<std::string> getDeckNames();
    void graftQAFrame(QFrame *f);
    void updateCard(card *c, assesments a);
    void displayQuestion();

private slots:
    void on_displayDeckButton_clicked();

    void on_backButton_clicked();

private:
    Ui::loadDeckFrame *ui;

    //std::vector<char*> *deckNames;
    startFrame *sf;
    QMainWindow *par;
    std::vector<std::string> deckNames;
    deck * displayDeck;
    questionFrame *qf;
    answerFrame *af;

};

#endif // LOADDECKFRAME_H
