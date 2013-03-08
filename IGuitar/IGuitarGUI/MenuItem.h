#ifndef MENUITEM_H
#define MENUITEM_H

#include <QGraphicsRectItem>
#include "ButtonItem.h"
#include "Configuration.h"

class MenuItem : public QGraphicsObject
{
Q_OBJECT
public:
    explicit MenuItem(QGraphicsItem *parent = 0);

    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
signals:
    
public slots:
    void closeMenu();
    void closeGame();
private:
    int width;
    int height;
    QGraphicsRectItem * rect;
    QMap <QString, QGraphicsItem*> menuMap;
};

#endif // MENUITEM_H