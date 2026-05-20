#include <stdio.h>
#include <stdlib.h>

int BuscaSequencial(int VET[], int n, int v){
    for(int i = 0; i < VET[n]; i++){
        if (VET[i] == v) return i;
    }
    return -1;
}

int BuscaBinaria(int VET[], int n, int v)
{
    int ini = 0, fim = n - 1, meio;
    while (ini <= fim)
    {
        meio = (ini + fim) / 2;
        if (VET[meio] > v)
            fim = meio - 1;
        else if (VET[meio] < v)
            ini = meio + 1;
        else
            return meio;
    }
    return -1;
}

int main(){
    int n, v, resultado,resultado2;
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&n);
    printf("Digite o valor desejado: ");
    scanf("%d",&v);
    int VET[] = {30,12,28,35,4,17,23,41,13,9,7,32,27,16,33,5};
    int VET2[] = {4,5,7,9,12,13,16,17,23,27,28,30,32,33,35,41};
    resultado = BuscaSequencial(VET,n,v);
    resultado2 = BuscaBinaria(VET2, n, v);
    printf("Posicao no vetor = %d\n",resultado);
    printf("Posicao no vetor = %d\n",resultado2);
    return 0;
}