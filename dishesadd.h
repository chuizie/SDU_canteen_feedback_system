#ifndef DISHESADD_H
#define DISHESADD_H

#include <QWidget>
#include <QMessageBox>
#include <string>

#include "dishes.h"

namespace Ui {
class dishesadd;
}

class dishesadd : public QWidget
{
    Q_OBJECT

public:
    explicit dishesadd(QWidget *parent = nullptr);
    ~dishesadd();

signals:
    void back();

private slots:
    void on_back_clicked();

    void on_add_clicked();

private:
    Ui::dishesadd *ui;
};

#endif // DISHESADD_H
