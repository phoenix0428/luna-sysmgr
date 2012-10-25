#include <QPainter>

#include "ConciergeBoard.h"

ConciergeBoard::ConciergeBoard(const QRectF& geometry)
    : ThingPaintable(geometry)
{
    
}

// virtual
ConciergeBoard::~ConciergeBoard()
{
}

//virtual
void ConciergeBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)
{
	paintBackground(painter);
}

//virtual
void ConciergeBoard::paintOffscreen(QPainter *painter)
{

}

void ConciergeBoard::paintBackground(QPainter * painter)
{
	//not sure if this is necessary
	QPoint sbo = painter->brushOrigin();
	painter->setBrushOrigin(m_geom.topLeft());
	painter->fillRect(m_geom, QColor(0, 0, 255, 127));
	painter->setBrushOrigin(sbo);
}


