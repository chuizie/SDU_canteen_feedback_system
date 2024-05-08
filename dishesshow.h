#ifndef DISHESSHOW_H
#define DISHESSHOW_H

#include <QWidget>
#include <vector>
#include <string>
#include "dishes.h"


namespace Ui {
class dishesshow;
}

class dishesshow : public QWidget
{
    Q_OBJECT

public:
    explicit dishesshow(QWidget *parent = nullptr);
    ~dishesshow();

signals:
    void back();

private slots:
    void on_back_clicked();

    void on_pushButton_clicked();

private:
    Ui::dishesshow *ui;
};

#endif // DISHESSHOW_H
