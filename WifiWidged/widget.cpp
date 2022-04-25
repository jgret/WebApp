#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>
Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    img.load(":/images/cpp_is_awesome.jpg");
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter g(this->ui->openGLWidget);
    g.drawImage(this->ui->openGLWidget->rect(), img.toImage());
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << event->key();
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    qDebug() << event->key();
}

Widget::~Widget()
{
    delete ui;
}

