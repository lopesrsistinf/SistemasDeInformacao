#include <stdio.h>
#include <stdlib.h>

struct lista {
    int Info;
    struct lista *prox;
};
typedef struct lista Lista;

Lista* CriarLista() {
    return NULL;
}

Lista* InserirLista(Lista *l, int v) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->Info = v;
    novo->prox = l;
    return novo;
}

int ComprimentoLista(Lista *l) {
    int tamanhoLista = 0;
    Lista *p;
    for (p = l; p != NULL; p = p->prox) {
        tamanhoLista++;
    }
    return tamanhoLista;
}

int quantidadeMaior(Lista *l, int n) {
    int contador = 0;
    Lista *p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->Info > n) contador++;
    }
    return contador;
}

Lista* Ultimo(Lista *l) {
    if (l == NULL) return NULL;
    Lista *p = l;
    while (p->prox != NULL) {
        p = p->prox;
    }
    return p;
}

Lista* BuscarLista(Lista *l, int v) {
    Lista *p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->Info == v) return p;
    }
    return NULL;
}

Lista* InserirAntes(Lista* l, int v, int x) {
    Lista *p, *ant = NULL;
    for (p = l; p != NULL; p = p->prox) {
        if (p->Info == x) break;
        ant = p;
    }
    
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->Info = v;
    novo->prox = p;

    if (ant != NULL) {
        ant->prox = novo; 
        return l;
    } else {
        return novo;
    }
}

Lista* ExcluirLista(Lista *l, int v) {
    Lista *p, *ant = NULL;
    for (p = l; p != NULL; p = p->prox) {
        if (p->Info == v) break;
        ant = p;
    }

    if (p == NULL) return l;

    if (ant != NULL)
        ant->prox = p->prox;
    else
        l = p->prox;

    free(p);
    return l;
}

Lista* LiberarLista(Lista *l) {
    Lista *p = l, *t;
    while (p != NULL) {
        t = p->prox;
        free(p);
        p = t;
    }
    return NULL;
}

int main() {
    Lista *l1 = CriarLista();
    l1 = InserirLista(l1, 10);
    l1 = InserirLista(l1, 20);
    l1 = InserirLista(l1, 30);

    int qnd = quantidadeMaior(l1, 15);
    printf("Nos maiores que 15: %d\n", qnd);

    Lista *u = Ultimo(l1);
    if (u == NULL) {
        printf("Lista Vazia!\n");
    } else {
        printf("O ultimo e %d!\n", u->Info); 
    }

    l1 = LiberarLista(l1);
    return 0;
}