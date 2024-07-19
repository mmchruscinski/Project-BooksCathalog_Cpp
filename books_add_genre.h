#ifndef BOOKS_ADD_GENRE_H
#define BOOKS_ADD_GENRE_H

#include <QDialog>

namespace Ui {
class books_add_genre;
}

class books_add_genre : public QDialog
{
    Q_OBJECT

public:
    explicit books_add_genre(QWidget *parent = nullptr);
    ~books_add_genre();

private:
    Ui::books_add_genre *ui;
};

#endif // BOOKS_ADD_GENRE_H
