package Figure.Objects3D;

import Figure.Figure;
import Figure.Figure3D;

public class Cylinder <typeFigure> implements Figure3D{
    private typeFigure f;

    private double h;

    public Cylinder(typeFigure f, double h) throws Exception {
        if (h > 0) {
            this.h = h;
            this.f = f;
        } else
            throw new Exception("Error creating cylinder");
    }

    public double calcVolume() {
        return h * ((Figure) f).calcArea();
    }
}
