#include "flashcards.h"
#include "ui_flashcards.h"

FlashCards::FlashCards(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::FlashCards)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

FlashCards::~FlashCards()
{
    delete ui;
}


//puts start frame on to main window
void FlashCards::on_startButton_clicked()
{
    sf = new startFrame(this);
    ui->centralWidget->close();
    setCentralWidget(sf);
    sf->show();
}
