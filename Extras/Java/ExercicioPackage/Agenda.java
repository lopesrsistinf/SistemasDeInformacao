class Pessoa{
    private String nome;
    private int idade;
    private float altura;

    public Pessoa(String nome, int idade, float altura){
        this.nome = nome;
        this.idade = idade;
        this.altura = altura;
    }

    public String getNome() {return nome;}
    public void setNome(String nome) {this.nome = nome;}
    public int getIdade(){ return idade;}
    public void setIdade(int idade) { this.idade = idade;}
    public float getAltura() { return altura;}
    public void setAltura(float altura) { this.altura = altura;}

}

public class Agenda{
    private Pessoa[] pessoas;

    public Agenda(){
        pessoas = new Pessoa[10];
    }

    public void armazenaPessoa(String nome, int idade, float altura) {
        for (int i = 0; i < pessoas.length; i++) {
            if (pessoas[i] == null) {
                pessoas[i] = new Pessoa(nome, idade, altura);
                return;
            }
        }
    }

    public void removePessoa(String nome) {
        for (int i = 0; i < pessoas.length; i++) {
            if (pessoas[i] != null && pessoas[i].getNome().equalsIgnoreCase(nome)) {
                pessoas[i] = null;
                return;
            }
        }
    }

    public int buscaPessoa(String nome) {
        for (int i = 0; i < pessoas.length; i++) {
            if (pessoas[i] != null && pessoas[i].getNome().equalsIgnoreCase(nome)) {
                return i;
            }
        }
        return -1;
    }

    public void imprimeAgenda() {
        System.out.println("\n--- Dados da Agenda ---");
        boolean agendaVazia = true;
        for (int i = 0; i < pessoas.length; i++) {
            if (pessoas[i] != null) {
                System.out.println("Posição " + i + " : " + pessoas[i].toString());
                agendaVazia = false;
            }
        }
        if (agendaVazia) {
            System.out.println("A agenda está vazia.");
        }
        System.out.println("-----------------------\n");
    }

    public void imprimePessoa(int index) {
        if (index >= 0 && index < pessoas.length) {
            if (pessoas[index] != null) {
                System.out.println("Dados na posição " + index + ": " + pessoas[index].toString());
            } else {
                System.out.println("A posição " + index + " está vazia no momento.");
            }
        } else {
            System.out.println("Indice inválido. Escolha um valor entre 0 e 9.");
        }
    }

    public static void main(String[] args) {
        Agenda minhaAgenda = new Agenda();

        minhaAgenda.armazenaPessoa("Ana", 25, 1.65f);
        minhaAgenda.armazenaPessoa("Carlos", 30, 1.80f);
        
        minhaAgenda.imprimeAgenda();
        
        int posicao = minhaAgenda.buscaPessoa("Carlos");
        System.out.println("Carlos está na posição: " + posicao);
        
        minhaAgenda.imprimePessoa(posicao);
        
        minhaAgenda.removePessoa("Ana");
        minhaAgenda.imprimeAgenda();
    }
}