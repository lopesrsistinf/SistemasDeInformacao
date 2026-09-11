import java.util.Random;

public class TesteCartaoCredito{
    public static void main(String[] args){
        CartaoCredito c = new CartaoCredito(
            "12345","Maria","Itau",1000
        );
        /*
        c.debitar(100);
        System.out.println("Saldo: "+c.getSaldo()+" limite: "+c.getLimite());
        c.setLimite(800);
        System.out.println("Saldo: "+c.getSaldo()+" limite: "+c.getLimite());
        c.setLimite(1200);
        System.out.println("Saldo: "+c.getSaldo()+" limite: "+c.getLimite());
        c.setLimite(50);
        System.out.println("Saldo: "+c.getSaldo()+" limite: "+c.getLimite());
        c.debitar(100);
        System.out.println("Saldo: "+c.getSaldo()+" limite: "+c.getLimite());
        c.setLimite(1000);
        System.out.println("Saldo: "+c.getSaldo()+" limite: "+c.getLimite());
        c.creditar(90);
        System.out.println("Saldo: "+c.getSaldo()+" limite: "+c.getLimite());
        c.creditar(10);
        System.out.println("Saldo: "+c.getSaldo()+" limite: "+c.getLimite());
        c.setLimite(2000);
        System.out.println("Saldo: "+c.getSaldo()+" limite: "+c.getLimite());
        CartaoCredito.imprimir(c);
        */
        Random random = new Random();
        Random rProb = new Random(12345);
        int cartao, probabilidade, operacao;
        double valor,diferenca;
        boolean tipo;
        CartaoCredito[] carteira = new CartaoCredito[3];
        carteira[0] = new CartaoCredito("1234","Maria","Itau",1000);
        carteira[1] = new CartaoCredito("1234","Maria","BTG",2000);
        carteira[2] = new CartaoCredito("9123","Maria","Nubanck",3000);
        for(int i=20; i>0; i--){
            cartao = random.nextInt(3);
            probabilidade = rProb.nextInt(100);
            if(probabilidade > 10){ //90% das operações sao de cartao
                operacao = random.nextInt(2);
                valor = random.nextDouble(carteira[cartao].getLimite());
                switch(operacao){
                    case 0: //debitar
                        carteira[cartao].debitar(valor);
                        break;
                    case 1: //creditar
                        carteira[cartao].creditar(valor);
                        break;
                }
            }
            else{ //10% sobre o limite
                diferenca = random.nextDouble(carteira[cartao].getLimite()*0.05);
                tipo = random.nextBoolean();
                if(tipo == true){
                    carteira[cartao].setLimite(carteira[cartao].getLimite() + diferenca);   
                }
                else{
                    carteira[cartao].setLimite(carteira[cartao].getLimite() - diferenca);
                }
            }
        }
        CartaoCredito.imprimir(carteira[0]);
        CartaoCredito.imprimir(carteira[1]);
        CartaoCredito.imprimir(carteira[2]);

    }
}