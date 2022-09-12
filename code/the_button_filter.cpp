#include "the_button_filter.h"
FilterButton::FilterButton(const QString &text):QPushButton(text) {
    this->setFlat(true);
    this->setMinimumSize(60,30);
    this->setMaximumSize(60,30);
    this->setFont(QFont("Times", 13, QFont::Bold));
}
