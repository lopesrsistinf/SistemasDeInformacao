#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
map<int, map<int,int>> G;
map<int, bool> visitados;

// Busca em profundidade (DFS):

void DFS(int no){
    visitados[no] = true;
    for (auto it = G[no].begin(); it != G[no].end();it++){
        if(!visitados[it->first])
            DFS(it->first);
    }
}

// Busca em largura (BFS):



int main(){
    
    G[1][2] = G[1][4] = 1;
    G[2][1] = G[2][3] = G[2][3] = 1;
    G[3][2] = G[3][4] = G[3][5] = 1;
    G[4][1] = G[4][2] = G[4][3] = 1;
    G[5][3] = 1;
    G[6][7] = 1;
    G[7][6] = 1;

    DFS(6);
    if (visitados[4]){
        printf("E possivel chegar no 6!\n");
    }
    else{
        printf("Nao e possivel chegar!\n");
    }
}