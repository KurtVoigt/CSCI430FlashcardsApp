#include "flashcards.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //perhaps here do time calculations and updata database
    QApplication a(argc, argv);
    FlashCards w;
    w.show();

    return a.exec();
}
