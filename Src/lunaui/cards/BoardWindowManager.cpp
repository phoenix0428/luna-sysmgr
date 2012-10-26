
#include "Common.h"
#include "BoardWindowManager.h"
#include "CardWindowManager.h"

BoardWindowManager::BoardWindowManager(int maxWidth, int maxHeight)
        : CardWindowManager(maxWidth, maxHeight)
{
    setObjectName("BoardWindowManager");

    m_pConciergeBoard = new ConciergeBoard(QRect(0, 0, maxWidth, maxHeight));
    m_pConciergeBoard->setParentItem(this);
    m_pConciergeBoard->setPos(-800, -200);
    m_pConciergeBoard->setScale(0.5);
    
    m_pSmartBoard = new SmartBoard(QRect(0, 0, maxWidth, maxHeight));
    m_pSmartBoard->setParentItem(this);
    m_pSmartBoard->setPos(200, -200);
    m_pSmartBoard->setScale(0.5);
    
}

BoardWindowManager::~BoardWindowManager()
{
}

// virtual
void BoardWindowManager::init()
{
    CardWindowManager::init();
}

// virtual
void BoardWindowManager::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    CardWindowManager::mousePressEvent(event);
}

// virtual
void BoardWindowManager::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
    CardWindowManager::mouseDoubleClickEvent(event);
}

// virtual
void BoardWindowManager::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    CardWindowManager::mouseMoveEvent(event);
    slideBoards();
}

// virtual
void BoardWindowManager::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    CardWindowManager::mouseReleaseEvent(event);
}

void BoardWindowManager::slideBoards()
{
    m_pConciergeBoard->setPos(m_activeGroupPivot - 600, -200);
    m_pSmartBoard->setPos(m_activeGroupPivot + 300, -200);
}

