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

private:
    Ui::bookswindow *ui;
    QSqlDatabase mydb;
};

#endif // BOOKSWINDOW_H
