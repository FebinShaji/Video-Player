#include "the_button_pause.h"
PauseButton::PauseButton(const QString &text):QPushButton(text) {
    this->setFlat(true);
    this->setMinimumSize(60,60);
    this->setMaximumSize(60,60);
    this->setIconSize(QSize(50,50));;
    this->setIcon(QIcon(":/pause.svg"));

//changed by XiujingLi
    makeConnections();
}

//changed by XiujingLi
void PauseButton::makeConnections(){
    connect(this,SIGNAL(clicked()),this,SIGNAL(pauseButton_pushed()));
}

void PauseButton::changeIcon(QMediaPlayer::State state){
    if(state == QMediaPlayer::PausedState)
        this->setIcon(QIcon(":/next.svg"));
    else if(state == QMediaPlayer::PlayingState)
        this->setIcon(QIcon(":/pause.svg"));
}
