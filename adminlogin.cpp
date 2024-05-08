#include "adminlogin.h"
#include "ui_adminlogin.h"
#include "admin.h"

adminLogin::adminLogin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::adminLogin)
{
    ui->setupUi(this);
    this->page4 = new adminsignup;
    this->page5 = new adminfunc;
    connect(this->page4, SIGNAL(back()), this, SLOT(comeBackToPrev()));
    connect(this->page5, SIGNAL(back()), this, SLOT(comeBackToPrev()));
}

QString adminaccount ;
QString adminpassword ;

adminLogin::~adminLogin()
{
    delete ui;
}

void adminLogin::on_back_clicked()
{
    emit this->back();
}

void adminLogin::on_login_clicked()
{
    QString Qaccount = ui->account->text();
    QString Qpassword = ui->password->text();

    adminaccount = Qaccount;
    adminpassword = Qpassword;

    std::string Saccount = Qaccount.toStdString();
    std::string Spassword = Qpassword.toStdString();
    admin newadmin(Saccount, Spassword);

    if (newadmin.login()){
        QMessageBox::information(this, "提示", "登录成功");
        ui->account->clear();
        ui->password->clear();
        this->close();
        this->page5->show();
    }
    else{
        if (Qaccount == ""){
            QMessageBox::information(this, "提示", "请输入用户名");
            ui->account->setFocus();
        }
        else {
            if(Qpassword == ""){
                QMessageBox::information(this, "提示", "请输入密码");
                ui->password->setFocus();
            }
            else{
                QMessageBox::information(this, "错误提示", "用户名或密码错误");
                ui->account->clear();
                ui->password->clear();
                ui->account->setFocus();
            }
        }
    }


}

void adminLogin::on_signup_clicked()
{
    this->close();
    this->page4->show();
}

void adminLogin::comeBackToPrev(){
    this->page4->hide();
    this->page5->hide();
    this->show();
}

