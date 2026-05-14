#include <stdio.h>
#include <stdlib.h>

int freq[231];

void OrdenaAltura(){
    int NC;
    scanf("%d",&NC);
    int hab, i, h, primeiro;    
    while(NC--){
        scanf("%d",&hab);
        for (int i = 0; i <= 230; i++) freq[i] = 0;
        for (int i = 0; i < hab; i++) {
            scanf("%d", &h);
            freq[h]++;
        }
        primeiro = 1;
        for (i = 20; i <= 230; i++) {
            while (freq[i] > 0) {
                if (!primeiro) printf(" ");
                printf("%d", i);
                primeiro = 0;
                freq[i]--;
            }
        }
        printf("\n");
    }
}

int main(){
    OrdenaAltura();
    return 0;
}