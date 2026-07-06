#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// Estrutura Principal:
typedef struct {
    int AppID;
    char Name[150], Release_Date[12], Primary_Genre[50], All_Tags[500];
    double Price_USD, Discount_Pct, Review_Score_Pct;
    int Total_Reviews;
    char Steam_Deck_Status[30];
    int Estimated_Owners, _24h_Peak_Players;
} steam_games_2026;

typedef struct abb Abb;

// Protótipos da Árvore:
Abb* CriarAbb();
Abb* InserirAbb(Abb* a, int id, int indice_no_vetor);
Abb* BuscaAbb(Abb* a, int v, int *acessos);
void LiberarAbb(Abb* a);

// Estrutura da Árvore de Busca:
struct abb {
    int AppID;          
    int IndiceVetor; 
    struct abb *Esq, *Dir;
};

Abb* CriarAbb(){
    return NULL;
}

Abb* InserirAbb(Abb* a, int Id, int IndiceVetor){
    if(a == NULL){
        Abb* Novo = (Abb*)malloc(sizeof(Abb));
        if(Novo == NULL) {
            printf("Erro de alocacao de memoria na arvore!\n");
            exit(1);
        }
        Novo->AppID = Id;
        Novo->IndiceVetor = IndiceVetor;
        Novo->Esq = Novo->Dir = NULL;
        return Novo;
    }
    if(Id < a->AppID) a->Esq = InserirAbb(a->Esq, Id, IndiceVetor);
    else if(Id > a->AppID) a->Dir = InserirAbb(a->Dir, Id, IndiceVetor);
    return a;
}

Abb* BuscaAbb(Abb* a, int v, int *acessos){
    if(a == NULL) return NULL;
    (*acessos)++;
    if(a->AppID == v) return a;
    if(v < a->AppID) return BuscaAbb(a->Esq, v, acessos);
    else return BuscaAbb(a->Dir, v, acessos);
}

void LiberarAbb(Abb* a){
    if (a != NULL) {
        LiberarAbb(a->Esq);
        LiberarAbb(a->Dir);
        free(a);
    }
}

// Vetor Global
steam_games_2026 SteamGames[50000];

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

// Função Principal:
int CarregaGames(){
    FILE *fp = fopen("steam_games_2026.csv", "r");
    if(fp == NULL){
        printf("Nao foi possivel abrir steam_games_2026.csv!\n");
        exit(1);
    }
    char Linha[2048];
    int cont = 0;

    // Pula o cabeçalho
    if(fgets(Linha, sizeof(Linha), fp) == NULL) {
        fclose(fp);
        return 0;
    }

    while(fgets(Linha, sizeof(Linha), fp) != NULL && cont < 50000){
        Linha[strcspn(Linha, "\r\n")] = 0;

        // Leitura manual caractere por caractere
        char buffer[1000];
        int b_idx = 0;
        int campo = 0;
        bool in_quotes = false;
        char *pt = Linha;

        while (*pt) {
            if (*pt == '\"') {
                in_quotes = !in_quotes;
            } else if (*pt == ',' && !in_quotes) {
                buffer[b_idx] = '\0';

                // Preenche a struct no vetor original
                if(campo == 0) SteamGames[cont].AppID = atoi(buffer);
                if(campo == 1) { strncpy(SteamGames[cont].Name, buffer, 149); SteamGames[cont].Name[149] = '\0'; }
                if(campo == 2) { strncpy(SteamGames[cont].Release_Date, buffer, 11); SteamGames[cont].Release_Date[11] = '\0'; }
                if(campo == 3) { strncpy(SteamGames[cont].Primary_Genre, buffer, 49); SteamGames[cont].Primary_Genre[49] = '\0'; }
                if(campo == 4) { strncpy(SteamGames[cont].All_Tags, buffer, 499); SteamGames[cont].All_Tags[499] = '\0'; }
                if(campo == 5) SteamGames[cont].Price_USD = strtof(replace(buffer, ',', '.'), NULL);
                if(campo == 6) SteamGames[cont].Discount_Pct = strtof(replace(buffer, ',', '.'), NULL);
                if(campo == 7) SteamGames[cont].Review_Score_Pct = strtof(replace(buffer, ',', '.'), NULL);
                if(campo == 8) SteamGames[cont].Total_Reviews = atoi(buffer);
                if(campo == 9) { strncpy(SteamGames[cont].Steam_Deck_Status, buffer, 29); SteamGames[cont].Steam_Deck_Status[29] = '\0'; }
                if(campo == 10) SteamGames[cont].Estimated_Owners = atoi(buffer);

                campo++;
                b_idx = 0;
            } else {
                if (b_idx < 999) buffer[b_idx++] = *pt;
            }
            pt++;
        }

        // Pega o último campo (_24h_Peak_Players)
        buffer[b_idx] = '\0';
        if (campo == 11) SteamGames[cont]._24h_Peak_Players = atoi(buffer);

        if(campo >= 10) cont++; // Confirma que leu a linha corretamente
    }
    fclose(fp);
    return cont;
}

int main()
{
    srand(time(NULL));
    int Contador = CarregaGames();
    printf("%d Registros Carregados do CSV\n\n", Contador);

    if(Contador == 0) {
        printf("Nenhum registro carregado\n");
        return 0;
    }

    Abb* Raiz = CriarAbb();
    for(int i = 0; i < Contador; i++){
        Raiz = InserirAbb(Raiz, SteamGames[i].AppID, i);
    }

    FILE *GameLista = fopen("GameSelection.txt", "w");
    if(GameLista == NULL) {
        printf("Erro ao criar o arquivo de saída!\n");
        return 1;
    }

    int RandAcess = 0;
    int SeqAcess = 0;
    clock_t TempIni, TempFim;
    double RandTime, SeqTime;

    Abb* NodoEncontrado = NULL;

    // Pesquisa Aleatória + Salvar arquivo
    fprintf(GameLista, "PESQUISA ALEATÓRIA\n");
    TempIni = clock();
    for(int i = 0; i < 100; i++) {
        int RandInd = rand() % Contador;
        int ChaveBusca = SteamGames[RandInd].AppID;
        NodoEncontrado = BuscaAbb(Raiz, ChaveBusca, &RandAcess);

        if(NodoEncontrado != NULL) {
            int idx = NodoEncontrado->IndiceVetor;
            fprintf(GameLista, "ID: %d | Nome: %s | Genero: %s | Preco: USD %.2f\n",
                    SteamGames[idx].AppID,
                    SteamGames[idx].Name,
                    SteamGames[idx].Primary_Genre,
                    SteamGames[idx].Price_USD);
        }
    }
    TempFim = clock();
    RandTime = ((double)(TempFim - TempIni)) / CLOCKS_PER_SEC;

    // Pesquisa Sequencial + Salvar arquivo
    fprintf(GameLista, "\nPESQUISA SEQUENCIAL\n");
    int IniSeq = rand() % (Contador > 100 ? Contador - 100 : 1);
    TempIni = clock();
    for(int i = 0; i < 100; i++) {
        int ChaveBusca = SteamGames[IniSeq + i].AppID;
        NodoEncontrado = BuscaAbb(Raiz, ChaveBusca, &SeqAcess);

        if(NodoEncontrado != NULL) {
            int idx = NodoEncontrado->IndiceVetor;
            fprintf(GameLista, "ID: %d | Nome: %s | Genero: %s | Preco: USD %.2f\n",
                    SteamGames[idx].AppID,
                    SteamGames[idx].Name,
                    SteamGames[idx].Primary_Genre,
                    SteamGames[idx].Price_USD);
        }
    }
    TempFim = clock();
    SeqTime = ((double)(TempFim - TempIni)) / CLOCKS_PER_SEC;

    fclose(GameLista);
    LiberarAbb(Raiz);

    printf("PESQUISA ALEATORIA:\n");
    printf("   Total de acessos: %d\n", RandAcess);
    printf("   Tempo de execucao: %.12f segundos\n\n", RandTime);

    printf("PESQUISA SEQUENCIAL:\n");
    printf("   Total de acessos: %d\n", SeqAcess);
    printf("   Tempo de execucao: %.12f segundos\n", SeqTime);
    printf("\n");
    return 0;
}
