#include "widget.h"

#include <QApplication>
#include <QBuffer>
#include <QImage>
#include <QMediaPlayer>

#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QFile>

#include <QDebug>
#include "imagestream.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Widget w;
    w.show();


    /*
    ImageStream imgstream;
    QObject::connect(&imgstream, &ImageStream::imageReady, &w, &Widget::updateImage);

    imgstream.openStream("http://172.17.5.241:81/stream");
    */

    QString part_boudary = "";


    QFile stream(":/stream/test.mjpg");
    if (stream.open(QIODevice::ReadOnly)) {
        QByteArray buffer;

        int state = 0;
        int datalen = 0;
        while (stream.bytesAvailable()) {

            switch (state) {
            case(0): {
                buffer.clear();
                datalen = 0;
                state = 1;
            }
            case(1): {
                while (stream.bytesAvailable()) {
                    char c;
                    int ret = stream.read(&c, 1);
                    if (ret == 1) {
                        if (c == '\n' || c == '\r') {
                            if (buffer.size() > 2) {
                                part_boudary = buffer.last(buffer.size() - 2); // -2 doesn't matter, test it
                                buffer.clear();
                                state = 2;
                                break;
                            }
                        } else {
                            buffer += c;
                        }
                    }
                }
                break;
            }
            case(2): {
                static int count;
                static int part;
                while (stream.bytesAvailable()) {
                    char c;
                    int ret = stream.read(&c, 1);
                    if (ret == 1) {
                        if (c == '\n' || c == '\r') {
                            count++;
                        } else {
                            buffer += c;
                        }

                        if (part == 0) {
                            if (count > 2) {
                                buffer.clear();
                                count = 0;
                                part++;
                            }
                        } else if (part == 1) {
                            if (count > 2) {
                                QTextStream head(&buffer);
                                head.read(16);
                                head >> datalen;

                                buffer.clear();
                                state = 3;
                                count = 0;
                                part = 0;
                            }
                        }
                    }
                }
                break;
            }
            case(3): {
                if (stream.bytesAvailable() >= datalen) {
                    buffer += stream.read(datalen);

                    QPixmap pixmap;
                    pixmap.loadFromData(buffer);
                    qDebug() << "image found";

                    state = 0;
                }
                break;
            }
            }
        }

        /*
        QString str_img(buffer);
        QStringList parts = str_img.split("\r\n\r\n");
        //qDebug() << str_img.count("\r\n\r\n");
        int tbytes = 10;
        for (int i = 0; i < parts.length(); i++) {
            if (parts[i].size() < tbytes) {
                qDebug() << i << ": " << parts[i];
            } else {
                qDebug() << i << ": " << parts[i].first(tbytes);
                qDebug() << "   > " << parts[i].last(tbytes + 50);
            }
        }
        */


    } else {
        qDebug() << "could not open file";
    }
    return a.exec();
}
