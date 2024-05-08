#ifndef COMMENTSUBMIT_H
#define COMMENTSUBMIT_H

#include <QWidget>
#include <QMessageBox>
#include <string>
#include "users.h"

namespace Ui {
class commentsubmit;
}

class commentsubmit : public QWidget
{
    Q_OBJECT

public:
    explicit commentsubmit(QWidget *parent = nullptr);
    ~commentsubmit();
signals:
    void back();

private slots:
    void on_back_clicked();

    void on_submit_clicked();

private:
    Ui::commentsubmit *ui;
};

#endif // COMMENTSUBMIT_H
