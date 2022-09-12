//    ______
//   /_  __/___  ____ ___  ___  ____
//    / / / __ \/ __ `__ \/ _ \/ __ \
//   / / / /_/ / / / / / /  __/ /_/ /
//  /_/  \____/_/ /_/ /_/\___/\____/
//              video for sports enthusiasts...
//
//  2811 cw3 : twak 11/11/2021
//

/* I have reorgenized all codes and split all
 * the buttons and functions, when you are coding the file you got,
 * please don't edit other's file unless you need some functions
 * from it and tell that guy first.
 * please leave your message when you want to edit the main file.
 * ----------chaodao
 * */

#include <iostream>
#include <QApplication>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMediaPlaylist>
#include <string>
#include <vector>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QFileInfo>
#include <QtWidgets/QFileIconProvider>
#include <QDesktopServices>
#include <QImageReader>
#include <QMessageBox>
#include <QtCore/QDir>
#include <QtCore/QDirIterator>
#include <QtWidgets>
#include <QScrollArea>
#include <QStyleFactory>
#include "whole_widget.h"
#include "the_menu.h"
#include "the_player.h"
#include "the_button.h"
#include "the_button_signin.h"
#include "the_button_signout.h"
#include "the_button_share.h"
#include "the_button_save.h"
#include "the_button_print.h"
#include "the_button_fullscreen.h"
#include "the_button_pause.h"
#include "the_button_backward.h"
#include "the_button_forward.h"
#include "the_button_voice.h"
#include "the_button_order.h"
#include "the_button_random.h"
#include "the_button_filter.h"
#include "the_button_sort.h"
#include "signinout_title.h"
//changed by XiujingLi
#include "the_customslider.h"
#include "initial_window.h"
#include "full_screen.h"

//changed by XiujingLi
CustomSlider *slider_volume;
CustomSlider *slider_video;
int maxValue = 1000;//the max value of slider_video
QTimer *timer = new QTimer;

ThePlayer *player;

// read in videos and thumbnails to this directory
std::vector<TheButtonInfo> getInfoIn (std::string loc) {

    std::vector<TheButtonInfo> out =  std::vector<TheButtonInfo>();
    QDir dir(QString::fromStdString(loc) );
    QDirIterator it(dir);

    while (it.hasNext()) { // for all files

        QString f = it.next();

            if (f.contains("."))

#if defined(_WIN32)
            if (f.contains(".wmv"))  { // windows
#else
            if (f.contains(".mp4") || f.contains("MOV"))  { // mac/linux
#endif

            QString thumb = f.left( f .length() - 4) +".png";
            if (QFile(thumb).exists()) { // if a png thumbnail exists
                QImageReader *imageReader = new QImageReader(thumb);
                    QImage sprite = imageReader->read(); // read the thumbnail
                    if (!sprite.isNull()) {
                        QIcon* ico = new QIcon(QPixmap::fromImage(sprite)); // voodoo to create an icon for the button
                        QUrl* url = new QUrl(QUrl::fromLocalFile( f )); // convert the file location to a generic url
                        out . push_back(TheButtonInfo( url , ico  ) ); // add to the output list
                    }
                    else
                        qDebug() << "warning: skipping video because I couldn't process thumbnail " << thumb << endl;
            }
            else
                qDebug() << "warning: skipping video because I couldn't find thumbnail " << thumb << endl;
        }
    }

    return out;
}

int main(int argc, char *argv[]) {

    // let's just check that Qt is operational first
    qDebug() << "Qt version: " << QT_VERSION_STR << endl;

    // create the Qt Application
    QApplication app(argc, argv);
    // edited by chaodao
    app.setStyle(QStyleFactory::create("fusion"));

    // collect all the videos in the folder
    std::vector<TheButtonInfo> videos;

    if (argc == 2)
        videos = getInfoIn( std::string(argv[1]) );

    if (videos.size() == 0) {

        const int result = QMessageBox::question(
                    NULL,
                    QString("Tomeo"),
                    QString("no videos found! download, unzip, and add command line argument to \"quoted\" file location. Download videos from Tom's OneDrive?"),
                    QMessageBox::Yes |
                    QMessageBox::No );

        switch( result )
        {
        case QMessageBox::Yes:
          QDesktopServices::openUrl(QUrl("https://leeds365-my.sharepoint.com/:u:/g/personal/scstke_leeds_ac_uk/EcGntcL-K3JOiaZF4T_uaA4BHn6USbq2E55kF_BTfdpPag?e=n1qfuN"));
          break;
        default:
            break;
        }
        exit(-1);
    }

    // the widget that will show the video
    whole_widget window;

    // the QMediaPlayer which controls the playback
//    ThePlayer *player = new ThePlayer;
    player = new ThePlayer();
    player->setVideoOutput(window.videoWidget);

    // a row of buttons    

    //CHANGE --- new VICTOR ZHANG
    QWidget *buttonWidget = new QWidget();
    QWidget *buttonWidget2 = new QWidget();
    //CHANGE --- new VICTOR ZHANG

    // a list of the buttons
    std::vector<TheButton*> buttons;
    // the buttons are arranged horizontally

    //CHANGE -- new VICTOR ZHANG
    //QHBoxLayout *layout = new QHBoxLayout();
    QVBoxLayout *firstvideos = new QVBoxLayout();
    QVBoxLayout *secondvideos = new QVBoxLayout();

    buttonWidget->setLayout(secondvideos);
    buttonWidget2->setLayout(firstvideos);
    //CHANGE -- new VICTOR ZHANG

    //CHANGE -- new VICTOR ZHANG
    /*
     for ( int i = 0; i < 4; i++ ) {
        TheButton *button = new TheButton(buttonWidget);
        button->connect(button, SIGNAL(jumpTo(TheButtonInfo* )), player, SLOT (jumpTo(TheButtonInfo*))); // when clicked, tell the player to play.
        buttons.push_back(button);
        layout->addWidget(button);
        button->init(&videos.at(i));
    }
    */
    // create the four buttons
    for ( auto i = 0; i < videos.size()/2; i++ ) {
        TheButton *button = new TheButton(buttonWidget);
        button->connect(button, SIGNAL(jumpTo(TheButtonInfo* )), player, SLOT (jumpTo(TheButtonInfo*))); // when clicked, tell the player to play.
        buttons.push_back(button);
        firstvideos->addWidget(button);
        button->init(&videos.at(i));
    }
    for ( auto i = videos.size()/2; i  < videos.size(); i++ ) {
        TheButton *button2 = new TheButton(buttonWidget2);
        button2->connect(button2, SIGNAL(jumpTo(TheButtonInfo* )), player, SLOT (jumpTo(TheButtonInfo*))); // when clicked, tell the player to play.
        buttons.push_back(button2);
        secondvideos->addWidget(button2);
        button2->init(&videos.at(i));
    }
    //CHANGE -- new VICTOR ZHANG

    // tell the player what buttons and videos are available
    player->setContent(&buttons, &videos);

    QMenuBar *theMenu = new TheMenu();
//    theMenu->setStyleSheet("background::yellow");
//    theMenu->setWindowFlag()
//    theMenu->setAttribute(Qt::WA_TranslucentBackground);
//    theMenu->setStyleSheet();
//    theMenu->setWindowOpacity(0.5);
    // if want to change color, use this code
    // edited by chaodao
    QPalette menupalette=theMenu->palette();
    menupalette.setColor(QPalette::Window, Qt::transparent);
    theMenu->setPalette(menupalette);

    // changed by chaodao
    SigninButton* signinButton = new SigninButton("");
    SignoutButton* signoutButton = new SignoutButton("");
    ShareButton* shareButton = new ShareButton("");
    SaveButton* saveButton = new SaveButton("");
    PrintButton* printButton = new PrintButton("");
    FullscreenButton* fullscreenButton = new FullscreenButton("");
    PauseButton* pauseButton = new PauseButton("");
    ForwardButton* forwardButton = new ForwardButton(" ");
    BackwardButton* backwardButton = new BackwardButton("");
    VoiceButton* voiceButton = new VoiceButton("");
    OrderButton* orderButton = new OrderButton("");
    RandomButton* randomButton = new RandomButton("");
    FilterButton* filterButton = new FilterButton("&Filter");
    SortButton* sortButton = new SortButton("");

    //changed by XiujingLi
    slider_volume = new CustomSlider(window.videoWidget);
    slider_volume->setOrientation(Qt::Horizontal);
    slider_volume->setValue(player->volume());
    slider_video = new CustomSlider(window.videoWidget);
    slider_video->setOrientation(Qt::Horizontal);
    slider_video->setRange(0,maxValue);

    timer->setInterval(1000);
    timer->start();

    QLabel* space = new QLabel("");

    QHBoxLayout* righttop = new QHBoxLayout();
    QHBoxLayout* belowtopLayout = new QHBoxLayout();
    QHBoxLayout* belowtoptopLayout = new QHBoxLayout();
    QHBoxLayout* belowbottomLayout = new QHBoxLayout();
    QVBoxLayout *right = new QVBoxLayout();
    QHBoxLayout* right2 = new QHBoxLayout();
    QVBoxLayout* right3 = new QVBoxLayout();
    QHBoxLayout *lefttopLayout = new QHBoxLayout();
    QVBoxLayout *left = new QVBoxLayout();
    QHBoxLayout *central = new QHBoxLayout();
    QVBoxLayout *whole = new QVBoxLayout();

    righttop->addWidget(printButton);
    righttop->addWidget(saveButton);
    righttop->addWidget(space);
    righttop->addWidget(window.signinout);
    righttop->addWidget(signinButton);
    righttop->addWidget(signoutButton);
    righttop->addWidget(shareButton);

    belowtopLayout->addWidget(voiceButton);
    belowtopLayout->addWidget(slider_volume);
    belowtopLayout->addStretch();
    belowtopLayout->addStretch();
    belowtopLayout->addWidget(orderButton);
    belowtopLayout->addWidget(randomButton);

    belowbottomLayout->addWidget(space);
    belowbottomLayout->addWidget(backwardButton);
    belowbottomLayout->addWidget(pauseButton);
    belowbottomLayout->addWidget(forwardButton);
    belowbottomLayout->addWidget(space);

    belowtoptopLayout->addWidget(slider_video);
    belowtoptopLayout->addWidget(fullscreenButton);

    // combain right part
    right->addWidget(window.videoWidget);
    right->addLayout(belowtoptopLayout);
    right->addLayout(belowtopLayout);    
    right->addLayout(belowbottomLayout);
    right->addWidget(space);    

    right2->addLayout(right);
    right2->addWidget(space);
    right2->addWidget(space);
    right2->addWidget(space);

    right3->addLayout(righttop);
    right3->addLayout(right2);

    lefttopLayout->addWidget(filterButton);
    lefttopLayout->addWidget(space);    
    lefttopLayout->addWidget(sortButton);
    //CHANGE -- new VICTOR ZHANG

    QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);
    // create the main window and layout


    // QScrollArea
    QScrollArea *roll = new QScrollArea();
    QWidget *rollWidget = new QWidget();
    QHBoxLayout *rollLayout = new QHBoxLayout(roll);
//    roll->setAttribute(Qt::ScrollBarAlwaysOn);
    roll->setMinimumWidth(423);
    roll->setWidgetResizable(true);
    rollWidget->setWindowOpacity(0.5);
//    roll->setStyleSheet("QScrollArea {background-color:transparent;}");
//    roll->viewport()->setStyleSheet("background-color:transparent;");
    roll->setFrameShape(QFrame::NoFrame);
    QPalette PAllbackground = roll->palette();
    QImage ImgAllbackground(":/scrollarea4.png");
    QImage fitimgpic=ImgAllbackground.scaled(roll->width(),roll->height(), Qt::IgnoreAspectRatio);
    PAllbackground.setBrush(QPalette::Window, QBrush(fitimgpic));
    roll->setPalette(PAllbackground);


    rollLayout->addWidget(buttonWidget);
    rollLayout->addWidget(buttonWidget2);
    rollWidget->setLayout(rollLayout);
    //rollWidget->setMinimumSize(400, 900);
    rollWidget->setMaximumSize(400, 2000);
    roll->setWidget(rollWidget);
    left->addLayout(lefttopLayout);
    left->addWidget(roll);

    // QScrollArea

    // Layout combain
    central->addLayout(left);
    central->addWidget(space);
    central->addWidget(space);
    central->addWidget(space);
    central->addLayout(right3);
    whole->addWidget(theMenu);
    whole->addLayout(central);
    // Layout combain

    //Changed by XiujingLi
    QObject::connect(theMenu,SIGNAL(fastForward_is_triggered1_5()),player,SLOT(playbackRateChangedSlot1_5()));
    QObject::connect(theMenu,SIGNAL(fastForward_is_triggered1_75()),player,SLOT(playbackRateChangedSlot1_75()));
    QObject::connect(theMenu,SIGNAL(fastForward_is_triggered2()),player,SLOT(playbackRateChangedSlot2()));
    QObject::connect(theMenu,SIGNAL(slowMotion_is_triggered0_75()),player,SLOT(playbackRateChangedSlot0_75()));
    QObject::connect(theMenu,SIGNAL(slowMotion_is_triggered0_5()),player,SLOT(playbackRateChangedSlot0_5()));
    QObject::connect(theMenu,SIGNAL(slowMotion_is_triggered0_1()),player,SLOT(playbackRateChangedSlot0_1()));
    QObject::connect(theMenu,SIGNAL(normalSpeed_is_triggered()),player,SLOT(playbackRateChangedSlot1()));

    QObject::connect(pauseButton,SIGNAL(pauseButton_pushed()),player,SLOT(changeState()));
    QObject::connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),pauseButton,SLOT(changeIcon(QMediaPlayer::State)));

    QObject::connect(slider_volume,SIGNAL(customSliderClicked()),player,SLOT(slider_volume_changed()));
    QObject::connect(slider_volume,SIGNAL(sliderMoved(int)),player,SLOT(slider_volume_changed(int)));

    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(onTimerOut()));
    QObject::connect(slider_video,SIGNAL(customSliderClicked()),player,SLOT(slider_video_clicked()));
    QObject::connect(slider_video,SIGNAL(sliderMoved(int)),player,SLOT(slider_video_moved(int)));
    QObject::connect(slider_video,SIGNAL(sliderReleased()),player,SLOT(slider_video_released()));

    QObject::connect(forwardButton,SIGNAL(clicked()),player,SLOT(forward_button_pushed()));
    QObject::connect(backwardButton,SIGNAL(clicked()),player,SLOT(backward_button_pushed()));

    QObject::connect(signinButton,SIGNAL(clicked()),&window,SLOT(initialShow()));
    QObject::connect(fullscreenButton,SIGNAL(clicked()),&window,SLOT(fullwindowShow()));

    QObject::connect(saveButton,SIGNAL(clicked()),&window,SLOT(save()));

    QObject::connect(theMenu,SIGNAL(openFile_is_triggered()),&window,SLOT(openFile()));
    QObject::connect(theMenu,SIGNAL(save_is_triggered()),&window,SLOT(save()));
    QObject::connect(theMenu,SIGNAL(share_is_triggered()),shareButton,SLOT(share()));
    QObject::connect(theMenu,SIGNAL(close_is_triggered()),&window,SLOT(closeAll()));

    // Edited by Shruti Naik
    QObject::connect(theMenu,SIGNAL(fullScreen_is_triggered()),&window,SLOT(fullwindowShow()));
    QObject::connect(theMenu,SIGNAL(minimizeScreen_is_triggered()),&window,SLOT(minimumWindowShow()));

    QObject::connect(theMenu,SIGNAL(mute_is_triggered()),player,SLOT(mute_unmute()));
    QObject::connect(voiceButton,SIGNAL(clicked()),player,SLOT(mute_unmute()));
    QObject::connect(player,SIGNAL(mutedChanged(bool)),voiceButton,SLOT(changeIcon(bool)));

    QObject::connect(signinButton,SIGNAL(clicked()),&window,SLOT(initialShow()));
    QObject::connect(signoutButton,SIGNAL(clicked()),window.signinout,SLOT(changeTitle2()));

    // the pictures would overlay
//    QPalette palette;
////    QPixmap pixmap(":/background2.jpg");
//    QPixmap pixmap(":/new/prefix1/main_interface.jpg");
//    palette.setBrush(window.backgroundRole(),QBrush(pixmap));
//    window.setPalette(palette);

    // the pictures would overlay
//    QPalette PAllbackground = window.palette();
//    QImage ImgAllbackground(":/new/prefix1/main_interface.jpg");
//    QImage fitimgpic=ImgAllbackground.scaled(window.width(),window.height(), Qt::IgnoreAspectRatio);
//    PAllbackground.setBrush(QPalette::Window, QBrush(fitimgpic));
//    window.setPalette(PAllbackground);

    // strange display, with all butttons showing the picture
//    window.setStyleSheet("border-image: url(:/new/prefix1/main_interface.jpg)");
//    window.setWindowOpacity(0.5);

    window.setLayout(whole);
    window.setWindowTitle("tomeo");
    window.setMinimumSize(800, 680);
    //CHANGE -- new VICTOR ZHANG

    // showtime!
    window.show();

    // wait for the app to terminate
    return app.exec();
}
