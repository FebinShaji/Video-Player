#ifndef MINIMUM_SCREEN_H
#define MINIMUM_SCREEN_H

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

/* Edited by: Shruti Naik */

class minimum_screen : public QWidget
{
    Q_OBJECT
public:
    minimum_screen();
    void setUI();

private:
    QVBoxLayout* videoLayout = new QVBoxLayout();
    QVideoWidget* videoWidget = new QVideoWidget();

};

#endif // MINIMUM_SCREEN_H
