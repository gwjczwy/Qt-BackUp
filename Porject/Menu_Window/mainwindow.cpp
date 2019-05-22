#include "mainwindow.h"
#include <QMenuBar>//添加菜单栏
#include <QMenu>//菜单 不写也行
#include <QAction>//菜单中的动作 不写也行
#include <QDebug>//打印
#include <QToolBar>//添加菜单栏里的选项
#include <QPushButton>//...
#include <QStatusBar>//状态栏
#include <QLabel>//标签
#include <QTextEdit>//文本编辑
#include <QDockWidget>//浮动窗口

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(320,450);
    //常用类型：
    //菜单栏
    QMenuBar *mBar = menuBar();

    //添加菜单
    QMenu *pFile = mBar->addMenu("File");

    //添加操作
    QAction *pOpen=pFile->addAction("Open File");
    pFile->addSeparator();//添加分割线
    QAction *pNew=pFile->addAction("New File");
    connect(pNew,&QAction::triggered,[=](){qDebug()<<"New File";});
    connect(pOpen,&QAction::triggered,[=](){qDebug()<<"Open File";});

    //  工具栏 操作的快捷方式
    QToolBar *TNew=addToolBar("toolBar");//新建 的快捷方式
    TNew->addAction(pNew);
    QToolBar *TOpen=addToolBar("toolBar");//打开文件 的快捷方式
    TOpen->addAction(pOpen);

    QPushButton *b=new QPushButton(this);//退出的按钮
    b->setText("close");
    QToolBar *TClose=addToolBar("toolBar");//工具栏的位置创建一个 退出按钮
    TClose->addWidget(b);
    connect(b,&QPushButton::clicked,[=](){close();});

    //  状态栏
    QStatusBar *sBar=statusBar();//创建一个状态栏
    QLabel *Text=new QLabel(this);//一个状态栏中有多个项目
    Text->setText("No File");//设置项目名称
    sBar->addWidget(Text);//将一个项目添加到状态栏中
    sBar->addWidget(new QLabel("4294967295"));//也可以直接new一个

    sBar->addPermanentWidget(new QLabel("从右往左"));//从右往左

    //  核心控件
    QTextEdit *textedit=new QTextEdit(this);//添加一个文本编辑器
    setCentralWidget(textedit);//把文本编辑器添加到主窗口中

    //  浮动窗口
    QDockWidget *dock=new QDockWidget(this);//创建一个浮动窗口
    addDockWidget(Qt::LeftDockWidgetArea,dock);//设置成默认在左边 并添加 dock_浮动部件
                    //这个参数太长 不好记？ 先随便打两个参数 然后点函数名后按F1会出现帮助文档

    QTextEdit *txt=new QTextEdit(this);//新建一个文本编辑器控件
    dock->setWidget(txt);//添加到 浮动部件中

}

MainWindow::~MainWindow()
{

}
