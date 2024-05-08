#include "dishesshow.h"
#include "ui_dishesshow.h"

dishesshow::dishesshow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dishesshow)
{
    ui->setupUi(this);
    std::vector<std::string> lines = dishes::showDish();
    std::string line;
    QString content;
    for (const auto& line : lines){
        content += QString::fromStdString(line) + "\n";
        ui->dishes->setText(content);
    }
}

dishesshow::~dishesshow()
{
    delete ui;
}


void dishesshow::on_pushButton_clicked()
{
    emit this->back();
}

