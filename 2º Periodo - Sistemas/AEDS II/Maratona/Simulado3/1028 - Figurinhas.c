#include <stdlib.h>
#include <stdio.h>

int main(){
    int N,F1,F2,troca = 0;
    scanf("%d",&N);
    while(N--){
        scanf("%d %d",&F1,&F2);
        int a,b,c = F2;
        while(c != 0){
            int temp = c;
            c = F1%c;
            F1 = temp;
        }
        int MMC = (F1*F2)/F1;
        printf("%d\n",F1);
    }
    return 0;
}