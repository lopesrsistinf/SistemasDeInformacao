import Figuras.retangulo;

public class Main{
    public static void main(String[] args) {
        retangulo r1 = new retangulo(5.0, 2.0);
        retangulo r2 = new retangulo(3, 4, 10.0, 8.0);
        retangulo r3 = new retangulo();

        r1.mover(2,3);
        System.out.println("Area: "+r1.area());
        
        System.out.println("Nº de retangulo: "+retangulo.quantidade);
    }
}