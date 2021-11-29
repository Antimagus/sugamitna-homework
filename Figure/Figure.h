#pragma once
#include <QGraphicsItem>
#include <cmath>
#include "Exception.h"
#include <QPainter>
#define _USE_MATH_DEFINES

class Figure : public QGraphicsItem
{
public:
	virtual double CalcArea() = 0;
	virtual double CalcPerimeter() = 0;
};

class Circle : public Figure
{
private:
	double r;

    QRectF boundingRect() const;
public:
	double CalcArea();
	double CalcPerimeter();
	double GetRadius();

	Circle(double r);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
};

class Triangle : public Figure
{
private:
	double a;
	double b;
	double c;

    double
    x1, y1,
    x2, y2,
    x3, y3;

    QRectF boundingRect() const;
public:
	enum side{
		A = 1,
		B = 2,
		C = 3,
	};
	double CalcArea();
	double CalcPerimeter();
	double GetSide(int number);

    Triangle(double x1, double y1, double x2, double y2, double x3, double y3);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

class Ring : public Figure
{
private:
	double r;
	double R;

    QRectF boundingRect() const;
public:
	double CalcArea();
	double CalcPerimeter();
	double GetSmallRadius();
	double GetBigRadius();

	Ring(double r, double R);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
