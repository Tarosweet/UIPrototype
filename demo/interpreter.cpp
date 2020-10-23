#include "interpreter.h"
#include <QDebug>

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
Interpreter::Interpreter()
{

}

char*
Interpreter::parseLine(QStringList args)
{
    char *buf = static_cast<char *>(malloc(16));
    QString INST = args.at(0);
    qreal arg1 = args.at(1).toDouble(nullptr);
    if (INST == "fd")
    {
        qDebug() << arg1 << Qt::endl;
    }

    return buf;
}
