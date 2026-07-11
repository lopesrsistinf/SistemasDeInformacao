#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<int, map<int, int>> G;
map<int, bool> visitados;
int total_arestas;

void DFS(int no) {
    visitados[no] = true;
    
    for (auto it = G[no].begin(); it != G[no].end(); it++) {
        int vizinho = it->first;
        if (!visitados[vizinho]) {
            total_arestas++; 
            DFS(vizinho);
        }
    }
}

int main() {
    int T; 
    if (!(cin >> T)) return 0;

    while (T--) {
        int inicio;
        cin >> inicio; 
        
        int V, A; 
        cin >> V >> A;

        G.clear();
        visitados.clear();
        total_arestas = 0;

        for (int i = 0; i < A; i++) {
            int x, y;
            cin >> x >> y;
            G[x][y] = G[y][x] = 1; 
        }
        DFS(inicio);
        int movimentos = total_arestas * 2;
        cout << movimentos << endl;
    }

    return 0;
}