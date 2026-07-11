#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
map<int, map<int,int>> G;
map<int, bool> visitados;

void DFS(int no){
    visitados[no] = true;
    for (auto it = G[no].begin(); it != G[no].end();it++){
        if(!visitados[it->first])
            DFS(it->first);
    }
}

int main(){
    
}