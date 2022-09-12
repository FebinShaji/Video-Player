#include "the_menu_audio.h"

AudioMenu::AudioMenu(const QString &title):QMenu(title) {
    muteunmutAction = new QAction("&Mute/Unmute");
    reverberatonAction = new QAction("&Reverberation");
    exportaudioonlyAction = new QAction("&Export audio only");
    addbgmtothevideoAction = new QAction("&Add BGM to the video");
    bgmidentifyAction = new QAction("&BGM identify");

    this->addAction(muteunmutAction);
    this->addSeparator();
    this->addAction(reverberatonAction);
    this->addSeparator();
    this->addAction(exportaudioonlyAction);
    this->addSeparator();
    this->addAction(addbgmtothevideoAction);
    this->addAction(bgmidentifyAction);

    makeConnections();
}

void AudioMenu::makeConnections(){
    connect(muteunmutAction,SIGNAL(triggered()),this,SIGNAL(mute_triggered()));
}
