#ifndef DISHESSHOWNEW_H
#define DISHESSHOWNEW_H

#include <QWidget>
#include "dishes.h"

namespace Ui {
class dishesshownew;
}

class dishesshownew : public QWidget
{
    Q_OBJECT

public:
    explicit dishesshownew(QWidget *parent = nullptr);
    ~dishesshownew();

signals:
    void back();

private slots:
    void on_back_clicked();

private:
    Ui::dishesshownew *ui;
};

#endif // DISHESSHOWNEW_H
