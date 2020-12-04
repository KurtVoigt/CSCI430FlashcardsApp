/********************************************************************************
** Form generated from reading UI file 'newDeckFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDECKFRAME_H
#define UI_NEWDECKFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewDeckFrame
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *instructionLabel;
    QLabel *deckNameLabel;
    QLineEdit *deckNameLineEdit;
    QLabel *dataLabel;
    QLineEdit *dataLineEdit;
    QLabel *answerLabel;
    QLineEdit *answerLineEdit;
    QLabel *sentenceLabel;
    QLineEdit *sentenceLineEdit;
    QPushButton *pushButton;
    QPushButton *createCardButton;
    QPushButton *exitButton;

    void setupUi(QFrame *NewDeckFrame)
    {
        if (NewDeckFrame->objectName().isEmpty())
            NewDeckFrame->setObjectName(QStringLiteral("NewDeckFrame"));
        NewDeckFrame->resize(1077, 386);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NewDeckFrame->sizePolicy().hasHeightForWidth());
        NewDeckFrame->setSizePolicy(sizePolicy);
        NewDeckFrame->setFrameShape(QFrame::StyledPanel);
        NewDeckFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(NewDeckFrame);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        verticalLayout_2->addLayout(verticalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        instructionLabel = new QLabel(NewDeckFrame);
        instructionLabel->setObjectName(QStringLiteral("instructionLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(instructionLabel->sizePolicy().hasHeightForWidth());
        instructionLabel->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::LabelRole, instructionLabel);

        deckNameLabel = new QLabel(NewDeckFrame);
        deckNameLabel->setObjectName(QStringLiteral("deckNameLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, deckNameLabel);

        deckNameLineEdit = new QLineEdit(NewDeckFrame);
        deckNameLineEdit->setObjectName(QStringLiteral("deckNameLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, deckNameLineEdit);

        dataLabel = new QLabel(NewDeckFrame);
        dataLabel->setObjectName(QStringLiteral("dataLabel"));
        sizePolicy.setHeightForWidth(dataLabel->sizePolicy().hasHeightForWidth());
        dataLabel->setSizePolicy(sizePolicy);
        dataLabel->setMaximumSize(QSize(400, 16777215));

        formLayout->setWidget(3, QFormLayout::LabelRole, dataLabel);

        dataLineEdit = new QLineEdit(NewDeckFrame);
        dataLineEdit->setObjectName(QStringLiteral("dataLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, dataLineEdit);

        answerLabel = new QLabel(NewDeckFrame);
        answerLabel->setObjectName(QStringLiteral("answerLabel"));
        sizePolicy.setHeightForWidth(answerLabel->sizePolicy().hasHeightForWidth());
        answerLabel->setSizePolicy(sizePolicy);
        answerLabel->setMaximumSize(QSize(400, 16777215));

        formLayout->setWidget(4, QFormLayout::LabelRole, answerLabel);

        answerLineEdit = new QLineEdit(NewDeckFrame);
        answerLineEdit->setObjectName(QStringLiteral("answerLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, answerLineEdit);

        sentenceLabel = new QLabel(NewDeckFrame);
        sentenceLabel->setObjectName(QStringLiteral("sentenceLabel"));
        sizePolicy.setHeightForWidth(sentenceLabel->sizePolicy().hasHeightForWidth());
        sentenceLabel->setSizePolicy(sizePolicy);
        sentenceLabel->setMaximumSize(QSize(400, 16777215));

        formLayout->setWidget(5, QFormLayout::LabelRole, sentenceLabel);

        sentenceLineEdit = new QLineEdit(NewDeckFrame);
        sentenceLineEdit->setObjectName(QStringLiteral("sentenceLineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, sentenceLineEdit);


        verticalLayout_2->addLayout(formLayout);

        pushButton = new QPushButton(NewDeckFrame);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        createCardButton = new QPushButton(NewDeckFrame);
        createCardButton->setObjectName(QStringLiteral("createCardButton"));
        sizePolicy.setHeightForWidth(createCardButton->sizePolicy().hasHeightForWidth());
        createCardButton->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(createCardButton);

        exitButton = new QPushButton(NewDeckFrame);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        verticalLayout_2->addWidget(exitButton);


        retranslateUi(NewDeckFrame);

        QMetaObject::connectSlotsByName(NewDeckFrame);
    } // setupUi

    void retranslateUi(QFrame *NewDeckFrame)
    {
        NewDeckFrame->setWindowTitle(QApplication::translate("NewDeckFrame", "Frame", 0));
        instructionLabel->setText(QApplication::translate("NewDeckFrame", "We will now create cards for your new deck", 0));
        deckNameLabel->setText(QApplication::translate("NewDeckFrame", "Deck Name(Unalterable after you press Finished)", 0));
        dataLabel->setText(QApplication::translate("NewDeckFrame", "Data ( The \"front\" side of your card)", 0));
        answerLabel->setText(QApplication::translate("NewDeckFrame", "Answer (the \"back\" side of your card)", 0));
        sentenceLabel->setText(QApplication::translate("NewDeckFrame", "Example Sentence (optional)", 0));
        pushButton->setText(QApplication::translate("NewDeckFrame", "Back to Main Menu (without saving)", 0));
        createCardButton->setText(QApplication::translate("NewDeckFrame", "Create Card", 0));
        exitButton->setText(QApplication::translate("NewDeckFrame", "Save Deck", 0));
    } // retranslateUi

};

namespace Ui {
    class NewDeckFrame: public Ui_NewDeckFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDECKFRAME_H
