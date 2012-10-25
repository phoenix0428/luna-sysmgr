#ifndef CONCIERGEBOARD_H_
#define CONCIERGEBOARD_H_

#include "Common.h"
#include "thingpaintable.h"

class ConciergeBoard : public ThingPaintable
{
	Q_OBJECT
	Q_INTERFACES(QGraphicsItem)

public:

	ConciergeBoard(const QRectF& geometry);
	virtual ~ConciergeBoard();

protected:
	virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option=0,QWidget *widget=0);
	virtual void paintOffscreen(QPainter *painter);
	void 	paintBackground(QPainter * painter);
};

#endif

