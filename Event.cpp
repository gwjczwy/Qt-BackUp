#include <QMouseEvent>

//���ౣ�����¼�������
void MyButton::mousePressEvent(QMouseEvent *e){//��������� ����㲻��д������� ���Ὣ��Ϣ�������´��� ����
    if(e->button() == Qt::LeftButton){//�ڵ������ǵ��¼�������֮����Ϣ��û�����´�
        qDebug()<<"Left-Button";
        e->ignore();//���źż������� ����ᴫ�ݸ������
        //e->accept();//���ٽ��źż�������
    }else{
    QPushButton::mousePressEvent(e);//��������Ϣ������ȥ
    }
}



#include <QMouseEvent>
#include <qDebug>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //���ô�һ��ʼ��׷�����
    setMouseTracking(true);
}

void MyLabel::mousePressEvent(QMouseEvent *ev){//���� �¼����� ev
    int sx= ev->x();//ȡ�¼������ x y ����
    int sy= ev->y();

    QString str = QString("<center><h1>%1,%2    ^_^</h1></center>").arg(sx).arg(sy);//�ٷֺ�+���� ����ĳ���ַ��� ������� .arg(������) ���δ��� %n
    setText(str);

    if(ev->button() == Qt::LeftButton){//ev->button() ��ȡ���µİ�ť
        qDebug()<<"Left";
    }else if(ev->button() == Qt::RightButton){
        qDebug()<<"Right";
    }else if(ev->button() == Qt::MidButton){
        qDebug()<<"Mid";
    }
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev){//���̧���¼�
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







#include <QKeyEvent>//���̰����¼�


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //���� 1000��������һ�μ�ʱ���¼�
    TimeId=this->startTimer(1000);
    QuckTimeId=this->startTimer(100);
    //��ʱ��ID
    connect(ui->pushButton,&MyButton::pressed,[=](){
        qDebug()<<"��ť������";
    });

    //��װ�¼�������
    ui->label_2->installEventFilter(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

//�����¼�
void MyWidget::keyPressEvent(QKeyEvent *event){
    if((event->modifiers() == Qt::ControlModifier) && (event->key() == Qt::Key_A)){//�����ϼ��İ���
        qDebug()<<"�㰴����Ctrl + A";
    }
}

//��ʱ���¼�
void MyWidget::timerEvent(QTimerEvent *event){
    if(event->timerId() == this->TimeId){//������¼��� TimeId �ļ�ʱ�¼�
        static int s=0;
        s++;
        ui->label->setText(QString("%1.0000S").arg(s));
        if(s==5){
            killTimer(TimeId);
        }
    }else if(event->timerId() == this->QuckTimeId){//������¼��� QuckTimeId �ļ�ʱ�¼�
        static int s=0;
        s++;
        ui->label_2->setText(QString("%1.0000S").arg(s));
    }
}

//��갴���¼�
void MyWidget::mousePressEvent(QMouseEvent *e){
    qDebug()<<"father:��걻����";
}

//�¼�
bool MyWidget::event(QEvent *event){//���ȼ����� ���Զ����и��߳��ڵ��¼��������ȹ���
    if(event->type() == QEvent::KeyPress){//������������¼�
        QKeyEvent *keyevent = static_cast<QKeyEvent *>(event);
        if(keyevent->key() == Qt::Key_Enter){
            qDebug()<<"�㰴���˻س�";
            return true;//����Qt����¼��Ѿ�������
        }else{
            //return false;//���¼����ݸ����ĸ�������ڴ���
            return QWidget::event(event);//�����㲥���¼�
        }
    }


    return QWidget::event(event);//Qt���¼��������Ļ���������
}

//�¼�������
bool MyWidget::eventFilter(QObject *obj, QEvent *event){
    if(obj == ui->label_2){//����� label_2 ���¼�
        QMouseEvent *env = static_cast<QMouseEvent *>(event);//static_cast: ��QEvent * ����ת���� QMouseEvent *
        if(event->type() == QEvent::MouseMove){
            ui->label_2->setText(QString("Mouse move:%1 %2").arg(env->x()).arg(env->y()));
            return true;
        }

    }
    return QWidget::eventFilter(obj,event);
}
