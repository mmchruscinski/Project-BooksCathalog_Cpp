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
    int selectedRow;

    explicit bookswindow(QWidget *parent = nullptr);
    ~bookswindow();
    void closeEvent(QCloseEvent* event);

private slots:
    void on_add_book_clicked();

    void on_add_genre_clicked();

    void on_add_cat_clicked();

    void on_add_author_clicked();

    void on_delete_book_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::bookswindow *ui;
    QSqlDatabase mydb;
    QSqlQueryModel *modelBooks = new QSqlQueryModel;
    QSortFilterProxyModel* proxymodel = new QSortFilterProxyModel;
    QString selectedTitle;

    void setTable();
    void setStats();
};

#endif // BOOKSWINDOW_H
