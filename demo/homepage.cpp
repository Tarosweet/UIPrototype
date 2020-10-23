#include "homepage.h"
#include <QApplication>
#include <QDebug>

Homepage::Homepage(QWidget *parent) : QMainWindow(parent)
{
    this->resize(WINDOW_WIDTH, WINDOW_HIGHT);
    this->setWindowTitle("My PC Logo");

    QFont font;
    font.setFamily("concolas");
    font.setBold(true);
    font.setPixelSize(20);
    this->setFont(font);


    canvas = new Canvas(this);
//    canvas->setGeometry(0, 0, (WINDOW_WIDTH * 3) /4, (WINDOW_HIGHT * 3) / 4);
    canvas->setGeometry(0, 0, WINDOW_WIDTH, (WINDOW_HIGHT * 3) / 4);
    canvas->setStyleSheet(QString::fromUtf8("border: 2px solid darkgray;"));

    console = new Console(this);
    console->setGeometry(0, (WINDOW_HIGHT * 3) / 4, WINDOW_WIDTH, WINDOW_HIGHT / 4);
    console->setStyleSheet(QString::fromUtf8("border: 2px solid gray;"));
    console->write("Welcome to the PC Logo!\nPlease type your code.\n");

    /*login = new Login(this);
    login->setGeometry((WINDOW_WIDTH * 3) /4, 0, WINDOW_WIDTH /4, (WINDOW_HIGHT * 3) /4);
    login->setStyleSheet(QString::fromUtf8("border: 2px solid gray;"));// background-image: qrc:/img/login.png"));*/


//    connect(console, SIGNAL(newLineWriten(QStringList)), canvas, SLOT(draw(qreal, qreal)));
    connect(console, SIGNAL(drawLine(qreal, bool)), canvas, SLOT(drawLine(qreal, bool)));
    connect(console, SIGNAL(turnDirection(qreal, bool)), canvas, SLOT(turnDirection(qreal, bool)));
    connect(console, SIGNAL(penDownUp(bool)), canvas, SLOT(penDownUp(bool)));
    connect(console, SIGNAL(setXT(qreal, qreal)), canvas, SLOT(setXT(qreal, qreal)));
    connect(console, SIGNAL(setPC(uint)), canvas, SLOT(setPC(uint)));
    connect(console, SIGNAL(setBG(QString)), this, SLOT(setCanvasBG(QString)));
    connect(console, SIGNAL(stampoval(qreal, qreal)), canvas, SLOT(stampoval(qreal, qreal)));
}

// SLOT
void
Homepage::setCanvasBG(QString color)
{
    QString qss = "border: 2px solid darkgray; background-color: ";
    qss.append(color);
    canvas->setStyleSheet(qss);
}
