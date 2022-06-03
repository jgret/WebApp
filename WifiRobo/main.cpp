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
/*
 * \r\n--123456789000000000000987654321\r\nContent-Type: image/jpeg\r\nContent-Length: %u\r\n\r\n
 */

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //Widget w;
    //w.show();


    /*
    ImageStream imgstream;
    QObject::connect(&imgstream, &ImageStream::imageReady, &w, &Widget::updateImage);

    imgstream.openStream("http://172.17.5.241:81/stream");
    */

    //    QString part_boudary = "";


    //    QFile stream(":/stream/test.mjpg");
    //    if (stream.open(QIODevice::ReadOnly)) {
    //        QByteArray buffer;

    //        bool end = false;
    //        int state = 0;
    //        int post_init_state = 1;
    //        int datalen = 0;
    //        while (stream.bytesAvailable() && !end) {
    //            switch (state) {

    //            // reset state machine
    //            case(0): {
    //                buffer.clear();
    //                datalen = 0;
    //                state = post_init_state;
    //                break;
    //            }

    //            // read part boundary
    //            case(1): {
    //                while (stream.bytesAvailable()) {
    //                    char c;
    //                    int ret = stream.read(&c, 1);
    //                    if (ret == 1) {
    //                        if (c == '\n' || c == '\r') {
    //                            if (buffer.size() > 2) {
    //                                part_boudary = buffer.last(buffer.size() - 2); // -2 doesn't matter, test it
    //                                qDebug() << "Part Boundary " << part_boudary;
    //                                stream.read(1);
    //                                buffer.clear();
    //                                state = 2;
    //                                post_init_state = 2;
    //                                break;
    //                            }
    //                        } else {
    //                            buffer += c; // add part to part_boundary buffer
    //                        }
    //                    }
    //                }
    //                break;
    //            }

    //            // read image header (length)
    //            case(2): {
    //                static int count;
    //                static int part;
    //                while (stream.bytesAvailable()) {
    //                    char c;
    //                    int ret = stream.read(&c, 1);
    //                    if (ret == 1) {

    //                        // skip first part
    //                        if (c == '\n' || c == '\r') {
    //                            count++;
    //                        } else {
    //                            buffer += c;
    //                        }

    //                        if (part == 0) {
    //                            if (count > 2) {
    //                                count = 0;
    //                                part++;
    //                            }
    //                        } else if (part == 1) {
    //                            if (count > 2) {
    //                                QTextStream head(&buffer);
    //                                head.read(16);
    //                                head >> datalen;
    //                                qDebug() << "Datalength: " << datalen;

    //                                buffer.clear();
    //                                state = 3;
    //                                count = 0;
    //                                part = 0;
    //                                break;
    //                            }
    //                        }
    //                    }
    //                }
    //                break;
    //            }
    //            case(3): {
    //                if (stream.bytesAvailable() >= datalen) {
    //                    //qDebug() << datalen;
    //                    buffer += stream.read(datalen);

    //                    //qDebug() << buffer;

    //                    QPixmap pixmap;
    //                    if (pixmap.loadFromData(buffer)) {
    //                        qDebug() << "image found";
    //                    }

    //                    state = 0;

    //                } else {
    //                    // only file mode
    //                    end = true;
    //                }
    //                break;
    //            }
    //            }
    //        }

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


    //    } else {
    //        qDebug() << "could not open file";
    //    }

    QString part_boudary = "";

    QByteArray buffer;
    QFile stream(":/stream/test.mjpg");
    if (stream.open(QIODevice::ReadOnly)) {

        buffer += stream.readAll();
        QString imgdata(buffer);

        QStringList parts = imgdata.split("\r\n\r\n");
        if (parts.length() > 0) {
            qDebug() << parts.length();
            for (QString s : parts) {
                int len = s.indexOf("\r");
                QStringList pparts = s.split("\r\n");
                qDebug() << "pparts.length: " << pparts.length();
                if (len > 0) {
                    QByteArray data = s.first(len).toUtf8();
                    qDebug() << "Header: " << s.last(20);
                    qDebug() << "Length: " << pparts[0].length();
                    qDebug() << "First: " << pparts[0].first(20);
                    qDebug() << "Last: " << pparts[0].last(20);
                    QPixmap p;
                    qDebug() << "Image Status: " << p.loadFromData(data);
                }
            }
        }
    }
    else {
        qDebug() << "Could not open file";
    }

    return 0;
}
