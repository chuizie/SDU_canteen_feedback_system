#ifndef DISHESSEARCH_H
#define DISHESSEARCH_H

#include <QWidget>
#include <QMessageBox>
#include <string>
#include "dishes.h"

namespace Ui {
class dishessearch;
}

class dishessearch : public QWidget
{
    Q_OBJECT

public:
    explicit dishessearch(QWidget *parent = nullptr);
    ~dishessearch();

signals:
    void back();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::dishessearch *ui;
};

#endif // DISHESSEARCH_H
