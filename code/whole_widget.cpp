#include "whole_widget.h"


whole_widget::whole_widget()
{
    makeConnections();
    // if like to make the widget transparent, use this code
    // setWindowOpacity(0.5);
//    QPalette palettechao=this->palette();
//    palettechao.setColor()
}

void whole_widget::initialShow() {
//    QPalette pal = palette();
//    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
//    setPalette(pal);
    initialWidget->resize(400, 200);
    initialWidget->show();
}

void whole_widget::fullwindowShow() {

    fullscreenWidget->setUI();
    fullscreenWidget->resize(800, 680);
    fullscreenWidget->show();
}

void whole_widget::setPlayer(){
    player->setVideoOutput(videoWidget);
}

void whole_widget::makeConnections(){
    connect(fullscreenWidget,SIGNAL(quitPushed()),this,SLOT(setPlayer()));
     connect(initialWidget,SIGNAL(close_clicked()),signinout,SLOT(changeTitle()));
}

void whole_widget::openFile(){
    QUrl fileUrl;

    fileUrl = QFileDialog::getOpenFileUrl(this,
                                            tr("Open File"), QUrl("/Users/macbookpro/Desktop/Tomeo project"), tr("all (*.png *.jpg *.jpeg *.wmv *.MOV *.mp4)"));
    if (!fileUrl.isEmpty()){
    //fileUrl即是选择的文件路径
    }
    else{
    //点是的取消
    }
}

void whole_widget::save(){
    QUrl fileUrl;

    fileUrl = QFileDialog::getSaveFileUrl(this,
                                            tr("Save File"), QUrl("/Users/macbookpro/Desktop/Tomeo project"), tr("all (*.png *.jpg *.jpeg *.wmv *.MOV *.mp4)"));

    if (!fileUrl.isEmpty()){
    //fileUrl是文件路径
    }
    else{
    //点的是取消
    }
}

// Edited by Shruti Naik
void whole_widget::minimumWindowShow() {
    minimumScreenWidget->setUI();
    minimumScreenWidget->resize(500, 320);
    minimumScreenWidget->show();
}

void whole_widget::closeAll(){
    close();
}

// edited by chaodao
void whole_widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
//    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/new/prefix1/main_interface.jpg"));
    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":background4.jpeg"));
}
