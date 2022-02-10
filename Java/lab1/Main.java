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

        try{
            figure = new Circle(r);
        }
        catch(Except except){
            except.show();
            return;
        }
        try{
            cylinder= new Cylinder<Figure>(figure, h);
        }
        catch(Except except){
            except.show();
            return;
        }
        System.out.println("Объем цилиндра: " + cylinder.calcVolume());
    }
}