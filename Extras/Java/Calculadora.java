import java.util.Scanner;

public class Calculadora{
    public static void calculo(){
        Scanner ler = new Scanner(System.in);
        int A,B,operacao,valor;
        do{
        System.out.printf("==============================%n");
		System.out.printf("CALCULADORA      %n");
		System.out.printf("==============================%n");
        System.out.printf("OPCOES: %n");
        System.out.printf("1 - SOMA:%n");
        System.out.printf("2 - SUBTRACAO:%n");
        System.out.printf("3 - DIVISAO:%n");
        System.out.printf("4 - MULTIPLICACAO:%n");
        System.out.printf("5 - SAIR:%n");
        System.out.printf("ESCOLHA UMA OPCAO E TECLE [ENTER]: %n");
        operacao = ler.nextInt();
        if(operacao == 5) break;
        System.out.printf("Forneca um valor: ");
        A = ler.nextInt();
        System.out.printf("Forneca um valor: ");
        B = ler.nextInt();
        switch(operacao){
            case 1:
                valor = A+B;
                System.out.printf("Resultado da soma = %d\n",valor);
                break;
            case 2:
                valor = A-B;
                System.out.printf("Resultado da subtracao = %d\n",valor);
                break;
            case 3:
                valor = A/B;
                System.out.printf("Resultado da divisao = %d\n",valor);
                break;
            case 4:
                valor = A*B;
                System.out.printf("Resultado da multiplicacao = %d\n",valor);
                break;
        }
        } while (operacao != 5);
        
        ler.close();
    }

    public static void main(String[] args){
        calculo();
    }
}