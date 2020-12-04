#include "answerFrame.h"
#include "ui_answerFrame.h"

answerFrame::answerFrame(loadDeckFrame *parent) :
    par(parent),
    QFrame(parent),
    ui(new Ui::answerFrame)
{
    ui->setupUi(this);
     setAttribute(Qt::WA_DeleteOnClose);
    //par = qobject_cast<loadDeckFrame*>(par);

}

answerFrame::~answerFrame()
{
    delete ui;
}

void answerFrame::setAnswerText(QString s){
    ui->answerLabel->setText(s);
}

void answerFrame::setCurrentCard(card *c){
    this->currentcard = c;
}


void answerFrame::on_greatButton_clicked()
{
    par->updateCard(currentcard, great);
   // par->displayQuestion();

}

void answerFrame::on_goodButton_clicked()
{
    par->updateCard(currentcard, good);
   // par->displayQuestion();
}

void answerFrame::on_neutralButton_clicked()
{
    par->updateCard(currentcard, neutral);
   // par->displayQuestion();
}

void answerFrame::on_badButton_clicked()
{
    par->updateCard(currentcard, bad);
   // par->displayQuestion();
}

void answerFrame::on_terribleButton_clicked()
{
    par->updateCard(currentcard, terrible);
    //par->displayQuestion();
}
