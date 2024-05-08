#ifndef USERSLOGIN_H
#define USERSLOGIN_H

#include <QWidget>
#include <QMessageBox>
#include <string>
#include "userssignup.h"
#include "usersfinc.h"

namespace Ui {
class userslogin;
}

class userssignup;
class usserfinc;

class userslogin : public QWidget
{
    Q_OBJECT

public:
    explicit userslogin(QWidget *parent = nullptr);
    ~userslogin();

    userssignup *page12 = NULL;
    usersfinc *page13 = NULL;

signals:
    void back();

private slots:
    void on_back_clicked();

    void on_login_clicked();

    void on_signup_clicked();

    void comeBackToPrev();

private:
    Ui::userslogin *ui;
};

#endif // USERSLOGIN_H
