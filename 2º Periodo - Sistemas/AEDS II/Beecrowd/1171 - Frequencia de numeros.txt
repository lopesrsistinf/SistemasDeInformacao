#include <stdio.h>
#include <stdlib.h>

void FrequenciaNumeros(int n){
    int V[2010],i,valor;
    for(i = 0; i <= 2000; i++) V[i] = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &valor);
        V[valor]++;
    }
    for (i = 1; i <= 2000; i++) {
        if (V[i] > 0) {
            printf("%d aparece %d vez(es)\n", i, V[i]);
        }
    }
}

int main(){
    int n,X[2010],valor;
    if (scanf("%d",&n) != EOF){
        FrequenciaNumeros(n);
    };
    return 0;
}