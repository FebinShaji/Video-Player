//
// Created by twak on 11/11/2019.
//

#include "the_player.h"

// all buttons have been setup, store pointers here
void ThePlayer::setContent(std::vector<TheButton*>* b, std::vector<TheButtonInfo>* i) {
    buttons = b;
    infos = i;
    jumpTo(buttons -> at(0) -> info);
}

// change the image and video for one button every one second
void ThePlayer::shuffle() {
    TheButtonInfo* i = & infos -> at (rand() % infos->size() );
//        setMedia(*i->url);
    buttons -> at( updateCount++ % buttons->size() ) -> init( i );
}

void ThePlayer::playStateChanged (QMediaPlayer::State ms) {
    switch (ms) {
        case QMediaPlayer::State::StoppedState:
            play(); // starting playing again...
            break;
    default:
        break;
    }
}

void ThePlayer::jumpTo (TheButtonInfo* button) {
    setMedia( * button -> url);
    play();
}

//changed by XiujingLi
void ThePlayer::playbackRateChangedSlot1_5(){
    setPlaybackRate(1.5);
}

void ThePlayer::playbackRateChangedSlot1_75(){
    setPlaybackRate(1.75);
}

void ThePlayer::playbackRateChangedSlot2(){
    setPlaybackRate(2);
}

void ThePlayer::playbackRateChangedSlot0_75(){
    setPlaybackRate(0.75);
}

void ThePlayer::playbackRateChangedSlot0_5(){
    setPlaybackRate(0.5);
}

void ThePlayer::playbackRateChangedSlot0_1(){
    setPlaybackRate(0.1);
}

void ThePlayer::playbackRateChangedSlot1(){
    setPlaybackRate(1);
}

void ThePlayer::changeState(){
    if(state() == QMediaPlayer::PlayingState)
        pause();
    else if(state() == QMediaPlayer::PausedState)
        play();
}

void ThePlayer::slider_volume_changed(int volume){
    setVolume(volume);
}

void ThePlayer::slider_volume_changed(){
    setVolume(slider_volume->value());
}

void ThePlayer::onTimerOut(){
    slider_video->setValue(position()*maxValue/duration());
}

void ThePlayer::slider_video_clicked(){
    setPosition(slider_video->value()*duration()/maxValue);
}

void ThePlayer::slider_video_moved(int position){
    timer->stop();
    setPosition(position*duration()/maxValue);
}

void ThePlayer::slider_video_released(){
    timer->start();
}

void ThePlayer::forward_button_pushed(){
    setPosition(position()+5000);
}

void ThePlayer::backward_button_pushed(){
    setPosition(position()-5000);
}

void ThePlayer::mute_unmute(){
    if(isMuted())
        setMuted(false);
    else
        setMuted(true);
}
