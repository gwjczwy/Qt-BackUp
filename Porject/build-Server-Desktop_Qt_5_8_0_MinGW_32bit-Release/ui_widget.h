/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include <mytextedit.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *textRead;
    myTextEdit *textWrite;
    QPushButton *buttonSend;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonClose;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(286, 495);
        Widget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textRead = new QTextBrowser(Widget);
        textRead->setObjectName(QStringLiteral("textRead"));
        QFont font;
        font.setPointSize(14);
        textRead->setFont(font);

        gridLayout->addWidget(textRead, 0, 0, 1, 3);

        textWrite = new myTextEdit(Widget);
        textWrite->setObjectName(QStringLiteral("textWrite"));
        textWrite->setMaximumSize(QSize(16777215, 140));
        textWrite->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(17);
        textWrite->setFont(font1);
        textWrite->setReadOnly(false);

        gridLayout->addWidget(textWrite, 1, 0, 1, 3);

        buttonSend = new QPushButton(Widget);
        buttonSend->setObjectName(QStringLiteral("buttonSend"));

        gridLayout->addWidget(buttonSend, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(234, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        buttonClose = new QPushButton(Widget);
        buttonClose->setObjectName(QStringLiteral("buttonClose"));

        gridLayout->addWidget(buttonClose, 2, 2, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        buttonSend->setText(QApplication::translate("Widget", "Send", Q_NULLPTR));
        buttonClose->setText(QApplication::translate("Widget", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
