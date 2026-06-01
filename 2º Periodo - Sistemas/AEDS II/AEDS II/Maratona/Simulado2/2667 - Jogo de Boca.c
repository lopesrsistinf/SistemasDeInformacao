#include <stdio.h>
#include <stdlib.h>

int main() {
    char numero[120];
    int contador = 0;
    int resultado = 0;
    scanf("%s", numero);
    for (int i = 0; numero[i] != '\0'; i++) {
        int numeroConv = contador + (numero[i] - '0');
        resultado = (numeroConv % 3);
    }
    printf("%d\n", resultado);
    return 0;
}