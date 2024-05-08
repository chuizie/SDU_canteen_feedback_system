#include "usersfinc.h"
#include "ui_usersfinc.h"

usersfinc::usersfinc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::usersfinc)
{
    ui->setupUi(this);
    this->page14 = new dishesshow;
    this->page15 = new dishessearch;
    this->page16 = new commentsubmit;
    this->page17 = new userspasswordchange;
    this->page18 = new dishesshownew;

    connect(this->page14, SIGNAL(back()), this, SLOT(comeBackToPrev()));
    connect(this->page15, SIGNAL(back()), this, SLOT(comeBackToPrev()));
    connect(this->page16, SIGNAL(back()), this, SLOT(comeBackToPrev()));
    connect(this->page17, SIGNAL(back()), this, SLOT(comeBackToPrev()));
    connect(this->page18, SIGNAL(back()), this, SLOT(comeBackToPrev()));




}

usersfinc::~usersfinc()
{
    delete ui;
}

void usersfinc::on_back_clicked()
{
    emit this->back();
}

void usersfinc::comeBackToPrev(){
    this->page14->hide();
    this->page15->hide();
    this->page16->hide();
    this->page17->hide();
    this->page18->hide();
    this->show();
}

void usersfinc::on_dishshow_clicked()
{
    this->close();
    this->page18->show();
}


void usersfinc::on_dishsearch_clicked()
{
    this->close();
    this->page15->show();
}


void usersfinc::on_commentsubmit_clicked()
{
    this->close();
    this->page16->show();
}


void usersfinc::on_passwordchange_clicked()
{
    this->close();
    this->page17->show();
}

