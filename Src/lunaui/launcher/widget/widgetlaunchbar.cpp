#include "widgetlaunchbar.h"
#include "widgetitem.h"
#include "widgetpage.h"
#include "pixmapbutton.h"

#include <QPixmap>
#include <QPainter>
#include <QString>
#include <QtDebug>
#include <QPair>
#include <QPropertyAnimation>

#define PATH_TO_IMAGES       QString("")
#define FILE_TO_WIDGETBG     QString(PATH_TO_IMAGES + "images/widgetlauncher-bg.png")
#define FILE_TO_WIDGETMORE_N QString(PATH_TO_IMAGES + "images/widgetlauncher-arrow-normal.png")


static QMap<QString, QPair<QString, QString> > _map; /* <id, pixmap1, pixmap2> */
static QList<QString> _listID;


static void _initMap()
{
    /* init map */
    _map.insert(QString("com.lge.widget.hotclip"), qMakePair(QString(PATH_TO_IMAGES + "images/widget_hotclip.png"), QString(PATH_TO_IMAGES + "images/widget_hotclip.png")));
    _map.insert(QString("com.lge.widget.keyword"), qMakePair(QString(PATH_TO_IMAGES + "images/widget_keyword.png"), QString(PATH_TO_IMAGES + "images/widget_keyword.png")));
    _map.insert(QString("com.lge.widget.news"),    qMakePair(QString(PATH_TO_IMAGES + "images/widget_news.png"),    QString(PATH_TO_IMAGES + "images/widget_news.png")));
    _map.insert(QString("com.lge.widget.score"),   qMakePair(QString(PATH_TO_IMAGES + "images/widget_score.png"),   QString(PATH_TO_IMAGES + "images/widget_score.png")));
    _map.insert(QString("com.lge.widget.sns"),     qMakePair(QString(PATH_TO_IMAGES + "images/widget_SNS.png"),     QString(PATH_TO_IMAGES + "images/widget_SNS.png")));
    _map.insert(QString("com.lge.widget.stock"),   qMakePair(QString(PATH_TO_IMAGES + "images/widget_stock.png"),   QString(PATH_TO_IMAGES + "images/widget_stock.png")));
    _map.insert(QString("com.lge.widget.traffic"), qMakePair(QString(PATH_TO_IMAGES + "images/widget_traffic.png"), QString(PATH_TO_IMAGES + "images/widget_traffic.png")));
    _map.insert(QString("com.lge.widget.weather"), qMakePair(QString(PATH_TO_IMAGES + "images/widget_weather.png"), QString(PATH_TO_IMAGES + "images/widget_weather.png")));
}

static void _initList()
{
    _listID << QString("com.lge.widget.weather") << QString("com.lge.widget.stock")   << QString("com.lge.widget.keyword") << QString("com.lge.widget.score")
            << QString("com.lge.widget.sns")     << QString("com.lge.widget.hotclip") << QString("com.lge.widget.news")    << QString("com.lge.widget.traffic");
}

static QPointF _posForLocation(int column)
{
    return QPointF(-1280/2, 0) + QPointF(19, -4) + QPointF(282/2, 0) + QPointF(column * 297, 0);
}

static void _makeDummyWidgetConfig()
{
    _initMap();
    _initList();
}

WidgetLaunchBar::WidgetLaunchBar(const QRectF &bounds, QGraphicsItem *parent)
	: QGraphicsObject(parent)
    , m_qp_slideAnimationGroup(0)
{
    _makeDummyWidgetConfig();

	m_bounds = bounds;
	m_bg = new QPixmap();
    m_bg->load(FILE_TO_WIDGETBG);

    QRectF itemBound(-310/2, -146/2, 310, 145);
    //QRectF itemBound(-282/2, -124/2, 282, 124);

    WidgetPage *newPage;
    WidgetItem *newItem;
    QPixmap *pixmap; QString id;

    newPage = new WidgetPage(m_bounds, this);
    for (int i = 0; i < 4; ++i)
    {
        newItem = new WidgetItem(itemBound, newPage);
        id = _listID.at(i);
        pixmap = new QPixmap(_map[id].first);
        newItem->setPixmap1(*pixmap);
        pixmap = new QPixmap(_map[id].second);
        newItem->setPixmap2(*pixmap);
        newItem->setPos(_posForLocation(i));
        newItem->setAcceptHoverEvents(true);

        newPage->addItem(newItem);
    }
    m_pages << newPage;

    newPage = new WidgetPage(m_bounds, this);
    for (int i = 4; i < _listID.length(); ++i)
    {
        newItem = new WidgetItem(itemBound, newPage);
        id = _listID.at(i);
        pixmap = new QPixmap(_map[id].first);
        newItem->setPixmap1(*pixmap);
        pixmap = new QPixmap(_map[id].second);
        newItem->setPixmap2(*pixmap);
        newItem->setPos(_posForLocation(i % 4));
        newItem->setAcceptHoverEvents(true);

        newPage->addItem(newItem);
    }
    newPage->setPos(0, 720 / 2 + 1);
    newPage->setVisible(true);
    m_pages << newPage;
    m_currPage = m_pages[0];

    /* Button - more */
    itemBound = QRectF(-42/2, -50/2, 42, 50);
    m_moreButton = new PixmapButton(itemBound, this);
    pixmap = new QPixmap(QString(FILE_TO_WIDGETMORE_N));
    m_moreButton->setPixmap(*pixmap, *pixmap);
    m_moreButton->setPos(1280 / 2 - 42/2 - 14, 0);
    m_moreButton->setAcceptHoverEvents(true);
    connect(m_moreButton, SIGNAL(signalButtonClicked()), this, SLOT(slotMoreButtonClicked()));
}


QRectF WidgetLaunchBar::boundingRect() const
{
	return m_bounds;
}


void WidgetLaunchBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);

	if (m_bg && m_bg->width() > 0)
	{
		painter->drawPixmap(-1 * m_bg->width() / 2, -1 * m_bg->height() / 2, *m_bg);
	}
}


void WidgetLaunchBar::slotMoreButtonClicked()
{
    SlideDirection updown;

    if (m_pages.indexOf(m_currPage) == 0)
    {
        updown = SlideUp;
    }
    else
        updown = SlideDown;
    slidePages(updown);
    return;

    m_currPage->setPos(0, 720);
    m_currPage->setVisible(false);

    int index = m_pages.indexOf(m_currPage);
    m_currPage = m_pages[++index % 2];
    m_currPage->setPos(0, 0);
    m_currPage->setVisible(true);
}


void WidgetLaunchBar::slidePages(SlideDirection updown)
{
    if (!m_qp_slideAnimationGroup.isNull())
    {
        if (m_qp_slideAnimationGroup->state() != QAbstractAnimation::Stopped)
            m_qp_slideAnimationGroup->stop();

        delete m_qp_slideAnimationGroup;
    }
    m_qp_slideAnimationGroup = new QParallelAnimationGroup(this);

    QPropertyAnimation *anim;
    QPointF posEnd;
    //float opaEnd;
    if (updown == SlideUp)
    {
        anim = new QPropertyAnimation(m_pages[0], "pos");
        posEnd.setX(0);
        posEnd.setY(m_pages[0]->y() - m_pages[0]->boundingRect().height());
        anim->setEndValue(posEnd);
        anim->setDuration(400);
        anim->setEasingCurve(QEasingCurve::OutCubic);
        m_qp_slideAnimationGroup->addAnimation(anim);

        anim = new QPropertyAnimation(m_pages[0], "opacity");
        anim->setEndValue(0.0);
        anim->setDuration(400);
        anim->setEasingCurve(QEasingCurve::OutCubic);
        m_qp_slideAnimationGroup->addAnimation(anim);

        anim = new QPropertyAnimation(m_pages[1], "pos");
        posEnd.setY(0);
        anim->setEndValue(posEnd);
        anim->setDuration(400);
        anim->setEasingCurve(QEasingCurve::OutCubic);
        m_qp_slideAnimationGroup->addAnimation(anim);

        anim = new QPropertyAnimation(m_pages[1], "opacity");
        anim->setEndValue(1.0);
        anim->setDuration(400);
        anim->setEasingCurve(QEasingCurve::OutCubic);
        m_qp_slideAnimationGroup->addAnimation(anim);

        m_pages[1]->setVisible(true);

        m_currPage = m_pages[1];
    }
    else
    {
        anim = new QPropertyAnimation(m_pages[0], "pos");
        posEnd.setX(0);
        posEnd.setY(0);
        anim->setEndValue(posEnd);
        anim->setDuration(400);
        anim->setEasingCurve(QEasingCurve::OutCubic);
        m_qp_slideAnimationGroup->addAnimation(anim);

        anim = new QPropertyAnimation(m_pages[0], "opacity");
        anim->setEndValue(1.0);
        anim->setDuration(400);
        anim->setEasingCurve(QEasingCurve::OutCubic);
        m_qp_slideAnimationGroup->addAnimation(anim);

        anim = new QPropertyAnimation(m_pages[1], "pos");
        posEnd.setY(m_bounds.height() + 1);
        anim->setEndValue(posEnd);
        anim->setDuration(400);
        anim->setEasingCurve(QEasingCurve::OutCubic);
        m_qp_slideAnimationGroup->addAnimation(anim);

        anim = new QPropertyAnimation(m_pages[1], "opacity");
        anim->setEndValue(0.0);
        anim->setDuration(400);
        anim->setEasingCurve(QEasingCurve::OutCubic);
        m_qp_slideAnimationGroup->addAnimation(anim);

        m_pages[0]->setVisible(true);

        m_currPage = m_pages[0];
    }

    if (!m_qp_slideAnimationGroup.isNull() && m_qp_slideAnimationGroup->animationCount())
    {
        connect(m_qp_slideAnimationGroup, SIGNAL(finished()), this, SLOT(slotSlideFinished()));
        m_qp_slideAnimationGroup->start(QAbstractAnimation::DeleteWhenStopped);
    }
}


void WidgetLaunchBar::slotSlideFinished()
{
    SlideDirection updown = (m_currPage == m_pages[1]) ? SlideUp: SlideDown;
    qDebug() << "updown: " << ((updown == SlideUp)?"up":"down");
    if (updown == SlideUp)
    {
        m_pages[0]->setVisible(false);
    }
    else
    {
        m_pages[1]->setVisible(false);
    }
}
