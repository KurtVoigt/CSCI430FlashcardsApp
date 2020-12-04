/********************************************************************************
** Form generated from reading UI file 'loadDeckFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADDECKFRAME_H
#define UI_LOADDECKFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_loadDeckFrame
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *deckList;
    QPushButton *displayDeckButton;
    QPushButton *backButton;

    void setupUi(QFrame *loadDeckFrame)
    {
        if (loadDeckFrame->objectName().isEmpty())
            loadDeckFrame->setObjectName(QStringLiteral("loadDeckFrame"));
        loadDeckFrame->resize(1118, 579);
        loadDeckFrame->setFrameShape(QFrame::StyledPanel);
        loadDeckFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(loadDeckFrame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(loadDeckFrame);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);

        verticalLayout->addWidget(label);

        deckList = new QListWidget(loadDeckFrame);
        deckList->setObjectName(QStringLiteral("deckList"));

        verticalLayout->addWidget(deckList);

        displayDeckButton = new QPushButton(loadDeckFrame);
        displayDeckButton->setObjectName(QStringLiteral("displayDeckButton"));

        verticalLayout->addWidget(displayDeckButton);

        backButton = new QPushButton(loadDeckFrame);
        backButton->setObjectName(QStringLiteral("backButton"));

        verticalLayout->addWidget(backButton);


        retranslateUi(loadDeckFrame);

        QMetaObject::connectSlotsByName(loadDeckFrame);
    } // setupUi

    void retranslateUi(QFrame *loadDeckFrame)
    {
        loadDeckFrame->setWindowTitle(QApplication::translate("loadDeckFrame", "Frame", 0));
        label->setText(QApplication::translate("loadDeckFrame", "Please Select a Deck from the list below:", 0));
        displayDeckButton->setText(QApplication::translate("loadDeckFrame", "Select Deck", 0));
        backButton->setText(QApplication::translate("loadDeckFrame", "Back to Main Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class loadDeckFrame: public Ui_loadDeckFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADDECKFRAME_H
