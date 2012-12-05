#ifndef PIXMAPBUTTON_H
#define PIXMAPBUTTON_H

#include <QGraphicsObject>

class PixmapButton : public QGraphicsObject
{
    Q_OBJECT
    Q_PROPERTY(bool focus READ focus WRITE setFocus)

public:
    PixmapButton(const QRectF &bounds, QGraphicsItem *parent = 0);

    bool focus() const;
    void setFocus(bool focus);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void setPixmap(const QPixmap &pixmap_normal, const QPixmap &pixmap_over);

Q_SIGNALS:
    void signalButtonClicked();

protected:
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QPixmap m_pixmapNormal;
    QPixmap m_pixmapOver;
    bool    m_isFocused;
    QRectF  m_bounds;
};

#endif // PIXMAPBUTTON_H
