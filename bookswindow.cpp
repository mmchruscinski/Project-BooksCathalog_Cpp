#include "bookswindow.h"
#include "ui_bookswindow.h"
#include "books_add.h"
#include "books_add_genre.h"
#include "books_add_cat.h"
#include "books_add_aut.h"
#include "book.h"
#include "colordelegate.h"

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
    connect(booksAdd, &books_add::acceptSignal, this, &bookswindow::updateWindow);
    booksAdd->show();
}

void bookswindow::on_edit_book_clicked()
{
    books_add *booksAdd = new books_add(nullptr, &selectedTitle);
    connect(booksAdd, &books_add::acceptSignal, this, &bookswindow::updateWindow);
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

    colordelegate *delegate = new colordelegate(ui->tableView);

    ui->tableView->setItemDelegate(delegate);

    setStats();
}

void bookswindow::on_add_author_clicked()
{
    books_add_aut* booksAddAut = new books_add_aut;
    booksAddAut->show();
}

void bookswindow::setStats()
{
    float itotal = 0, ifinished = 0;

    QSqlQuery qtotal("SELECT COUNT(*) FROM Books");
    if (qtotal.next()) {
        ui->label_total->setText(qtotal.value(0).toString());
        itotal = qtotal.value(0).toInt();
    }

    QSqlQuery qfinished("SELECT COUNT(*) FROM Books WHERE Read_num > 0 OR Listen_num > 0");
    if (qfinished.next()) {
        ui->label_finished->setText(qfinished.value(0).toString());
        ifinished = qfinished.value(0).toInt();
    }

    QSqlQuery qread("SELECT COUNT(*) FROM Books WHERE Read_num > 0");
    if (qread.next()) {
        ui->label_read->setText(qread.value(0).toString());
    }

    QSqlQuery qlisten("SELECT COUNT(*) FROM Books WHERE Listen_num > 0");
    if (qlisten.next()) {
        ui->label_listened->setText(qlisten.value(0).toString());
    }

    ui->progressBar->setValue(int((ifinished/itotal)*100));
}

void bookswindow::on_delete_book_clicked()
{
    QMessageBox dialog;
    dialog.setText("Delete the record '" + selectedTitle + "'?");
    dialog.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    dialog.setDefaultButton(QMessageBox::Yes);
    int res = dialog.exec();
    if (res == QMessageBox::Yes) {
        Book virtualBook;
        virtualBook.del(selectedTitle);
        setTable();
    }
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
    //const QString mess = "Hello signal!";
    //QMessageBox::information(this, mess, mess);
    setTable();
}

