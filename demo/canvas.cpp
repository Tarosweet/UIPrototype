#include "canvas.h"
#include <QApplication>
#include <QStyleOption>
#include <QDebug>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    CANVAS_WIDTH = (parent->width() * 3) / 4;
    CANVAS_HEIGHT = (parent->height() * 3) / 4;
    CURR_POS = new QPointF(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2);
    CURR_ANGLE = 90;
    PEN_IS_DOWN = true;
}

// public
void
Canvas::addAngle(qreal delta)
{
    CURR_ANGLE += delta;

    if (CURR_ANGLE >= 360)
        CURR_ANGLE -= 360;
    else if (CURR_ANGLE < 0)
        CURR_ANGLE += 360;
}

void
Canvas::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    p.setPen(pen);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

//    for (QVector<QPointF> line : _lines)
//    {
//        p.drawLine(line.at(0), line.at(line.size() - 1));
//        for(int j = 0; j < line.size() - 1; j++)
//            p.drawLine(line.at(j), line.at(j+1));
//    }

    for (QLineF line : LINES)
    {
        p.drawLine(line);
    }
}

void
Canvas::mousePressEvent(QMouseEvent *ev)
{
    QVector<QPointF> line;
    _lines.append(line);

    QVector<QPointF> &lastline = _lines.last();
    lastline.append(ev->pos());
}

void
Canvas::mouseMoveEvent(QMouseEvent *ev)
{
    if (_lines.size() == 0)
    {
        QVector<QPointF> line;
        _lines.append(line);
    }


    QVector<QPointF> &lastline = _lines.last();
    lastline.append(ev->pos());

    update();
}

void
Canvas::mouseReleaseEvent(QMouseEvent *ev)
{
    QVector<QPointF> &lastline = _lines.last();
    lastline.append(ev->pos());
}

// SLOT
void
Canvas::drawLine(qreal rlen, bool flag)
{
    const QPointF aP1(CURR_POS->rx(), CURR_POS->ry());

    QLineF line;
    line.setP1(aP1);
    if (flag == false)
        addAngle(180);

    line.setAngle(CURR_ANGLE);
    line.setLength(rlen);

    if (PEN_IS_DOWN)
        LINES.append(line);

    CURR_POS->setX(line.pointAt(1).x());
    CURR_POS->setY(line.pointAt(1).y());
    update();
}

void
Canvas::turnDirection(qreal delta, bool flag)
{
    if (flag)
        addAngle(delta * (-1));
    else
        addAngle(delta);
}

void
Canvas::reset()
{
    LINES.clear();
    _lines.clear();

    CURR_POS->setX(CANVAS_WIDTH/2);
    CURR_POS->setY(CANVAS_HEIGHT/2);

    update();
}

void
Canvas::penDownUp(bool flag)
{
    PEN_IS_DOWN = flag;
}

void
Canvas::setXT(qreal rx, qreal ry)
{
    CURR_POS->setX(rx);
    CURR_POS->setY(ry);
}

void
Canvas::setPC(uint color)
{
    pen.setColor(color);
    update();
}


void
Canvas::stampoval(qreal rx, qreal ry)
{
    qDebug() << rx << ' ' << ry << Qt::endl;
}



