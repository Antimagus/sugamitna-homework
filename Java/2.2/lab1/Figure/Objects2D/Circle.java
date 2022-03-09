package Figure.Objects2D;

import static java.lang.Math.PI;

import Figure.Figure;

public class Circle implements Figure{
    private double radius;

    public double calcArea() {
        return PI * radius * radius;
    }

    public double calcPerimeter() {
        return 2 * PI * radius;
    }

    public double getRadius() {
        return radius;
    }

    public Circle(double radius) throws Exception {
        if (radius > 0) {
            this.radius = radius;
        } else
            throw new Exception("Error creating circle");
    }
}
