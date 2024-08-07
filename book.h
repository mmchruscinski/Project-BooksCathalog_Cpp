#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#ifndef BOOK_H
#define BOOK_H
using namespace std;
class Book
{
private:
    QString _name;
    QString _author;
    QString _genre;
    QString _date;
    int _read;
    int _list;
public:
    Book();
    Book(QString name,
        QString author,
        QString genre,
        QString date,
        int read,
        int list);
    Book(const QString title);
    Book(const int id);

    void add2base();
    void print();
    void del(const QString title);
};

#endif // BOOK_H
