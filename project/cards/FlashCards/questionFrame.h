#ifndef QUESTIONFRAME_H
#define QUESTIONFRAME_H

#include <QFrame>
#include "../../src/card.h"
#include "answerFrame.h"
#include "loadDeckFrame.h"
#include <QDebug>
class card;
namespace Ui {
class questionFrame;
}

class questionFrame : public QFrame
{
    Q_OBJECT

public:
    explicit questionFrame(loadDeckFrame *parent = 0);
    ~questionFrame();

    void setQuestionTag(QString s);
    void setSentenceTag(QString s);
    void setUpRightButton(QString s);
    void setBotRightButton(QString s);
    void setUpLeftButton(QString s);
    void setBotLeftButton(QString s);
    void setCurrentCard(card *c);

private slots:
    void on_buttonUpLeft_clicked();

    void on_buttonUpRight_clicked();

    void on_buttonBotLeft_clicked();

    void on_buttonBotRight_clicked();

private:
    Ui::questionFrame *ui;
    card *currentCard;
    answerFrame *af;
    loadDeckFrame *par;
};

#endif // QUESTIONFRAME_H
