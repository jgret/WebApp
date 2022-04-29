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
    this->img = new QPixmap();
    img->load(":/images/cpp_is_awesome.jpg");
    this->show();
    updateImage(img);
}

void Widget::paintEvent(QPaintEvent *event) {
    // QPainter g(this->ui->openGLWidget);
    // g.drawImage(this->ui->openGLWidget->rect(), *this->img);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << event->key();
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    qDebug() << event->key();
}

void Widget::updateImage(QPixmap *img)
{
    QPainter g(this->ui->openGLWidget);
    g.drawPixmap(this->ui->openGLWidget->rect(), *this->img);
}

Widget::~Widget()
{
    delete ui;
}

