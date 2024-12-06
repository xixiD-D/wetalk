//
// Created by 29697 on 24-12-4.
//

#include "ListItemBase.h"

#include <QPainter>
#include <QStyleOption>

ListItemBase::ListItemBase(QWidget *parent) : QWidget(parent) {
}

void ListItemBase::SetItemType(ListItemType itemType) {
    _itemType = itemType;
}

ListItemType ListItemBase::GetItemType() {
    return _itemType;
}

void ListItemBase::paintEvent(QPaintEvent *event) {
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}