#ifndef BOOKS_ADD_H
#define BOOKS_ADD_H

#include <QDialog>
#include <QDebug>
#include <QSqlQueryModel>
#include "book.h"

namespace Ui {
class books_add;
}

class books_add : public QDialog
{
    Q_OBJECT

public:
    explicit books_add(QWidget *parent = nullptr);
    ~books_add();

private slots:
    void on_buttonBox_accepted();

    void on_combo_cat_currentTextChanged(const QString &arg1);

    void on_books_add_accepted();

private:
    Ui::books_add *ui;

signals:
    void acceptSignal();
};

#endif // BOOKS_ADD_H
