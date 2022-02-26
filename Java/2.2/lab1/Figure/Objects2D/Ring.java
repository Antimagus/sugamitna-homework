package Figure.Objects2D;
import static java.lang.Math.PI;

import Figure.Figure;

public class Ring implements Figure {
    private double r;

    private double R;

    public double calcArea() {
        return PI * R * R - PI * r * r;
    }

    public double calcPerimeter() {
        return 2 * PI * r + 2 * PI * R;
    }

    public double getSmallRadius() {
        return r;
    }

    public double getBigRadius() {
        return R;
    }

    public Ring(double r, double R) throws Exception {
        if (r > 0 && R > 0 && r != R) {
            if (r > R) {
                this.r = R;
                this.R = r;
            } else {
                this.r = r;
                this.R = R;
            }
        } else
            throw new Exception("Error creating ring");
    }
}
