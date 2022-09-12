#ifndef INITIAL_WINDOW_H
#define INITIAL_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QLayout>

class initial_window : public QWidget
{
    Q_OBJECT
public:
    QPushButton* submitButton;
    QPushButton* closeButton;
    QPushButton* registerButton;
    QLabel *username;
    QLabel *password;
    QLabel *signTitle;
    QLineEdit *nameField;
    QLineEdit *passwordField;
    QPushButton* registerButton2;
    QLabel *username2;
    QLabel *password2;
    QLabel *signTitle2;
    QLineEdit *nameField2;
    QLineEdit *passwordField2;

    void makeConnections();

private slots:
    void setUI();
    void initialSignal();
    void on_Login();
    void registerWindow();

signals:
    void close_clicked();

public:
    initial_window();
};

#endif // INITIAL_WINDOW_H
