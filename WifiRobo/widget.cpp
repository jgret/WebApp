#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

void Widget::updateImage(QImage &img)
{
}

Widget::~Widget()
{
    delete ui;
}
