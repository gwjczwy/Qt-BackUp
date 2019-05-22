#include "mywidget.h"
#include "ui_mywidget.h"
#include <QKeyEvent>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //设置 1000毫秒运行一次计时器事件
    TimeId=this->startTimer(1000);
    QuckTimeId=this->startTimer(100);

    connect(ui->pushButton,&MyButton::pressed,[=](){
        qDebug()<<"按钮被按下";
    });

    //安装事件过滤器
    ui->label_2->installEventFilter(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

//按键事件
void MyWidget::keyPressEvent(QKeyEvent *event){
    if((event->modifiers() == Qt::ControlModifier) && (event->key() == Qt::Key_A)){
        qDebug()<<"你按下了Ctrl + A";
    }
}

//计时器事件
void MyWidget::timerEvent(QTimerEvent *event){
    if(event->timerId() == this->TimeId){
        static int s=0;
        s++;
        ui->label->setText(QString("%1.0000S").arg(s));
        if(s==5){
            killTimer(TimeId);
        }
    }else if(event->timerId() == this->QuckTimeId){
        static int s=0;
        s++;
        ui->label_2->setText(QString("%1.0000S").arg(s));
    }
}

//鼠标按下事件
void MyWidget::mousePressEvent(QMouseEvent *e){
    qDebug()<<"father:鼠标被按下";
}

//事件
bool MyWidget::event(QEvent *event){
    if(event->type() == QEvent::KeyPress){//如果发生按下事件
        QKeyEvent *keyevent = static_cast<QKeyEvent *>(event);
        if(keyevent->key() == Qt::Key_Enter){
            qDebug()<<"你按下了回车";
            return true;//告诉Qt这个事件已经被处理
        }else{
            //return false;//把事件传递给它的父组件窗口处理
            return QWidget::event(event);
        }
    }


    return QWidget::event(event);//Qt把事件交给他的基类来处理
}

//事件过滤器
bool MyWidget::eventFilter(QObject *obj, QEvent *event){
    if(obj == ui->label_2){
        QMouseEvent *env = static_cast<QMouseEvent *>(event);
        if(event->type() == QEvent::MouseMove){
            ui->label_2->setText(QString("Mouse move:%1 %2").arg(env->x()).arg(env->y()));
            return true;
        }

    }
    return QWidget::eventFilter(obj,event);
}


















