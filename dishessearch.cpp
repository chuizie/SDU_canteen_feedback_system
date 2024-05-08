#include "dishessearch.h"
#include "ui_dishessearch.h"

dishessearch::dishessearch(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dishessearch)
{
    ui->setupUi(this);
}

dishessearch::~dishessearch()
{
    delete ui;
}

void dishessearch::on_pushButton_2_clicked()
{
    emit this->back();
}


void dishessearch::on_pushButton_clicked()
{
    QString Qname = ui->name->text();
    QString Qdishes;
    std::string Sname = Qname.toStdString();
    std::string Sdishes = dishes::searchDish(Sname);
    if (Sdishes == ""){
        QMessageBox::information(this, "提示", "菜品名错误或菜品不存在");
        ui->name->clear();
        ui->name->setFocus();
    }
    else{
        Qdishes = QString::fromStdString(Sdishes);
        QMessageBox::information(this, "查询成功", Qdishes);
        ui->name->clear();
    }
}

