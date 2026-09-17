package tad;

public class Pilha {
    private Bloco topo;
    private int tamanho;

    public Pilha(){
        topo = null;
        tamanho = 0;
    }

    public boolean vazia(){
        return topo == null;
    }
    
    public int getInicio(){
        return topo.dado;
    }

    public void inserir(int dado){
        Bloco novo = new Bloco(dado);
        if(vazia()) InsereNovo(novo);
        else InsereNovo(novo);
        tamanho++;
    }

    private void InsereNovo(Bloco novo){
        topo = novo; 
        System.out.println("Topo: "+topo);
    }


    public void remover(){
        if(topo == null) moverInicio();
        if(tamanho > 0) tamanho--;
    }

    private void moverInicio(){
        Bloco aux = topo;
        topo = topo.prox;
        aux.prox = null;
    }

    public void imprimir(){
        if(vazia()) return;
        Bloco aux = topo;
        while(aux != null){
            System.out.printf("%d ",aux.dado);
            aux = aux.prox;
        }
    }
}
