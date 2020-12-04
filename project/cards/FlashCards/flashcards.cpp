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


/*void FlashCards::on_pushButton_clicked()
{
    ndf = new NewDeckFrame(this);
    ui->pushButton->hide();
    ui->gridLayout->addWidget(ndf);
    //ndf->show();
}

void FlashCards::displayFirstScreen(){
    std::cout << "hello";
    //ndf->close();
    //ui->gridLayout->removeWidget(ndf);
    ui->pushButton->show();
   // ndf->close();
}

void FlashCards::on_pushButton_2_clicked()
{
   this->close();
}*/

void FlashCards::on_startButton_clicked()
{
    sf = new startFrame(this);
    ui->centralWidget->close();
    setCentralWidget(sf);
    sf->show();
}
