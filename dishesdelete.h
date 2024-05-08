#ifndef DISHESDELETE_H
#define DISHESDELETE_H

#include <QWidget>
#include <QMessageBox>
#include <string>
#include "dishes.h"

namespace Ui {
class dishesdelete;
}

class dishesdelete : public QWidget
{
    Q_OBJECT

public:
    explicit dishesdelete(QWidget *parent = nullptr);
    ~dishesdelete();

signals:
    void back();

private slots:
    void on_back_clicked();

    void on_delete_2_clicked();

private:
    Ui::dishesdelete *ui;
};

#endif // DISHESDELETE_H
