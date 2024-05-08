#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include "adminlogin.h"
#include "userslogin.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class homepage;
}
QT_END_NAMESPACE
class adminLogin;
class userslogin;

class homepage : public QMainWindow
{
    Q_OBJECT

public:
    homepage(QWidget *parent = nullptr);
    ~homepage();

    adminLogin *page2 = NULL;
    userslogin *page3 = NULL;

private slots:
    void on_admin_clicked();
    void on_users_clicked();
    void comeBackToPrev();


private:
    Ui::homepage *ui;
};
#endif // HOMEPAGE_H
