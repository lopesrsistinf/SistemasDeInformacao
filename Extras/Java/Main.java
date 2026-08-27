public class Main {
    public static void main(String[] args) {
        Carro c = new Carro();
        Carro meucarro = new Carro("Azul","uno",150);

        Carro.cor = "Rosa";
        System.out.println(c.cor);
        System.out.println(c.modelo);
        System.out.println(Carro.VELOCIDADE_MAXIMA);
        c.acelerar(50);
        c.freiar(10);
        System.out.println(c.getVelocidadeAtual());
        
        meucarro.ligar();
        System.out.println(meucarro.cor);
        System.out.println(meucarro.modelo);
        System.out.println(meucarro.getVelocidadeAtual());
        System.out.println(meucarro.getVelocidadeMaxima());
        meucarro.acelerar(50);
        meucarro.freiar(10);
        System.out.println(meucarro.getVelocidadeAtual());
        meucarro.desligar();
    }
}

