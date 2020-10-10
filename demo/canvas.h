#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

/*
    | 小海龟的前后、转向 | FD, BK, RT, LT  n |
    | 清屏复位 | LT |
    | 提笔、落笔 | PU, PD |
    | 坐标定位 | SETXT[x y]|
    | 设置笔的颜色 | SETPC n (n为颜色号) |
    | 设置背景的颜色 | SETBG n, n为颜色号 |
    | 画圆 | STAMPOVAL x y (x 表示横向半径，y表示纵向半径) |
    | 重复命令 | Repeat n [ ], 即[]内的命令重复n次 |
    | 移到行首、移到行尾 | Home, End |
    | 命令的编辑功能 | copy (Ctrl + C), Cut(Ctrl+X), Paste(Ctrl+V) 等 |
 */

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas() override { _lines.clear(); }

private:
    int CANVAS_WIDTH, CANVAS_HEIGHT;
    QPointF *CURR_POS;
    qreal CURR_ANGLE;

    bool PEN_IS_DOWN;
    QPen pen;

    QVector<QVector<QPointF>> _lines;
    QVector<QLineF> LINES;

public:
    void addAngle(qreal);

signals:

public slots:
    void drawLine(qreal, bool);
    void turnDirection(qreal, bool);
    void reset();
    void penDownUp(bool);
    void setXT(qreal, qreal);
    void setPC(uint);
    void stampoval(qreal, qreal);

protected:
    virtual void paintEvent(QPaintEvent *ev) override;
    virtual void mouseMoveEvent(QMouseEvent *ev) override;
    virtual void mousePressEvent(QMouseEvent *ev) override;
    virtual void mouseReleaseEvent(QMouseEvent *ev) override;

};

#endif // CANVAS_H
