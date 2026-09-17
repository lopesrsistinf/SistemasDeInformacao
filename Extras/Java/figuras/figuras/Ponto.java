package figuras;

public class Ponto {
    public double x;
    public double y;

    public Ponto() {
        this(0, 0);
    }
    
    public Ponto(double x, double y) {
        this.x = x;
        this.y = y;
    }

    void mover(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double distancia(Ponto d) {
        return Math.sqrt((x - d.x)*(x - d.x) + (y - d.y)*(y - d.y));
    }
}