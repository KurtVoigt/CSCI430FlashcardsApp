/********************************************************************************
** Form generated from reading UI file 'answerFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANSWERFRAME_H
#define UI_ANSWERFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_answerFrame
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *answerLabel;
    QLabel *knowledgeScorePromptLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *greatButton;
    QPushButton *goodButton;
    QPushButton *neutralButton;
    QPushButton *badButton;
    QPushButton *terribleButton;

    void setupUi(QFrame *answerFrame)
    {
        if (answerFrame->objectName().isEmpty())
            answerFrame->setObjectName(QStringLiteral("answerFrame"));
        answerFrame->resize(1235, 633);
        answerFrame->setFrameShape(QFrame::StyledPanel);
        answerFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(answerFrame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        answerLabel = new QLabel(answerFrame);
        answerLabel->setObjectName(QStringLiteral("answerLabel"));
        QFont font;
        font.setPointSize(18);
        answerLabel->setFont(font);
        answerLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(answerLabel);

        knowledgeScorePromptLabel = new QLabel(answerFrame);
        knowledgeScorePromptLabel->setObjectName(QStringLiteral("knowledgeScorePromptLabel"));
        QFont font1;
        font1.setPointSize(16);
        knowledgeScorePromptLabel->setFont(font1);
        knowledgeScorePromptLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(knowledgeScorePromptLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        greatButton = new QPushButton(answerFrame);
        greatButton->setObjectName(QStringLiteral("greatButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(greatButton->sizePolicy().hasHeightForWidth());
        greatButton->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(13);
        greatButton->setFont(font2);

        horizontalLayout->addWidget(greatButton);

        goodButton = new QPushButton(answerFrame);
        goodButton->setObjectName(QStringLiteral("goodButton"));
        sizePolicy.setHeightForWidth(goodButton->sizePolicy().hasHeightForWidth());
        goodButton->setSizePolicy(sizePolicy);
        goodButton->setFont(font2);

        horizontalLayout->addWidget(goodButton);

        neutralButton = new QPushButton(answerFrame);
        neutralButton->setObjectName(QStringLiteral("neutralButton"));
        sizePolicy.setHeightForWidth(neutralButton->sizePolicy().hasHeightForWidth());
        neutralButton->setSizePolicy(sizePolicy);
        neutralButton->setFont(font2);

        horizontalLayout->addWidget(neutralButton);

        badButton = new QPushButton(answerFrame);
        badButton->setObjectName(QStringLiteral("badButton"));
        sizePolicy.setHeightForWidth(badButton->sizePolicy().hasHeightForWidth());
        badButton->setSizePolicy(sizePolicy);
        badButton->setFont(font2);

        horizontalLayout->addWidget(badButton);

        terribleButton = new QPushButton(answerFrame);
        terribleButton->setObjectName(QStringLiteral("terribleButton"));
        sizePolicy.setHeightForWidth(terribleButton->sizePolicy().hasHeightForWidth());
        terribleButton->setSizePolicy(sizePolicy);
        terribleButton->setFont(font2);

        horizontalLayout->addWidget(terribleButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(answerFrame);

        QMetaObject::connectSlotsByName(answerFrame);
    } // setupUi

    void retranslateUi(QFrame *answerFrame)
    {
        answerFrame->setWindowTitle(QApplication::translate("answerFrame", "Frame", 0));
        answerLabel->setText(QApplication::translate("answerFrame", "ANSWER (NOT SEE IT)", 0));
        knowledgeScorePromptLabel->setText(QApplication::translate("answerFrame", "How do you feel about your knowledge of this card?", 0));
        greatButton->setText(QApplication::translate("answerFrame", "Great", 0));
        goodButton->setText(QApplication::translate("answerFrame", "Good", 0));
        neutralButton->setText(QApplication::translate("answerFrame", "Neutral", 0));
        badButton->setText(QApplication::translate("answerFrame", "Bad", 0));
        terribleButton->setText(QApplication::translate("answerFrame", "Terrible", 0));
    } // retranslateUi

};

namespace Ui {
    class answerFrame: public Ui_answerFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANSWERFRAME_H
