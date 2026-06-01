#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,p;
    int contador = 0;
    scanf("%d",&n);
    p=1;
    do{
        p = p*2;
        if(p>n) p = p - (n+1);
        contador++;
    } while (p!=1);
    printf("%d\n",contador);
    return 0;
}