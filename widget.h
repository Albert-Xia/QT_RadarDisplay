#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


    void paintEvent(QPaintEvent *event);

private:
    Ui::Widget *ui;

    int angle;
    QTimer *m_timer;
};
#endif // WIDGET_H
