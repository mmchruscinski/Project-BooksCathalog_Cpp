#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bookswindow.h"
#include "museumswindow.h"
#include "concertswindow.h"
#include "theatreswindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonBooks_clicked()
{
    bookswindow* booksWin = new bookswindow();
    booksWin->show();
}


void MainWindow::on_buttonMuseums_clicked()
{
    museumswindow* museumsWin = new museumswindow();
    museumsWin->show();
}


void MainWindow::on_buttonTheatre_clicked()
{
    theatreswindow* theatresWin = new theatreswindow();
    theatresWin->show();
}


void MainWindow::on_buttonConcerts_clicked()
{
    concertswindow* concertsWin = new concertswindow();
    concertsWin->show();
}

