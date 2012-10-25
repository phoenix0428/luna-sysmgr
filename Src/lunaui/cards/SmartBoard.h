#ifndef SMARTBOARD_H_
#define SMARTBOARD_H_

#include "Common.h"
#include "thingpaintable.h"

class SmartBoard : public ThingPaintable
{
	Q_OBJECT
	Q_INTERFACES(QGraphicsItem)

public:

	SmartBoard(const QRectF& geometry);
	virtual ~SmartBoard();

protected:
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option=0,QWidget *widget=0);
	virtual void paintOffscreen(QPainter *painter);
	void 	paintBackground(QPainter * painter);
};

#endif

