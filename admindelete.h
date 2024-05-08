#ifndef ADMINDELETE_H
#define ADMINDELETE_H

#include <QWidget>
#include <QMessageBox>
#include <string>
#include "admin.h"

namespace Ui {
class admindelete;
}

class admindelete : public QWidget
{
    Q_OBJECT

public:
    explicit admindelete(QWidget *parent = nullptr);
    ~admindelete();

signals:
    void back();

private slots:
    void on_delete_2_clicked();

    void on_back_clicked();

private:
    Ui::admindelete *ui;
};

#endif // ADMINDELETE_H
