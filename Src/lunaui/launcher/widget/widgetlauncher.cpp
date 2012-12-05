#include "widgetlauncher.h"
#include "widgetlaunchbar.h"

WidgetLauncher::WidgetLauncher(QWidget *parent)
: QGraphicsView(parent)
{
    QRectF geom(-1280/2, -134/2, 1280, 134);
	m_pBar = new WidgetLaunchBar(geom);
    m_pBar->setPos(0, 720/2 - 134/2);

	// Scene
	QGraphicsScene *scene = new QGraphicsScene(this);
	scene->addItem(m_pBar);
    scene->setSceneRect(QRectF(-1280/2, -720/2, 1280, 720));
    //scene->setSceneRect(scene->itemsBoundingRect());
	setScene(scene);
}


void WidgetLauncher::resizeEvent(QResizeEvent *event)
{
	QGraphicsView::resizeEvent(event);
}
