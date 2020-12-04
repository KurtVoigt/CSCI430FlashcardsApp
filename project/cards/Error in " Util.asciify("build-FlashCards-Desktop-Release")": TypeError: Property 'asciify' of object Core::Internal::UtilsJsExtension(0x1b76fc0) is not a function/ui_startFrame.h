/********************************************************************************
** Form generated from reading UI file 'startFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTFRAME_H
#define UI_STARTFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_startFrame
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *newDeckButton;
    QPushButton *loadDeckButton;
    QPushButton *editDeckButton;
    QPushButton *quitButton;

    void setupUi(QFrame *startFrame)
    {
        if (startFrame->objectName().isEmpty())
            startFrame->setObjectName(QStringLiteral("startFrame"));
        startFrame->resize(1176, 523);
        startFrame->setFrameShape(QFrame::StyledPanel);
        startFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(startFrame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        newDeckButton = new QPushButton(startFrame);
        newDeckButton->setObjectName(QStringLiteral("newDeckButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newDeckButton->sizePolicy().hasHeightForWidth());
        newDeckButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(newDeckButton);

        loadDeckButton = new QPushButton(startFrame);
        loadDeckButton->setObjectName(QStringLiteral("loadDeckButton"));
        sizePolicy.setHeightForWidth(loadDeckButton->sizePolicy().hasHeightForWidth());
        loadDeckButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(loadDeckButton);

        editDeckButton = new QPushButton(startFrame);
        editDeckButton->setObjectName(QStringLiteral("editDeckButton"));
        sizePolicy.setHeightForWidth(editDeckButton->sizePolicy().hasHeightForWidth());
        editDeckButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(editDeckButton);

        quitButton = new QPushButton(startFrame);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        sizePolicy.setHeightForWidth(quitButton->sizePolicy().hasHeightForWidth());
        quitButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(quitButton);


        retranslateUi(startFrame);

        QMetaObject::connectSlotsByName(startFrame);
    } // setupUi

    void retranslateUi(QFrame *startFrame)
    {
        startFrame->setWindowTitle(QApplication::translate("startFrame", "Frame", 0));
        newDeckButton->setText(QApplication::translate("startFrame", "New Deck", 0));
        loadDeckButton->setText(QApplication::translate("startFrame", "Load Deck", 0));
        editDeckButton->setText(QApplication::translate("startFrame", "Edit Deck", 0));
        quitButton->setText(QApplication::translate("startFrame", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class startFrame: public Ui_startFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTFRAME_H
