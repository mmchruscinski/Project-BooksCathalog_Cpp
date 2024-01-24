#ifndef CONCERTSWINDOW_H
#define CONCERTSWINDOW_H

#include <QWidget>

namespace Ui {
class concertswindow;
}

class concertswindow : public QWidget
{
    Q_OBJECT

public:
    explicit concertswindow(QWidget *parent = nullptr);
    ~concertswindow();

private:
    Ui::concertswindow *ui;
};

#endif // CONCERTSWINDOW_H
