#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include "canvas.h"
#include "console.h"
#include "login.h"

#define WINDOW_HIGHT 720
#define WINDOW_WIDTH 1280

class Homepage : public QMainWindow
{
    Q_OBJECT
public:
    explicit Homepage(QWidget *parent = nullptr);
    ~Homepage() {}
private:
    Canvas *canvas;
    Console *console;
    Login *login;

signals:

public slots:
    void setCanvasBG(QString);
};
#endif // HOMEPAGE_H
