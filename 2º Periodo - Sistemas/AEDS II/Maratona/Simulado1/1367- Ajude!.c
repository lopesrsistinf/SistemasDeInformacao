#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int resolvidos = 0;
        int tempo_total = 0;
        int penalidades[26] = {0};
        int ja_resolvido[26] = {0};

        for (int i = 0; i < n; i++) {
            char id;
            int tempo;
            char julgamento[20];
            
            scanf(" %c %d %s", &id, &tempo, julgamento);
            int idx = id - 'A';
            if (ja_resolvido[idx]) {
                continue;
            }

            if (strcmp(julgamento, "correct") == 0) {

                ja_resolvido[idx] = 1;
                resolvidos++;
                tempo_total += tempo + (penalidades[idx] * 20);
            } else {
                penalidades[idx]++;
            }
        }
        printf("%d %d\n", resolvidos, tempo_total);
    }
    return 0;
}