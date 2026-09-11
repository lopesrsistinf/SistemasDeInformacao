package figuras;

public class Ponto{
    public int x;
    public int y;

    public Ponto(){
        this(0,0);
    }
    public Ponto(int x, int y){
        this.x = x;
        this.y = y;
    }
    public void mover(int x,int y){
        this.x = x;
        this.y = y;
    }
    public double distancia(Ponto d){
        return Math.sqrt((x - d.x)*(x - d.x) + (y - d.y)*(y - d.y));
    }
}