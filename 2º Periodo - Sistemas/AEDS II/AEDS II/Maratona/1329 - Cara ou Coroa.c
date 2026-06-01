#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, Ri = 0;
    while(scanf("%d", &n) && n != 0){
        int m = 0,j = 0;
        for(int i=0; i<n;i++){
            scanf("%d ",&Ri);
            (Ri == 0) ? m++ : j++;
        }
        n--;
        printf("Mary won %d times and John won %d times\n",m,j);
    }
    
    return 0;
}