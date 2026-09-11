package figuras;

public class Retangulo {
    private Ponto origem;
    private double altura;
    private double largura;
    public static int quantidade = 0;

    public Retangulo() {
        this(new Ponto(), 0.0, 0.0);
    }

    public Retangulo(double altura, double largura) {
        this(new Ponto(), altura, largura);
    }

    public Retangulo(double x, double y, double altura, double largura) {
        this(new Ponto(x,y), altura, largura);
    }

    private Retangulo(Ponto origem, double altura, double largura) {
        this.origem = origem;
        this.altura = altura;
        this.largura = largura;
        quantidade++;
    }

    public void mover(double x, double y) {
        origem.mover(x, y);
    }

    public double area() {
        return altura*largura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public void setLargura(double largura) {
        this.largura = largura;
    }
}