#include "theatreswindow.h"
#include "ui_theatreswindow.h"

theatreswindow::theatreswindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::theatreswindow)
{
    ui->setupUi(this);
}

theatreswindow::~theatreswindow()
{
    delete ui;
}
