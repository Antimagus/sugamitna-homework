package Figure.Objects2D;
import static java.lang.Math.sqrt;

import Figure.Figure;

public class Triangle implements Figure {
    protected double a;

    protected double b;

    protected double c;

    public double calcArea() {
        double p = calcPerimeter() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    public double calcPerimeter() {
        return a + b + c;
    }

    public double getA() {
        return a;
    }

    public double getB() {
        return b;
    }

    public double getC() {
        return c;
    }

    public Triangle(double a, double b, double c) throws Exception {
        if (a > 0 && b > 0 && c > 0 && (a + b) > c && (a + c) > b && (b + c) > a) {
            this.a = a;
            this.b = b;
            this.c = c;
        } else
            throw new Exception("Error creating triangle");
    }
}
