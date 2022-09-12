#include "the_button_voice.h"
VoiceButton::VoiceButton(const QString &text):QPushButton(text) {
    this->setFlat(true);
    this->setMinimumSize(30,30);
    this->setMaximumSize(30,30);
    this->setIconSize(QSize(30,30));;
    this->setIcon(QIcon(":/sound-max.svg"));
}

void VoiceButton::makeConnections(){
    connect(this,SIGNAL(clicked()),this,SIGNAL(voiceButton_pushed()));
}

void VoiceButton::changeIcon(bool muted){
    if(muted == true)
        setIcon(QIcon(":/sound-mute-alt.svg"));
    else
        setIcon(QIcon(":/sound-max.svg"));
}
