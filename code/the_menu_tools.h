#ifndef THE_MENU_TOOLS_H
#define THE_MENU_TOOLS_H

#include <QMenu>

/* Edited by: Shruti Naik */

class ToolsMenu : public QMenu {
    Q_OBJECT
private:
    QAction* metadataAction;
    QAction* viewAction;
    QAction* subtitlesAction;

    // Tools View
    QAction* fullscreenAction;
    QAction* minimizeAction;

    // Tools Subtitles
    QAction* uploadtranscriptAction;
    QAction* edittranscriptAction;
    QAction* hideshowAction;

    QMenu *viewMenu = new QMenu;
    QMenu *subtitlesMenu = new QMenu;

signals:
    void fullScreen_triggered();
    void minimizeScreen_triggered();

public slots:
    void metaData();

public:
    ToolsMenu(const QString &title);
    void makeConnections();
};

#endif // THE_MENU_TOOLS_H
