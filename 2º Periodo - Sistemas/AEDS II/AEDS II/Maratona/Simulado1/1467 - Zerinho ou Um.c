#include <stdio.h>
#include <stdlib.h>

int main(){
    int A, B, C;
    while (scanf("%d %d %d", &A, &B, &C) != EOF){
        
        if (A == 0 && B == 0 && C ==0)
            printf("*\n");
        if (A == 0 && B == 0 && C ==1)
            printf("C\n");
        if (A == 0 && B == 1 && C ==0)
            printf("B\n");
        if (A == 0 && B == 1 && C ==1)
            printf("A\n");
        if (A == 1 && B == 0 && C ==0)
            printf("A\n");
        if (A == 1 && B == 0 && C ==1)
            printf("B\n");
        if (A == 1 && B == 1 && C ==0)
            printf("C\n");
        if (A == 1 && B == 1 && C ==1)
            printf("*\n");
    }
    return 0;
}