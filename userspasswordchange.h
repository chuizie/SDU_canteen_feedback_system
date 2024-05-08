#ifndef USERSPASSWORDCHANGE_H
#define USERSPASSWORDCHANGE_H

#include <QWidget>
#include <QMessageBox>
#include <string>
#include "users.h"
namespace Ui {
class userspasswordchange;
}

class userspasswordchange : public QWidget
{
    Q_OBJECT

public:
    explicit userspasswordchange(QWidget *parent = nullptr);
    ~userspasswordchange();

signals:
    void back();

private slots:
    void on_back_clicked();

    void on_change_clicked();

private:
    Ui::userspasswordchange *ui;
};

#endif // USERSPASSWORDCHANGE_H
