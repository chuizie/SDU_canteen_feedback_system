#include "dishesdelete.h"
#include "ui_dishesdelete.h"

dishesdelete::dishesdelete(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dishesdelete)
{
    ui->setupUi(this);
}

dishesdelete::~dishesdelete()
{
    delete ui;
}

void dishesdelete::on_back_clicked()
{
    emit this->back();
}


void dishesdelete::on_delete_2_clicked()
{
    QString Qname = ui->name->text();
    std::string Sname = Qname.toStdString();

    if(dishes::deleteDish(Sname)){
        QMessageBox::information(this, "提示", "删除成功");
        ui->name->clear();
    }
    else{
        QMessageBox::information(this, "提示", "删除失败");
        ui->name->clear();
        ui->name->setFocus();
    }
}

