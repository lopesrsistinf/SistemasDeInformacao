public class CartaoCredito{
    private final String numero;
    private final String nomeTitular;
    private final String nomeBanco;
    private double saldo;
    private double limite;

    public CartaoCredito(String numero, String nomeTitular, String nomeBanco, double limite){
        this.numero = numero;
        this.nomeTitular = nomeTitular;
        this.nomeBanco = nomeBanco;
        this.limite = limite;
        saldo = limite;
    }

    public String getNumero(){return numero;}
    public String getNomeTitular(){return nomeTitular;}
    public String getNomeBanco(){return nomeBanco;}
    public double getSaldo(){return saldo;}
    public double getLimite(){return limite;}

    public boolean debitar(double valor){
        if(valor <= saldo){
            saldo -= valor;
            return true;
        }
        return false;
    }

    public void creditar(double valor){
        if(valor <= (limite-saldo)){
            saldo += valor;
        }
    }

    public void setLimite(double novoLimite){
        double diferenca = Math.abs(novoLimite - limite);
        if ((novoLimite - limite) > 0) saldo += diferenca; 
        else saldo -= diferenca;
        limite = novoLimite;
    }

    public static void imprimir(CartaoCredito c){
        System.out.println("======================");
        System.out.println("Titular: "+c.getNomeTitular());
        System.out.println("Numero: "+c.getNumero());
        System.out.println("Banco: "+c.getNomeBanco());
        System.out.println("Saldo: "+c.getSaldo()+"\tlimite: "+c.getLimite());
    }
}