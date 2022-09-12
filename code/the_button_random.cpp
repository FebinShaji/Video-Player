#include "the_button_random.h"
RandomButton::RandomButton(const QString &text):QPushButton(text) {
    this->setFlat(true);
    this->setMinimumSize(50,50);
    this->setMaximumSize(50,50);
    this->setIconSize(QSize(40,40));;
    this->setIcon(QIcon(":/shuffle.svg"));
}
