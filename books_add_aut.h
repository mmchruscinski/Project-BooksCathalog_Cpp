#ifndef BOOKS_ADD_AUT_H
#define BOOKS_ADD_AUT_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class books_add_aut;
}

class books_add_aut : public QDialog
{
    Q_OBJECT

public:
    explicit books_add_aut(QWidget *parent = nullptr);
    ~books_add_aut();

public slots:
    void addAuthor();
    void deleteAuthor();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::books_add_aut *ui;
    QString selectedAuthor;
    QSqlQueryModel *modelAuthors = new QSqlQueryModel;
    QSortFilterProxyModel *proxymodel = new QSortFilterProxyModel;

    void setTable();
};

#endif // BOOKS_ADD_AUT_H
