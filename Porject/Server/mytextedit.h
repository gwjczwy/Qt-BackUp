#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>

class myTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit myTextEdit(QTextEdit *parent = 0);

signals:

public slots:
};

#endif // MYTEXTEDIT_H
