#include "widget.h"

#include <QApplication>
#include <QBuffer>
#include <QImage>
#include <QMediaPlayer>

#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QDebug>
#include "imagestream.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Widget w;
    w.show();

    ImageStream imgstream;
    int ret = imgstream.openStream("http://192.168.0.53:81/stream");
    if (ret != 0) {
        qDebug() << "failed to start stream: " << ret;
    }

    return a.exec();
}
