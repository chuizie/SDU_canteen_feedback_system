#include "dishesadd.h"
#include "ui_dishesadd.h"

dishesadd::dishesadd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dishesadd)
{
    ui->setupUi(this);
}

dishesadd::~dishesadd()
{
    delete ui;
}

void dishesadd::on_back_clicked()
{
    emit this->back();
}


void dishesadd::on_add_clicked()
{
    QString Qname = ui->name->text();
    QString Qsort = ui->sort->text();
    QString Qingredient = ui->ingredient->text();
    QString Qlocation = ui->location->text();
    QString Qprice = ui->price->text();
    QString Qnote1 = ui->note1->text();
    QString Qnote2 = ui->note2->text();
    QString Qnote3 = ui->note3->text();

    std::string Sname = Qname.toStdString();
    std::string Ssort = Qsort.toStdString();
    std::string Singredient = Qingredient.toStdString();
    std::string Slocation = Qlocation.toStdString();
    std::string Sprice = Qprice.toStdString();
    std::string Snote1 = Qnote1.toStdString();
    std::string Snote2 = Qnote2.toStdString();
    std::string Snote3 = Qnote3.toStdString();

    if (Qname != "" || Qsort != "" || Qingredient != "" || Qlocation != "" || Qprice != ""){
        if (Qsort == "炒菜类"){
            stir_fry newdishes(Sname, Singredient, Slocation, Sprice, Snote1, Snote2);
            newdishes.addDish();
            QMessageBox::information(this, "提示", "添加成功");
        }
        else if (Qsort == "汤面类"){
            noodle_soup newdishes(Sname, Singredient, Slocation, Sprice, Snote1, Snote2);
            newdishes.addDish();
            QMessageBox::information(this, "提示", "添加成功");
        }
        else{
            otherdish newdishes(Sname, Singredient, Slocation, Sprice, Ssort, Snote1, Snote2, Snote3);
            newdishes.addDish();
            QMessageBox::information(this, "提示", "添加成功");
        }
    }
    else{
        QMessageBox::information(this, "提示", "必填选项不能为空");
    }
}

