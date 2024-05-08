#include "adminpasswordchange.h"
#include "ui_adminpasswordchange.h"

adminpasswordchange::adminpasswordchange(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::adminpasswordchange)
{
    ui->setupUi(this);
}

adminpasswordchange::~adminpasswordchange()
{
    delete ui;
}

void adminpasswordchange::on_back_clicked()
{
    emit this->back();
}


void adminpasswordchange::on_change_clicked()
{
    QString Qaccount = ui->account->text();
    QString QoldPassword = ui->oldpassword->text();
    QString QnewPassword = ui->newpassword->text();

    std::string Saccount = Qaccount.toStdString();
    std::string SoldPassword = QoldPassword.toStdString();
    std::string SnewPassword = QnewPassword.toStdString();

    admin newadmin(Saccount, SoldPassword);
    if (newadmin.passwordChange(SnewPassword)){
        QMessageBox::information(this, "提示", "修改成功");
        ui->account->clear();
        ui->oldpassword->clear();
        ui->newpassword->clear();
    }
    else{
        if (Qaccount == ""){
            QMessageBox::information(this, "提示", "请输入用户名");
            ui->account->setFocus();
        }
        else if(QoldPassword == ""){
            QMessageBox::information(this, "提示", "请输入原密码");
            ui->account->setFocus();
        }
        else if(QnewPassword == ""){
            QMessageBox::information(this, "提示", "请输入新密码");
            ui->account->setFocus();
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

