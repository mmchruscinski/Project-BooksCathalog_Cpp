#include "museumswindow.h"
#include "ui_museumswindow.h"

museumswindow::museumswindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::museumswindow)
{
    ui->setupUi(this);
}

museumswindow::~museumswindow()
{
    delete ui;
}
