#ifndef WIDGETLAUNCHBAR_H
#define WIDGETLAUNCHBAR_H

#include <QGraphicsObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QParallelAnimationGroup>
#include <QPointer>

class WidgetItem;
class WidgetPage;
class PixmapButton;

class WidgetLaunchBar : public QGraphicsObject
{
	Q_OBJECT

public:
	WidgetLaunchBar(const QRectF &bounds, QGraphicsItem *parent = 0);

	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

protected:
    enum SlideDirection {
        SlideUp,
        SlideDown
    };

    void slidePages(SlideDirection updown);

private Q_SLOTS:
    void slotMoreButtonClicked();
    void slotSlideFinished();

private:

	QPixmap *m_bg;
    QList<WidgetPage *> m_pages;
    WidgetPage *m_currPage;
    PixmapButton *m_moreButton;

    QPointer<QParallelAnimationGroup> m_qp_slideAnimationGroup;

	QRectF m_bounds;
};

#endif // WIDGETLAUNCHBAR_H
