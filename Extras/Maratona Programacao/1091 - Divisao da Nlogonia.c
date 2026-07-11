#include <stdio.h>
#include <stdlib.h>

int main()
{
    int K, N, M, X, Y;
    while (scanf("%d", &K) && K != 0)
    {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < K; i++)
        {
            scanf("%d %d", &X, &Y);
            if (X > N && Y > M)
                printf("NE\n");
            if (X < N && Y > M)
                printf("NO\n");
            if (X > N && Y < M)
                printf("SE\n");
            if (X < N && Y < M)
                printf("SO\n");
            if (X == N || Y == M)
                printf("divisa\n");
        }
    }
    return 0;
}
