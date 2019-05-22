/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QTextEdit *textEdit;
    QPushButton *pushButtonChouse;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonLoad;

    void setupUi(QWidget *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(400, 300);
        gridLayout = new QGridLayout(Server);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(137, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 2);

        label = new QLabel(Server);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(25);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 3, 1, 2);

        textEdit = new QTextEdit(Server);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 1, 5);

        pushButtonChouse = new QPushButton(Server);
        pushButtonChouse->setObjectName(QStringLiteral("pushButtonChouse"));

        gridLayout->addWidget(pushButtonChouse, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(217, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 3);

        pushButtonLoad = new QPushButton(Server);
        pushButtonLoad->setObjectName(QStringLiteral("pushButtonLoad"));

        gridLayout->addWidget(pushButtonLoad, 2, 4, 1, 1);


        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QWidget *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Server", Q_NULLPTR));
        label->setText(QApplication::translate("Server", "\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        pushButtonChouse->setText(QApplication::translate("Server", "\351\200\211\346\213\251\346\226\207\344\273\266", Q_NULLPTR));
        pushButtonLoad->setText(QApplication::translate("Server", "\345\217\221\351\200\201\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
