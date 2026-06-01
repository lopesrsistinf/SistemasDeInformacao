#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char risadola[60],ordem[60],inversa[60];
    scanf(" %s",risadola);
    int tamanho = strlen(risadola);
    int contador = 0,contador2 = 0;
    for(int i = 0; i < tamanho; i++){
        if(risadola[i] == 'a' || risadola[i] == 'e' || risadola[i] == 'i' || risadola[i] == 'o' || risadola[i] == 'u'){
            ordem[contador] = risadola[i];
            contador++;
        }
    }
    ordem[contador] = '\0';
    for(int i = contador-1; i >= 0; i--){
        inversa[contador2] = ordem[i];
        contador2++;
    }
    inversa[contador2] = '\0';
    if(strcmp(inversa,ordem) == 0)
        printf("S\n");
    else
        printf("N\n");
    return 0;
}