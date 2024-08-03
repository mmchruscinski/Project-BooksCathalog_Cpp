#include <QStyledItemDelegate>
#include <QPainter>
#include <QApplication>
#ifndef COLORDELEGATE_H
#define COLORDELEGATE_H

class colordelegate : public QStyledItemDelegate {
public:
    colordelegate(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // COLORDELEGATE_H
