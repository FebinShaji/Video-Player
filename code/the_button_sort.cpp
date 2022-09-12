#include "the_button_sort.h"
SortButton::SortButton(const QString &text):QPushButton(text) {
    this->setFlat(true);
    this->setMinimumSize(30,30);
    this->setMaximumSize(30,30);
    this->setIconSize(QSize(30,30));;
    this->setIcon(QIcon(":/filter-alt.svg"));
}
