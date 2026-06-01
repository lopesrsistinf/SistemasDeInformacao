#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    map<int, vector<int>> M;
    int n,m,k,v,x;
    while(cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            M[x].push_back(i+1);
        }
        while(m--)
        {
            cin >> k >> v;
            if(k > M[v].size())
                cout << 0 << endl;
            else
                cout << M[v][k-1] << endl;
        }
        M.clear();
    }
    return 0;
}