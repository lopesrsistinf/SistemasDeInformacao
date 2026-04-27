#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------------------------------------

//Recursão:
/*
int fatorial(int n){
    if (n >=1)
        return n * fatorial(n-1);
    else 
        return 1;
}

int fibonacci(int n){
    if(n == 0 || n == 1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int fator,resultadoFatorial,fibo,resultadoFibo;
    printf("Digite o valor para fatorar: ");
    scanf("%d",&fator);
    printf("Digita o nº do elemento de fibonacci: ");
    scanf("%d",&fibo);
    resultadoFatorial = fatorial(fator);
    resultadoFibo = fibonacci(fibo);
    printf("Fatorial = %d\n",resultadoFatorial);
    printf("Elemento Fibonacci = %d\n", resultadoFibo);
    return 0;
}
*/
//-----------------------------------------------------------------------

//Ponteiro:



//-----------------------------------------------------------------------

//Lista:
/*
struct lista{
    int Info;
    struct lista *prox;
};
typedef struct lista Lista;

Lista* criarLista(){
    return NULL;
}

Lista* inserirElemento(Lista*l, int v){
    Lista* novo = (Lista*)malloc(sizeof(Lista*));
    novo -> Info = v;
    novo -> prox = l;
    return novo;
}

int comprimentoLista(Lista* l){
    int tamanho = 0;
    Lista *p;
    for (p = l; p!=NULL;p -> prox)
        tamanho++;
    return tamanho;
}

int quantidadeMaior(Lista* l, int n){
    int contador = 0;
    Lista *p;
    for(p = l;p != NULL; p-> prox)
        if(p->Info > n) contador++;
    return contador;
}

Lista* ultimo(Lista*l){
    if (l == NULL) return NULL;
    Lista *p = l;
    while(p -> prox != NULL)
        p = p->prox;
    return p;
}

Lista* buscarLista(Lista*l, int v){
    Lista *p;
    for(p = l; p != NULL;p->prox)
        if (p -> Info == v) return p;
    return NULL;
}

Lista* inserirAntes(Lista*l, int x, int v){
    Lista*p,*ant = NULL;
    for(p = l; p!= NULL; p->prox){
        if(p->Info == x) break;
        ant = p;
    }
    Lista* novo = (Lista*)malloc(sizeof(Lista*));
    novo -> Info = v;
    novo -> prox = p;
    if(ant != NULL){
        ant -> prox = novo;
        return l;
    } else {
        return novo;
    }
}

Lista* excluirLista (Lista* l,int v){
    Lista*p,*ant = NULL;
    for (p = l; p != NULL; p->prox){
        if (p->Info == v) break;
        ant = p;
    }
    if (p == NULL) return l;
    if (ant != NULL)
        ant -> prox = p->prox;
    else
        l = p ->prox;
    free(p);
    return l;
}

Lista* LiberarLista(Lista *l){
    Lista*p = l,*t;
    while(p != NULL){
        t = p->prox;
        free(p);
        p=t;
    }
    return NULL;
}
    */

//-----------------------------------------------------------------------

//Fila:

struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

struct fila{
    struct lista*primeiro;
    struct lista*ultimo;
};
typedef struct fila Fila;

Fila* criarFila(){
    Fila*novo = (Fila*)malloc(sizeof(Fila*));
    novo -> primeiro = novo -> ultimo = NULL;
    return novo;
}

//-----------------------------------------------------------------------

//Prova 1:

//1:

/* V F F V V*/

//2:
/*
n = 7
n = 5
n = 3
n = 1
n = 0
Resultado = 16*/

//3: 
/*
double SomaSerie(int n){
    double soma = 0;
    if (n <= 1) soma = 1.0;
    else {
        soma = (1.0/n) + SomaSerie(n-1);
    }
    return soma;
}*/

//4:
/*
struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

void lst_imprime(Lista*li){
    Lista*p;
    for(p = li; p!=NULL; p = p->prox){
        printf("info = %d\n", p->info);
    }
}

Lista* lst_BuscaUltima(Lista* li, int v){
    Lista*p,*ultimo = NULL;
    for(p = li; p != NULL; p = p->prox){
        if (p->prox == v) ultimo = p;
    }
    return ultimo;
}

Lista* lst_ExcluiSegundo(Lista*li){
    if (li == NULL || li->prox == NULL){
        return li;
    }
    Lista*segundo = li->prox;
    li->prox = segundo->prox;
    free(segundo);
    return li;
}*/

//5:

