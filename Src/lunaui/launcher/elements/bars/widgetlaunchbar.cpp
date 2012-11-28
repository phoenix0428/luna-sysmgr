#include "widgetlaunchbar.h"

#include <QPainter>
#include <QString>
#include <QEvent>
#include <QGesture>
#include <QGestureEvent>
#include <QPropertyAnimation>
#include <QDebug>

#include "Settings.h"


#define WIDGETLAUNCH_BG_SOLID		QString("/quicklaunch-bg-solid.png")
#define WIDGETLAUNCH_BG_TRANSLUCENT QString("/quicklaunch-bg.png")

#define LA_BUTTON_FILEPATH		QString("quicklaunch-button-launcher.png")
#define LA_BUTTON_NORMAL_LOC	QRect(0, 0, 64, 64)
#define LA_BUTTON_ACTIVE_LOC	QRect(0, 64, 64, 64)
#define MOVING_ICON_Y_OFFSET	15


WidgetLaunchBar::WidgetLaunchBar(const QRectF& geom, WidgetLauncher *p_widgetLauncherWindow)
: ThingPaintable(geom)
{
}

// virtual
WidgetLaunchBar::~WidgetLaunchBar()
{
}


//virtual
void WidgetLaunchBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	if (m_qp_currentBg)
	{
		paintBackground(painter);
	}
}


//virtual
void WidgetLaunchBar::paintOffscreen(QPainter *painter)
{
	// TODO: IMPLEMENT
}


inline void WidgetLaunchBar::paintBackground(QPainter *painter)
{
	QPoint sbo = painter->brushOrigin();
	painter->setBrushOrigin(m_geom.topLeft());
	painter->fillRect(m_geom, QBrush(*(*m_qp_currentBg)));
	painter->setBrushOrigin(sbo);
}


//virtual
bool WidgetLaunchBar::resize(const QSize& s)
{
}


//virtual
bool WidgetLaunchBar::sceneEvent(QEvent *event)
{
}


//virtual
bool WidgetLaunchBar::tapGesture(QTapGesture *tapEvent, QGestureEvent *baseGestureEvent)
{
}


