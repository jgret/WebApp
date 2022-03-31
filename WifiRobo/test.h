#ifndef TEST_H
#define TEST_H

#include <QObject>

class Test : public QObject
{
    Q_OBJECT

public slots:
    void printMessage(QString msg);

public:
    Test();
};

#endif // TEST_H
