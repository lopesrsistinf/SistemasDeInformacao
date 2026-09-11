package Figuras;

public class retangulo {
    private ponto origem;
    private double altura;
    private double largura;
    public static int quantidade = 0;

    public retangulo() {
        this(new ponto(), 0.0, 0.0);
    }

    public retangulo(double altura, double largura) {
        this(new ponto(), altura, largura);
    }

    public retangulo(double x, double y, double altura, double largura) {
        this(new ponto(x, y), altura, largura);
    }

    public retangulo(ponto origem, double altura, double largura) {
        this.origem = origem;
        this.altura = altura;
        this.largura = largura;
        quantidade++;
    }

    public void mover(double x, double y) {
        origem.mover(x, y);
    }

    public double area() {
        return altura * largura;
    }
}