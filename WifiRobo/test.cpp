#include "test.h"
#include <QDebug>

Test::Test()
{

}

void Test::printMessage(QString msg) {
    qDebug() << msg;
}
