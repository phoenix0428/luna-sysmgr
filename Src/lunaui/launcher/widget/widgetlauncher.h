#ifndef WIDGETLAUNCHER_H
#define WIDGETLAUNCHER_H

#include <QGraphicsView>
#include <QWidget>

class WidgetLaunchBar;

class WidgetLauncher : public QGraphicsView
{
	Q_OBJECT

public:
	WidgetLauncher(QWidget *parent = 0);

protected:
	void resizeEvent(QResizeEvent *event);

private:
	WidgetLaunchBar *m_pBar;
};

#endif // WIDGETLAUNCHER_H
