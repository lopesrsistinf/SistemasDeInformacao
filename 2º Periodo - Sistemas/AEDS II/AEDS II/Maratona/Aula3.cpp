#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    vector<string> Nomes;
    Nomes.push_back("Joao");
    Nomes.push_back("Paulo");
    Nomes.push_back("Maria");
    Nomes.push_back("Jose");
    Nomes.push_back("Lucia");

    cout << Nomes[0] << endl << endl;
    Nomes[1] = "Marcos";

    Nomes.insert(Nomes.begin() + 2, "Julia");

    Nomes.erase(Nomes.begin());

    Nomes.clear();

    for(int i = 0; i < Nomes.size(); i++){
        cout << Nomes[i] << endl;
    }

    return 0;
}
