#ifndef SIGNINOUT_TITLE_H
#define SIGNINOUT_TITLE_H

#include <QLabel>
#include <QPushButton>

class SignInOutTitle : public QPushButton
{
    Q_OBJECT
public:
    SignInOutTitle(const QString &text);
    void makeConnection();
    void makeConnection2();

signals:
    void signin_pushed();
    void signout_pushed();

public slots:
    void changeTitle();
    void changeTitle2();
};

#endif // SIGNINOUT_TITLE_H

