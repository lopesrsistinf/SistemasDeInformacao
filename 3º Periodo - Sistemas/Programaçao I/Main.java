public class Main {
    public static void main(String[] args) {
        Carro c = new Carro();
        Carro meucarro = new Carro("azul","uno");

        meucarro.ligar();
        System.out.println(meucarro.cor);
        System.out.println(meucarro.modelo);
        System.out.println(meucarro.getVelocidadeAtual());
        System.out.println(Carro.VELOCIDADE_MAXIMA);

        meucarro.acelerar(50);
        meucarro.freiar(10);
        System.out.println(meucarro.getVelocidadeAtual());
        meucarro.desligar();

        System.out.println(c.cor);
        System.out.println(meucarro.cor);
    }
}