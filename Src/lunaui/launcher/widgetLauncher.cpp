#include "widgetLauncher.h"
#include "widgetLaunchBar.h"
#include "dimensionsglobal.h"

#include <QPointer>


QPointer<WidgetLauncher>  WidgetLauncher::s_qp_primaryInstance = 0;
QPointer<WidgetLaunchBar> WidgetLauncher::s_qp_primaryWidgetLaunchBar = 0;

// static
WidgetLauncher *WidgetLauncher::primaryInstance()
{
	return s_qp_primaryInstance;
}


WidgetLauncher::WidgetLauncher(quint32 width, quint32 height)
: Window(Window::Type_QtNativePaintWindow, width, height)
	, m_bgOpacity(1.0)
{
	if (!s_qp_primaryInstance)
	{
		s_qp_primaryInstance = this;
	}

	setFlag(ItemHasNoContents, true);

	if ((width == 0) || (height == 0))
	{
		return;
	}

	s_qp_primaryWidgetLaunchBar = new WidgetLaunchBar(DimensionsGlobal::realRectAroundRealPoint(QSize(width, height)), this);
	s_qp_primaryWidgetLaunchBar->fullInit(width, height);
	s_qp_primaryWidgetLaunchBar->setParentItem(this);
	s_qp_primaryWidgetLaunchBar->setVisible(true);
	setupProxySignals();
	m_lastResize = QSize(width, height);
}


// virtual
WidgetLauncher::~WidgetLauncher()
{
	delete s_qp_primaryWidgetLaunchBar;
}


// virtual
void WidgetLauncher::resize(int w, int h)
{
	if ((w == 0) || (h == 0))
		return;

	m_lastResize = QSize(w, h);

	bool success = false;
	if (!s_qp_primaryWidgetLaunchBar)
	{
		
	}
	else
	{
		QSize s = WidgetLaunchBar::WidgetLaunchSizeFromScreenSize(w, h);
		success = s_qp_primaryWidgetLaunchBar->resize(s);
	}
}


// virtual
QRectF WidgetLauncher::geometry() const
{
}


// virtual
int WidgetLauncher::normalHeight() const
{
}


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
