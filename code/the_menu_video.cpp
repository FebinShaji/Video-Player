#include "the_menu_video.h"

VideoMenu::VideoMenu(const QString &title):QMenu(title) {
    // Video
    sortmediaAction = new QAction("&Sort media");
    filtermediaAction = new QAction("&Filter media");
    fastforwardAction = new QAction("&Fast forward");
    slowmotionAction = new QAction("&Slow motion");


    this->addAction(sortmediaAction);
    this->addAction(filtermediaAction);
    this->addSeparator();
    this->addAction(fastforwardAction);
    this->addAction(slowmotionAction);

    fastForward1_5 = new QAction("* 1.5");
    fastForward1_75 = new QAction("* 1.75");
    fastForward2 = new QAction("* 2.0");
    slowMotion0_75 = new QAction("* 0.75");
    slowMotion0_5 = new QAction("* 0.5");
    slowMotion0_1 = new QAction("* 0.1");
    normalSpeed = new QAction("* 1.0");

    fastForwardMenu = new QMenu();
    slowMotionMenu = new QMenu();

    fastForwardMenu->addAction(fastForward1_5);
    fastForwardMenu->addAction(fastForward1_75);
    fastForwardMenu->addAction(fastForward2);
    fastForwardMenu->addAction(normalSpeed);

    slowMotionMenu->addAction(slowMotion0_75);
    slowMotionMenu->addAction(slowMotion0_5);
    slowMotionMenu->addAction(slowMotion0_1);
    slowMotionMenu->addAction(normalSpeed);

    fastforwardAction->setMenu(fastForwardMenu);
    slowmotionAction->setMenu(slowMotionMenu);

    //changed by XiujingLi
    makeConnections();
}

void VideoMenu::makeConnections(){
    connect(fastForward1_5,SIGNAL(triggered()),this,SIGNAL(fastForward_triggered1_5()));
    connect(fastForward1_75,SIGNAL(triggered()),this,SIGNAL(fastForward_triggered1_75()));
    connect(fastForward2,SIGNAL(triggered()),this,SIGNAL(fastForward_triggered2()));
    connect(slowMotion0_75,SIGNAL(triggered()),this,SIGNAL(slowMotion_triggered0_75()));
    connect(slowMotion0_5,SIGNAL(triggered()),this,SIGNAL(slowMotion_triggered0_5()));
    connect(slowMotion0_1,SIGNAL(triggered()),this,SIGNAL(slowMotion_triggered0_1()));
    connect(normalSpeed,SIGNAL(triggered()),this,SIGNAL(normalSpeed_triggered()));

}
