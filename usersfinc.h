#ifndef USERSFINC_H
#define USERSFINC_H

#include <QWidget>
#include "dishesshow.h"
#include "dishessearch.h"
#include "commentsubmit.h"
#include "userspasswordchange.h"
#include "dishesshownew.h"


namespace Ui {
class usersfinc;
}

class dishesshow;
class dishessearch;
class commentsubmit;
class userspasswordchange;
class dishesshownew;


class usersfinc : public QWidget
{
    Q_OBJECT

public:
    explicit usersfinc(QWidget *parent = nullptr);
    ~usersfinc();

    dishesshow *page14 = NULL;
    dishessearch * page15 = NULL;
    commentsubmit *page16 = NULL;
    userspasswordchange *page17 = NULL;
    dishesshownew *page18 = NULL;


private slots:
    void on_back_clicked();
    void comeBackToPrev();
    void on_dishshow_clicked();
    void on_dishsearch_clicked();
    void on_commentsubmit_clicked();
    void on_passwordchange_clicked();

signals:
    void back();

private:
    Ui::usersfinc *ui;
};

#endif // USERSFINC_H
