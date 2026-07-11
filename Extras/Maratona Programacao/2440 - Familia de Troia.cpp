#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<int, map<int, int>> G;
map<int, bool> visitados;

void DFS(int no) {
    visitados[no] = true;
    for (auto it = G[no].begin(); it != G[no].end(); it++) {
        int vizinho = it->first;
        if (!visitados[vizinho]) {
            DFS(vizinho);
        }
    }
}

int main() {
    int N, M;
    if (cin >> N >> M) {
        G.clear();
        visitados.clear();
        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;
            G[x][y] = G[y][x] = 1;
        }
        int familia = 0;
        for (int i = 1; i <= N; i++) {
            if (!visitados[i]) {
                familia++;
                DFS(i);
            }
        }
        cout << familia << endl;
    }
    return 0;
}