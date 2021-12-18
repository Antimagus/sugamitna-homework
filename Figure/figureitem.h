#ifndef FIGUREITEM_H
#define FIGUREITEM_H

#include <QGraphicsItem>
#include "Figure.h"
#include <QPainter>
#include <QCursor>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QToolTip>
#include <QStyleOptionGraphicsItem>
class FigureItem : public QGraphicsItem
{
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QRectF boundingRect() const;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    QPointF point;
    QPointF position;
    QColor color;
    QString InfoCoor;
    QString InfoFigure;

protected:
    QPainterPath path;
    QRectF bounding;
    FigureItem(QPoint position, QColor color);
    void setInfoCoor(QPointF position);
    void setInfoFigure(Figure*);
    void updateInfo();
public:
    virtual ~FigureItem();
};

class CircleItem : public FigureItem
{
private:
    void setPaint();
public:
    Circle* circle;
    CircleItem(Circle circle, QPoint position, QColor color);
    void scalling(int i)
    {
        circle->setRadius(circle->getRadius() * i);
        setPaint();
        setInfoFigure(circle);
        updateInfo();
    }
    ~CircleItem();
};

class TriangleItem : public FigureItem
{
public:
    Triangle* triangle;
    TriangleItem(Triangle triangle, QPoint position, QColor color);
    ~TriangleItem();
};

class RingItem : public FigureItem
{
public:
    Ring* ring;
    RingItem(Ring ring, QPoint position, QColor color);
    ~RingItem();
};

#endif // FIGUREITEM_H
