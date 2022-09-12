#ifndef THE_MENU_VIDEO_H
#define THE_MENU_VIDEO_H

#include <QMenu>

class VideoMenu : public QMenu {
    Q_OBJECT
private:
    QAction* sortmediaAction;
    QAction* filtermediaAction;
    QAction* fastforwardAction;
    QAction* slowmotionAction;


    QMenu* fastForwardMenu;
    QMenu* slowMotionMenu;

    QAction* fastForward1_5;
    QAction* fastForward1_75;
    QAction* fastForward2;

    QAction* slowMotion0_75;
    QAction* slowMotion0_5;
    QAction* slowMotion0_1;

    QAction* normalSpeed;

signals:
    void fastForward_triggered1_5();
    void fastForward_triggered1_75();
    void fastForward_triggered2();
    void slowMotion_triggered0_75();
    void slowMotion_triggered0_5();
    void slowMotion_triggered0_1();
    void normalSpeed_triggered();

public:
    VideoMenu(const QString &title);
    void makeConnections();
};

#endif // THE_MENU_VIDEO_H
