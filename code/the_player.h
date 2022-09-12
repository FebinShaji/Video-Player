//
// Created by twak on 11/11/2019.
//

#ifndef CW2_THE_PLAYER_H
#define CW2_THE_PLAYER_H


#include <QApplication>
#include <QMediaPlayer>
#include "the_button.h"
#include <vector>
#include <QTimer>

//changed by XiujingLI
#include "the_customslider.h"
extern CustomSlider* slider_volume;
extern QTimer* timer;
extern CustomSlider* slider_video;
extern int maxValue;

class ThePlayer : public QMediaPlayer {

Q_OBJECT

private:
    std::vector<TheButtonInfo>* infos;
    std::vector<TheButton*>* buttons;
    QTimer* mTimer;
    long updateCount = 0;

public:
    ThePlayer() : QMediaPlayer(NULL) {
        setVolume(0); // be slightly less annoying
        connect (this, SIGNAL (stateChanged(QMediaPlayer::State)), this, SLOT (playStateChanged(QMediaPlayer::State)) );
        setPlaybackRate(1.0);

    }

    // all buttons have been setup, store pointers here
    void setContent(std::vector<TheButton*>* b, std::vector<TheButtonInfo>* i);

private slots:

    // change the image and video for one button every one second
    void shuffle();

    void playStateChanged (QMediaPlayer::State ms);

public slots:

    // start playing this ButtonInfo
    void jumpTo (TheButtonInfo* button);
    //changed by XiujingLI
    void playbackRateChangedSlot1_5();
    void playbackRateChangedSlot1_75();
    void playbackRateChangedSlot2();
    void playbackRateChangedSlot0_75();
    void playbackRateChangedSlot0_5();
    void playbackRateChangedSlot0_1();
    void playbackRateChangedSlot1();

    void changeState();

    void slider_volume_changed(int);
    void slider_volume_changed();

    void onTimerOut();
    void slider_video_clicked();
    void slider_video_moved(int);
    void slider_video_released();

    void forward_button_pushed();
    void backward_button_pushed();

    void mute_unmute();
};

#endif //CW2_THE_PLAYER_H
