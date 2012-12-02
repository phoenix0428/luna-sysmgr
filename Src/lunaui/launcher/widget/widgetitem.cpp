#include "widgetitem.h"

#include <QtGui/QtGui>

#define WIDGETITEM_IMG_FOCUS  QString("/widget-focus.png");

WidgetItem::WidgetItem(const QRectF &bounds, QGraphicsItem *parent)
: QGraphicsObject(parent), m_bounds(bounds), m_focused(false)
{
	m_p_selection =
			new Pixmap(
					QString(GraphicsSettings::settings()->graphicsAssetBaseDirectory + WIDGETITEM_IMG_FOCUS
			);
	setAcceptHoverEvents(true);
}

//virtual
WidgetItem::~WidgetItem()
{
	delete m_p_selection; m_p_selection = null;
	delete m_p_pix; m_p_pix = null;
}


QRectF WidgetItem::boundingRect() const
{
	return m_bounds;
}


void WidgetItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);

	if (m_focused)
	{
		painter->drawPixmap(-m_p_selection.width() / 2, -m_p_selection.height() / 2, m_p_selection);
	}
	else
	{
		painter->setPen(Qt::NoPen);
		painter->setBrush(QColor(0, 0, 0, 64));
		painter->drawRect(m_bounds.translated(2, 2));
	}
	
	if (!m_p_pix.isNull())
	{
		painter->drawPixmap(-m_p_pix->width() / 2, -m_p_pix->height() / 2, *m_p_pix);
	}
}


bool WidgetItem::focused() const
{
	return m_focused;
}

void WidgetItem::setFocus(bool focus)
{
	if (focus != m_focused)
	{
		m_focused = focus;
		update();
	}
}

void WidgetItem::setPixmap(const QPixmap &pixmap)
{
	m_p_pixmap = &pixmap;
	update();
}


// virtual
void WidgetItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	setFocus(true);
}


// virtual
void WidgetItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	setFocus(false);
}


