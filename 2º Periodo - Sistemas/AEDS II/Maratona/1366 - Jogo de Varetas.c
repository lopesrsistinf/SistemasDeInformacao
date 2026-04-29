#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, Ci, Vi, par = 0, soma = 0;
    while (scanf("%d", &n) && n != 0)
    {
        soma = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &Ci, &Vi);
            par = Vi / 2;
            soma += par;
        }
        soma = soma / 2;
        printf("%d\n", soma);
    }
    return 0;
}