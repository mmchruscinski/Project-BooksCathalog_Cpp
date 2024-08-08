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
    int _id;
    QString _name;
    int _author;
    int _genre;
    QString _date;
    int _read;
    int _list;
    bool _own;
public:
    Book();
    Book(QString name,
        int author,
        int genre,
        QString date,
        int read,
        int list,
        bool own);
    Book(const QString title);
    Book(const int id);

    void add2base();
    void print();
    void del(const QString title);
};

#endif // BOOK_H
