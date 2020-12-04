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
