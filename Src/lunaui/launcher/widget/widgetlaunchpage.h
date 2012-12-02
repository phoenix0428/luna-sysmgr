#ifndef WIDGETLAUNCHPAGE_H_
#define WIDGETLAUNCHPAGE_H_

#include "widgetitem.h"

#include <QGraphicsObject>
#include <QVector>

class WidgetLaunchPage : public QGraphicsObject
{
public:
	WidgetLaunchPage(const QSize &size, QGraphicsObject *parent = 0);
	virtual ~WidgetLaunchPage();

private:
	QVector<WidgetItem *> m_items;
};

#endif /* WIDGETLAUNCHPAGE_H_ */

