import java.util.Scanner;

public class Hello{
        public static void main(String[] args){
 		Scanner e = new Scanner(System.in);   
		String nome = "Maria da Silva";
		System.out.printf("Nome = %s \n",nome);
		nome = e.nextLine();
		System.out.printf("Nome = %s \n",nome);
}
}
