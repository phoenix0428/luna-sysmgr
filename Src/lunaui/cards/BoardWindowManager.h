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

    ConciergeBoard *m_pConciergeBoard;
    SmartBoard *m_pSmartBoard;
};

#endif

