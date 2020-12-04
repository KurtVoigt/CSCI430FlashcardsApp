/********************************************************************************
** Form generated from reading UI file 'editDeckFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDECKFRAME_H
#define UI_EDITDECKFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_editDeckFrame
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QGridLayout *gridLayout;
    QListWidget *deckList;
    QVBoxLayout *verticalLayout_2;
    QPushButton *selectDeckButton;
    QPushButton *deleteCardButton;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *questionLabel;
    QLineEdit *questionLineEdit;
    QLabel *answerLabel;
    QLineEdit *answerLineEdit;
    QLabel *sentenceLabel;
    QLineEdit *sentenceLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *addCardButton;
    QPushButton *mainMenuButton;

    void setupUi(QFrame *editDeckFrame)
    {
        if (editDeckFrame->objectName().isEmpty())
            editDeckFrame->setObjectName(QStringLiteral("editDeckFrame"));
        editDeckFrame->resize(1234, 676);
        editDeckFrame->setFrameShape(QFrame::StyledPanel);
        editDeckFrame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(editDeckFrame);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(editDeckFrame);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);

        verticalLayout_3->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        deckList = new QListWidget(editDeckFrame);
        deckList->setObjectName(QStringLiteral("deckList"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deckList->sizePolicy().hasHeightForWidth());
        deckList->setSizePolicy(sizePolicy);

        gridLayout->addWidget(deckList, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        selectDeckButton = new QPushButton(editDeckFrame);
        selectDeckButton->setObjectName(QStringLiteral("selectDeckButton"));

        verticalLayout_2->addWidget(selectDeckButton);

        deleteCardButton = new QPushButton(editDeckFrame);
        deleteCardButton->setObjectName(QStringLiteral("deleteCardButton"));

        verticalLayout_2->addWidget(deleteCardButton);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        questionLabel = new QLabel(editDeckFrame);
        questionLabel->setObjectName(QStringLiteral("questionLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, questionLabel);

        questionLineEdit = new QLineEdit(editDeckFrame);
        questionLineEdit->setObjectName(QStringLiteral("questionLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, questionLineEdit);

        answerLabel = new QLabel(editDeckFrame);
        answerLabel->setObjectName(QStringLiteral("answerLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, answerLabel);

        answerLineEdit = new QLineEdit(editDeckFrame);
        answerLineEdit->setObjectName(QStringLiteral("answerLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, answerLineEdit);

        sentenceLabel = new QLabel(editDeckFrame);
        sentenceLabel->setObjectName(QStringLiteral("sentenceLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, sentenceLabel);

        sentenceLineEdit = new QLineEdit(editDeckFrame);
        sentenceLineEdit->setObjectName(QStringLiteral("sentenceLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, sentenceLineEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addCardButton = new QPushButton(editDeckFrame);
        addCardButton->setObjectName(QStringLiteral("addCardButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addCardButton->sizePolicy().hasHeightForWidth());
        addCardButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(addCardButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        mainMenuButton = new QPushButton(editDeckFrame);
        mainMenuButton->setObjectName(QStringLiteral("mainMenuButton"));

        verticalLayout_3->addWidget(mainMenuButton);


        retranslateUi(editDeckFrame);

        QMetaObject::connectSlotsByName(editDeckFrame);
    } // setupUi

    void retranslateUi(QFrame *editDeckFrame)
    {
        editDeckFrame->setWindowTitle(QApplication::translate("editDeckFrame", "Frame", 0));
        label->setText(QApplication::translate("editDeckFrame", "Please select a Deck from the list below:", 0));
        selectDeckButton->setText(QApplication::translate("editDeckFrame", "Select Deck", 0));
        deleteCardButton->setText(QApplication::translate("editDeckFrame", "Delete", 0));
        questionLabel->setText(QApplication::translate("editDeckFrame", "Question", 0));
        answerLabel->setText(QApplication::translate("editDeckFrame", "Answer", 0));
        sentenceLabel->setText(QApplication::translate("editDeckFrame", "Sentence", 0));
        addCardButton->setText(QApplication::translate("editDeckFrame", "Add Card", 0));
        mainMenuButton->setText(QApplication::translate("editDeckFrame", "Back to Main Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class editDeckFrame: public Ui_editDeckFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDECKFRAME_H
