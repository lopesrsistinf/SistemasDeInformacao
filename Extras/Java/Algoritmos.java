import java.util.Scanner;
public class Algoritmos{
	public static int mensagem(){
		Scanner ler = new Scanner(System.in);
		int x;
		System.out.printf("==============================%n");
		System.out.printf("Forneça um valor inteiro      %n");
		System.out.printf("==============================%n");
		System.out.printf("Valor: ");
		x = ler.nextInt();
		System.out.printf("O valor digitado foi %d%n",x);
		return x;
	}
	public static int calculo(int a,int b,int c){
		int resultado;
		resultado = (a*a*a)+(5*(b*b))+1000*c;
		return resultado;
	}
	public static void main(String[] args){
		int x,y,z,r;
		x = mensagem();
		y = mensagem();
		z = mensagem();
		r = calculo(x,y,z);
		System.out.printf("Resultado = %d%n",r);
	}
}
