#ifndef BOOKS_ADD_CAT_H
#define BOOKS_ADD_CAT_H

#include <QDialog>

namespace Ui {
class books_add_cat;
}

class books_add_cat : public QDialog
{
    Q_OBJECT

public:
    explicit books_add_cat(QWidget *parent = nullptr);
    ~books_add_cat();

private:
    Ui::books_add_cat *ui;
};

#endif // BOOKS_ADD_CAT_H
