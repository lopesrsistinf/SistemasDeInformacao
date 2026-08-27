
public class Carro{
    //atributos + qual é a visibilidade deles? (encapsulamento)
    public static String cor;
    public String modelo;
    private boolean ligado;
    private int velocidadeAtual;
    public static final int VELOCIDADE_MAXIMA = 300;
    
    //construtor default
    public Carro(){
        cor = "vermelho";
        modelo = "Focus";
        ligado = false;
        velocidadeAtual = 0;
        //velocidadeMaxima = 300;
    }
    
    //sobrecarga de construtores
    
    /*public Carro(String c,String m, int vmax){
        cor = c;
        modelo = m;
        velocidadeMaxima = vmax;
    }*/

    public Carro(String cor,String modelo, int vmax){
        this.cor = cor;
        this.modelo = modelo;
        //velocidadeMaxima = vmax;
        ligado = false;
    }

    //metodos
    public int getVelocidadeMaxima(){
        return VELOCIDADE_MAXIMA;
    }

    public int getVelocidadeAtual(){
        return velocidadeAtual;
    }

    public void ligar(){
        ligado = true;
        velocidadeAtual = 0;
    }

    public void desligar(){
        ligado = false;
        velocidadeAtual = 0;
    }

    public void acelerar(int q){
        if(ligado){
            if(velocidadeAtual+q <= VELOCIDADE_MAXIMA){
            velocidadeAtual += q;
        }
        else velocidadeAtual = VELOCIDADE_MAXIMA;
        }
    }

    public void freiar(int q){
        if(velocidadeAtual-q >= 0){
            velocidadeAtual -= q;
        }
        else velocidadeAtual = VELOCIDADE_MAXIMA;
    }
}