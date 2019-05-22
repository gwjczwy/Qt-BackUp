#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QDialog>
#include <QAction>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>//选择文件窗口类

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(340,560);
    QMenuBar *mBar=menuBar();
    setMenuBar(mBar);
    QMenu *pHelp=mBar->addMenu("Help");
    QAction *pAbout=pHelp->addAction("About_模态");
    QAction *pWith=pHelp->addAction("With us_非模态");

    connect(pAbout,QAction::triggered ,[=]()
    {
        //模态对话框     等待当前对话框结束后才能对其他对话框进行操作
        QDialog *Dia=new QDialog(this);
        Dia->resize(250,160);
        Dia->exec();
    });
    connect(pWith,QAction::triggered,[=](){
        //QDialog unDia;    //直接创建会导致窗口一闪而过 因为在显示完成后对话框即被销毁
        //unDia.resize(250,160);
        //unDia.show();

        //QDialog *unDia=new QDialog(this);     //使用指针创建的对话框不会被销毁 但内存仍在占用 打开多个对话框会导致内存耗尽
        //unDia->resize(250,160);
        //unDia->show();

        QDialog *unDia=new QDialog(this);
        unDia->setAttribute(Qt::WA_DeleteOnClose);  //虽然是动态分配内存 但设置成了在关闭时自动释放内存 这样就不会出现内存耗尽
        unDia->resize(250,160);                                                         //最优解
        unDia->show();

        //也可以直接把对话框设置成成员变量 在要显示的时候直接 show() 就行了
    });

    //创建一个对话框
    QAction *p1=pHelp->addAction("对话框");
    //这个对话框真尼玛人性化！
    connect(p1,QAction::triggered,[this](){
        int flag = QMessageBox::question(this,"Question","Are you ok?",
                                         QMessageBox::Ok
                                        |QMessageBox::Open
                                        |QMessageBox::Save
                                        |QMessageBox::Cancel
                                        |QMessageBox::Close
                                        |QMessageBox::Discard
                                        |QMessageBox::Apply
                                        |QMessageBox::Reset
                                        |QMessageBox::RestoreDefaults
                                        |QMessageBox::Help
                                        |QMessageBox::SaveAll
                                        |QMessageBox::Yes
                                        |QMessageBox::YesToAll
                                        |QMessageBox::No
                                        |QMessageBox::NoToAll
                                        |QMessageBox::Abort
                                        |QMessageBox::Retry
                                        |QMessageBox::Ignore
                                        |QMessageBox::NoButton
);
        switch(flag){
            case::QMessageBox::No:
                qDebug()<<"不如跳舞";
            break;
            case::QMessageBox::Yes:
                qDebug()<<"I'm OK!";
            break;
        }
    });


            //MessageBox 类型的对话框
    QAction *p2=pHelp->addAction("关于");
    connect(p2,QAction::triggered,[this](){
        QMessageBox::about(this,"About","关于");});

    QMenu *pFile=mBar->addMenu("文件");
    QAction *popen=pFile->addAction("打开");
    connect(popen,&QAction::triggered,
            [=]()
    {
        QString path = QFileDialog::getOpenFileName(this,"要打开什么文件？！","C:\\Users\\Administrator\\Desktop",
                                            tr("image(*.jpg *.jepg *.gif *.png);;text(*.txt *.text *.doc *.docx)"));
        qDebug()<<path;
    }

    );


}


MainWindow::~MainWindow()
{

}
