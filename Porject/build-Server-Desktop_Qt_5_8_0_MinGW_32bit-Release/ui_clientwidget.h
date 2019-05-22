/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include <mytextedit.h>

QT_BEGIN_NAMESPACE

class Ui_ClientWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *buttonConnect;
    QPushButton *buttonSend;
    QLineEdit *lineEditPort;
    QPushButton *buttonClose;
    QLineEdit *lineEditIP;
    QLabel *label_2;
    QTextBrowser *textBrowserRead;
    QLabel *label;
    myTextEdit *textBrowserWrite;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QStringLiteral("ClientWidget"));
        ClientWidget->resize(358, 532);
        gridLayout = new QGridLayout(ClientWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonConnect = new QPushButton(ClientWidget);
        buttonConnect->setObjectName(QStringLiteral("buttonConnect"));

        gridLayout->addWidget(buttonConnect, 0, 5, 2, 1);

        buttonSend = new QPushButton(ClientWidget);
        buttonSend->setObjectName(QStringLiteral("buttonSend"));

        gridLayout->addWidget(buttonSend, 4, 0, 1, 2);

        lineEditPort = new QLineEdit(ClientWidget);
        lineEditPort->setObjectName(QStringLiteral("lineEditPort"));
        lineEditPort->setMinimumSize(QSize(49, 0));
        lineEditPort->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(lineEditPort, 1, 4, 1, 1);

        buttonClose = new QPushButton(ClientWidget);
        buttonClose->setObjectName(QStringLiteral("buttonClose"));

        gridLayout->addWidget(buttonClose, 4, 5, 1, 1);

        lineEditIP = new QLineEdit(ClientWidget);
        lineEditIP->setObjectName(QStringLiteral("lineEditIP"));
        lineEditIP->setMinimumSize(QSize(60, 0));
        lineEditIP->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(lineEditIP, 1, 1, 1, 2);

        label_2 = new QLabel(ClientWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        textBrowserRead = new QTextBrowser(ClientWidget);
        textBrowserRead->setObjectName(QStringLiteral("textBrowserRead"));
        QFont font;
        font.setPointSize(14);
        textBrowserRead->setFont(font);

        gridLayout->addWidget(textBrowserRead, 2, 0, 1, 6);

        label = new QLabel(ClientWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 3, 1, 1);

        textBrowserWrite = new myTextEdit(ClientWidget);
        textBrowserWrite->setObjectName(QStringLiteral("textBrowserWrite"));
        textBrowserWrite->setMinimumSize(QSize(0, 0));
        textBrowserWrite->setMaximumSize(QSize(16777215, 141));
        textBrowserWrite->setSizeIncrement(QSize(0, 0));
        QFont font1;
        font1.setPointSize(17);
        textBrowserWrite->setFont(font1);
        textBrowserWrite->setReadOnly(false);

        gridLayout->addWidget(textBrowserWrite, 3, 0, 1, 6);


        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QApplication::translate("ClientWidget", "Form", Q_NULLPTR));
        buttonConnect->setText(QApplication::translate("ClientWidget", "\350\277\236\346\216\245", Q_NULLPTR));
        buttonSend->setText(QApplication::translate("ClientWidget", "\345\217\221\351\200\201", Q_NULLPTR));
        lineEditPort->setText(QApplication::translate("ClientWidget", "8888", Q_NULLPTR));
        buttonClose->setText(QApplication::translate("ClientWidget", "\345\205\263\351\227\255", Q_NULLPTR));
        lineEditIP->setText(QApplication::translate("ClientWidget", "127.0.0.1", Q_NULLPTR));
        label_2->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200:", Q_NULLPTR));
        textBrowserRead->setHtml(QApplication::translate("ClientWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
