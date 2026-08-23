import java.util.Scanner;

/*
public class Exercicio1 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        int A;
        System.out.printf("Digite o valor: ");
        A = ler.nextInt();
        if (A % 2 == 0){
            System.out.printf("O valor %d eh par\n",A);
        } else {
            System.out.printf("O valor %d eh impar\n",A);
        }
    }
}
*/

/*
public class Exercicio1{
    public static void main(String[] args){
        Scanner ler = new Scanner (System.in);
        int A;
        System.out.printf("Digite o valor inteiro: ");
        A = ler.nextInt();
        if (A < 0){
            System.out.printf("O valor %d eh negativo\n",A);
        } else if (A == 0){
            System.out.printf("O valor %d eh zero\n",A);
        } else {
            System.out.printf("O valor %d eh positivo\n",A);
        }
    }
}
*/

/*
public class Exercicio1{
    public static void main (String[] args){
        Scanner ler = new Scanner (System.in);
        int A;
        System.out.printf("Digite um valor: ");
        A = ler.nextInt();
        if (A>= 0 && A <= 9){
            System.out.printf("O valor %d esta entre 0 e 9!\n",A);
        } else {
            System.out.printf("O valor %d nao esta entre 0 e 9!\n",A);
        }
    }
}
*/

/*
public class Exercicio1{
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        int A;
        System.out.printf("Digite um valor entre 100 e 999: ");
        A = ler.nextInt();
        char[] arrayChar = Integer.toString(A).toCharArray();
        for (int i = 0;i< arrayChar.length;i++){
            System.out.printf("O valor do algarismo %d eh: %s\n",i,arrayChar[i]);
        }        

    }
}
*/

/*
public class Exercicio1{
    public static void main(String[] args){
        Scanner ler = new Scanner(System.in);
        int horasNorm,horasExt;
        float salarioTotal;
        System.out.printf("Digite o total de horas normais trabalhadas: ");
        horasNorm = ler.nextInt();
        System.out.printf("Digite o total de horas extras trabalhadas: ");
        horasExt = ler.nextInt();
        salarioTotal = (horasNorm * 10) + (horasExt * 15);
        System.out.printf("O valor do seu salario anual eh de: %.2f\n",salarioTotal);
    }
}
*/

/*
public class Exercicio1{
    public static void main(String[] args){
        Scanner ler = new Scanner(System.in);
        int horasNorm,horasExt;
        double salarioTotal;
        System.out.printf("Digite o total de horas normais trabalhadas: ");
        horasNorm = ler.nextInt();
        System.out.printf("Digite o total de horas extras trabalhadas: ");
        horasExt = ler.nextInt();
        salarioTotal = (horasNorm * 10) + (horasExt * 15);
        if(salarioTotal <= 12000) salarioTotal *= 0.9;
        else salarioTotal = (salarioTotal*0.9) - (salarioTotal*0.25);
        System.out.printf("Seu salario anual com o imposto aplicado eh: %.2f\n",salarioTotal);
    }
}
*/

public class Exercicio1{
    public static void main(String[] args){
        
    }
}

