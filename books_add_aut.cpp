#include "books_add_aut.h"
#include "ui_books_add_aut.h"
#include <QMessageBox>

books_add_aut::books_add_aut(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::books_add_aut)
{
    ui->setupUi(this);

    setTable();
}

books_add_aut::~books_add_aut()
{
    delete ui;
}

void books_add_aut::setTable()
{
    qDebug() << "Set authors";
    modelAuthors->setQuery(
        "SELECT Author\
        FROM Authors"
        );
    modelAuthors->setHeaderData(0, Qt::Horizontal, "Author name");
    proxymodel->setSourceModel(modelAuthors);
    ui->tableView->setModel(proxymodel);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setColumnWidth(0, 250);
}

void books_add_aut::addAuthor()
{
    QString name = ui->lineEdit->text();
    QSqlQueryModel check;
    check.setQuery(
        "SELECT ID\
        FROM Authors\
        WHERE Author = '" + name + "'"
        );

    if (check.rowCount() == 0) {
        QSqlQuery addAuth;
        addAuth.prepare(
            "INSERT INTO Authors (Author)\
            VALUES (:Author)"
            );
        addAuth.bindValue(":Author", name);
        addAuth.finish();
        if (addAuth.exec()) {
            qDebug() << "Record inserted successfully";
        } else {
            qDebug() << "Error: " << addAuth.lastError().text();
        }
    } else {
        QMessageBox dialog;
        dialog.setText("An Author already exists in the database!");
        dialog.exec();
        qDebug() << "Exists!";
    }
}

void books_add_aut::deleteAuthor()
{

}

void books_add_aut::on_tableView_clicked(const QModelIndex &index)
{
    QModelIndex sortedIndex = proxymodel->index(index.row(), 0);
    QModelIndex sourceIndex = proxymodel->mapToSource(sortedIndex);
    selectedAuthor = sourceIndex.data().toString();
    qDebug() << selectedAuthor;
}

