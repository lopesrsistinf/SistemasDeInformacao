#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Feijoes(int n, int b){
    int ini = 0, fim = n - 1, meio, x;
    while (ini <= fim)
    {
        meio = (ini + fim) / 2;
        x = pow(n,n) - pow(meio,meio);
        if (b < x)
            fim = meio - 1;
        else if (b > x)
            ini = meio + 1;
        else
            return meio;
    }
    return -1;

}

int main(){
    int N,B;
}