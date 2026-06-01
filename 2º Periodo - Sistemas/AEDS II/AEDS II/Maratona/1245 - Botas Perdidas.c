#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, E[61], D[61], M;
    char l;
    int soma;

    while (scanf("%d", &N) != EOF)
    {
        soma = 0;
        for (int i = 30; i < 61; i++)
        {
            E[i] = D[i] = 0;
        }
    
        while(N--)
        {
            scanf("%d %c", &M, &l);
            if(l == 'E') E[M]++;
            else if(l == 'D') D[M]++;
        }
        
        for (int i = 30; i < 61; i++)
        {
            if(E[i] < D[i]) 
                soma += E[i];
            else 
                soma += D[i];
        }
        
        printf("%d\n", soma);
    }
    return 0;
}