#ifndef TCPIMAGEREADER_H
#define TCPIMAGEREADER_H

#include <QObject>
#include <QTcpSocket>

class TCPImageReader : public QObject
{
    Q_OBJECT

private:
    QTcpSocket *socket;
public:
    explicit TCPImageReader(QObject *parent = nullptr);
    TCPImageReader(QObject *parent, QString ip, int port);

signals:

};

#endif // TCPIMAGEREADER_H
