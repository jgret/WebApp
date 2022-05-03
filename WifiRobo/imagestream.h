#ifndef IMAGESTREAM_H
#define IMAGESTREAM_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTextStream>

class ImageStream : public QObject
{
    Q_OBJECT

private:
    QNetworkAccessManager *manager;
    QNetworkReply* stream;
    QByteArray* buffer;
    QString imageData;
    QString part_boundary;

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
