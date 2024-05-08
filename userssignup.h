#ifndef USERSSIGNUP_H
#define USERSSIGNUP_H

#include <QWidget>
#include <QMessageBox>
#include <string>
#include "users.h"

namespace Ui {
class userssignup;
}

class userssignup : public QWidget
{
    Q_OBJECT

public:
    explicit userssignup(QWidget *parent = nullptr);
    ~userssignup();

signals:
    void back();

private slots:
    void on_back_clicked();

    void on_signup_clicked();

private:
    Ui::userssignup *ui;
};

#endif // USERSSIGNUP_H
