#ifndef FLASHCARDS_H
#define FLASHCARDS_H
#define str(s) stri(s)
#define stri(s) #s
#define DBNAME flashcarddatabase.db
#include <QMainWindow>
#include "newDeckFrame.h"
#include "startFrame.h"
class startFrame;
namespace Ui {
class FlashCards;
}

class FlashCards : public QMainWindow
{
    Q_OBJECT

public:
    explicit FlashCards(QWidget *parent = 0);
    void displayFirstScreen();
    ~FlashCards();

private slots:


    void on_startButton_clicked();

private:
    Ui::FlashCards *ui;
    startFrame * sf;
};

#endif // FLASHCARDS_H
