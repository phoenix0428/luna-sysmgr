#ifndef WIDGETLAUNCHER_H_
#define WIDGETLAUNCHER_H_

#include "widgetlaunchbar.h"
#include "Window.h"
#include "dimensionstypes.h"

class WidgetLauncher : public Window
{
	Q_OBJECT
	Q_INTERFACES(QGraphicsItem)
	Q_PROPERTY(qreal backgroundOpacity READ backgroundOpacity WRITE setBackgroundOpacity)

public:
	friend class WidgetLaunchBar;

	/* singleton instance */
	static WidgetLauncher *primaryInstance();
	
	WidgetLauncher(quint32 width, quint32 height);
	virtual ~WidgetLauncher();

	virtual void resize (int w, int h);
	virtual QRectF geometry() const;
	virtual int normalHeight() const;

	static WidgetLaunchBar *widgetLaunchBar();

	virtual void save();
	virtual void restore();

	/* property 'backgroundOpacity' */
	qreal backgroundOpacity() const { return m_bgOpacity; }
	void setBackgroundOpacity(const qreal& value);

public Q_SLOTS:

	void slotDestroyWidgetLauncher();
	void slotCreateWidgetLauncher();
	void slotRecreateWidgetLauncher();

Q_SIGNALS:

	void signalReady();
	void signalNotReady();
	
	void signalHideMe(DimensionsTypes::HideCause::Enum cause = DimensionsTypes::HideCause::None);
	void signalShowMe(DimensionsTypes::ShowCause::Enum cause = DimensionsTypes::ShowCause::None);

protected:

	void setupProxySignals();

protected:
	qreal m_bgOpacity;
	static QPointer<WidgetLauncher> s_qp_primaryInstance;
	static QPointer<WidgetLaunchBar> s_qp_primaryWidgetLaunchBar;

	QSize m_lastResize;

};

#endif /* WIDGETLAUNCHER_H_ */

