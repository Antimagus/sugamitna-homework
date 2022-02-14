import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Figure figure;
        Cylinder<Figure> cylinder;

        System.out.println("Введите радиус круга и высоту:");
        Scanner in = new Scanner(System.in);
        System.out.print("Радиус: ");
        double r = in.nextDouble();
        System.out.print("Высота: ");
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
        System.out.println("Объем цилиндра: " + cylinder.calcVolume());
    }
}