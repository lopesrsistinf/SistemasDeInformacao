#include <stdio.h>
#include <stdlib.h>

struct abb{
    int Info;
    struct abb *Esq,*Dir;
};
typedef struct abb Abb;

Abb*CriarArv(){
    return NULL;
}

Abb*InserirNo(Abb*a,int v){
    if (a == NULL){
        Abb*Novo = (Abb*)malloc(sizeof(Abb));
        Novo -> Info = v;
        Novo -> Esq = Novo -> Dir = NULL;
        return Novo;
    }
    if (v < a -> Info) a->Esq = InserirNo(a->Esq,v);
    else if (v > a -> Info) a -> Dir = InserirNo(a ->Dir,v);
    return a;
}

void ImprimirNo(Abb*a){
    if (a == NULL) return;
    ImprimirNo(a -> Esq);
    printf("%d ",a->Info);
    ImprimirNo(a -> Dir);
}

Abb*BuscaNo(Abb*a,int v){
    if (a == NULL) return NULL;
    if (v == a -> Info) return a;
    if (v < a->Info) return BuscaNo(a->Esq,v);
    else return BuscaNo(a -> Dir,v);
}

Abb*ApagarNo(Abb*a,int v){
    
}


int main(){

}