#include "widgetlaunchbar.h"
#include "WidgetItem.h"

#include <QtGui/QtGui>

#define WIDGETLAUNCHBAR_IMG_BG QString("/widgetlauncher-bg.png")


static QList<WidgetItem *> makeWidgets()
{
	QList<WidgetItem *> items;
	items.
}

WidgetLaunchBar::WidgetLaunchBar(const QRectF &bounds, QGraphicsObject *parent)
: QGraphicsObject(parent), m_bounds(bounds)
{
	m_p_background =
			new QPixmap(
					QString(GraphicsSettings::settings()->graphicsAssetBaseDirectory + WIDGETLAUNCHBAR_IMG_BG
			);

	WidgetLaunchPage *page;

	page = new WidgetLaunchPage();
	page->setWidgets();
	m_pages[0] = page;

	page = new WidgetLaunchPage();
	page->setWidgets();
	m_pages[1] = page;
}


// virtual
WidgetLaunchBar::~WidgetLaunchBar()
{
}


QRectF WidgetLaunchBar::boundingRect() const
{
	return m_bounds;
}


void WidgetLaunchBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);

	if (m_p_background)
	{
		painter->drawPixmap(-m_p_background->width() / 2, -m_p_background->height() / 2, *m_p_background);
	}

}
