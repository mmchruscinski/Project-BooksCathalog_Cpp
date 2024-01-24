#ifndef THEATRESWINDOW_H
#define THEATRESWINDOW_H

#include <QWidget>

namespace Ui {
class theatreswindow;
}

class theatreswindow : public QWidget
{
    Q_OBJECT

public:
    explicit theatreswindow(QWidget *parent = nullptr);
    ~theatreswindow();

private:
    Ui::theatreswindow *ui;
};

#endif // THEATRESWINDOW_H
