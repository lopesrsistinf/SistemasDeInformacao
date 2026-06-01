#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char mensagem[10005], crib[10005];
    int tamCrib = 0, tamMsg = 0, valorfinal = 0;
    scanf(" %s", mensagem);
    scanf(" %s", crib);
    tamCrib = strlen(crib);
    tamMsg = strlen(mensagem);
    for (int i = 0; i <= tamMsg - tamCrib; i++)
    {
        int contador = 0;
        for (int j = 0; j < tamCrib; j++)
        {
            if (mensagem[i + j] == crib[j])
            {
                contador = 1;
                break;
            }
        }
        if (contador == 0)
            valorfinal++;
    }
    printf("%d\n", valorfinal);
    return 0;
}