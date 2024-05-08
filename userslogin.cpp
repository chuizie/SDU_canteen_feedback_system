#include "userslogin.h"
#include "ui_userslogin.h"
#include "users.h"

userslogin::userslogin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::userslogin)
{
    ui->setupUi(this);
    this->page12 = new userssignup;
    this->page13 = new usersfinc;

    connect(this->page12, SIGNAL(back()), this, SLOT(comeBackToPrev()));
    connect(this->page13, SIGNAL(back()), this, SLOT(comeBackToPrev()));

}

userslogin::~userslogin()
{
    delete ui;
}

void userslogin::comeBackToPrev(){
    this->page12->hide();
    this->page13->hide();
    this->show();
}

void userslogin::on_back_clicked()
{
    emit this->back();
}


void userslogin::on_login_clicked()
{
    QString Qaccount = ui->account->text();
    QString Qpassword = ui->password->text();

    std::string Saccount = Qaccount.toStdString();
    std::string Spassword = Qpassword.toStdString();
    // std::string Sname = "new user";

    // users newuser(Sname, Saccount, Spassword);

    if(users::login(Saccount, Spassword)){
        QMessageBox::information(this, "提示", "登录成功");
        this->hide();
        this->page13->show();
    }
    else{
        if (Qaccount == ""){
            QMessageBox::information(this, "提示", "请输入用户名");
            ui->account->setFocus();
        }
        else if (Qpassword == ""){
            QMessageBox::information(this, "提示", "请输入用户名");
            ui->password->setFocus();
        }
        else{
            QMessageBox::information(this, "提示", "账号或密码错误");
            ui->account->clear();
            ui->password->clear();
            ui->account->setFocus();
        }
    }

}


void userslogin::on_signup_clicked()
{
    this->close();
    this->page12->show();
}

