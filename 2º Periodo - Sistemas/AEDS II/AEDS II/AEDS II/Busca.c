#include <stdio.h>
#include <stdlib.h>

struct abb{
    int Info;
    struct abb *Esq,*Dir;
};
typedef struct abb Abb;

Abb*CriarAbb();
Abb*InserirAbb(Abb*a,int v);
void ImprimirAbb(Abb*a);
Abb*BuscaAbb(Abb*a,int v);
Abb*RetirarAbb(Abb*a,int v);

int BuscaSequencial(int VET[], int n, int v){
    for(int i = 0; i < VET[n]; i++){
        if (VET[i] == v) return i;
    }
    return -1;
}

int BuscaBinaria(int VET[], int n, int v)
{
    int ini = 0, fim = n - 1, meio;
    while (ini <= fim)
    {
        meio = (ini + fim) / 2;
        if (VET[meio] > v)
            fim = meio - 1;
        else if (VET[meio] < v)
            ini = meio + 1;
        else
            return meio;
    }
    return -1;
}
Abb*CriarAbb(){
    return NULL;
}

Abb*InserirAbb(Abb*a,int v){
    if(a==NULL){
        Abb*Novo = (Abb*)malloc(sizeof(Abb));
        Novo -> Info = v;
        Novo -> Esq = Novo -> Dir = NULL;
        return Novo;
    }
    if(v < a->Info) a -> Esq = InserirAbb(a->Esq,v);
    else if(v > a->Info) a -> Dir = InserirAbb(a->Dir,v);
    //else //Atualizar
    return a;
}

void ImprimirAbb(Abb*a){
    if (a == NULL) return;
    ImprimirAbb(a->Esq);
    printf("%d ",a->Info);
    ImprimirAbb(a->Dir);
}

Abb*BuscaAbb(Abb*a,int v){
    if(a == NULL || a->Info == v) return a;
    if(v < a->Info) return BuscaAbb(a->Esq,v);
    else return BuscaAbb(a->Dir,v);
}

Abb*RetirarAbb(Abb*a,int v){
    if (a == NULL) return NULL;
    if (v < a->Info) {
        a->Esq = RetirarAbb(a->Esq, v);
    } else if (v > a->Info) {
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
        a->Info = aux->Info;
        a->Dir = RetirarAbb(a->Dir, aux->Info);
    }
    return a;
}

int main(){
    int n, v, resultado,resultado2;
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&n);
    printf("Digite o valor desejado: ");
    scanf("%d",&v);
    int VET[] = {30,12,28,35,4,17,23,41,13,9,7,32,27,16,33,5};
    int VET2[] = {4,5,7,9,12,13,16,17,23,27,28,30,32,33,35,41};
    resultado = BuscaSequencial(VET,n,v);
    resultado2 = BuscaBinaria(VET2, n, v);
    printf("Posicao no vetor = %d\n",resultado);
    printf("Posicao no vetor = %d\n",resultado2);
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