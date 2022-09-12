#include "the_menu_file.h"

FileMenu::FileMenu(const QString &title):QMenu(title) {

    openfileAction = new QAction("&Open file ");
    openfolderAction = new QAction("&Open folder ");
    closeallAction = new QAction("&Close");
    saveAction = new QAction("&Save ");
    saveasAction = new QAction("&Save as ");
    exportAction = new QAction("&Export media");
    shareAction = new QAction("&Share");
    exitAction = new QAction("&Exit ");
    quitAction = new QAction("&Quit Tomeo");

    this->addAction(openfileAction);
    this->addAction(openfolderAction);
    this->addSeparator();
    this->addAction(closeallAction);
    this->addSeparator();
    this->addAction(saveAction);
    this->addAction(saveasAction);
    this->addSeparator();
    this->addAction(exportAction);
    this->addAction(shareAction);
    this->addSeparator();
    this->addAction(exitAction);
    this->addAction(quitAction);

    makeConnections();
}

void FileMenu::makeConnections(){
    connect(openfileAction,SIGNAL(triggered()),this,SIGNAL(openFile_triggered()));
    connect(saveAction,SIGNAL(triggered()),this,SIGNAL(save_triggered()));
    connect(saveasAction,SIGNAL(triggered()),this,SIGNAL(save_triggered()));
    connect(exportAction,SIGNAL(triggered()),this,SIGNAL(save_triggered()));
    connect(shareAction,SIGNAL(triggered()),this,SIGNAL(share_triggered()));
    connect(closeallAction,SIGNAL(triggered()),this,SIGNAL(close_triggered()));
}
