#include "commentsubmit.h"
#include "ui_commentsubmit.h"

commentsubmit::commentsubmit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::commentsubmit)
{
    ui->setupUi(this);
}

commentsubmit::~commentsubmit()
{
    delete ui;
}

void commentsubmit::on_back_clicked()
{
    emit this->back();
}


void commentsubmit::on_submit_clicked()
{
    QString Qname = ui->name->text();
    QString Qcomment = ui->comment->text();

    std::string Sname = Qname.toStdString();
    std::string Scomment = Qcomment.toStdString();

    if (users::submintComments(Sname, Scomment)){
        QMessageBox::information(this, "提示", "提交成功");
        ui->name->clear();
        ui->comment->clear();
        ui->name->setFocus();
    }
    else{
        if(Qname == ""){
            QMessageBox::information(this, "提示", "菜名不能为空");
            ui->name->setFocus();
        }
        else if(Qcomment == ""){
            QMessageBox::information(this, "提示", "意见不能为空");
            ui->comment->setFocus();
        }
        else{
            QMessageBox::information(this, "提示", "提交失败");
            ui->name->clear();
            ui->comment->clear();
            ui->name->setFocus();
        }
    }

}

