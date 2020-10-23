#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QPaintEvent>

class Login : public QWidget
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);
    ~Login() override {}

protected:
    virtual void paintEvent(QPaintEvent *) override;
};

#endif // LOGIN_H
