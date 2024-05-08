#ifndef ADMINSIGNUP_H
#define ADMINSIGNUP_H

#include <QWidget>
#include <string>
#include <QMessageBox>
namespace Ui {
class adminsignup;
}


class adminsignup : public QWidget
{
    Q_OBJECT

public:
    explicit adminsignup(QWidget *parent = nullptr);
    ~adminsignup();

signals:
    void back();

private slots:
    void on_back_clicked();

    void on_signup_clicked();

private:
    Ui::adminsignup *ui;
};

#endif // ADMINSIGNUP_H
