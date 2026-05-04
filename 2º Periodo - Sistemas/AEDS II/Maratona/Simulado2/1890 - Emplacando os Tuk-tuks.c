#include <stdio.h>
#include <stdlib.h>

int main(){
    int T,C,D;
    scanf("%d",&T);
    int N = T;
    while(T>0) {
        for(int i = 0; i < N; i++){
            int placas = 1;
            scanf("%d %d",&C,&D);
            for(int j = 0; j < C;j++){
                placas *= 26;
            }
            for(int k = 0; k < D;k++){
                placas *= 10;
            }
            if (C == 0 && D == 0){
                placas = 0;
            }
            printf("%d\n",placas);
            T--;
        }
    }
    return 0;
}