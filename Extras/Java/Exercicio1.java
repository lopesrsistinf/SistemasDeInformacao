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
        ler.close();
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
        ler.close();
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
        ler.close();
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
        ler.close();
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
        ler.close();
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
        ler.close();
    }
}
*/

/*
public class Exercicio1{
    public static void main(String[] args){
        Scanner ler = new Scanner(System.in);
        int A,B;
        double divisao;
        System.out.printf("Digite o primeiro valor: ");
        A = ler.nextInt();
        System.out.printf("Digite o segundo valor: ");
        B = ler.nextInt();
        if(B == 0){
            System.out.printf("Digite um novo valor diferente de 0: ");
            B = ler.nextInt();
        }
        divisao = A/B;
        System.out.printf("O valor de divisao de %d por %d eh: %.2f\n",A,B,divisao);
        ler.close();
    }
}
*/

/*
public class Exercicio1{
    public static void main(String[] args){
        Scanner ler = new Scanner(System.in);
        double custoLitro,valorPosto,valorFinal;
        custoLitro = 6.13;
        System.out.printf("Digite o valor do consumo mensal do posto: ");
        valorPosto = ler.nextDouble();
        if(valorPosto <= 50000){
            valorFinal = custoLitro*1.2;
            System.out.printf("O custo do litro passa a ser %.2f\n",valorFinal);
        }
        else{
            valorFinal = custoLitro*1.12;
            System.out.printf("O custo do litro passa a ser %.2f\n",valorFinal);
        }
        ler.close();
    }
}
*/

/*
public class Exercicio1 {
    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);
        double nota1, nota2, mediaNota;
        char resp;
        
        do {
            System.out.printf("Digite o valor da primeira nota (de 0 a 10): ");
            nota1 = ler.nextDouble();
            System.out.printf("Digite o valor da segunda nota (de 0 a 10): ");
            nota2 = ler.nextDouble();
            
            if ((nota1 >= 0 && nota1 <= 10) && (nota2 >= 0 && nota2 <= 10)) {
                mediaNota = (nota1 + nota2) / 2;
                System.out.printf("A media do aluno eh: %.2f\n", mediaNota);
            } else {
                System.out.printf("Valores Invalidos\n");
            }
            
            System.out.printf("Deseja realizar um novo calculo (S/N)? ");
            resp = ler.next().toUpperCase().charAt(0);
            
        } while (resp == 'S');
        
        System.out.println("Encerrando o programa...");
        ler.close();
    }
}
*/

/*
public class Exercicio1{
    public static void main(String[] args){
        for(int i = 1; i <= 10; i++){
            System.out.printf("%d ",i);
        }
    }
}
*/

/*
public class Exercicio1{
    public static void main(String[] args){
        for(int i = 10; i > 0; i--){
            System.out.printf("%d ",i);
        }
    }
}
*/

/*
public class Exercicio1{
    public static void main(String[] args){
        for(int i = 100; i <= 110; i++){
            System.out.printf("%d ",i);
        } 
    }
}
*/

/*
public class Exercicio1{
    public static void main(String[] args){
        Scanner ler = new Scanner(System.in);
        int N;
        System.out.printf("Digite o valor de N: ");
        N = ler.nextInt();
        if(N > 0){
            for(int i = 1; i <= N; i++){
                System.out.printf("%d ",i);
            }
        }
        ler.close();
    }
}
*/

/*
public class Exercicio1{
    public static void main(String[] args){
        Scanner ler = new Scanner(System.in);
        int N;
        System.out.printf("Digite o valor de N: ");
        N = ler.nextInt();
        do{
            System.out.printf("Digite um novo valor para N: ");
            N = ler.nextInt();
        } while (N <= 0);
        for(int i = 1; i <= N; i++){
            System.out.printf("%d ",i);
        }
        ler.close();
    }
}
*/

/*
public class Exercicio1{
    public static void main(String[] args){
        for(int i = 1; i <= 10; i++) System.out.printf("8 * %d = %d\n",i,8*i);
    }
}
*/

/*
public class Exercicio1{
    public static void main(String[] args){
        Scanner ler = new Scanner(System.in);
        int N;
        System.out.printf("Digite o valor da tabuada de 1 a 10: ");
        N = ler.nextInt();
        if(N>=1 && N <=10)
            for(int i = 1; i <= 10; i++) System.out.printf("%d * %d = %d\n",N,i,N*i);
        else System.out.printf("Sabe ler nao, animal?\n");
        ler.close();
    }
}
*/

/*
public class Exercicio1{
    public static void main(String[] args){
        Scanner ler = new Scanner(System.in);
        int X,exp;
        System.out.printf("Digite o valor de X a ser calculado: ");
        X = ler.nextInt();
        exp = X + (X*X) + (X*X*X*X);
        System.out.printf("O valor da expressao eh: %d\n",exp);
        ler.close();
    }
}
*/

/*
public class Exercicio1{
    public static void main(String[] args){
        Scanner ler = new Scanner(System.in);
        int N,X,Exp = 0,termo = 1;
        System.out.printf("Digite o valor de X: ");
        X = ler.nextInt();
        System.out.printf("Digite o valor do expoente: ");
        N = ler.nextInt();
        for(int i = 1; i <= N;i++){
            termo *= X;
            Exp += termo;
            //Exp += Math.pow(X,i);
        }
        System.out.printf("O valor total da expressao eh: %d\n",Exp);
        ler.close();
    }
}
*/

/*
public class Exercicio1{
    public static void main(String[] args){
        Scanner ler = new Scanner(System.in);
        int idade;
        System.out.printf("Digite o valor da idade do nadador: ");
        idade = ler.nextInt();
        switch(idade){
            case 5:
            case 6:
            case 7:
                System.out.printf("Categoria: Infantil A.\n");
                break;
            case 8:
            case 9:
            case 10:
                System.out.printf("Categoria: Infantil B.\n");
                break;
            case 11:
            case 12:
            case 13:
                System.out.printf("Categoria: Juvenil A.\n");
                break;
            case 14:
            case 15:
            case 16:
            case 17:
                System.out.printf("Categoria: Juvenil B.\n");
                break;
            default:
                if (idade >= 18) System.out.printf("Categoria: Senior.\n");
                else System.out.printf("Idade baixa para competir.\n");
                break;
        }
        ler.close();
    }
}
*/
