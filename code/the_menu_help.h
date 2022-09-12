#ifndef THE_MENU_HELP_H
#define THE_MENU_HELP_H

#include <QMenu>

/* Edited by: Shruti Naik */

class HelpMenu : public QMenu {
private:
    QAction* helpAction;
    QAction* moreinformation;
    QAction* guideAction;
    QAction* registerAction;
public:
    HelpMenu(const QString &title);
public slots:
    // display help
    void help();
    // display guide
    void moreInfo();
};
#endif // THE_MENU_HELP_H
