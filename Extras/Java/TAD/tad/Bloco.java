package tad;

public class Bloco{
    int dado; //visibilidade amigavel (dentro do pacote)
    Bloco prox; //todo nome de objeto guarda uma referencia

    public Bloco(){
        this(0);
    }

    public Bloco(int dado){
        this.dado = dado;
        prox = null;
    }
}