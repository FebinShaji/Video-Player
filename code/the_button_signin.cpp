#include "the_button_signin.h"
SigninButton::SigninButton(const QString &text):QPushButton(text) {
    this->setFlat(true);
    this->setMinimumSize(40,30);
    this->setMaximumSize(40,30);
    this->setIconSize(QSize(30,30));;
    this->setIcon(QIcon(":/log-in-2.svg"));
}
