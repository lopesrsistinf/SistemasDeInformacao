#include <stdio.h>
#include <stdlib.h>

struct abb{
    int Info;
    struct abb*Esq,*Dir;
};
typedef struct abb Abb;

Abb*CriarAbb(){
    return NULL;
}

Abb*InserirAbb(Abb*a,int v){
    if (a == NULL){
        Abb*Novo = (Abb*)malloc(sizeof(Abb));
        Novo -> Info = v;
        Novo -> Esq = Novo -> Dir = NULL;
        return Novo;
    }
    if(v < a -> Info) a -> Esq = InserirAbb(a -> Esq, v);
    else if (v > a -> Info) a -> Dir = InserirAbb(a ->Dir,v);
    return a;
}

void ImprimirAbb(Abb*a){
    if(a == NULL) return;
    ImprimirAbb(a -> Esq);
    printf("%d ",a -> Info);
    ImprimirAbb(a -> Dir);
}

Abb*BuscaAbb(Abb*a,int v){
    if(a == NULL || a -> Info == v) return a;
    if(v < a->Info) return BuscaAbb(a->Esq,v);
    else return BuscaAbb(a -> Dir,v);
}

Abb*RemoverNo(Abb*a,int v){
    if(a == NULL) return NULL;
    if(v < a->Info) a -> Esq = RemoverNo(a->Esq,v);
    else if (v > a->Info) a->Dir = RemoverNo(a->Dir,v);
    else{
        if(a ->Esq == NULL){
            Abb*aux = a -> Dir;
            free(a);
            return aux;
        } else if (a ->Dir == NULL){
            Abb*aux = a -> Esq;
            free(a);
            return aux;
        }
        Abb*aux = a->Dir;
        while(aux -> Esq != NULL) aux = aux->Esq;
        a->Info = aux->Info;
        a->Dir = RemoverNo(a -> Dir, aux ->Info);
    }
    return a;
}

int main(){
    Abb*raiz = CriarAbb();
    raiz = InserirAbb(raiz,45);
    raiz = InserirAbb(raiz,20);
    raiz = InserirAbb(raiz,25);
    raiz = InserirAbb(raiz,35);
    raiz = InserirAbb(raiz,28);
    raiz = InserirAbb(raiz,50);
    raiz = InserirAbb(raiz,52);
    raiz = InserirAbb(raiz,53);
    raiz = InserirAbb(raiz,48);
    raiz = InserirAbb(raiz,47);
    raiz = InserirAbb(raiz,29);
    raiz = InserirAbb(raiz,33);
    Abb*achou = BuscaAbb(raiz,50);
    printf("%d\n\n",achou->Info);
    ImprimirAbb(raiz);
    return 0;
}