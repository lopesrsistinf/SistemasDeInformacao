#include <stdio.h>
#include <stdlib.h>

void InsertSort(int VET[],int n, int v){
    int i;
    for (i = n-1;i>=0; i--){
        if(VET[i] > v) VET[i+1] = VET[i];
        else break;
    }
    VET[i+1] = v;
}   

int main(){
    int n = 7;
    int v = 35;
    int VET[12] = {5,8,12,15,20,40,50};
    InsertSort(VET, n, v);
    n++;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", VET[i]);
    }
    return 0;
}