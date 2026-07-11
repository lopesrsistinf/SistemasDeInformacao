#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> V;
    int nc, bom = 0,mal = 0;
    string comp,nome;
    cin >> nc;
    for(int i = 0; i < nc; i++)
    {
        cin >> comp  >> nome;
        V.push_back(nome);
        if(comp == "+") bom++;
        else if(comp == "-") mal++;
    }
    sort(V.begin(),V.end());
    for(int j = 0; j < nc; j++)
    {
        cout << V[j]  << endl;
    }
    cout << "Se comportaram: " << bom << " | Nao se comportaram: " << mal << endl;
    return 0;
}
