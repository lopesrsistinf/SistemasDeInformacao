#include <stdio.h>
#include <stdlib.h>

int main(){
    int h1,m1,h2,m2;
    while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2) && (h1 != 0 || m1 != 0 || h2 != 0 || m2 != 0)){
        int total1 = 0,total2 = 0, diff = 0;
        total1 = (h1*60) + m1;
        total2 = (h2*60) + m2;
        diff = total2 - total1;
        if (diff <= 0) {
            diff += 24 * 60;
        }
        printf("%d\n",diff);
    }
    return 0;
}