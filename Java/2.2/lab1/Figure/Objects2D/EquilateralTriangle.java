package Figure.Objects2D;

public class EquilateralTriangle extends Triangle {
    public EquilateralTriangle(double a) throws Exception{
        super(a, a, a);
    }

    public double calcPerimeter() {
        return a * 3;
    }

}
