#include <QPainter>

#include "SmartBoard.h"

SmartBoard::SmartBoard(const QRectF& geometry)
        : ThingPaintable(geometry)
{
}

// virtual
SmartBoard::~SmartBoard()
{
}

//virtual
void SmartBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)
{
	paintBackground(painter);
}

//virtual
void SmartBoard::paintOffscreen(QPainter *painter)
{

}

void SmartBoard::paintBackground(QPainter * painter)
{
	//not sure if this is necessary
	QPoint sbo = painter->brushOrigin();
	painter->setBrushOrigin(m_geom.topLeft());
	painter->fillRect(m_geom, QColor(255, 0, 0, 127));
	painter->setBrushOrigin(sbo);
}

