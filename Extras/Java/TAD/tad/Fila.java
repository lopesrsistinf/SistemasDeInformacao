package tad;

public class Fila{
    private Bloco inicio;
    private Bloco fim;
    private int tamanho;

    public Fila(){
        inicio = fim = null;
        tamanho = 0;
    }

    public boolean vazia(){
        return inicio == null;
    }
    
    public int getInicio(){
        return inicio.dado;
    }

    public void inserir(int dado){
        Bloco novo = new Bloco(dado);
        if(vazia()) InsereNovo(novo);
        else InsereFinal(novo);
        tamanho++;
    }

    private void InsereNovo(Bloco novo){
        inicio = fim = novo; 
        System.out.println("inicio: "+inicio);
        System.out.println("fim: "+fim);
        System.out.println("novo: "+novo);
    }

    private void InsereFinal(Bloco novo){
        fim.prox = novo;
        fim = novo;
    }

    public void remover(){
        if(inicio != fim) moverInicio();
        else if(!vazia()) inicio = fim = null;
        if(tamanho > 0) tamanho--;
    }

    private void moverInicio(){
        Bloco aux = inicio;
        inicio = inicio.prox;
        aux.prox = null;
    }

    public void imprimir(){
        if(vazia()) return;
        Bloco aux = inicio;
        while(aux != null){
            System.out.printf("%d ",aux.dado);
            aux = aux.prox;
        }
    }
}