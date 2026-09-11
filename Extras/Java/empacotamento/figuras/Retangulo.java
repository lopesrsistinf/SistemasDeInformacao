package figuras;

public class Retangulo {
    private Ponto origem;
    private double altura;
    private double largura;
    public static int quantidade = 0;

    public Retangulo(){
        this(new Ponto(),0.0,0.0);

    }
    public Retangulo(Ponto origem, double altura,double largura){
        this.origem = origem;
        this.altura = altura;
        this.largura = largura;
    }
    public void mover(double x, double y){
        origem.mover(x,y);
    }
    public double area(){
        return altura*largura;
    }
    public void setAltura(double altura){
        this.altura = altura;
    }

    public void setAltura(double largura){
        this.largura = largura;
    }
    
}
