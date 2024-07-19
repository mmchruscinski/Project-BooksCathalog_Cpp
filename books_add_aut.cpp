#include "books_add_aut.h"
#include "ui_books_add_aut.h"

books_add_aut::books_add_aut(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::books_add_aut)
{
    ui->setupUi(this);
}

books_add_aut::~books_add_aut()
{
    delete ui;
}
