#include "the_button_print.h"
#include "QMessageBox"
#include "the_player.h"
#include "QApplication"
#include "QDialog"
#include "QTextEdit"
#include "QVBoxLayout"

/* Edited by: Shruti Naik */

PrintButton::PrintButton(const QString &text):QPushButton(text) {
    this->setFlat(true);
    this->setMinimumSize(40,30);
    this->setMaximumSize(40,30);
    this->setIconSize(QSize(30,30));;
    this->setIcon(QIcon(":/print-alt.svg"));

    setShortcut(tr("CTRL+P"));
    setStatusTip("Print media meta data");
    connect(this, &QPushButton::released, this, &PrintButton::print);
}

void PrintButton::print() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Print Successful");
    msgBox.setText("Media meta data sent\nto print at Printer 3800");
    msgBox.exec();
}
