�����ػ�(�Զ�����)

#include <QPainter>
#include <QPen>
#include <QBrush>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event){
    //QPainter p(this);//�������� ��ָ����ͼ����
    static QString FilePath;
    QPainter p;//��������
    p.begin(this);//ָ����ͼ�豸 ����Ҫ�������� p->end()
    //��ͼ����
    p.drawPixmap(0,0,width(),height(),QPixmap("D:\\as the king of the road\\note\\Qt\\Project\\1.jpg"));
    p.drawPixmap(x,0,80,70,QPixmap("C:\\Users\\Administrator\\Desktop\\�ޱ���.png"));
    //p.drawPixmap(0,0,width(),height(),QPixmap(*path));

    //��������
    QPen pen;
    pen.setWidth(5);
    pen.setColor( QColor(24,218,213) );//�趨���� QColor(R,G,B);
    pen.setStyle(Qt::DashDotLine);//�趨���

    //�ѻ��ʽ�������
    p.setPen(pen);

    //��ֱ��
    p.drawLine(115,484,135,484);
    p.drawLine(112,480,139,488);
    p.drawLine(118,486,142,490);
    //p.drawLine(5,0,5,height());

    //�趨��ˢ
    QBrush brush;
    brush.setColor(Qt::red);//������ɫ
    brush.setStyle(Qt::Dense1Pattern);//�趨���
    p.setBrush(brush);

    //������
    //p.drawRect(5,5,width()-10,height()-10);

    //Բ��
    //p.drawEllipse(QPoint(75,75),25,36);


    p.end();
    
    QPainter p(this);
    QPixmap pixmap;
    pixmap.load("D:\\as the king of the road\\note\\Qt\\Project\\1.jpg");
    QImage tempImage=pixmap.toImage();//��Pixmapץ����Image
    p.drawImage(0,-400,tempImage);
}

void FilePathChange(QString s){
    static QString FilePath=s;
//    qDebug()<<FilePath;
//    qDebug()<<s;
//    qDebug()<<"FilePathChange";
}


void Widget::on_pushButton_clicked()
{
    x+=70;
    if(x>=width()){
        x=0;
    }
    update(x-80,0,160,70);//�ػ洰��
}
