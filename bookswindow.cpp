#include "bookswindow.h"
#include "ui_bookswindow.h"
#include "books_add.h"

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

    QSqlQueryModel *modelBooks = new QSqlQueryModel;
    modelBooks->setQuery(
        "SELECT Title, Author, Cathegory, Genre, Date, Read_num, Listen_num\
        FROM Books INNER JOIN Authors\
        ON Books.AuthorID = Authors.Id INNER JOIN Genres\
        ON Books.GenreID = Genres.Id INNER JOIN Cathegories\
        ON Genres.CathegoryID = Cathegories.Id\
        ");

    //poniższe w miarę mozliwości do nowe funkcji lub lv hard: dziedziczenie tableview
    modelBooks->setHeaderData(0, Qt::Horizontal, "Book title");
    modelBooks->setHeaderData(1, Qt::Horizontal, "Book author");
    modelBooks->setHeaderData(5, Qt::Horizontal, "Read c.");
    modelBooks->setHeaderData(6, Qt::Horizontal, "Listen c.");
    QSortFilterProxyModel* proxymodel = new QSortFilterProxyModel;
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

bookswindow::~bookswindow()
{
    delete ui;
}

void bookswindow::on_add_book_clicked()
{
    books_add* booksAdd = new books_add();
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

