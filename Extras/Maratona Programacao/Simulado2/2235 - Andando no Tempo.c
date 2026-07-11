#include <stdio.h>
#include <stdlib.h>

int main(){
    int A,B,C;
    int presente = 0;
    scanf("%d %d %d",&A,&B,&C);
    if(A-B == 0 || A-C == 0 || C-B == 0 || A+B-C == 0 || C+B-A == 0 || A+C-B == 0)
        printf("S\n");
    else
        printf("N\n");
    return 0;
}