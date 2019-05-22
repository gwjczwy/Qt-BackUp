/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEditPort;
    QTextEdit *textEditRead;
    QLineEdit *lineEditIP;
    QPushButton *pushButtonConnect;
    QProgressBar *progressBar;

    void setupUi(QWidget *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(400, 300);
        gridLayout = new QGridLayout(Client);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(Client);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 2, 1);

        label = new QLabel(Client);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 2, 1);

        lineEditPort = new QLineEdit(Client);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 3, 1, 1, 1);

        textEditRead = new QTextEdit(Client);
        textEditRead->setObjectName(QStringLiteral("textEditRead"));

        gridLayout->addWidget(textEditRead, 4, 0, 1, 3);

        lineEditIP = new QLineEdit(Client);
        lineEditIP->setObjectName(QStringLiteral("lineEditIP"));

        gridLayout->addWidget(lineEditIP, 1, 1, 1, 1);

        pushButtonConnect = new QPushButton(Client);
        pushButtonConnect->setObjectName(QStringLiteral("pushButtonConnect"));
        QFont font1;
        font1.setPointSize(17);
        pushButtonConnect->setFont(font1);

        gridLayout->addWidget(pushButtonConnect, 1, 2, 3, 1);

        progressBar = new QProgressBar(Client);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 5, 0, 1, 3);


        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QWidget *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Form", Q_NULLPTR));
        label_2->setText(QApplication::translate("Client", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243", Q_NULLPTR));
        label->setText(QApplication::translate("Client", "\346\234\215\345\212\241\345\231\250IP", Q_NULLPTR));
        lineEditPort->setText(QApplication::translate("Client", "8810", Q_NULLPTR));
        lineEditIP->setText(QApplication::translate("Client", "127.0.0.1", Q_NULLPTR));
        pushButtonConnect->setText(QApplication::translate("Client", "Connetc", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
