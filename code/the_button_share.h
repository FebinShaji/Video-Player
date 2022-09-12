#ifndef THE_BUTTON_SHARE_H
#define THE_BUTTON_SHARE_H

#include <QPushButton>
#include <QWidget>
#include <QLayout>
#include <QDesktopServices>
#include <QUrl>

class ShareButton : public QPushButton {
    Q_OBJECT
private:
    QPushButton *tiktok = new QPushButton();
    QPushButton *youtube = new QPushButton();
public:
    ShareButton(const QString &text);
    void makeConnections();
public slots:
    void share();

private slots:
    void openTiktok();
    void openYoutube();
};

#endif // THE_BUTTON_SHARE_H
