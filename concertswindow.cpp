#include "concertswindow.h"
#include "ui_concertswindow.h"

concertswindow::concertswindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::concertswindow)
{
    ui->setupUi(this);
}

concertswindow::~concertswindow()
{
    delete ui;
}
