#include "book.h"

Book::Book(QString name, QString author, QString genre, QString date, int read, int list) :
    _name(name), _author(author), _genre(genre), _date(date), _read(read), _list(list) {
}

Book::Book() {

}

void Book::add2base() {
    QString authorId, genreId;

    QSqlQueryModel author;
    author.setQuery(
        "SELECT ID\
        FROM Authors\
        WHERE Author = '" + _author + "'"
        );

    if (author.rowCount() == 0) {
        qDebug() << "not found";
        QMessageBox dialog;
        dialog.setText("Inserted author doesn't exist in the database. Add the author?");
        dialog.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        dialog.setDefaultButton(QMessageBox::No);
        int res = dialog.exec();

        if (res == QMessageBox::Yes) {
            QSqlQuery addAuth;
            addAuth.prepare(
                "INSERT INTO Authors (Author)\
                VALUES (:Author)"
                );
            addAuth.bindValue(":Author", _author);
            addAuth.finish();

            if (addAuth.exec()) {
                qDebug() << "Record inserted successfully";
                author.setQuery(
                    "SELECT ID\
                    FROM Authors\
                    WHERE Author = '" + _author + "'"
                    );
                addAuth.finish();

            } else {
                qDebug() << "Error: " << addAuth.lastError().text();
            }
        }
    }

    authorId = author.data(author.index(0,0)).toString();

    QSqlQueryModel genre;
    author.setQuery(
        "SELECT ID\
        FROM Genres\
        WHERE Genre = '" + _genre + "'"
        );
    genreId = author.data(author.index(0,0)).toString();

    QSqlQuery add;
    add.prepare(
        "INSERT INTO Books (Title, AuthorID, GenreID, Date, Read_num, Listen_num)\
        VALUES (:Title, :AuthorID, :GenreID, :Date, :Read_num, :Listen_num)"
        );
    add.bindValue(":Title",         _name);
    add.bindValue(":AuthorID",      authorId);
    add.bindValue(":GenreID",       genreId);
    add.bindValue(":Date",          _date);
    add.bindValue(":Read_num",      _read);
    add.bindValue(":Listen_num",    _list);
    add.finish();

    if (add.exec()) {
        qDebug() << "Record inserted successfully";
    } else {
        qDebug() << "Error: " << add.lastError().text();
    }
}

void Book::print() {
    qDebug() << _name;
    qDebug() << _author;
    qDebug() << _date;
    qDebug() << _genre;
    qDebug() << _list;
    qDebug() << _read;
}

void Book::del(const int row) {
    QSqlQuery del;
    del.prepare(
        "DELETE\
        FROM Books\
        WHERE Id = :ID"
        );
    del.bindValue(":ID", row);
    del.finish();

    if (del.exec()) {
        qDebug() << "Record deleted successfully";
    } else {
        qDebug() << "Error: " << del.lastError().text();
    }

    qDebug() << row;
}


