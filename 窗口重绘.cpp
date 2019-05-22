窗口重绘(自动调用)

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
    //QPainter p(this);//创建画家 并指定绘图对象
    static QString FilePath;
    QPainter p;//创建画家
    p.begin(this);//指定绘图设备 且需要在最后添加 p->end()
    //绘图操作
    p.drawPixmap(0,0,width(),height(),QPixmap("D:\\as the king of the road\\note\\Qt\\Project\\1.jpg"));
    p.drawPixmap(x,0,80,70,QPixmap("C:\\Users\\Administrator\\Desktop\\无标题.png"));
    //p.drawPixmap(0,0,width(),height(),QPixmap(*path));

    //创建画笔
    QPen pen;
    pen.setWidth(5);
    pen.setColor( QColor(24,218,213) );//设定画笔 QColor(R,G,B);
    pen.setStyle(Qt::DashDotLine);//设定风格

    //把画笔交给画家
    p.setPen(pen);

    //画直线
    p.drawLine(115,484,135,484);
    p.drawLine(112,480,139,488);
    p.drawLine(118,486,142,490);
    //p.drawLine(5,0,5,height());

    //设定画刷
    QBrush brush;
    brush.setColor(Qt::red);//设置颜色
    brush.setStyle(Qt::Dense1Pattern);//设定风格
    p.setBrush(brush);

    //画矩形
    //p.drawRect(5,5,width()-10,height()-10);

    //圆形
    //p.drawEllipse(QPoint(75,75),25,36);


    p.end();
    
    QPainter p(this);
    QPixmap pixmap;
    pixmap.load("D:\\as the king of the road\\note\\Qt\\Project\\1.jpg");
    QImage tempImage=pixmap.toImage();//把Pixmap抓换成Image
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
    update(x-80,0,160,70);//重绘窗口
}
