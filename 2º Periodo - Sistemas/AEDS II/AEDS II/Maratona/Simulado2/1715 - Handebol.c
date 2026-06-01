#include <stdio.h>
#include <stdlib.h>

int main(){
    int N,M,contador = 0,individ = 0;
    int resultado[110][110];
    scanf("%d %d",&N,&M);
    for(int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%d",&resultado[i][j]);
        }
    }
    for(int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if(resultado[i][j] > 0) individ++;
            if(resultado[i][j] == 0) individ--;
        }
        if(individ == M) contador++;
        individ = 0;
    }
    printf("%d\n",contador);
    return 0;
}