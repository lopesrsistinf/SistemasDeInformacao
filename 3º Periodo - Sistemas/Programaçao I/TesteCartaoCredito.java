import java.util.Random;

public class TesteCartaoCredito {    
    public static void opCartao(int cartao, Random random, CartaoCredito[] carteira, int probabilidade) {
        int operacao;
        double valor;

        System.out.println("Prob. "+probabilidade+" OP cartao");
        operacao = random.nextInt(2);
        valor = random.nextDouble(carteira[cartao].getLimite());
        switch(operacao) {
            case 0: //debitar
                System.out.println("Operacao DEBITAR - Valor "+valor);
                carteira[cartao].debitar(valor);
                break;
            case 1: //creditar
                System.out.println("Operacao CREDITAR - Valor "+valor);
                carteira[cartao].creditar(valor);
                break;
        }
    }

    public static void opLimite(int cartao, Random random, CartaoCredito[] carteira, int probabilidade) {
        double diferenca;
        boolean tipo;

        System.out.println("Prob. "+probabilidade+" OP limite");
        diferenca = random.nextDouble(carteira[cartao].getLimite()*0.05);
        tipo = random.nextBoolean();
        System.out.println("Tipo "+tipo+" - diferenca "+diferenca);
        if(tipo == true) //aumenta
            carteira[cartao].setLimite(carteira[cartao].getLimite()+diferenca);
        else //diminui
            carteira[cartao].setLimite(carteira[cartao].getLimite()-diferenca);
    }
    public static void main(String[] args) {
        Random random = new Random();
        Random rProb = new Random(12345);
        int cartao, probabilidade;

        CartaoCredito[] carteira = new CartaoCredito[3];
        carteira[0] = new CartaoCredito("1234", "Maria", "itau", 1000);
        carteira[1] = new CartaoCredito("5678", "Maria", "BTG", 2000);
        carteira[2] = new CartaoCredito("9123", "Maria", "Nubank", 3000);

        for(int i=20; i>0; i--) {
            System.out.println("-----------------------------------");
            cartao = random.nextInt(3);
            probabilidade = rProb.nextInt(100);
            if(probabilidade > 10) { //90% das operações são de cartão
                opCartao(cartao, random, carteira, probabilidade);
            }
            else { //10% são sobre o limite
                opLimite(cartao, random, carteira, probabilidade);
            }
        }

        CartaoCredito.imprimir(carteira[0]);
        CartaoCredito.imprimir(carteira[1]);
        CartaoCredito.imprimir(carteira[2]);

    }
}