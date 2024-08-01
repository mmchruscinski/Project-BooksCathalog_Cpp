#include "bookswindow.h"
#include "ui_bookswindow.h"
#include "books_add.h"
#include "books_add_genre.h"
#include "books_add_cat.h"
#include "books_add_aut.h"
#include "book.h"

#include <QMessageBox>

bookswindow::bookswindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::bookswindow)
{
    ui->setupUi(this);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/MyData/Repos/IT/Project-BooksCathalog_Cpp/CultureManager3/Cathalog.db");

    if(mydb.open()) {
        ui->label_isopen->setText("DB connected!");
    } else {
        ui->label_isopen->setText("DB not found :(");
    }

    setTable();
}

bookswindow::~bookswindow()
{
    delete ui;
}

void bookswindow::on_add_book_clicked()
{
    books_add* booksAdd = new books_add();
    connect(booksAdd, &books_add::accepted, this, &bookswindow::updateWindow);
    booksAdd->show();
}

void bookswindow::closeEvent(QCloseEvent* event)
{
    QSqlDatabase mydb = QSqlDatabase::database("qt_sql_default_connection");
    //QSqlQuery query(mydb);
    //query.finish();
    mydb.close();
    QSqlDatabase::removeDatabase("qt_sql_default_connection");
    qDebug() << "window closed";
}


void bookswindow::on_add_genre_clicked()
{
    books_add_genre* booksAddGenre = new books_add_genre();
    booksAddGenre->show();
}


void bookswindow::on_add_cat_clicked()
{
    books_add_cat* booksAddCat = new books_add_cat();
    booksAddCat->show();
}

void bookswindow::setTable()
{
    qDebug() << "Set table";
    modelBooks->setQuery(
        "SELECT Title, Author, Cathegory, Genre, Date, Read_num, Listen_num\
        FROM Books INNER JOIN Authors\
        ON Books.AuthorID = Authors.Id INNER JOIN Genres\
        ON Books.GenreID = Genres.Id INNER JOIN Cathegories\
        ON Genres.CathegoryID = Cathegories.Id"
    );
    modelBooks->setHeaderData(0, Qt::Horizontal, "Book title");
    modelBooks->setHeaderData(1, Qt::Horizontal, "Book author");
    modelBooks->setHeaderData(5, Qt::Horizontal, "Read c.");
    modelBooks->setHeaderData(6, Qt::Horizontal, "Listen c.");
    proxymodel->setSourceModel(modelBooks);
    ui->tableView->setModel(proxymodel);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setColumnWidth(0, 310);
    ui->tableView->setColumnWidth(1, 200);
    ui->tableView->setColumnWidth(2, 120);
    ui->tableView->setColumnWidth(3, 120);
    ui->tableView->setColumnWidth(4, 100);
    ui->tableView->setColumnWidth(5, 55);
    ui->tableView->setColumnWidth(6, 55);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}

void bookswindow::on_add_author_clicked()
{
    books_add_aut* booksAddAut = new books_add_aut;
    booksAddAut->show();
}

void bookswindow::setStats()
{
    //int total,
    //    finished,
    //    read,
    //    listened,
    //    doubled;
}


void bookswindow::on_delete_book_clicked()
{
    Book virtualBook;
    virtualBook.del(selectedTitle);
    setTable();
}

void bookswindow::on_tableView_clicked(const QModelIndex &index)
{
    QModelIndex sortedIndex = proxymodel->index(index.row(), 0);
    QModelIndex sourceIndex = proxymodel->mapToSource(sortedIndex);
    QString title = sourceIndex.data().toString();
    qDebug() << title;
    selectedTitle = title;
}

void bookswindow::updateWindow()
{
    const QString mess = "Hello signal!";
    QMessageBox::information(this, mess, mess);
    setTable();
}
