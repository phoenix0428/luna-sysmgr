#ifndef WIDGETLAUNCHBAR_H_
#define WIDGETLAUNCHBAR_H_

#include "widgetlaunchpage.h"

#include <QGraphicsObject>

class WidgetLaunchBar : public QGraphicsObject
{
public:
	WidgetLaunchBar(const QRectF &bounds, QGraphicsObject *parent = 0);
	virtual ~WidgetLaunchBar();

	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
	
private:
	QPixmap *m_p_background;
	WidgetLaunchPage *m_p_currPage;
	QVector<WidgetLaunchPage *> m_pages;
	QRectF m_bounds;
	
};

#endif /* WIDGETLAUNCHBAR_H_ */

