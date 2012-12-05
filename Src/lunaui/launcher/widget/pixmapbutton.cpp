#include "pixmapbutton.h"

#include <QPainter>
#include <QtDebug>


PixmapButton::PixmapButton(const QRectF &bounds, QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , m_isFocused(false)
    , m_bounds(bounds)
{
}


QRectF PixmapButton::boundingRect() const
{
    return m_bounds;
}


void PixmapButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if (m_pixmapNormal.isNull())
        return;

    if (focus())
    {
        painter->drawPixmap(-m_pixmapOver.width() / 2, -m_pixmapOver.height() / 2, m_pixmapOver);
    }
    else
    {
        painter->drawPixmap(-m_pixmapNormal.width() / 2, -m_pixmapNormal.height() / 2, m_pixmapNormal);
    }
}


// virtual
void PixmapButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setFocus(true);
}


// virtual
void PixmapButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setFocus(false);
}


void PixmapButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_EMIT signalButtonClicked();
}

void PixmapButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
}

bool PixmapButton::focus() const
{
    return m_isFocused;
}


void PixmapButton::setFocus(bool focus)
{
    if (focus != m_isFocused)
    {
        m_isFocused = focus;
        update();
    }
}


void PixmapButton::setPixmap(const QPixmap &pixmap_normal, const QPixmap &pixmap_over)
{
    m_pixmapNormal = pixmap_normal;
    m_pixmapOver   = pixmap_over;
}
