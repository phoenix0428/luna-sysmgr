#ifndef WIDGETLAUNCHBAR_H_
#define WIDGETLAUNCHBAR_H_

#include "thingpaintable.h"
#include "pixmapobject.h"
#include "widgetLauncher.h"

#include <QPointer>
#include <QSize>
#include <QPointF>
#include <QList>
#include <QParallelAnimationGroup>
#include <QTimer>

class QGesture;
class QGestureEvent;
class QTapAndHoldGesture;
class QTapGesture;
class FlickGesture;

class WidgetLaunchBar : public ThingPaintable
{
	Q_OBJECT
//	Q_INTERFACES(QGraphicsItem)

public:

	WidgetLaunchBar(const QRectF & geom, WidgetLauncher *widgetLauncherWindow);
	virtual ~WidgetLaunchBar();

	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option=0, QWidget *widget=0);
	virtual void paintOffscreen(QPainter *painter);
	inline void paintBackground(QPainter *painter);

	virtual bool resize(const QSize& s);

protected:

	virtual bool sceneEvent(QEvent *event);
	virtual bool tapGesture(QTapGesture *tapEvent, QGestureEvent *baseGestureEvent);

protected:

	QPointer<PixmapObject> m_qp_background;
	QList m_widgets;

	QTimer m_refreshTimer;
};


#endif /* not WIDGETLAUNCHBAR_H_ */

