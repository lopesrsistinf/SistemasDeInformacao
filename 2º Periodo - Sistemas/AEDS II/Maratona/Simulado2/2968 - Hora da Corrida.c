#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int V,N;
    scanf("%d %d",&V,&N);
    int noventa = (int)ceil((N*V)*0.9);
    int oitenta = (int)ceil((N*V)*0.8);
    int setenta = (int)ceil((N*V)*0.7);
    int sessenta = (int)ceil((N*V)*0.6);
    int cinquenta = (int)ceil((N*V)*0.5);
    int quarenta = (int)ceil((N*V)*0.4);
    int trinta = (int)ceil((N*V)*0.3);
    int vinte = (int)ceil((N*V)*0.2);
    int dez = (int)ceil((N*V)*0.1);
    printf("%d %d %d %d %d %d %d %d %d\n",dez,vinte,trinta,quarenta,cinquenta,sessenta,setenta,oitenta,noventa);
    return 0;
}