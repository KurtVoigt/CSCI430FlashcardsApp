#include "questionFrame.h"
#include "ui_questionFrame.h"

questionFrame::questionFrame(loadDeckFrame *parent) :
    par(parent),
    QFrame(parent),
    ui(new Ui::questionFrame)
{
    ui->setupUi(this);
     setAttribute(Qt::WA_DeleteOnClose);
}

questionFrame::~questionFrame()
{
    delete ui;
}

 void questionFrame::setQuestionTag(QString s){
     ui->questionLabel->setText(s);
 }

 void questionFrame::setSentenceTag(QString s){
     ui->sentenceLabel->setText(s);
 }
 void questionFrame::setUpRightButton(QString s){
     ui->buttonUpRight->setText(s);
 }
 void questionFrame::setUpLeftButton(QString s){
     ui->buttonUpLeft->setText(s);
 }
 void questionFrame::setBotRightButton(QString s){
     ui->buttonBotRight->setText(s);
 }
 void questionFrame::setBotLeftButton(QString s){
     ui->buttonBotLeft->setText(s);
 }

 void questionFrame::setCurrentCard(card *c){
     currentCard = c;
 }

void questionFrame::on_buttonUpLeft_clicked()
{
    if(ui->buttonUpLeft->text() != QString::fromStdString(currentCard->getAnswer())) {
      //  qDebug() << ui->buttonUpLeft->text() << QString::fromStdString(currentCard->getAnswer());
        ui->buttonUpLeft->setEnabled(false);
    }
    else{ //correct
        //qDebug() << ui->buttonUpLeft->text() << QString::fromStdString(currentCard->getAnswer());

       // par = qobject_cast<loadDeckFrame *>(par);

       af = new answerFrame(this->par);
        af->setAnswerText(QString::fromStdString(currentCard->getAnswer()));
        af->setCurrentCard(this->currentCard);
        this->close();
        par->graftQAFrame(af);

    }
}

void questionFrame::on_buttonUpRight_clicked()
{
    if(ui->buttonUpRight->text() != QString::fromStdString(currentCard->getAnswer())) {
       // qDebug() << ui->buttonUpRight->text() << QString::fromStdString(currentCard->getAnswer());
        ui->buttonUpRight->setEnabled(false);
    }
    else{
      //  qDebug() << ui->buttonUpRight->text() << QString::fromStdString(currentCard->getAnswer());
        af = new answerFrame(this->par);
        af->setAnswerText(QString::fromStdString(currentCard->getAnswer()));
        af->setCurrentCard(this->currentCard);
        this->close();
        par->graftQAFrame(af);
    }
}

void questionFrame::on_buttonBotLeft_clicked()
{
    if(ui->buttonBotLeft->text() != QString::fromStdString(currentCard->getAnswer())) {
       // qDebug() << ui->buttonBotLeft->text() << QString::fromStdString(currentCard->getAnswer());
        ui->buttonBotLeft->setEnabled(false);
    }
    else{
        //qDebug() << ui->buttonBotLeft->text() << QString::fromStdString(currentCard->getAnswer());
        af = new answerFrame(this->par);
        af->setAnswerText(QString::fromStdString(currentCard->getAnswer()));
        af->setCurrentCard(this->currentCard);
        this->close();
        par->graftQAFrame(af);
    }
}

void questionFrame::on_buttonBotRight_clicked()
{
    if(ui->buttonBotRight->text() != QString::fromStdString(currentCard->getAnswer())) {
       // qDebug() << ui->buttonBotRight->text() << QString::fromStdString(currentCard->getAnswer());
        ui->buttonBotRight->setEnabled(false);
    }
    else{
       // qDebug() << ui->buttonBotRight->text() << QString::fromStdString(currentCard->getAnswer());
        af = new answerFrame(this->par);
        af->setAnswerText(QString::fromStdString(currentCard->getAnswer()));
        af->setCurrentCard(this->currentCard);
        this->close();
        par->graftQAFrame(af);
    }
}
