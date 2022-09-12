#include "the_button_fullscreen.h"
FullscreenButton::FullscreenButton(const QString &text):QPushButton(text) {
    this->setFlat(true);
    this->setMinimumSize(30,30);
    this->setMaximumSize(30,30);
    this->setIconSize(QSize(30,30));;
    this->setIcon(QIcon(":/maximize-size.svg"));
}
