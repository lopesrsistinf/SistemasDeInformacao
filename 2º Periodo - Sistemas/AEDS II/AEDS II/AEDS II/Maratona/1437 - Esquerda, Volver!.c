#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    char letra[1002];
    float soma;
    while(scanf("%d",&N) && N != 0){
        int soma = 0;
        scanf("%s",letra);
        for (int i = 0; i < N; i++){
            if(letra[i] == 'E') soma = (soma + 3) % 4;
            if(letra[i] == 'D') soma = (soma + 1) % 4;
        }
        if(soma == 0) printf("N\n");
        if(soma == 1) printf("L\n");
        if(soma == 2) printf("S\n");
        if(soma == 3) printf("O\n");
    }
    return 0;
}