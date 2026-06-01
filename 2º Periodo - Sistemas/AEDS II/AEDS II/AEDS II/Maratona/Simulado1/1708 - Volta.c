#include <stdio.h>
#include <stdlib.h>

int main(){
    int X,Y,somatorio = 0,contador = 0;;
    scanf("%d %d",&X,&Y);
    while (Y>somatorio){
        somatorio += abs(Y-X);
        contador++;
    }
    printf("%d\n",contador);
    return 0;
}