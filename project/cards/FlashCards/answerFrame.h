#ifndef ANSWERFRAME_H
#define ANSWERFRAME_H

#include <QFrame>
#include "questionFrame.h"
#include "loadDeckFrame.h"
/*
 * answerFrame, this class displays the answer to
 * the current card and stores user feedback
 * to update the weights of the currently displayed card
 * when feedback button is pressed, sends signal to parent frame to update
 * deck with that feedback and closes itself
 */

namespace Ui {
class answerFrame;
}

class answerFrame : public QFrame
{
    Q_OBJECT

public:
    explicit answerFrame(loadDeckFrame *parent = 0);
    ~answerFrame();
    void setAnswerText(QString s);
    void setCurrentCard(card *c);

private slots:

    void on_greatButton_clicked();

    void on_goodButton_clicked();

    void on_neutralButton_clicked();

    void on_badButton_clicked();

    void on_terribleButton_clicked();

private:
    Ui::answerFrame *ui;
    card *currentcard;
    loadDeckFrame *par;
};

#endif // ANSWERFRAME_H
