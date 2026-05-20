#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Feijoes(int n, int b){
    int ini = 0, fim = n - 1, meio;
    while (ini <= fim)
    {
        meio = (ini + fim) / 2;
        if (pow((n*n)-(c-q)*2)>b)
            fim = meio - 1;
        else if (VET[meio] < v)
            ini = meio + 1;
        else
            return meio;
    }
    return -1;
}

int main(){
    int N,B;
}