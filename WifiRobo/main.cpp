#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQuickItem>
#include <QQmlComponent>
#include "test.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView view;
    view.engine()->addImportPath("qrc:/qml/imports");
    view.setSource(QUrl("qrc:/qml/content/App.qml"));
    if (!view.errors().isEmpty())
        return -1;
    view.show();

    Test t;
    QObject::connect((QObject*) view.rootObject(), SIGNAL(qmlSignal(QString)), &t, SLOT(printMessage(QString)));

    QQuickItem* item = view.rootObject();

    return app.exec();
}
