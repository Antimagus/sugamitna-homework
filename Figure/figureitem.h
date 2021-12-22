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

protected:
    QPainterPath path;
    QRectF bounding;
    Figure* figure;
    FigureItem(QPoint position, QColor color);
    void updateInfo();

public:
    virtual ~FigureItem();
    virtual void scale(int i) = 0;
};

class CircleItem : public FigureItem
{
private:
    void setPaint();
public:
    CircleItem(Circle circle, QPoint position, QColor color);
    void scale(int i);
    ~CircleItem();
};

class TriangleItem : public FigureItem
{
private:
    void setPaint();
public:
    TriangleItem(Triangle triangle, QPoint position, QColor color);
    void scale(int i);
    ~TriangleItem();
};

class RingItem : public FigureItem
{
private:
    void setPaint();
public:
    RingItem(Ring ring, QPoint position, QColor color);
    void scale(int i);
    ~RingItem();
};

#endif // FIGUREITEM_H
