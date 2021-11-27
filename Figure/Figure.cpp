#include "Figure.h"

//______________________Figure______________________________

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

//______________________Circle______________________________

double Circle::CalcArea()
{
	return M_PI * r * r;
}

double Circle::CalcPerimeter()
{
	return 2 * M_PI * r;
}

double Circle::GetRadius()
{
	return r;
}

Circle::Circle(double r)
{
	if (r > 0) this->r = r;
	else throw Exception(1, "Error creating circle");
}

QRectF Circle::boundingRect() const
{
    return QRectF(0, 0, r, r);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(0, 0, r, r);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

//______________________Triangle______________________________

double Triangle::CalcArea()
{
	double p = CalcPerimeter() / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::CalcPerimeter()
{
	return a + b + c;
}

double Triangle::GetSide(int number)
{
	switch (number)
	{
	case 1:
	{
		return a;
	}
	case 2:
	{
		return b;
	}
	case 3:
	{
		return c;
	}
	default:
		break;
	}
	throw Exception(0, "Error select side");
}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double A = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double B = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double C = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    if (A > 0 && B > 0 && C > 0 && (A + B) > C && (A + C) > B && (B + C) > A)
	{
        this->a = A;
        this->b = B;
        this->c = C;
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
	}
	else throw Exception(1, "Error creating triangle");
}

QRectF Triangle::boundingRect() const
{
    double min = a;
    if(b < min) min = b;
    if(c < min) min = c;
    return QRectF(0, 0, min, min);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    polygon << QPoint(x1, y1) << QPoint(x2, y2) << QPoint(x3, y3);
    painter->setBrush(Qt::black);
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

//______________________Ring______________________________

double Ring::CalcArea()
{
	return M_PI * R * R - M_PI * r * r;
}

double Ring::CalcPerimeter()
{
	return 2 * M_PI * r + 2 * M_PI * R;
}

double Ring::GetSmallRadius()
{
	return r;
}
double Ring::GetBigRadius()
{
	return R;
}

Ring::Ring(double r, double R)
{
	if (r > 0 && R > 0 && r != R)
	{
		if (r > R)
		{
			this->r = R;
			this->R = r;
		}
		else
		{
			this->r = r;
			this->R = R;
		}
	}
	else throw Exception(1, "Error creating ring");
}

QRectF Ring::boundingRect() const
{
    return QRectF(0, 0, R, R);
}

void Ring::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(0, 0, R, R);
    painter->setBrush(Qt::white);
    painter->drawEllipse((R-r)/2, (R-r)/2, r, r);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
