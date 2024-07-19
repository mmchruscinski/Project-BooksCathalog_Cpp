#ifndef BOOKS_ADD_AUT_H
#define BOOKS_ADD_AUT_H

#include <QDialog>

namespace Ui {
class books_add_aut;
}

class books_add_aut : public QDialog
{
    Q_OBJECT

public:
    explicit books_add_aut(QWidget *parent = nullptr);
    ~books_add_aut();

private:
    Ui::books_add_aut *ui;
};

#endif // BOOKS_ADD_AUT_H
