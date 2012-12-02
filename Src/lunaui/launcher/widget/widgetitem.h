#ifndef WIDGETITEM_H_
#define WIDGETITEM_H_

#include <QGraphicsObject>

class WidgetItem : public QGraphicsObject
{
	Q_OBJECT
	Q_PROPERTY(bool focused READ focused WRITE setFocus)

public:
	WidgetItem(const QRectF &bounds, QGraphicsItem *parent=0);
	virtual ~WidgetItem();

	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

	bool focused() const;
	void setFocus(bool focus);

	void setPixmap(const QPixmap &pixmap);

	virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
	virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private:
	QPixmap *m_p_selection;
	QPixmap *m_p_pix;
	bool     m_focused;
	QRectF   m_bounds;
};

#endif /* WIDGETITEM_H_

