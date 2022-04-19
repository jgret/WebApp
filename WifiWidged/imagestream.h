#ifndef IMAGESTREAM_H
#define IMAGESTREAM_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class ImageStream : public QObject
{
    Q_OBJECT

private:
    QNetworkAccessManager *manager;
    QNetworkReply* stream;
    QByteArray* buffer;

public:
    explicit ImageStream(QObject *parent = nullptr);
    ~ImageStream();
    int openStream(QString ip);

private slots:
    void dataReady();

signals:
    void imageReady(QImage* img);
};

#endif // IMAGESTREAM_H
