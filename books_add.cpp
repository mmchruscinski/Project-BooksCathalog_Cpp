#include "books_add.h"
#include "ui_books_add.h"

books_add::books_add(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::books_add)
{
    ui->setupUi(this);

    for (int i=0; i<6; i++) {
        ui->combo_read->addItem(QString::number(i));
        ui->combo_listen->addItem(QString::number(i));
    }

    QSqlQueryModel* modelCats  = new QSqlQueryModel();
    modelCats->setQuery(
        "SELECT Cathegory\
        FROM Cathegories"
    );

    for (int i=0; i<modelCats->rowCount(); i++) {
        QString cat = modelCats->data(modelCats->index(i, 0)).toString();
        ui->combo_cat->addItem(cat);
    }

    //connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &bookswindow::updateWindow);
}

books_add::~books_add()
{
    delete ui;
}

void books_add::on_buttonBox_accepted()
{
    QString name    = ui->text_name->text();
    QString author  = ui->text_author->text();
    QString date    = ui->text_date->text();
    QString genre   = ui->combo_genre->currentText();
    int read        = ui->combo_read->currentText().toInt();
    int list        = ui->combo_listen->currentText().toInt();

    Book currentBook(name, author, genre, date, read, list);
    currentBook.print();
    currentBook.add2base();
}


void books_add::on_combo_cat_currentTextChanged(const QString &arg1)
{
    ui->combo_genre->clear();
    QSqlQueryModel* modelGen  = new QSqlQueryModel();
    modelGen->setQuery(
        "SELECT Genre FROM Genres\
        JOIN Cathegories\
        ON Genres.CathegoryID = Cathegories.Id\
        WHERE Cathegories.Cathegory = '"
        + arg1 + "'"
    );

    for (int i=0; i<modelGen->rowCount(); i++) {
        QString gen = modelGen->data(modelGen->index(i, 0)).toString();
        ui->combo_genre->addItem(gen);
    }

    delete modelGen;
}
