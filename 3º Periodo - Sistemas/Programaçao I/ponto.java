package Figuras;

public class ponto {
    public double x;
    public double y;

    public ponto(){
        this(0, 0);
    }

    public ponto(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public void mover(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double distancia(ponto d) {
        return Math.sqrt((x - d.x) * (x - d.x) + (y - d.y) * (y - d.y));
    }
}