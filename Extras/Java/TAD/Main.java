import tad.Pilha;
public class Main {
    public static void main(String[] args){
        Pilha f = new Pilha();
        f.inserir(1);
        f.inserir(2);
        f.inserir(3);
        f.inserir(4);
        f.imprimir();
        f.remover();
        f.imprimir();
        f.remover();
        f.remover();
        f.remover();
        f.imprimir();
        if(!f.vazia())
            System.out.println(f.getInicio());
    }
}
