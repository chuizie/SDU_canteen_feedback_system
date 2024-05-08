#ifndef COMMENTSHOW_H
#define COMMENTSHOW_H

#include <QWidget>
#include <string>
#include <vector>
#include "admin.h"

namespace Ui {
class commentshow;
}

class commentshow : public QWidget
{
    Q_OBJECT

public:
    explicit commentshow(QWidget *parent = nullptr);
    ~commentshow();

signals:
    void back();

private slots:
    void on_back_clicked();

private:
    Ui::commentshow *ui;
};

#endif // COMMENTSHOW_H
