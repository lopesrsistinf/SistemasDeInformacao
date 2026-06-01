#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<int> V;
    int nc, n, k, p;
    cin >> nc;
    for(int i = 0; i < nc; i++){
        cin >> n >> k;
        for(int j = 0; j < n; j++){
            V.push_back(j+1);
        }
        p = 0;
        while(V.size() > 1){
            p = p + (k - 1);
            p = p % V.size();
            V.erase(V.begin() + p);
        }
        cout << "Case " << i+1 << ": "<< V[0] << endl;
        V.clear();
    }
    return 0;
}
