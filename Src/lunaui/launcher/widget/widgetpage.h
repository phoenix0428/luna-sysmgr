#ifndef WIDGETPAGE_H
#define WIDGETPAGE_H

#include "widgetitem.h"

#include <QGraphicsObject>

class WidgetPage : public QGraphicsObject
{
    Q_OBJECT

public:
    WidgetPage(const QRectF &bounds, QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void addItem(WidgetItem *item);

private:
    QList<WidgetItem *> m_items;
    QRectF m_bounds;
};

#endif // WIDGETPAGE_H
