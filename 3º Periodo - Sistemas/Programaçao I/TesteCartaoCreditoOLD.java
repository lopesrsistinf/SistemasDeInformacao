public class TesteCartaoCredito {
    public static void main(String[] args) {
        CartaoCredito c = new CartaoCredito(
            "12345", "Maria", "itau", 1000
        );

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
        c.setLimite(2000);
        System.out.println("Saldo: "+c.getSaldo()+" limite: "+c.getLimite());

        CartaoCredito.imprimir(c);
    }
}