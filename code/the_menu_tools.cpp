#include "the_menu_tools.h"
#include "whole_widget.h"
#include "QApplication"
#include "QDialog"
#include "QTextEdit"
#include "QVBoxLayout"

/* Edited by: Shruti Naik */

ToolsMenu::ToolsMenu(const QString &title):QMenu(title) {

    // Tools
    metadataAction = new QAction("&Meta data");
    viewAction = new QAction("&View");
    subtitlesAction = new QAction("&Subtitles");

    this->addAction(metadataAction);
    this->addSeparator();

    metadataAction->connect(metadataAction, &QAction::triggered, this, &ToolsMenu::metaData);

    // View
    this->addAction(viewAction);
    fullscreenAction = new QAction("&Full screen");
    minimizeAction = new QAction("&Minimize");

    viewMenu->addAction(fullscreenAction);
    viewMenu->addAction(minimizeAction);

    viewAction->setMenu(viewMenu);
    this->addMenu(viewMenu);

    this->addSeparator();

    // Subtitles
    this->addAction(subtitlesAction);
    uploadtranscriptAction = new QAction("&Upload transcript");
    edittranscriptAction = new QAction("&Edit transcript");
    hideshowAction = new QAction("&Hide/Show subtitles");

    subtitlesMenu->addAction(uploadtranscriptAction);
    subtitlesMenu->addAction(edittranscriptAction);
    subtitlesMenu->addAction(hideshowAction);

    subtitlesAction->setMenu(subtitlesMenu);
    this->addMenu(subtitlesMenu);

    makeConnections();
}

void ToolsMenu::metaData() {
    QDialog *msgBox = new QDialog();
    QTextEdit *text = new QTextEdit();
    QVBoxLayout *layout = new QVBoxLayout();
    text->setText("g.wmv\n"
                "File size: 7.8 MB\n"
                "File type: WMV\n"
                "File Length: 8209157\n"
                "Codec Name: msmpeg4v3\n"
                "Duration: 19.16s\n"
                "Min Packet Size: 3200\n"
                "Max Packet Size: 3200\n"
                "Max Bitrate: 4.18 Mbps\n"
                "Image Width: 1920\n"
                "Image Height: 1080\n"
                "Audio Channels: 2\n"
                "Megapixels: 2.1\n\n"
                "f.wmv\n"
                "File size: 5.4 MB\n"
                "File type: WMV\n"
                "File Length: 5665492\n"
                "Codec Name: msmpeg4v3\n"
                "Duration: 12.68s\n"
                "Min Packet Size: 3200\n"
                "Max Packet Size: 3200\n"
                "Max Bitrate: 4.18 Mbps\n"
                "Image Width: 1920\n"
                "Image Height: 1080\n"
                "Audio Channels: 2\n"
                "Megapixels: 2.1\n\n"
                "e.wmv\n"
                "File size: 4.9 MB\n"
                "File type: WMV\n"
                "File Length: 5156554\n"
                "Codec Name: msmpeg4v3\n"
                "Duration: 11.41s\n"
                "Min Packet Size: 3200\n"
                "Max Packet Size: 3200\n"
                "Max Bitrate: 4.18 Mbps\n"
                "Image Width: 1920\n"
                "Image Height: 1080\n"
                "Audio Channels: 2\n"
                "Megapixels: 2.1\n\n"
                "d.wmv\n"
                "File size: 4.8 MB\n"
                "File type: WMV\n"
                "File Length: 4996564\n"
                "Codec Name: msmpeg4v3\n"
                "Duration: 12.39s\n"
                "Min Packet Size: 3200\n"
                "Max Packet Size: 3200\n"
                "Max Bitrate: 4.18 Mbps\n"
                "Image Width: 1920\n"
                "Image Height: 1080\n"
                "Audio Channels: 2\n"
                "Megapixels: 2.1\n\n"
                "c.wmv\n"
                "File size: 3.1MB\n"
                "File type: WMV\n"
                "File Length: 3242906\n"
                "Codec Name: msmpeg4v3\n"
                "Duration: 14.22s\n"
                "Min Packet Size: 3200\n"
                "Max Packet Size: 3200\n"
                "Max Bitrate: 2.18 Mbps\n"
                "Image Width: 1920\n"
                "Image Height: 1080\n"
                "Audio Channels: 2\n"
                "Megapixels: 2.1\n\n"
                "b.wmv\n"
                "File size: 4.8 MB\n"
                "File type: WMV\n"
                "File Length: 5025330\n"
                "Codec Name: msmpeg4v3\n"
                "Duration: 18.19s\n"
                "Min Packet Size: 3200\n"
                "Max Packet Size: 3200\n"
                "Max Bitrate: 2.18 Mbps\n"
                "Image Width: 1920\n"
                "Image Height: 1080\n"
                "Audio Channels: 2\n"
                "Megapixels: 2.1\n\n"
                "a.wmv\n"
                "File size: 20 MB\n"
                "File type: WMV\n"
                "File Length: 21348548\n"
                "Codec Name: msmpeg4v3\n"
                "Duration: 21.89s\n"
                "Min Packet Size: 3200\n"
                "Max Packet Size: 3200\n"
                "Max Bitrate: 4.18 Mbps\n"
                "Image Width: 1920\n"
                "Image Height: 1080\n"
                "Audio Channels: 2\n"
                "Megapixels: 2.1\n\n"
                "a.mov\n"
                "File size: 30 MB\n"
                "File type: MOV\n"
                "File Length: 21348548\n"
                "Codec Name: h264\n"
                "Duration: 18.75s\n"
                "Min Packet Size: 3200\n"
                "Max Packet Size: 3200\n"
                "Max Bitrate: 13.5 Mbps\n"
                "Image Width: 1920\n"
                "Image Height: 1080\n"
                "Audio Channels: 2\n"
                "Megapixels: 2.1\n\n"
                "b.mov\n"
                "File size: 20 MB\n"
                "File type: MOV\n"
                "File Length: 21314634\n"
                "Codec Name: h242\n"
                "Duration: 15.05s\n"
                "Min Packet Size: 3200\n"
                "Max Packet Size: 3200\n"
                "Max Bitrate: 29.97 Mbps\n"
                "Image Width: 1920\n"
                "Image Height: 1080\n"
                "Audio Channels: 2\n"
                "Megapixels: 2.1\n\n"
                "c.mov\n"
                "File size: 13 MB\n"
                "File type: MOV \n"
                "File Length: 13929414\n"
                "Codec Name: h983 \n"
                "Duration: 11.08s \n"
                "Min Packet Size: 3200 \n"
                "Max Packet Size: 3200 \n"
                "Max Bitrate: 10.19 Mbps \n"
                "Image Width: 1920 \n"
                "Image Height: 1080 \n"
                "Audio Channels: 2 \n"
                "Megapixels: 2.1 \n\n"
                "d.mp4 \n"
                "File size: 6 MB \n"
                "File type: MP4 \n"
                "File Length: 6280364 \n"
                "Codec Name: h264 \n"
                "Duration: 9.26s \n"
                "Min Packet Size: 3200 \n"
                "Max Packet Size: 3200 \n"
                "Max Bitrate: 5.42 Mbps \n"
                "Image Width: 1920 \n"
                "Image Height: 1080 \n"
                "Audio Channels: 2 \n"
                "Megapixels: 2.1 \n\n"
                "e.mp4  \n"
                "File size: 18 MB  \n"
                "File type: MP4  \n"
                "File Length: 18397926 \n"
                "Codec Name: h264  \n"
                "Duration: 8.26 s  \n"
                "Min Packet Size: 3200  \n"
                "Max Packet Size: 3200  \n"
                "Max Bitrate: 17.8 Mbps  \n"
                "Image Width: 1920  \n"
                "Image Height: 1080  \n"
                "Audio Channels: 2  \n"
                "Megapixels: 2.1 \n\n"
                "f.mp4  \n"
                "File size: 20 MB  \n"
                "File type: MP4  \n"
                "File Length: 21006832\n"
                "Codec Name: h264  \n"
                "Duration: 9.56 s  \n"
                "Min Packet Size: 3200  \n"
                "Max Packet Size: 3200  \n"
                "Max Bitrate: 17.6 Mbps  \n"
                "Image Width: 1920  \n"
                "Image Height: 1080  \n"
                "Audio Channels: 2  \n"
                "Megapixels: 2.1 \n" );
    text->setReadOnly(true);
    layout->addWidget(text);
    msgBox->setWindowTitle("Meta Data");
    msgBox->resize(500,350);
    msgBox->setLayout(layout);
    msgBox->exec();
}

void ToolsMenu::makeConnections() {
    connect(fullscreenAction,SIGNAL(triggered()),this,SIGNAL(fullScreen_triggered()));
    connect(minimizeAction, SIGNAL(triggered()), this, SIGNAL(minimizeScreen_triggered()));
}
