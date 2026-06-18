#include <stdio.h>
#include <stdlib.h>

void Bolha(int VET[], int n)
{
    int aux, i, j, troca = 0;
    for (j = n - 1; j > 0; j--)
    {
        troca = 0;
        for (i = 0; i < j; i++)
        {
            if (VET[i] > VET[i + 1])
            {
                troca = 1;
                aux = VET[i];
                VET[i] = VET[i + 1];
                VET[i + 1] = aux;
            }
        }
        if (!troca) break;
    }
}

int main()
{
    int n = 11;
    int VET[] = {80, 70, 20, 22, 31, 43, 13, 25, 64, 73, 19};
    Bolha(VET, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", VET[i]);
    }
    return 0;
}