#ifndef ADMINPASSWORDCHANGE_H
#define ADMINPASSWORDCHANGE_H

#include <QWidget>
#include <QMessageBox>
#include <string>
#include "admin.h"

namespace Ui {
class adminpasswordchange;
}

class adminpasswordchange : public QWidget
{
    Q_OBJECT

public:
    explicit adminpasswordchange(QWidget *parent = nullptr);
    ~adminpasswordchange();

signals:
    void back();

private slots:
    void on_back_clicked();

    void on_change_clicked();

private:
    Ui::adminpasswordchange *ui;
};

#endif // ADMINPASSWORDCHANGE_H
