#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
map<int, map<int,int>> G;
map<int, bool> visitados;
int Cont;

void DFS(int no){
    visitados[no] = true;
    Cont++;
    for (auto it = G[no].begin(); it != G[no].end();it++){
        if(!visitados[it->first])
            DFS(it->first);
    }
}

int main(){

    int E,L,x,y;
    int contador = 1;
    while(cin >> E >> L && (E!=0 || L!=0)){
        G.clear();
        visitados.clear();
        while(L--){
            cin >> x >> y;
            G[x][y] = G[y][x] = 1;
        }
        Cont = 0;
        DFS(1);
        Cont--;
        Cont *= 2;
        printf("Teste %d\n",contador++);
        if (visitados.size() == E){
            printf("normal\n\n");
        }
        else{
            printf("falha\n\n");
        }
    }

    return 0;
}