#include "dialog_author.h"
#include "ui_dialog_author.h"

dialog_author::dialog_author(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dialog_author)
{
    ui->setupUi(this);
}

dialog_author::~dialog_author()
{
    delete ui;
}
