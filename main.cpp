#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //light mode definition
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white);
    palette.setColor(QPalette::WindowText, Qt::black);  // Text color
    palette.setColor(QPalette::Base, Qt::white);  // Text box background color
    palette.setColor(QPalette::AlternateBase, Qt::lightGray); // Alternative base color
    palette.setColor(QPalette::ToolTipBase, Qt::white);  // Tool tip background
    palette.setColor(QPalette::ToolTipText, Qt::black);  // Tool tip text color
    palette.setColor(QPalette::ButtonText, Qt::black);
    palette.setColor(QPalette::Button, Qt::lightGray);
    a.setPalette(palette);

    MainWindow w;
    w.show();
    return a.exec();
}
