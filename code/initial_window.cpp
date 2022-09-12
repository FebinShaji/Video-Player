// ADD by Victor Zhang
// 2021/21/2

#include "initial_window.h"

initial_window::initial_window()
{
    setUI();
    initialSignal();
    setWindowTitle("Submit Interface");
}

void initial_window::setUI()
{
    QLabel *space = new QLabel("");
    signTitle = new QLabel("  Login In Page");
    signTitle->setFont(QFont("Times", 15, QFont::Bold));

    username = new QLabel("User Name:");
    username->setFont(QFont("Times", 12, QFont::Bold));
    nameField = new QLineEdit;
    nameField->setMinimumHeight(14);
    QHBoxLayout *input_name = new QHBoxLayout;
    input_name->addWidget(username);
    input_name->addWidget(nameField);

    password = new QLabel("Password: ");
    password->setFont(QFont("Times", 12, QFont::Bold));
    passwordField = new QLineEdit;
    passwordField->setMinimumHeight(14);
    QHBoxLayout *input_password = new QHBoxLayout;
    input_password->addWidget(password);
    input_password->addWidget(passwordField);

    submitButton = new QPushButton("submit");
    closeButton = new QPushButton("close");
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(submitButton);
    buttonLayout->addWidget(space);
    buttonLayout->addWidget(space);
    buttonLayout->addWidget(space);
    buttonLayout->addWidget(closeButton);

    registerButton = new QPushButton("register");

    QVBoxLayout *signinLayout = new QVBoxLayout;
    signinLayout->addWidget(signTitle);
    signinLayout->addWidget(space);
    signinLayout->addLayout(input_name);
    signinLayout->addWidget(space);
    signinLayout->addLayout(input_password);
    signinLayout->addWidget(space);
    signinLayout->addLayout(buttonLayout);
    signinLayout->addWidget(space);
    signinLayout->addWidget(registerButton);
    setLayout(signinLayout);
}

void initial_window::initialSignal()
{
    connect(submitButton,SIGNAL(clicked()),this,SLOT(on_Login()));
    makeConnections();
}

void initial_window::on_Login()
{
    static int cout = 0;
    QString user = nameField->text();
    QString pass = passwordField->text();
    QString p="";
    int lenth = pass.count();
    for(int i = 0; i < lenth; i++){
        p.append("*");
    }
    passwordField->setText(p);

    if(user == "Leedsuser" && pass == "123456") {
        signTitle->setStyleSheet("color:green");
        p="  Login Successful";
        connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
    }
    else {
        signTitle->setStyleSheet("color:red;");
        p="  Login Failed";
        cout++;
    }

    if(cout >= 4) {
        signTitle->setStyleSheet("color:red;");
        p = "Too many failed operations!  Login is prohibited";
        disconnect(submitButton,SIGNAL(clicked),this,SLOT(on_Login()));
    }
    int len = user.count();
    if(len == 0 || lenth == 0) {
        signTitle->setStyleSheet("color:red;");
        p="  Nothing Entered";
        cout--;
    }
    signTitle->setText(p);
}

void initial_window::registerWindow() {
    QWidget *registerWindow = new QWidget();
    QLabel *space = new QLabel("");
    signTitle = new QLabel("  Register Page");
    signTitle->setFont(QFont("Times", 15, QFont::Bold));

    username2 = new QLabel("User Name:");
    username2->setFont(QFont("Times", 12, QFont::Bold));
    nameField2 = new QLineEdit;
    nameField2->setMinimumHeight(14);
    QHBoxLayout *input_name = new QHBoxLayout;
    input_name->addWidget(username2);
    input_name->addWidget(nameField2);

    password2 = new QLabel("Password: ");
    password2->setFont(QFont("Times", 12, QFont::Bold));
    passwordField2 = new QLineEdit;
    nameField2->setMinimumHeight(14);
    QHBoxLayout *input_password = new QHBoxLayout;
    input_password->addWidget(password2);
    input_password->addWidget(passwordField2);

    registerButton2 = new QPushButton("register");
    QVBoxLayout *registerLayout = new QVBoxLayout;
    registerLayout->addWidget(signTitle);
    registerLayout->addWidget(space);
    registerLayout->addLayout(input_name);
    registerLayout->addWidget(space);
    registerLayout->addLayout(input_password);
    registerLayout->addWidget(space);
    registerLayout->addWidget(registerButton2);
    registerWindow->setLayout(registerLayout);
    registerWindow->show();
}

void initial_window::makeConnections(){
    connect(closeButton,SIGNAL(clicked()),this,SIGNAL(close_clicked()));
    connect(registerButton,SIGNAL(clicked()),this,SLOT(registerWindow()));
}
