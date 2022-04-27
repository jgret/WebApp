#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QPixmap>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::Widget *ui;
    QPixmap img;
};
#endif // WIDGET_H
