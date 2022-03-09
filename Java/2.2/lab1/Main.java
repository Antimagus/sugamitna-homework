import java.util.Scanner;

import Figure.Figure;
import Figure.Objects2D.EquilateralTriangle;
import Figure.Objects3D.Cylinder;

class Main {
    public static void main(String[] args) {
        Figure figure;
        Cylinder<Figure> cylinder;

        System.out.println("Сторона:");
        Scanner in = new Scanner(System.in);
        System.out.print("a: ");
        double a = in.nextDouble();
        System.out.print("h: ");
        double h = in.nextDouble();
        in.close();

        try {
            figure = new EquilateralTriangle(a);
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