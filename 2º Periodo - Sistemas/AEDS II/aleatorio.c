#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct lista{
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

struct fila{
    Lista*inicio;
    Lista*fim;
};
typedef struct fila Fila;

struct pilha{
    int n;
    int vet[MAX];
};
typedef struct pilha Pilha;

Lista* criarLista(){
    return NULL;
}

Fila* criarFila(){
    Fila*f;
    f = (Fila*)malloc(sizeof(Fila*));
    f -> inicio = f -> fim = NULL;
    return f;
}

Pilha* criarPilha(){
    Pilha*p;
    p = (Pilha*)malloc(sizeof(Pilha*));
    if(p != NULL)
        p->n = 0;
    return p;
}

Lista* listaVazia(Lista*l){
    return NULL;
}

Fila* filaVazia(Fila*f){
    return f->inicio = NULL;
}

Pilha* pilhaVazia(Pilha*p){
    return p->n = 0;
}

void pilha_push(Pilha*p,int v){
    p->vet[p->n] = v;
    p->n++;
    
}

Pilha* pilha_pop(Pilha*p){
    p->n--;
    return p->vet[p->n];
}

void pilha_libera(Pilha* p){
    free(p);
}

void fila_insere(Fila*f,int v){
    
}

int fila_retira(Fila*f){

}

void fila_libera(Fila*f){

}