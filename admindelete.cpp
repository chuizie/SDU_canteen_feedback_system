#include "admindelete.h"
#include "ui_admindelete.h"

admindelete::admindelete(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::admindelete)
{
    ui->setupUi(this);
}

admindelete::~admindelete()
{
    delete ui;
}

void admindelete::on_delete_2_clicked()
{
    QString Qaccount = ui->account->text();
    std::string Saccount = Qaccount.toStdString();
    std::string Spassword;

    admin theadmin(Saccount, Spassword);

    if (theadmin.deleteAdmin()){
        QMessageBox::information(this, "提示", "删除成功");
        ui->account->clear();
    }
    else{
        QMessageBox::information(this, "提示", "删除失败");
        ui->account->clear();
        ui->account->setFocus();
    }
}


void admindelete::on_back_clicked()
{
    emit this->back();
}

