import java.util.Scanner;

import Figure.Figure;
import Figure.Objects2D.Circle;
import Figure.Objects3D.Cylinder;

class Main {
    public static void main(String[] args) {
        Figure figure;
        Cylinder<Figure> cylinder;

        System.out.println("¬ведите радиус круга и высоту:");
        Scanner in = new Scanner(System.in);
        System.out.print("r: ");
        double r = in.nextDouble();
        System.out.print("h: ");
        double h = in.nextDouble();
        in.close();

        try {
            figure = new Circle(r);
        } catch (Exception exception) {
            System.out.println(exception.getMessage());
            return;
        }
        try {
            cylinder = new Cylinder<Figure>(figure, h);
        } catch (Exception exception) {
            System.out.println(exception.getMessage());
            return;
        }
        System.out.println("V: " + cylinder.calcVolume());
    }
}