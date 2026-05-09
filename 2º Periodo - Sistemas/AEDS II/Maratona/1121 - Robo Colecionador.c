#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, S,contador = 0;
    while (scanf('%d %d %d', &N, &M, &S) != (N == 0 && M == 0 && S == 0))
    {
        scanf("%d %d %d", &N, &M, &S);
        int VET[N][M];
        int instrucoes[S];
        int posIni = VET[0][0];
        int frente = 0;
        contador = 0;
        for (int i = 0; i < S; i++){
            scanf("%c",instrucoes[i]);
        }
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if(instrucoes[i] == 'E') frente = (frente + 3) % 4;
                if(instrucoes[i] == 'D') frente = (frente + 1) % 4;
                if(frente == 0 && instrucoes[i] == 'F') VET[i+1][j]; //N
                if(frente == 1 && instrucoes[i] == 'F') VET[i][j+1]; //L
                if(frente == 2 && instrucoes[i] == 'F') VET[i-1][j]; //S
                if(frente == 3 && instrucoes[i] == 'F') VET[i][j-1]; //O
                if(instrucoes[i] == '*') contador++;
                if((instrucoes[i] == '#' && frente == 0)) VET[i-1][j];
                if((instrucoes[i] == '#' && frente == 2)) VET[i+1][j];
                if((instrucoes[i] == '#' && frente == 1)) VET[i][j-1];
                if((instrucoes[i] == '#' && frente == 3)) VET[i][j+1];
            }
        }
        printf("%d\n",contador);
    }
    return 0;
}

#include <stdio.h>

int main() {
    int N, M, S;
    while (scanf("%d %d %d", &N, &M, &S) && (N != 0)) {
        char mapa[105][105];
        char comandos[50005];
        int x, y, dir; // dir: 0=N, 1=L, 2=S, 3=O

        for (int i = 0; i < N; i++) {
            scanf("%s", mapa[i]);
            for (int j = 0; j < M; j++) {
                // Encontra a posição inicial e direção do robô
                if (mapa[i][j] == 'N') { x = i; y = j; dir = 0; }
                else if (mapa[i][j] == 'L') { x = i; y = j; dir = 1; }
                else if (mapa[i][j] == 'S') { x = i; y = j; dir = 2; }
                else if (mapa[i][j] == 'O') { x = i; y = j; dir = 3; }
            }
        }
        scanf("%s", comandos);

        int figurinhas = 0;
        for (int i = 0; i < S; i++) {
            if (comandos[i] == 'D') dir = (dir + 1) % 4;
            else if (comandos[i] == 'E') dir = (dir + 3) % 4;
            else {
                // Tenta mover para frente
                int nx = x, ny = y;
                if (dir == 0) nx--;      // Norte sobe (linha diminui)
                else if (dir == 1) ny++; // Leste (coluna aumenta)
                else if (dir == 2) nx++; // Sul (linha aumenta)
                else if (dir == 3) ny--; // Oeste (coluna diminui)

                // Verifica se está dentro do mapa e não é parede
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && mapa[nx][ny] != '#') {
                    x = nx; y = ny;
                    if (mapa[x][y] == '*') {
                        figurinhas++;
                        mapa[x][y] = '.'; // Coleta a figurinha
                    }
                }
            }
        }
        printf("%d\n", figurinhas);
    }
    return 0;
}