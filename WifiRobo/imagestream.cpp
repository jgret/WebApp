#include "imagestream.h"
#include <QDebug>

ImageStream::ImageStream(QObject *parent)
    : QObject{parent}
{
    this->manager = new QNetworkAccessManager(parent);
    this->stream = nullptr;
    this->buffer = new QByteArray();

}

ImageStream::~ImageStream()
{
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
    QByteArray data = stream->readAll();
    this->buffer->append(data);
    qDebug() << data;

    if (this->buffer->contains("abc")) {
        /*
         *  QImage* img = new QImage(buffer);
         *  buffer->split()
         *  emit this->imageReady(img);
         */
    }

}

