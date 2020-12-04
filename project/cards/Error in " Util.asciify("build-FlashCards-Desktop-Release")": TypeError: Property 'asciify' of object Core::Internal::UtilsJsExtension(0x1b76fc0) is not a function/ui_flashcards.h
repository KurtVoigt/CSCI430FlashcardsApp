/********************************************************************************
** Form generated from reading UI file 'flashcards.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLASHCARDS_H
#define UI_FLASHCARDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlashCards
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QPushButton *startButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FlashCards)
    {
        if (FlashCards->objectName().isEmpty())
            FlashCards->setObjectName(QStringLiteral("FlashCards"));
        FlashCards->resize(1139, 576);
        centralWidget = new QWidget(FlashCards);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        titleLabel = new QLabel(centralWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QFont font;
        font.setPointSize(28);
        titleLabel->setFont(font);
        titleLabel->setTextFormat(Qt::AutoText);
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(18);
        startButton->setFont(font1);

        verticalLayout->addWidget(startButton);

        FlashCards->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FlashCards);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1139, 27));
        FlashCards->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FlashCards);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FlashCards->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FlashCards);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FlashCards->setStatusBar(statusBar);

        retranslateUi(FlashCards);

        QMetaObject::connectSlotsByName(FlashCards);
    } // setupUi

    void retranslateUi(QMainWindow *FlashCards)
    {
        FlashCards->setWindowTitle(QApplication::translate("FlashCards", "FlashCards", 0));
        titleLabel->setText(QApplication::translate("FlashCards", "FlashCards", 0));
        startButton->setText(QApplication::translate("FlashCards", "Start!", 0));
    } // retranslateUi

};

namespace Ui {
    class FlashCards: public Ui_FlashCards {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLASHCARDS_H
