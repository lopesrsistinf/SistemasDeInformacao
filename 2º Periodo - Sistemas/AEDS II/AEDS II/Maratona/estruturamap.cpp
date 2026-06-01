#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    //Estrutura de Chave - Valor = map()
    pair<int, string> par;
    par.first = 23;
    par.second = "Joao";
    map<int, string> Nomes;
    map<int, string>::iterator iNomes;
    Nomes[1024] = "Joao de Deus";
    Nomes[3045] = "Jose Geraldo";
    Nomes[567] = "Maria Souza";
    Nomes[1043] = "Lucia Almeida";

    cout << Nomes[3045] << endl;

    if(Nomes.find(1234) == Nomes.end()) //procura ate o fim do vetor
        cout << "Nao encontrei 1234\n" << endl;

    cout << Nomes[1234] << endl;
    cout << Nomes.size() << endl << endl << endl;

    for(iNomes = Nomes.begin(); iNomes != Nomes.end(); iNomes++){
        cout << iNomes -> first << endl;
        cout << iNomes -> second << endl;
    }

    /*for(auto i = Nomes.begin(); i != Nomes.end(); i++){

    }*/

    map<int, map<int,string>> M;

    return 0;
}



