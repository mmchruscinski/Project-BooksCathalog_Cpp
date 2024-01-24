#ifndef DIALOG_AUTHOR_H
#define DIALOG_AUTHOR_H

#include <QDialog>

namespace Ui {
class dialog_author;
}

class dialog_author : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_author(QWidget *parent = nullptr);
    ~dialog_author();

private:
    Ui::dialog_author *ui;
};

#endif // DIALOG_AUTHOR_H
