import figuras.*;

public class Main{
    public static void main(String[] args) {
        Retangulo r1 = new Retangulo(5.0, 2.0);
        Retangulo r2 = new Retangulo(3, 4, 10.0, 8.0);
        Retangulo r3 = new Retangulo();
        Ponto p1 = new Ponto();
        

        r1.mover(2,3);
        System.out.println("Area: " + r1.area());

        System.out.println("Nº de retangulos: "+Retangulo.quantidade);
    }
}