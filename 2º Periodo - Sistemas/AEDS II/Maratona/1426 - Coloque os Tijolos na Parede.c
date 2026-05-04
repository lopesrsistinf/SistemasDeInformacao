#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m[9][9];
    if (scanf("%d", &n) != 1) return 0; 
    while(n--){
        memset(m, 0, sizeof(m));
        for(int i = 0; i < 9; i+=2){
            for(int j = 0; j <= i; j+=2){
                scanf("%d", &m[i][j]);
            }
        }
        
        for(int i = 2; i < 9; i+=2){
            for(int j = 1; j < i; j+=2){
                m[i][j] = (m[i-2][j-1] - m[i][j-1] - m[i][j+1])/2;
                m[i-1][j-1] = m[i][j-1] + m[i][j];
                m[i-1][j] = m[i][j] + m[i][j+1];
            }
        }
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j <= i; j++){
                if(j > 0) printf(" ");
                printf("%d", m[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}