#include "colordelegate.h"

colordelegate::colordelegate(QObject *parent) : QStyledItemDelegate(parent) {}

void colordelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QVariant value = index.sibling(index.row(), 5).data();
    QVariant listen = index.sibling(index.row(), 6).data();

    QColor backgroundColor;
    if (value.toInt() > 0) {
        backgroundColor = QColor(Qt::darkGreen);
    } else if (listen.toInt() > 0) {
        backgroundColor = QColor(Qt::darkYellow);
    } else {
        backgroundColor = QColor(Qt::white);
    }

    painter->fillRect(option.rect, backgroundColor);
    QStyledItemDelegate::paint(painter, option, index);
}

