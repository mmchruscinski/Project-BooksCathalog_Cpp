#ifndef BOOKSWINDOW_H
#define BOOKSWINDOW_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <qtableview.h>
#include <QTableWidgetItem>
#include <QSortFilterProxyModel>

namespace Ui {
class bookswindow;
}

class bookswindow : public QWidget
{
    Q_OBJECT

public:
    explicit bookswindow(QWidget *parent = nullptr);
    ~bookswindow();
    void closeEvent(QCloseEvent* event);

private slots:
    void on_add_book_clicked();

    void on_add_genre_clicked();

    void on_add_cat_clicked();

    void on_add_author_clicked();

private:
    Ui::bookswindow *ui;
    QSqlDatabase mydb;

    void setTable();
    void setStats();
};

#endif // BOOKSWINDOW_H
