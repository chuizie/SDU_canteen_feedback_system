#ifndef ADMINFUNC_H
#define ADMINFUNC_H

#include <QWidget>
#include <iostream>
#include "dishesadd.h"
#include "dishesdelete.h"
#include "admindelete.h"
#include "usersdelete.h"
#include "commentshow.h"
#include "adminpasswordchange.h"

namespace Ui {
class adminfunc;
}

class dishesadd;
class dishesdelete;
class admindelete;
class usersdelete;
class commentshow;
class adminpasswordchange;

class adminfunc : public QWidget
{
    Q_OBJECT

public:
    explicit adminfunc(QWidget *parent = nullptr);
    ~adminfunc();

    dishesadd *page6 = NULL;
    dishesdelete *page7 = NULL;
    admindelete *page8 = NULL;
    usersdelete *page9 = NULL;
    commentshow *page10 = NULL;
    adminpasswordchange *page11 = NULL;

signals:
    void back();

private slots:
    void on_back_clicked();
    void comeBackToPrev();
    void on_dishesadd_clicked();
    void on_dishesdelete_clicked();
    void on_admindelete_clicked();
    void on_usersdelete_clicked();
    void on_commentsshow_clicked();

    void on_passwordchange_clicked();

private:
    Ui::adminfunc *ui;
};

#endif // ADMINFUNC_H
