#include "dishesshownew.h"
#include "ui_dishesshownew.h"

dishesshownew::dishesshownew(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dishesshownew)
{
    ui->setupUi(this);
    std::vector<std::string> lines = dishes::showDish();
    std::string line;
    QString content;
    for (const auto &line : lines) {
        content += QString::fromStdString(line) + "\n";
        ui->dishes->setText(content);
    }
}

dishesshownew::~dishesshownew()
{
    delete ui;
}

void dishesshownew::on_back_clicked()
{
    emit this->back();
}
