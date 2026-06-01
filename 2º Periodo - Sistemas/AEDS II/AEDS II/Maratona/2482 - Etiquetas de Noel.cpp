#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    map<string, string> felizNatal;
    int N,M;
    string idioma,traducao,nome;
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++){
       getline(cin,idioma);
       getline(cin,traducao);
       felizNatal[idioma] = traducao;
    }
    cin >> M;
    cin.ignore();
    for(int i = 0; i < M; i++){
        getline(cin,nome);
        getline(cin,idioma);
        cout << nome << endl;
        cout << felizNatal[idioma] << endl << endl;
    }
    return 0;
}