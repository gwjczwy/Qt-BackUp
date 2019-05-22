#include <QMouseEvent>

//基类保留的事件处理函数
void MyButton::mousePressEvent(QMouseEvent *e){//正常情况下 如果你不改写这个函数 它会将消息继续向下传递 而现
    if(e->button() == Qt::LeftButton){//在调用我们的事件处理函数之后消息并没有向下传
        qDebug()<<"Left-Button";
        e->ignore();//将信号继续传递 这里会传递给父组件
        //e->accept();//不再将信号继续传递
    }else{
    QPushButton::mousePressEvent(e);//继续将消息传递下去
    }
}



#include <QMouseEvent>
#include <qDebug>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //设置从一开始就追踪鼠标
    setMouseTracking(true);
}

void MyLabel::mousePressEvent(QMouseEvent *ev){//传递 事件对象 ev
    int sx= ev->x();//取事件对象的 x y 坐标
    int sy= ev->y();

    QString str = QString("<center><h1>%1,%2    ^_^</h1></center>").arg(sx).arg(sy);//百分号+数字 代表某个字符串 在最后用 .arg(参数名) 依次代替 %n
    setText(str);

    if(ev->button() == Qt::LeftButton){//ev->button() 获取按下的按钮
        qDebug()<<"Left";
    }else if(ev->button() == Qt::RightButton){
        qDebug()<<"Right";
    }else if(ev->button() == Qt::MidButton){
        qDebug()<<"Mid";
    }
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev){//鼠标抬起事件
    int sx = ev->x();
    int sy = ev->y();

    QString str=QString("<center><h2>%1,%1  *_*</h></center>").arg(sx).arg(sy);
    setText(str);
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev){
    int sx = ev->x();
    int sy = ev->y();

    QString str=QString("<center><h3>%1,%1  @_@</h></center>").arg(sx).arg(sy);
    //setText(str);
}

void MyLabel::enterEvent(QEvent *event){
     QString str=QString("<center><h1>In</h></center>");
     setText(str);
}

void MyLabel::leaveEvent(QEvent *event){
    QString str=QString("<center><h1>Out</h></center>");
    setText(str);
}







#include <QKeyEvent>//键盘按下事件


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //设置 1000毫秒运行一次计时器事件
    TimeId=this->startTimer(1000);
    QuckTimeId=this->startTimer(100);
    //计时器ID
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
    if((event->modifiers() == Qt::ControlModifier) && (event->key() == Qt::Key_A)){//检测组合件的按下
        qDebug()<<"你按下了Ctrl + A";
    }
}

//计时器事件
void MyWidget::timerEvent(QTimerEvent *event){
    if(event->timerId() == this->TimeId){//如果该事件是 TimeId 的计时事件
        static int s=0;
        s++;
        ui->label->setText(QString("%1.0000S").arg(s));
        if(s==5){
            killTimer(TimeId);
        }
    }else if(event->timerId() == this->QuckTimeId){//如果该事件是 QuckTimeId 的计时事件
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
bool MyWidget::event(QEvent *event){//优先级超高 可以对所有该线程内的事件进行优先过滤
    if(event->type() == QEvent::KeyPress){//如果发生按下事件
        QKeyEvent *keyevent = static_cast<QKeyEvent *>(event);
        if(keyevent->key() == Qt::Key_Enter){
            qDebug()<<"你按下了回车";
            return true;//告诉Qt这个事件已经被处理
        }else{
            //return false;//把事件传递给它的父组件窗口处理
            return QWidget::event(event);//继续广播该事件
        }
    }


    return QWidget::event(event);//Qt把事件交给他的基类来处理
}

//事件过滤器
bool MyWidget::eventFilter(QObject *obj, QEvent *event){
    if(obj == ui->label_2){//如果是 label_2 的事件
        QMouseEvent *env = static_cast<QMouseEvent *>(event);//static_cast: 对QEvent * 类型转换成 QMouseEvent *
        if(event->type() == QEvent::MouseMove){
            ui->label_2->setText(QString("Mouse move:%1 %2").arg(env->x()).arg(env->y()));
            return true;
        }

    }
    return QWidget::eventFilter(obj,event);
}
