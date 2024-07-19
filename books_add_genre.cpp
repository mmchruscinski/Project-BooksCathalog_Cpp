#include "books_add_genre.h"
#include "ui_books_add_genre.h"

books_add_genre::books_add_genre(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::books_add_genre)
{
    ui->setupUi(this);
}

books_add_genre::~books_add_genre()
{
    delete ui;
}
