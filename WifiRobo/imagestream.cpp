#include "imagestream.h"
#include <QDebug>
#include <QPixmap>

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
    this->buffer->append(stream->readAll());

    QString data(*this->buffer);

    bool found = data.contains(this->part_boundary);

    if(!found) //I am still reading the same image
    {
        imageData = imageData.append(data);

    } else // I have finished reading the image and another image is received
    {

        QImage image;
        //remove the headers
        QStringList l2= imageData.split("\n\r");

        if(l2.size()>1)
        {
            imageData= l2[1];
            QByteArray arrd= l2[1].toUtf8();
            if (image.loadFromData(arrd))
            {
                // QPixmap pixmap = QPixmap::fromImage(image);
                emit imageReady(&image);
            }

            imageData.clear();
            imageData.append(data);
        }

    }

}
