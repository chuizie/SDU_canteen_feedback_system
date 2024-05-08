#include "commentshow.h"
#include "ui_commentshow.h"

commentshow::commentshow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::commentshow)
{
    ui->setupUi(this);
    std::vector<std::string> lines = admin::showComments();
    std::string line;
    QString content;
    for (const auto& line : lines){
        content += QString::fromStdString(line) + "\n";
        ui->comments->setText(content);
    }
}

commentshow::~commentshow()

{
    delete ui;
}

void commentshow::on_back_clicked()
{
    emit this->back();
}

