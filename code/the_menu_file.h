#ifndef THE_MENU_FILE_H
#define THE_MENU_FILE_H

#include <QMenu>

class FileMenu : public QMenu {
    Q_OBJECT
private:
    QAction* openfileAction;
    QAction* openfolderAction;
    QAction* closeallAction;
    QAction* saveAction;
    QAction* saveasAction;
    QAction* exportAction;
    QAction* shareAction;
    QAction* exitAction;
    QAction* quitAction;
public:
    FileMenu(const QString &title);
    void makeConnections();
signals:
    void openFile_triggered();
    void save_triggered();
    void share_triggered();
    void close_triggered();
};

#endif // THE_MENU_FILE_H
