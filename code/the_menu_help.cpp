#include "the_menu_help.h"
#include "QMessageBox"
#include "the_player.h"
#include "QApplication"
#include "QDialog"
#include "QTextEdit"
#include "QVBoxLayout"

/* Edited by: Shruti Naik */

HelpMenu::HelpMenu(const QString &title):QMenu(title) {
    // Help
    helpAction = new QAction("&Help");
    this->addAction(helpAction);
    helpAction->setShortcut(tr("CTRL+H"));
    helpAction->setStatusTip("Learn more about how to use Tomeo");
    helpAction->connect(helpAction, &QAction::triggered, this, &HelpMenu::help);

    // Guide to Tomeo
    guideAction = new QAction("&Guide");
    this->addSeparator();
    this->addAction(guideAction);
    guideAction->connect(guideAction, &QAction::triggered, this, &HelpMenu::moreInfo);
}

void HelpMenu::help() {
    // Display help box
    QMessageBox msgBox;
    msgBox.setWindowTitle("Help");
    msgBox.setText("For easiest access to the Tomeo application features "
                   "use the navigation bar at the top of the window screen\n\n"
                   "For any other queries contact: help@tomeoapp.com\n");
    msgBox.exec();
}

void HelpMenu::moreInfo() {
    // Display guide
    QDialog *msgBox = new QDialog();
    QTextEdit *text = new QTextEdit();
    QVBoxLayout *layout = new QVBoxLayout();
    text->setText("                     A guide to how to use Tomeo\n\n"
              "Tomeo is a simple to use application that aims to provide users with a simple "
              "platform to upload, edit, export and share media!\n\n"
              "Use the navigation bar at the top of your screen to access various functions \n"
              "File: open, close, and export media and quit Tomeo \n"
              "Video: video sort, filter and edit media files \n"
              "Audio: mute, unmute and edit audio of media \n"
              "Tools: access metadata and subtitle features \n"
              "Help: basic guide and access to help\n\n"
              "For any other queries contact: help@tomeoapp.com\n");
    text->setReadOnly(true);
    layout->addWidget(text);
    msgBox->setWindowTitle("Guide to Tomeo");
    msgBox->resize(400,250);
    msgBox->setLayout(layout);
    msgBox->exec();
}
