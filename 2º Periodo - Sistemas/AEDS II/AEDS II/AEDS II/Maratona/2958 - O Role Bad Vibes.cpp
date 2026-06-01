#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    reverse(V.begin(),V.end());
    vector<vector<string>> V;
    vector<vector<string>> D;
    int N,M;
    cin >> N  >> M;
    string nome;
    for(int i = 0; i < nc; i++)
    {
        cin >> nome;
        if (str[1] == "V") V.push_back(nome);
        if (str[1] == "D") D.push_back(nome);
    }
    sort(V.begin(),V.end());
    sort(D.begin(),D.end());
    for(int j = 0; j < nc; j++)
    {
        cout << V[j]  << endl;
    }
    
    return 0;
}
