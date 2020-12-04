/********************************************************************************
** Form generated from reading UI file 'questionFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONFRAME_H
#define UI_QUESTIONFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_questionFrame
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *questionLabel;
    QLabel *sentenceLabel;
    QGridLayout *gridLayout;
    QPushButton *buttonUpLeft;
    QPushButton *buttonUpRight;
    QPushButton *buttonBotLeft;
    QPushButton *buttonBotRight;

    void setupUi(QFrame *questionFrame)
    {
        if (questionFrame->objectName().isEmpty())
            questionFrame->setObjectName(QStringLiteral("questionFrame"));
        questionFrame->resize(1245, 609);
        questionFrame->setFrameShape(QFrame::StyledPanel);
        questionFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(questionFrame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        questionLabel = new QLabel(questionFrame);
        questionLabel->setObjectName(QStringLiteral("questionLabel"));
        QFont font;
        font.setPointSize(18);
        questionLabel->setFont(font);
        questionLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(questionLabel);

        sentenceLabel = new QLabel(questionFrame);
        sentenceLabel->setObjectName(QStringLiteral("sentenceLabel"));
        QFont font1;
        font1.setPointSize(16);
        sentenceLabel->setFont(font1);
        sentenceLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(sentenceLabel);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonUpLeft = new QPushButton(questionFrame);
        buttonUpLeft->setObjectName(QStringLiteral("buttonUpLeft"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonUpLeft->sizePolicy().hasHeightForWidth());
        buttonUpLeft->setSizePolicy(sizePolicy);

        gridLayout->addWidget(buttonUpLeft, 0, 0, 1, 1);

        buttonUpRight = new QPushButton(questionFrame);
        buttonUpRight->setObjectName(QStringLiteral("buttonUpRight"));
        sizePolicy.setHeightForWidth(buttonUpRight->sizePolicy().hasHeightForWidth());
        buttonUpRight->setSizePolicy(sizePolicy);

        gridLayout->addWidget(buttonUpRight, 0, 1, 1, 1);

        buttonBotLeft = new QPushButton(questionFrame);
        buttonBotLeft->setObjectName(QStringLiteral("buttonBotLeft"));
        sizePolicy.setHeightForWidth(buttonBotLeft->sizePolicy().hasHeightForWidth());
        buttonBotLeft->setSizePolicy(sizePolicy);

        gridLayout->addWidget(buttonBotLeft, 1, 0, 1, 1);

        buttonBotRight = new QPushButton(questionFrame);
        buttonBotRight->setObjectName(QStringLiteral("buttonBotRight"));
        sizePolicy.setHeightForWidth(buttonBotRight->sizePolicy().hasHeightForWidth());
        buttonBotRight->setSizePolicy(sizePolicy);

        gridLayout->addWidget(buttonBotRight, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(questionFrame);

        QMetaObject::connectSlotsByName(questionFrame);
    } // setupUi

    void retranslateUi(QFrame *questionFrame)
    {
        questionFrame->setWindowTitle(QApplication::translate("questionFrame", "Frame", 0));
        questionLabel->setText(QApplication::translate("questionFrame", "QUESTION (YOU SHOULD HOPEFULLY NOT SEE THIS)", 0));
        sentenceLabel->setText(QApplication::translate("questionFrame", "EXAMPLE SENTENCE (THIS NEITHER)", 0));
        buttonUpLeft->setText(QApplication::translate("questionFrame", "PushButton", 0));
        buttonUpRight->setText(QApplication::translate("questionFrame", "PushButton", 0));
        buttonBotLeft->setText(QApplication::translate("questionFrame", "PushButton", 0));
        buttonBotRight->setText(QApplication::translate("questionFrame", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class questionFrame: public Ui_questionFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONFRAME_H
