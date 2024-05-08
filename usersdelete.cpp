#include "usersdelete.h"
#include "ui_usersdelete.h"

usersdelete::usersdelete(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::usersdelete)
{
    ui->setupUi(this);
}

usersdelete::~usersdelete()
{
    delete ui;
}

void usersdelete::on_back_clicked()
{
    emit this->back();
}


void usersdelete::on_delete_2_clicked()
{
    QString Qaccount = ui->account->text();
    std::string Saccount = Qaccount.toStdString();

    if(users::deleteUsers(Saccount)){
        QMessageBox::information(this, "提示", "删除成功");
        ui->account->clear();
    }
    else {
        QMessageBox::information(this, "提示", "删除失败");
        ui->account->clear();
        ui->account->setFocus();
    }


}

