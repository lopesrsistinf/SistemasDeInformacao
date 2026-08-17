import java.util.Scanner;

public class Soma{
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        int A,B,C;
        System.out.printf("Digite o primeiro numero a ser somado: ");
        A = ler.nextInt();
        System.out.printf("Digite o segundo numero a ser somado: ");
        B = ler.nextInt();
        C = A + B;
        System.out.printf("O resultado da soma eh: %d \n",C);
    }
}

