#ifndef THE_MENU_H
#define THE_MENU_H

#include <QMenuBar>
#include <QMenu>
#include <Qt>
#include "the_menu_file.h"
#include "the_menu_video.h"
#include "the_menu_audio.h"
#include "the_menu_tools.h"
#include "the_menu_help.h"
class TheMenu : public QMenuBar
{
    Q_OBJECT
private:
    FileMenu *fileMenu;
    VideoMenu *videoMenu;
    AudioMenu *audioMenu;
    ToolsMenu *toolsMenu;
    HelpMenu *helpMenu;

signals:
    //changed by XiujingLi
    void fastForward_is_triggered1_5();
    void fastForward_is_triggered1_75();
    void fastForward_is_triggered2();
    void slowMotion_is_triggered0_75();
    void slowMotion_is_triggered0_5();
    void slowMotion_is_triggered0_1();
    void normalSpeed_is_triggered();

    void openFile_is_triggered();
    void save_is_triggered();
    void share_is_triggered();

    // Edited by Shruti Naik
    void fullScreen_is_triggered();
    void minimizeScreen_is_triggered();

    void mute_is_triggered();
    void close_is_triggered();

public:
    TheMenu();
    //changed by XiujingLi
    void makeConnections();
};

#endif
