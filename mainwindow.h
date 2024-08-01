
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <iostream>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonBooks_clicked();

    void on_buttonMuseums_clicked();

    void on_buttonTheatre_clicked();

    void on_buttonConcerts_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
