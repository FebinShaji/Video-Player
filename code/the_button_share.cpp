#include "the_button_share.h"

ShareButton::ShareButton(const QString &text):QPushButton(text) {
    this->setFlat(true);
    this->setMinimumSize(40,30);
    this->setMaximumSize(40,30);
    this->setIconSize(QSize(30,30));;
    this->setIcon(QIcon(":/upload-3.svg"));
    makeConnections();
}

void ShareButton::share(){
    QWidget *share_widget = new QWidget();
    share_widget->setWindowTitle("Choose a website to share");
    QHBoxLayout *shareIconLayout = new QHBoxLayout();

    tiktok->setFlat(true);
    tiktok->setIcon(QIcon(":/tiktok.svg"));
    tiktok->setMinimumSize(100,100);
    tiktok->setIconSize(QSize(100,100));
    youtube->setFlat(true);
    youtube->setIcon(QIcon(":/youtube.svg"));
    youtube->setMinimumSize(100,100);
    youtube->setIconSize(QSize(100,100));
    shareIconLayout->addWidget(tiktok);
    shareIconLayout->addWidget(youtube);
    share_widget->setLayout(shareIconLayout);
    share_widget->show();
}

void ShareButton::openTiktok(){
    QDesktopServices::openUrl(QUrl("https://www.tiktok.com"));
}

void ShareButton::openYoutube(){
    QDesktopServices::openUrl(QUrl("https://www.youtube.com"));
}

void ShareButton::makeConnections(){
    connect(this,SIGNAL(clicked()),this,SLOT(share()));
    connect(tiktok,SIGNAL(clicked()),this,SLOT(openTiktok()));
    connect(youtube,SIGNAL(clicked()),this,SLOT(openYoutube()));
}
