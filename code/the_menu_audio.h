#ifndef THE_MENU_AUDIO_H
#define THE_MENU_AUDIO_H

#include <QMenu>

class AudioMenu : public QMenu {
    Q_OBJECT
private:
    QAction* muteunmutAction;
    QAction* reverberatonAction;
    QAction* exportaudioonlyAction;
    QAction* addbgmtothevideoAction;
    QAction* bgmidentifyAction;

public:
    AudioMenu(const QString &title);
    void makeConnections();

signals:
    void mute_triggered();

};

#endif // THE_MENU_AUDIO_H
