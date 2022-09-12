#include "the_customslider.h"

void CustomSlider::mousePressEvent(QMouseEvent *ev)
{
    QSlider::mousePressEvent(ev);

    double pos;
    if(this->orientation() == Qt::Horizontal )
    {   //horizontal Slider
        pos = ev->pos().x() / (double)width();
        setValue(pos * (maximum() - minimum()) + minimum());
    }
    else if(this->orientation() == Qt::Vertical )
    {   //vertical Slider
        pos = ev->pos().y() / (double)height();
        setValue(maximum() - pos * (maximum() - minimum()));
    }

    //emit signal
    emit customSliderClicked();
}
