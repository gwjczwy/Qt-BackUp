#ifndef BOSS_H
#define BOSS_H

#include <QWidget>
#include <QPushButton>
#include <brother.h>
class Boss : public QWidget
{
    Q_OBJECT

public:
    Boss(QWidget *parent = 0);
    ~Boss();

private:
    Brother b;
    QPushButton bt1,bt2;
    void good();
    void bad();
    void toBrother();
    void toBoss();

};

#endif // BOSS_H
