#include "homepage.h"
#include "./ui_homepage.h"

homepage::homepage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::homepage)
{
    ui->setupUi(this);
    this->page2 = new adminLogin;
    this->page3 = new userslogin;

    connect(this->page2, SIGNAL(back()), this, SLOT(comeBackToPrev()));
    connect(this->page3, SIGNAL(back()), this, SLOT(comeBackToPrev()));
}

homepage::~homepage()
{
    delete ui;
}

void homepage::comeBackToPrev(){
    this->page2->hide();
    this->page3->hide();
    this->show();
}

void homepage::on_admin_clicked()
{
    this->close();
    this->page2->show();
}


void homepage::on_users_clicked()
{
    this->close();
    this->page3->show();
}

