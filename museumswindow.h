#ifndef MUSEUMSWINDOW_H
#define MUSEUMSWINDOW_H

#include <QWidget>

namespace Ui {
class museumswindow;
}

class museumswindow : public QWidget
{
    Q_OBJECT

public:
    explicit museumswindow(QWidget *parent = nullptr);
    ~museumswindow();

private:
    Ui::museumswindow *ui;
};

#endif // MUSEUMSWINDOW_H
