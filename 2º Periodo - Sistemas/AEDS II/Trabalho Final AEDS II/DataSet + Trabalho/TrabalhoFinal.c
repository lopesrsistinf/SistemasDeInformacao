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
} steam_games_2026;

typedef struct abb Abb;

// Protótipos da Árvore:
Abb* CriarAbb();
Abb* InserirAbb(Abb* a, steam_games_2026 NovoJogo);
Abb* BuscaAbb(Abb* a, int v, int *acessos);

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

Abb* BuscaAbb(Abb* a, int v, int *acessos){
    if(a == NULL) return NULL;
    (*acessos)++;
    if(a->Jogo.AppID == v) return a;
    if(v < a->Jogo.AppID) return BuscaAbb(a->Esq, v, acessos);
    else return BuscaAbb(a->Dir, v, acessos);
}

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
            if(campo == 2) { strncpy(SteamGames[cont].Release_Date, texto, 11); SteamGames[cont].Release_Date[11] = '\0'; }
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
    printf("%d Registros Carregados do CSV\n\n", Contador);

    if(Contador == 0) {
        printf("Nenhum registro carregado\n");
        return 0;
    }

    Abb* Raiz = CriarAbb();
    for(int i = 0; i < Contador; i++){
        Raiz = InserirAbb(Raiz, SteamGames[i]);
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

    Abb* JogoEncontrado = NULL;

    // Pesquisa Aleatória + Salvar arquivo
    fprintf(GameLista, "PESQUISA ALEATÓRIA\n");
    TempIni = clock();
    for(int i = 0; i < 100; i++) {
        int RandInd = rand() % Contador; //Função pra pegar um valor aleatorio da arvre
        int ChaveBusca = SteamGames[RandInd].AppID;
        JogoEncontrado = BuscaAbb(Raiz, ChaveBusca, &RandAcess);
        if(JogoEncontrado != NULL) {
            fprintf(GameLista, "ID: %d | Nome: %s | Genero: %s | Preco: USD %.2f\n",
                    JogoEncontrado->Jogo.AppID,
                    JogoEncontrado->Jogo.Name,
                    JogoEncontrado->Jogo.Primary_Genre,
                    JogoEncontrado->Jogo.Price_USD);
        }
    }
    TempFim = clock();
    RandTime = ((double)(TempFim - TempIni)) / CLOCKS_PER_SEC;

    // Pesquisa Sequencial + Salvar arquivo
    fprintf(GameLista, "\nPESQUISA SEQUENCIAL\n");
    int IniSeq = rand() % (Contador > 100 ? Contador - 100 : 1);
    //int IniSeq = 0;
    TempIni = clock();
    for(int i = 0; i < 100; i++) {
        int ChaveBusca = SteamGames[IniSeq + i].AppID;
        JogoEncontrado = BuscaAbb(Raiz, ChaveBusca, &SeqAcess);
        if(JogoEncontrado != NULL) {
            fprintf(GameLista, "ID: %d | Nome: %s | Genero: %s | Preco: USD %.2f\n",
                    JogoEncontrado->Jogo.AppID,
                    JogoEncontrado->Jogo.Name,
                    JogoEncontrado->Jogo.Primary_Genre,
                    JogoEncontrado->Jogo.Price_USD);
        }
    }
    TempFim = clock();
    SeqTime = ((double)(TempFim - TempIni)) / CLOCKS_PER_SEC;

    fclose(GameLista);

    printf("PESQUISA ALEATORIA:\n");
    printf("   Total de acessos: %d\n", RandAcess);
    printf("   Tempo de execucao: %.12f segundos\n\n", RandTime);

    printf("PESQUISA SEQUENCIAL:\n");
    printf("   Total de acessos: %d\n", SeqAcess);
    printf("   Tempo de execucao: %.12f segundos\n", SeqTime);
    printf("\n");
    return 0;
}