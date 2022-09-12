#include "full_screen.h"


full_screen::full_screen()
{
    //on_action_triggered();
    setWindowTitle("Full Screen");

    setLayout(videoLayout);
    videoLayout->addWidget(videoWidget);
    videoLayout->addWidget(quitFullscreen);
    makeConnections();
    //setStyleSheet("background::yellow");
}

void full_screen::on_action_triggered()
{
    //player->play();
}

void full_screen::setUI()
{
    player->setVideoOutput(videoWidget);
}

void full_screen::makeConnections(){
    connect(quitFullscreen,SIGNAL(clicked()),this,SLOT(close()));
    connect(quitFullscreen,SIGNAL(clicked()),this,SIGNAL(quitPushed()));
}
