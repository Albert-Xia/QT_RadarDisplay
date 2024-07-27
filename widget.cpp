#include "widget.h"
#include "ui_widget.h"

#include <QPainter>
#include <QConicalGradient>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    m_timer = new QTimer(this);

    angle = 0;

    connect(m_timer,&QTimer::timeout,[=]()
    {

        angle += 5;
        if(angle > 360)
        {
            angle =0;
        }
        update();
    });
    m_timer->start(50);
}

Widget::~Widget()
{
    delete m_timer;

    delete ui;
}

 void Widget::paintEvent(QPaintEvent *event)
{
    (void)event;

    QPainter painter(this);
    painter.setRenderHint( QPainter::Antialiasing, true);

    painter.setBrush(Qt::black);
    painter.drawRect(this->rect());

    int side = qMin(width(),height())/2/7;

    painter.translate(rect().center());
    painter.setPen(QPen(Qt::green,1));
    painter.setBrush(Qt::NoBrush);
    for(int i = 1; i <= 7; i++)
    {
        painter.drawEllipse(QPoint(0,0),side*i,side*i);
    }


    painter.drawLine(-side*7,0,side*7,0);//X轴
    painter.drawLine(0,-side*7,0,side*7);//Y轴

    QConicalGradient co(0,0,-angle);
    co.setColorAt(0,QColor(0,255,0,200));
    co.setColorAt(0.1,QColor(0,255,0,100));
    co.setColorAt(0.2,QColor(0,255,0,0));
    co.setColorAt(1,QColor(0,255,0,0));

    painter.setPen(Qt::NoPen);
    painter.setBrush(co);
    painter.drawPie(-qMin(width(),height())/2,-qMin(width(),height())/2,qMin(width(),height()),qMin(width(),height()),
                    -angle*16,72*16);
}
