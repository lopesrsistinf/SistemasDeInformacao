#include <stdio.h>
#include <stdlib.h>

int OrganizaVagoes(int l, int VAG[]){
        int contador = 0;
        for(int j = l-1; j> 0; j--){
            for(int i = 0; i < j; i++){
                if (VAG[i] > VAG[i + 1]){
                    int aux = VAG[i];
                    VAG[i] = VAG[i+1];
                    VAG[i+1] = aux;
                    contador++;
                }
            }
        }
    return contador;
}



int main(){
    int n, l, vagao,VAG[60],contador = 0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&l);
        for (int i = 0; i < l;i++){
            scanf("%d",&vagao);
            VAG[i] = vagao;
        }
        contador = OrganizaVagoes(l,VAG);
        printf("Optimal train swapping takes %d swaps.\n",contador);
    }
    return 0;
}