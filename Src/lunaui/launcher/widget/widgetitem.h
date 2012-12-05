#ifndef WIDGETITEM_H
#define WIDGETITEM_H

#include <QGraphicsObject>

class WidgetItem : public QGraphicsObject
{
	Q_OBJECT
    Q_PROPERTY(bool selected READ selected WRITE setSelected)

public:
    WidgetItem(const QRectF &bounds, QGraphicsItem *parent = 0);

    bool selected() const;
    void setSelected(bool select);

	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void setPixmap1(const QPixmap &pixmap);
    void setPixmap2(const QPixmap &pixmap);

protected:
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private:
    QPixmap m_pixmap1;
    QPixmap m_pixmap2;
    QPixmap *m_selection;
    bool    m_isSelected;
    QRectF  m_bounds;
};

#endif // WIDGETITEM_H
