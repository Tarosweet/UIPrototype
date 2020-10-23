#include "login.h"
#include <QStyleOption>
#include <QPainter>

Login::Login(QWidget *parent) : QWidget(parent)
{
//    this->setStyleSheet(QString::fromUtf8("background-image: url(qrc:/img/login.png) ;border: 2px solid gray"));
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/img/login.png")));
    this->setPalette(palette);
}

void
Login::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
