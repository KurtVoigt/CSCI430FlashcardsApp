#include "startFrame.h"
#include "ui_startFrame.h"
startFrame::startFrame(QMainWindow *parent) :

    par(parent),
    QFrame(parent),
    ui(new Ui::startFrame)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

startFrame::~startFrame()
{
    delete ui;
}

void startFrame::on_newDeckButton_clicked()
{

    FlashCards* hopeThisWorks = qobject_cast<FlashCards*>(par);
    ndf = new NewDeckFrame(hopeThisWorks);
    this->close();
    hopeThisWorks->centralWidget()->close();
    hopeThisWorks->setCentralWidget(ndf);
}

void startFrame::on_quitButton_clicked()
{
    QApplication::quit();

}

void startFrame::on_loadDeckButton_clicked()
{
    FlashCards* hopeThisWorks = qobject_cast<FlashCards*>(par);
    ldf = new loadDeckFrame(hopeThisWorks);
    this->close();
    hopeThisWorks->centralWidget()->close();
    hopeThisWorks->setCentralWidget(ldf);
}

void startFrame::on_editDeckButton_clicked()
{
    FlashCards* hopeThisWorks = qobject_cast<FlashCards*>(par);
    edf = new editDeckFrame(hopeThisWorks);
    this->close();
    hopeThisWorks->centralWidget()->close();
    hopeThisWorks->setCentralWidget(edf);
}
