#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int R,G,B,P;
    int T,contador = 1;
    char conversao[20];
    scanf("%d",&T);
    int N = T;
    while(T>0){
        for(int i = 0; i < N; i++){
            scanf(" %s",conversao);
            scanf("%d %d %d",&R,&G,&B);
            if(strcmp(conversao,"eye") == 0){
                P = (int)((0.30*R) + (0.59*G) + (0.11*B));
            } else if (strcmp(conversao,"mean") == 0){
                P = (int)((R+G+B)/3);
            } else if(strcmp(conversao,"min") == 0){
                int menor = R;
                if(G < menor) menor = G;
                if(B < menor) menor = B;
                P = menor;
            } else if(strcmp(conversao,"max") == 0){
                int maior = R;
                if(G > maior) maior = G;
                if(B > maior) maior = B;
                P = maior;
            }
            printf("Caso #%d: %d\n",contador,P);
            contador++;
            T--;
        }

    }
    return 0;
}