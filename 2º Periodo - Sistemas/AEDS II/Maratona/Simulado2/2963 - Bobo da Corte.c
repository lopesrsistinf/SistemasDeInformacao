#include <stdio.h>
#include <stdlib.h>

int main(){
    int N,V,maior = 0;
    scanf("%d",&N);
    int votos[N];
    for(int i = 0; i < N; i++){
        scanf("%d",&V);
        votos[i] = V;
    }
    maior = votos[0];
    for(int i = 0; i< N;i++){
        if(votos[i] > maior) maior = votos[i];
    }
    if(maior == votos[0]){
        printf("S\n");
    } else {
        printf("N\n");
    }
    return 0;
}