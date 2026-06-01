#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,fatorial = 1,soma = 0,contador = 0;
    scanf("%d",&n);
    for (int i= 1; i < n;i++){
            fatorial *= i;
            soma += fatorial;
            if (soma <= n)
                contador++;
    }
    printf("%d\n",contador); 
    return 0;
}