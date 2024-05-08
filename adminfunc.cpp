#include "adminfunc.h"
#include "ui_adminfunc.h"
#include "admin.h"
#include "adminlogin.h"



adminfunc::adminfunc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::adminfunc)
{
    ui->setupUi(this);
    this->page6 = new dishesadd;
    this->page7 = new dishesdelete;
    this->page8 = new admindelete;
    this->page9 = new usersdelete;
    this->page10 = new commentshow;
    this->page11 = new adminpasswordchange;

    connect(this->page6, SIGNAL(back()), this, SLOT(comeBackToPrev()));
    connect(this->page7, SIGNAL(back()), this, SLOT(comeBackToPrev()));
    connect(this->page8, SIGNAL(back()), this, SLOT(comeBackToPrev()));
    connect(this->page9, SIGNAL(back()), this, SLOT(comeBackToPrev()));
    connect(this->page10, SIGNAL(back()), this, SLOT(comeBackToPrev()));
    connect(this->page11, SIGNAL(back()), this, SLOT(comeBackToPrev()));
}

adminfunc::~adminfunc()
{
    delete ui;
}

void adminfunc::comeBackToPrev(){
    this->page6->hide();
    this->page7->hide();
    this->page8->hide();
    this->page9->hide();
    this->page10->hide();
    this->page11->hide();
    this->show();
}


void adminfunc::on_back_clicked()
{
    emit this->back();
}


void adminfunc::on_dishesadd_clicked()
{
    this->close();
    this->page6->show();
}


void adminfunc::on_dishesdelete_clicked()
{
    this->close();
    this->page7->show();
}


void adminfunc::on_admindelete_clicked()
{
    this->close();
    this->page8->show();
}


void adminfunc::on_usersdelete_clicked()
{
    this->close();
    this->page9->show();
}


void adminfunc::on_commentsshow_clicked()
{
    this->close();
    this->page10->show();
}


void adminfunc::on_passwordchange_clicked()
{
    this->close();
    this->page11->show();
}

