/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *PathText;
    QLabel *Explan1;
    QLabel *Explan2;
    QLabel *Explan3;
    QLabel *Explan4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *FileChouse;
    QPushButton *go;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(502, 286);
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        Dialog->setFont(font);
        PathText = new QLabel(Dialog);
        PathText->setObjectName(QStringLiteral("PathText"));
        PathText->setGeometry(QRect(20, 20, 271, 31));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        PathText->setFont(font1);
        Explan1 = new QLabel(Dialog);
        Explan1->setObjectName(QStringLiteral("Explan1"));
        Explan1->setGeometry(QRect(90, 170, 261, 31));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        Explan1->setFont(font2);
        Explan2 = new QLabel(Dialog);
        Explan2->setObjectName(QStringLiteral("Explan2"));
        Explan2->setGeometry(QRect(90, 190, 261, 31));
        Explan2->setFont(font2);
        Explan3 = new QLabel(Dialog);
        Explan3->setObjectName(QStringLiteral("Explan3"));
        Explan3->setGeometry(QRect(90, 210, 201, 21));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setWeight(50);
        font3.setStrikeOut(true);
        Explan3->setFont(font3);
        Explan4 = new QLabel(Dialog);
        Explan4->setObjectName(QStringLiteral("Explan4"));
        Explan4->setGeometry(QRect(0, 261, 301, 20));
        QFont font4;
        font4.setPointSize(8);
        Explan4->setFont(font4);
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(310, 20, 160, 27));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        FileChouse = new QPushButton(widget);
        FileChouse->setObjectName(QStringLiteral("FileChouse"));
        QFont font5;
        font5.setPointSize(11);
        font5.setBold(true);
        font5.setWeight(75);
        FileChouse->setFont(font5);

        horizontalLayout->addWidget(FileChouse);


        horizontalLayout_2->addLayout(horizontalLayout);

        go = new QPushButton(widget);
        go->setObjectName(QStringLiteral("go"));
        QFont font6;
        font6.setPointSize(11);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setUnderline(false);
        font6.setWeight(75);
        font6.setStrikeOut(false);
        font6.setKerning(true);
        go->setFont(font6);
        go->setCursor(QCursor(Qt::CrossCursor));

        horizontalLayout_2->addWidget(go);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        PathText->setText(QApplication::translate("Dialog", "\350\257\267\351\200\211\346\213\251\346\226\207\344\273\266   ^_^", Q_NULLPTR));
        Explan1->setText(QApplication::translate("Dialog", "\346\234\254\347\250\213\345\272\217\351\200\232\350\277\207\345\257\271\346\226\207\344\273\266\346\234\253\345\260\276\345\244\204\346\267\273\345\212\240\351\232\217\346\234\272\345\255\227\347\254\246", Q_NULLPTR));
        Explan2->setText(QApplication::translate("Dialog", "\344\275\277\346\226\207\344\273\266\347\232\204Md5\345\217\221\347\224\237\345\217\230\345\274\202", Q_NULLPTR));
        Explan3->setText(QApplication::translate("Dialog", "\344\273\216\350\200\214\351\200\203\351\201\277\347\231\276\345\272\246\344\272\221\347\232\204\347\246\201\351\273\204\347\263\273\347\273\237", Q_NULLPTR));
        Explan4->setText(QApplication::translate("Dialog", "\346\263\250\357\274\232\350\247\206\351\242\221\346\226\207\344\273\266\347\255\211\350\276\203\345\244\247\346\226\207\344\273\266\350\257\267\345\234\250\346\233\264\346\224\271\345\211\215\345\244\207\344\273\275\357\274\214\344\273\245\351\230\262\345\217\221\347\224\237\344\270\215\346\265\213", Q_NULLPTR));
        FileChouse->setText(QApplication::translate("Dialog", "\351\200\211\346\213\251", Q_NULLPTR));
        go->setText(QApplication::translate("Dialog", "\346\211\247\350\241\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
