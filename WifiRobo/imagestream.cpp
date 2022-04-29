#include "imagestream.h"
#include <QDebug>
#include <QPixmap>
#include <QFile>

ImageStream::ImageStream(QObject *parent)
    : QObject{parent}
{
    this->manager = new QNetworkAccessManager(parent);
    this->stream = nullptr;
    this->buffer = new QByteArray();
    this->part_boundary = "123456789000000000000987654321";
}

ImageStream::~ImageStream()
{
    /*
    QFile fout("test1.mjpg");
    qDebug() << this->buffer->size();
    if(fout.open(QIODevice::WriteOnly)) {
        qDebug() << "file test.mjpg open";
        QTextStream out(&fout);
        out << *this->buffer;
    } else {
        qDebug() << "ERROR: file not open";
    }
    fout.close();
    qDebug() << "file written";
    */

    this->stream->close();
    delete this->manager;
    delete this->stream;
    delete this->buffer;
}

int ImageStream::openStream(QString ip)
{
    this->stream = manager->get(QNetworkRequest(QUrl(ip)));
    int ret = this->stream->error();
    if (ret == 0) {
        connect(stream, &QNetworkReply::readyRead, this, &ImageStream::dataReady);
    }
    return ret;
}

void ImageStream::dataReady()
{
    QByteArray newdata = stream->readAll();
    this->buffer->append(newdata);
    QString data(*this->buffer);

    this->buffer->remove(0, 1000);

    int found = data.count(this->part_boundary);

    //remove the headers
    QStringList l2= data.split("\n\r");

    //qDebug() << "\nNEW IMAGE:";

    if (l2[l2.size()-1].size() > 1000) {
        QImage img;
        img.loadFromData(l2[l2.size()-1].toUtf8());
        emit imageReady(&img);
    }

    /*
    imageData= l2[1];
    QByteArray arrd= l2[1].toUtf8();
    if (image.loadFromData(arrd))
    {
        // QPixmap pixmap = QPixmap::fromImage(image);
        emit imageReady(&image);
    }

    imageData.clear();
    imageData.append(data);
    */

}
