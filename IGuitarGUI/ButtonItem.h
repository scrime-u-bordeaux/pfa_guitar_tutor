#ifndef BUTTONITEM_H
#define BUTTONITEM_H

#include <QGraphicsPixmapItem>
#include <QtGui>

/**
 * @brief Classe permettant d'imiter le comportement d'un bouton à partir d'un QGraphicsObject
 *
 *  Contient un Pixmap pour représenter le bouton.
 *  La classe QGraphics Object permet a la classe d'envoyer des signaux
 */
class ButtonItem : public QGraphicsObject
{
Q_OBJECT
public:
    ButtonItem(const QPixmap & pixmap, QGraphicsItem * parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *widget = 0);

    void changeImage(QPixmap&);
signals:
    void pushed(); //!< Signal émis lors d'un clic sur le bouton
private:
    QGraphicsPixmapItem* m_image;
};

#endif // BUTTONITEM_H
