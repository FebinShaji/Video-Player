#ifndef FULL_SCREEN_H
#define FULL_SCREEN_H
// There is absoultely a bug in fullscreen button, after full screen the main window can not display

#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include <string>
#include <vector>
#include <QtCore/QFileInfo>
#include <QtWidgets/QFileIconProvider>
#include <QDesktopServices>
#include <QImageReader>
#include <QMessageBox>
#include <QtCore/QDir>
#include <QtCore/QDirIterator>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include "the_player.h"

extern ThePlayer *player;
//extern full_screen *fullscreenWidget;


class full_screen : public QWidget
{
    Q_OBJECT

public:
    full_screen();
    void setUI();
    void makeConnections();

private:
    QPushButton* quitFullscreen = new QPushButton("quit");
    QVBoxLayout* videoLayout = new QVBoxLayout();
    QVideoWidget* videoWidget = new QVideoWidget();


private slots:
    void on_action_triggered();

signals:
    void quitPushed();

};

#endif // FULL_SCREEN_H
