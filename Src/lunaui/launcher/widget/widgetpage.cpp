#include "widgetpage.h"
#include "widgetitem.h"


WidgetPage::WidgetPage(const QRectF &bounds, QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , m_bounds(bounds)
{
}


QRectF WidgetPage::boundingRect() const
{
    return m_bounds;
}


void WidgetPage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}


void WidgetPage::addItem(WidgetItem *item)
{
    if (item->parentItem() != this)
    {
        item->setParentItem(this);
    }

    if (m_items.indexOf(item) == -1)
        m_items << item;
}
