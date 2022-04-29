#include "robocontrol.h"
#include <QDebug>

RoboControl::RoboControl(QObject *parent)
    : QObject{parent}
{

}

RoboControl::~RoboControl()
{

}

void RoboControl::connectTo(QBluetoothAddress &address)
{

}

void RoboControl::discoveredDevice(const QBluetoothDeviceInfo &device)
{
    qDebug() << device.name() << " [" << device.address() << "]";
    this->devices.append(device);
}


