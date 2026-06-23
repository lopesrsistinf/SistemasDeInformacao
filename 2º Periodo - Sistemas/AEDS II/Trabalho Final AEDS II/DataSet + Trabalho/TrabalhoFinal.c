#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Estrutura Principal:
typedef struct {
    int AppID;
    char Name[150], Release_Date[12], Primary_Genre[50], All_Tags[500];
    double Price_USD, Discount_Pct, Review_Score_Pct;
    int Total_Reviews;
    char Steam_Deck_Status[30];
    int Estimated_Owners, _24h_Peak_Players;
    int Data;
} steam_games_2026;

typedef struct abb Abb;

// Protótipos da Árvore:
Abb* CriarAbb();
Abb* InserirAbb(Abb* a, steam_games_2026 NovoJogo);
void ImprimirAbb(Abb* a);
Abb* BuscaAbb(Abb* a, int v, int *acessos);
Abb* RetirarAbb(Abb* a, int v);

//Estrutura da Árvore de Busca:
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
        if(Novo == NULL) {
            printf("Erro de alocacao de memoria na arvore!\n");
            exit(1);
        }
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

steam_games_2026 SteamGames[50000];

int DataConv(int Dia, int Mes, int Ano){
    return (1461*(Ano + 4800 + (Mes - 14)/12))/4+
        (367 * (Mes - 2 - 12 * ((Mes - 14) / 12)))/12 -
        (3 * ((Ano + 4900 + (Mes - 14)/12)/100))/4 +
        Dia - 32075;
}

char * replace(char *s, char c1, char c2)
{
    int l = strlen(s);
    for (int i = 0; i < l; i++)
    {
        if (s[i] == c1)
            s[i] = c2;
    }
    return s;
}

//Função Principal para carregar o .csv:
int CarregaGames(){
    FILE *fp = fopen("steam_games_2026.csv", "r");
    if(fp == NULL){
        printf("Nao foi possivel abrir steam_games_2026.csv!\n");
        exit(1);
    }
    char Linha[10000], *p, texto[10000];
    int cont = 0, campo;
    if(fgets(Linha, sizeof(Linha), fp) == NULL) {
        fclose(fp);
        return 0;
    }
    while(fgets(Linha, sizeof(Linha), fp) != NULL){
        Linha[strcspn(Linha, "\r\n")] = 0;
        p = strtok(Linha, ",");
        campo = 0;
        while(p != NULL){
            strcpy(texto, p);
            if(texto[0] == '\"'){ 
                strcpy(texto, p+1); 
                p = strtok(NULL, ",");
                if(p != NULL) {
                    int tam = strlen(p);
                    if (p[tam - 1] == '\"') p[tam - 1] = '\0';
                    strcat(texto, ","); 
                    strcat(texto, p);
                }
            }

            if(campo == 0) SteamGames[cont].AppID = atoi(texto);
            if(campo == 1) { strncpy(SteamGames[cont].Name, texto, 149); SteamGames[cont].Name[149] = '\0'; }
            if(campo == 2) {
                strncpy(SteamGames[cont].Release_Date, texto, 11); SteamGames[cont].Release_Date[11] = '\0';
                char sdia[5], smes[5], sano[5];
                if(sscanf(texto, "%2s/%2s/%4s", sdia, smes, sano) == 3) {
                    SteamGames[cont].Data = DataConv(atoi(sdia), atoi(smes), atoi(sano));
                }
            }
            if(campo == 3) { strncpy(SteamGames[cont].Primary_Genre, texto, 49); SteamGames[cont].Primary_Genre[49] = '\0'; }
            if(campo == 4) { strncpy(SteamGames[cont].All_Tags, texto, 499); SteamGames[cont].All_Tags[499] = '\0'; }
            if(campo == 5) SteamGames[cont].Price_USD = strtof(replace(texto, ',', '.'), NULL);
            if(campo == 6) SteamGames[cont].Discount_Pct = strtof(replace(texto, ',', '.'), NULL);
            if(campo == 7) SteamGames[cont].Review_Score_Pct = strtof(replace(texto, ',', '.'), NULL);
            if(campo == 8) SteamGames[cont].Total_Reviews= atoi(texto);
            if(campo == 9) { strncpy(SteamGames[cont].Steam_Deck_Status, texto, 29); SteamGames[cont].Steam_Deck_Status[29] = '\0'; }
            if(campo == 10) SteamGames[cont].Estimated_Owners= atoi(texto);
            if(campo == 11) SteamGames[cont]._24h_Peak_Players= atoi(texto);
                
            p = strtok(NULL, ",");
            campo++;
        }
        cont++;
        if(cont >= 50000) break;
    }
    fclose(fp);
    return cont;
}

int main()
{
    srand(time(NULL));
    int Contador = CarregaGames();
    printf("%d Registros Carregados do CSV!\n\n", Contador);

    if(Contador == 0) {
        printf("Nenhum registro carregado.\n");
        return 0;
    }

    Abb* Raiz = CriarAbb();
    for(int i = 0; i < Contador; i++){
        Raiz = InserirAbb(Raiz, SteamGames[i]);
    }

    int RandAcess = 0;
    int SeqAcess = 0;
    clock_t TempIni, TempFim;
    double RandTime, SeqTime;

    // Pesquisa Aleatória
    TempIni = clock();
    for(int i = 0; i < 100; i++) {
        int RandInd = rand() % Contador;
        int ChaveBusca = SteamGames[RandInd].AppID;
        BuscaAbb(Raiz, ChaveBusca, &RandAcess);
    }
    TempFim = clock();
    RandTime = ((double)(TempFim - TempIni)) / CLOCKS_PER_SEC;

    // Pesquisa Sequencial
    int IniSeq = rand() % (Contador > 100 ? Contador - 100 : 1);
    TempIni = clock();
    for(int i = 0; i < 100; i++) {
        int ChaveBusca = SteamGames[IniSeq + i].AppID;
        BuscaAbb(Raiz, ChaveBusca, &SeqAcess);
    }
    TempFim = clock();
    SeqTime = ((double)(TempFim - TempIni)) / CLOCKS_PER_SEC;
    
    printf("PESQUISA ALEATORIA:\n");
    printf("   Total de acessos (comparacoes): %d\n", RandAcess);
    printf("   Media de acessos por chave:    %.2f\n", RandAcess / 100.0);
    printf("   Tempo total de execucao:       %.6f segundos\n\n", RandTime);

    printf("PESQUISA SEQUENCIAL:\n");
    printf("   Total de acessos (comparacoes): %d\n", SeqAcess);
    printf("   Media de acessos por chave:    %.2f\n", SeqAcess / 100.0);
    printf("   Tempo total de execucao:       %.6f segundos\n", SeqTime);

    return 0;
}