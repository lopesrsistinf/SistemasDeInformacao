#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBusca.h"

struct abb {
    steam_games_2026 Jogo; 
    struct abb *Esq, *Dir;
};

Abb* CriarAbb(){
    return NULL;
}

Abb* InserirAbb(Abb* a, steam_games_2026 NovoJogo){
    if(a == NULL){
        Abb* Novo = (Abb*)malloc(sizeof(Abb));
        Novo->Jogo = NovoJogo;
        Novo->Esq = Novo->Dir = NULL;
        return Novo;
    }
    if(NovoJogo.AppID < a->Jogo.AppID) a->Esq = InserirAbb(a->Esq, NovoJogo);
    else if(NovoJogo.AppID > a->Jogo.AppID) a->Dir = InserirAbb(a->Dir, NovoJogo);
    return a;
}

void ImprimirAbb(Abb* a){
    if (a == NULL) return;
    ImprimirAbb(a->Esq);
    printf("%d ", a->Jogo.AppID); 
    ImprimirAbb(a->Dir);
}

Abb* BuscaAbb(Abb* a, int v, int *acessos){
    if(a == NULL) return NULL;
    (*acessos)++;
    if(a->Jogo.AppID == v) return a;
    if(v < a->Jogo.AppID) return BuscaAbb(a->Esq, v, acessos);
    else return BuscaAbb(a->Dir, v, acessos);
}

Abb* RetirarAbb(Abb* a, int v){
    if (a == NULL) return NULL;
    if (v < a->Jogo.AppID) {
        a->Esq = RetirarAbb(a->Esq, v);
    } else if (v > a->Jogo.AppID) {
        a->Dir = RetirarAbb(a->Dir, v);
    } else {
        if (a->Esq == NULL) {
            Abb* aux = a->Dir;
            free(a);
            return aux;
        }
        else if (a->Dir == NULL) {
            Abb* aux = a->Esq;
            free(a);
            return aux;
        }
        Abb* aux = a->Dir;
        while (aux->Esq != NULL) {
            aux = aux->Esq;
        }
        a->Jogo = aux->Jogo;
        a->Dir = RetirarAbb(a->Dir, aux->Jogo.AppID);
    }
    return a;
}