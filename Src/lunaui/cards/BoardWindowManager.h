#ifndef BOARDWINDOWMANAGER_H_
#define BOARDWINDOWMANAGER_H_

#include "Common.h"
#include "CardWindowManager.h"
#include "ConciergeBoard.h"
#include "SmartBoard.h"

class BoardWindowManager : public CardWindowManager
{
	Q_OBJECT

public:

	BoardWindowManager(int maxWidth, int maxHeight);
	virtual ~BoardWindowManager();
	virtual void init();
	
protected:

	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

    void slideBoards();
	
    ConciergeBoard *m_pConciergeBoard;
    SmartBoard *m_pSmartBoard;
};

#endif

