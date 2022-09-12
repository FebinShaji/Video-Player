#ifndef THE_CUSTOMSLIDER_H
#define THE_CUSTOMSLIDER_H
#include <QSlider>
#include <QMouseEvent>
#include <QCoreApplication>

class CustomSlider:public QSlider
{
    Q_OBJECT
public:
    CustomSlider(QWidget *parent = 0):QSlider(parent){}

protected:
    void mousePressEvent(QMouseEvent *ev);

signals:
    void customSliderClicked();
};

#endif // THE_CUSTOMSLIDER_H

