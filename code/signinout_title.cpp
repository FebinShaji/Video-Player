#include "signinout_title.h"

SignInOutTitle::SignInOutTitle(const QString &text) : QPushButton(text)
{
    this->setFlat(true);
    this->setText("Not Sign In");
    this->setFont(QFont("Times", 12, QFont::Bold));
    this->setStyleSheet("color:red");
    makeConnection();
}

void SignInOutTitle::makeConnection() {
    connect(this,SIGNAL(clicked()), this, SIGNAL(signin_pushed()));
}

void SignInOutTitle::changeTitle() {
    this->setText("Welcome User: Leedsuser");
    this->setFont(QFont("Times", 12, QFont::Bold));
    this->setStyleSheet("color:green");
}

void SignInOutTitle::makeConnection2() {
    connect(this,SIGNAL(clicked()), this, SIGNAL(signout_pushed()));
}

void SignInOutTitle::changeTitle2() {
    this->setText("Not Sign In");
    this->setFont(QFont("Times", 12, QFont::Bold));
    this->setStyleSheet("color:red");
}
