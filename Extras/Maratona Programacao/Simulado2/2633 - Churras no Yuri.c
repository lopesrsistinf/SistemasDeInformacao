#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N,D;
    char carnes[20][30],ordem[20][30];
    while(scanf("%d",&N) != EOF){
        for (int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf(" %s %d",carnes,&D);
            }
        }
        char menor = carnes[0][0];
        for (int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(carnes[i][j] < menor) menor = carnes[i][j];
                ordem[i][j] = carnes[i][j];
            }
            printf("%s",ordem);
        }

    }
}