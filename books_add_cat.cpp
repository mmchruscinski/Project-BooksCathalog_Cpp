#include "books_add_cat.h"
#include "ui_books_add_cat.h"

books_add_cat::books_add_cat(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::books_add_cat)
{
    ui->setupUi(this);
}

books_add_cat::~books_add_cat()
{
    delete ui;
}
