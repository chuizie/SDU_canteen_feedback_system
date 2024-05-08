#include "adminsignup.h"
#include "ui_adminsignup.h"
#include "admin.h"

adminsignup::adminsignup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::adminsignup)
{
    ui->setupUi(this);
}

adminsignup::~adminsignup()
{
    delete ui;
}

void adminsignup::on_back_clicked()
{
    emit this->back();
}

void adminsignup::on_signup_clicked()
{
    QString Qaccount = ui->account->text();
    QString Qpassword = ui->password->text();

    std::string Saccount = Qaccount.toStdString();
    std::string Spassword = Qpassword.toStdString();

    admin nowadmin(Saccount, Spassword);

    if(nowadmin.signupAdmin()){
        QMessageBox::information(this, "提示", "注册成功！");
        ui->account->clear();
        ui->password->clear();
        ui->password->setFocus();
    }
    else{
        if (Qaccount == ""){
            QMessageBox::information(this, "提示", "请输入用户名！");
            ui->account->setFocus();
        }
        else if (Qpassword == ""){
            QMessageBox::information(this, "提示", "请输入密码！");
            ui->password->setFocus();
        }
        else{
            QMessageBox::information(this, "提示", "用户名或密码格式非法!");

        }
    }

}

