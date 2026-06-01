#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int info;
    struct lista*prox;
};
typedef struct lista Lista;

struct fila
{
    struct lista*primeiro;
    struct lista*ultimo;
};
typedef struct fila Fila;

Fila *CriarFila();
void FilaInserir(Fila *f, int v);
int FilaVazia(Fila*f);
int FilaRetirar(Fila*f);
Fila* LiberarFila(Fila*f);

Fila*CriarFila()
{
    Fila*f;
    f = (Fila*)malloc(sizeof(Fila));
    f->primeiro = f->ultimo=NULL;
    return f;
}

void FilaInserir(Fila *f, int v)
{
    Lista*novo = (Lista*)malloc(sizeof(Lista));
    novo -> info = v;
    novo -> prox = NULL;
    if(f->ultimo!=NULL)
        f->ultimo->prox = novo;
    else
        f->primeiro = novo;
    f->ultimo = novo;
}

int FilaVazia(Fila*f)
{
    return f->primeiro == NULL;
}

int FilaRetirar(Fila*f)
{
    int v;
    Lista*t;
    if(FilaVazia(f))
    {
        printf("Fila vazia!\n");
        exit(1);
    }
    t = f->primeiro;
    v=t->info;
    f->primeiro = t->prox;
    free(t);
    if(f->primeiro==NULL)
        f->ultimo=NULL;

    return v;
}

Fila* LiberarFila(Fila*f)
{
    Lista*p = f->primeiro,*t;
    while(p!=NULL)
    {
        t = p->prox;
        free(p);
        p = t;
    }
    free(f);
    return NULL;
}

int main()
{
    Fila* f1;
    int valor;
    f1 = CriarFila();
    FilaInserir(f1, 10);
    FilaInserir(f1, 20);
    FilaInserir(f1, 30);
    valor = FilaRetirar(f1);
    printf("O valor retirado da fila foi: %d\n", valor);
    valor = FilaRetirar(f1);
    printf("O proximo valor retirado foi: %d\n", valor);
    if (!FilaVazia(f1))
        printf("A fila ainda nao esta vazia.\n");
    f1 = LiberarFila(f1);
    return 0;
}
