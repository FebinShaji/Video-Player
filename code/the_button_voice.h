#ifndef THE_BUTTON_VOICE_H
#define THE_BUTTON_VOICE_H

#include <QPushButton>
#include "the_player.h"

class VoiceButton : public QPushButton {
    Q_OBJECT
public:
    VoiceButton(const QString &text);
//changed by XiujingLi
    void makeConnections();

//changed bu XiujingLi
signals:
    void voiceButton_pushed();

public slots:
    void changeIcon(bool);
};

#endif // THE_BUTTON_VOICE_H
