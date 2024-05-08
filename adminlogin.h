#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QWidget>
#include <string>
#include <QMainWindow>
#include <QMessageBox>
#include "adminsignup.h"
#include "adminfunc.h"


extern QString adminaccount;
extern QString adminpassword;

namespace Ui {
class adminLogin;
}

class adminsignup;
class adminfunc;

class adminLogin : public QWidget
{
    Q_OBJECT

public:
    explicit adminLogin(QWidget *parent = nullptr);
    ~adminLogin();

    adminsignup *page4 = NULL;
    adminfunc *page5 = NULL;

signals:
    void back();

private slots:
    void on_back_clicked();
    void on_login_clicked();
    void on_signup_clicked();
    void comeBackToPrev();

private:
    Ui::adminLogin *ui;
};

#endif // ADMINLOGIN_H
