#ifndef ROBOCONTROL_H
#define ROBOCONTROL_H

#include <QObject>
#include <QBluetoothAddress>
#include <QBluetoothDeviceInfo>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothSocket>

// https://www.youtube.com/watch?v=6oUTEatBoh4
// https://tecnologia5853.blogspot.com/2017/03/here-is-coding-for-android-device.html

class RoboControl : public QObject
{
    Q_OBJECT

private:
    QBluetoothDeviceDiscoveryAgent *agent;
    QBluetoothSocket *socket;
    QList<QBluetoothDeviceInfo> devices;

public:
    explicit RoboControl(QObject *parent = nullptr);
    ~RoboControl();
    void connectTo(QBluetoothAddress &address);
    void discoveredDevice(const QBluetoothDeviceInfo &device);

signals:

};

#endif // ROBOCONTROL_H
