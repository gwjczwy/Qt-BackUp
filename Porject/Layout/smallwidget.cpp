#include "smallwidget.h"
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>

SmallWidget::SmallWidget(QWidget *parent) : QWidget(parent)
{
    QSpinBox *spin = new QSpinBox(this);
    QSlider *slider = new QSlider(Qt::Horizontal,this);

    //指定父对象
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    setLayout(hLayout);//指定父对象
    hLayout->addWidget(spin);//数字调节框
    hLayout->addWidget(slider);//滑块调节框


                                                            //当数字调节框变动时 改变滑块调节框
    connect(spin, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            slider,&QSlider::setValue
            );

                                                       //当滑块框改变时 改变数字调节框
    connect(slider,&QSlider::valueChanged,spin,&QSpinBox::setValue);

}
