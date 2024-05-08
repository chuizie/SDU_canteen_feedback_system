#ifndef USERSDELETE_H
#define USERSDELETE_H

#include <QWidget>
#include <QMessageBox>
#include <string>
#include "users.h"

namespace Ui {
class usersdelete;
}

class usersdelete : public QWidget
{
    Q_OBJECT

public:
    explicit usersdelete(QWidget *parent = nullptr);
    ~usersdelete();

signals:
    void back();

private slots:
    void on_back_clicked();

    void on_delete_2_clicked();

private:
    Ui::usersdelete *ui;
};

#endif // USERSDELETE_H
