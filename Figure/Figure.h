#pragma once
#include <QGraphicsItem>
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
};

class Triangle : public Figure
{
private:
	double a;
	double b;
	double c;

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

	Triangle(double a, double b, double c);

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
