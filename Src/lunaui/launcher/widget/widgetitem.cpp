#include "widgetitem.h"

#include <QPainter>

WidgetItem::WidgetItem(const QRectF &bounds, QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , m_isSelected(false)
{
    m_selection = new QPixmap(QString("images/widget_focus.png"));
    m_bounds = bounds;
}


QRectF WidgetItem::boundingRect() const
{
	return m_bounds;
}


void WidgetItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if (m_isSelected)
    {
        painter->drawPixmap(-m_selection->width() / 2, -m_selection->height() / 2 - 5, *m_selection);
    }

    if (!m_pixmap1.isNull())
    {
        painter->drawPixmap(-m_pixmap1.width() / 2, -m_pixmap1.height() / 2, m_pixmap1);
    }
}


// virtual
void WidgetItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setSelected(true);
}


// virtual
void WidgetItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setSelected(false);
}


bool WidgetItem::selected() const
{
    return m_isSelected;
}


void WidgetItem::setSelected(bool select)
{
    if (select != m_isSelected)
    {
        m_isSelected = select;
        update();
    }
}


void WidgetItem::setPixmap1(const QPixmap &pixmap)
{
    m_pixmap1 = pixmap;
    update();
}

void WidgetItem::setPixmap2(const QPixmap &pixmap)
{
    m_pixmap2 = pixmap;
    update();
}
