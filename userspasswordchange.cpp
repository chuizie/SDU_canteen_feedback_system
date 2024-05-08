#include "userspasswordchange.h"
#include "ui_userspasswordchange.h"

userspasswordchange::userspasswordchange(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::userspasswordchange)
{
    ui->setupUi(this);
}

userspasswordchange::~userspasswordchange()
{
    delete ui;
}

void userspasswordchange::on_back_clicked()
{
    emit this->back();
}


void userspasswordchange::on_change_clicked()
{
    QString Qaccount = ui->account->text();
    QString Qoldpassword = ui->oldpassword->text();
    QString Qnewpassword = ui->newpassword->text();

    std::string Saccount = Qaccount.toStdString();
    std::string Soldpassword = Qoldpassword.toStdString();
    std::string Snewpassword = Qnewpassword.toStdString();

    if(users::changePassword(Saccount, Soldpassword, Snewpassword)){
        QMessageBox::information(this, "提示", "修改成功");
        ui->account->clear();
        ui->oldpassword->clear();
        ui->newpassword->clear();
    }
    else{
        if(Qaccount == ""){
            QMessageBox::information(this, "提示", "账号不能为空");
            ui->account->setFocus();
        }
        else if(Qoldpassword == ""){
            QMessageBox::information(this, "提示", "原密码不能为空");
            ui->oldpassword->setFocus();
        }
        else if(Qnewpassword == ""){
            QMessageBox::information(this, "提示", "新密码不能为空");
            ui->newpassword->setFocus();
        }
        else{
            QMessageBox::information(this, "提示", "账号或密码错误");
            ui->account->clear();
            ui->oldpassword->clear();
            ui->newpassword->clear();
            ui->account->setFocus();
        }
    }
}

