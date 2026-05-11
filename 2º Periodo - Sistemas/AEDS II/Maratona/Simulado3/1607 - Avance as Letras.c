#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int T,ops = 0;
    char A[10005],B[10005];
    scanf("%d", &T);
    while(T--){
        scanf(" %s %s",A,B);
        for (int i = 0; i < strlen(A); i++){
            int diferenca = B[i] - A[i];
            if (diferenca < 0) {
                diferenca += 26;
            }
            ops += diferenca;
        }
        printf("%d\n",ops);
        ops = 0;
        
    }
    return 0;
}