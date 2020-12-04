#ifndef STARTFRAME_H
#define STARTFRAME_H

#include <QFrame>
#include <QMainWindow>
#include "newDeckFrame.h"
#include "loadDeckFrame.h"
#include "editDeckFrame.h"
class NewDeckFrame;
class loadDeckFrame;
class editDeckFrame;
/*
 * startFrame, the main menu of the application that gives access to
 * all the functionallity. Has empty pointers to each frame that it would need
 * to put on to its parent(parent in the qt sense) window (FlashCards object)
 */
namespace Ui {
class startFrame;
}

class startFrame : public QFrame
{
    Q_OBJECT

public:
    explicit startFrame(QMainWindow *parent = 0);
    ~startFrame();

private slots:
    void on_newDeckButton_clicked();

    void on_quitButton_clicked();

    void on_loadDeckButton_clicked();

    void on_editDeckButton_clicked();

private:
    Ui::startFrame *ui;
    NewDeckFrame* ndf;
    QMainWindow* par;
    loadDeckFrame* ldf;
    editDeckFrame *edf;
};

#endif // STARTFRAME_H
