#include "userssignup.h"
#include "ui_userssignup.h"

userssignup::userssignup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::userssignup)
{
    ui->setupUi(this);
}

userssignup::~userssignup()
{
    delete ui;
}

void userssignup::on_back_clicked()
{
    emit this->back();
}


void userssignup::on_signup_clicked()
{
    QString Qname = ui->name->text();
    QString Qaccount = ui->account->text();
    QString Qpassword = ui->password->text();

    std::string Sname = Qname.toStdString();
    std::string Saccount = Qaccount.toStdString();
    std::string Spassword = Qpassword.toStdString();

    users newusers(Sname, Saccount, Spassword);

    if (newusers.addUsers()){
        QMessageBox::information(this, "提示", "注册成功");
        ui->name->clear();
        ui->account->clear();
        ui->password->clear();
    }
    else{
        if (Qname == ""){
            QMessageBox::information(this, "提示", "姓名不能为空");
            ui->name->setFocus();
        }
        else if (Qaccount == ""){
            QMessageBox::information(this, "提示", "账号不能为空");
            ui->account->setFocus();
        }
        else if (Qpassword == ""){
            QMessageBox::information(this, "提示", "密码不能为空");
            ui->password->setFocus();
        }
        else{
            QMessageBox::information(this, "提示", "账号和密码不合法");
            ui->name->clear();
            ui->account->clear();
            ui->password->clear();
            ui->account->setFocus();
        }
    }
}

