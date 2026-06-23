#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ArvoreBusca.h"

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

int CarregaGames(){
    FILE *fp = fopen("steam_games_2026.csv", "r");
    if(fp == NULL){
        printf("Nao foi possivel abrir steam_games_2026.csv!\n");
        exit(1);
    }
    char Linha[10000], *p, texto[10000];
    int cont = 0, campo;
    if(fgets(Linha, sizeof(Linha), fp) == NULL) return 0;
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
    int cont = CarregaGames();
    printf("%d Registros Carregados do CSV!\n\n", cont);

    if(cont == 0) {
        printf("Nenhum registro carregado. Encerrando.\n");
        return 0;
    }

    // 2. Criar a estrutura e indexar os registros pelo campo AppID
    printf("Indexando registros na Arvore de Busca Binaria (ABB)...\n");
    Abb* raiz = CriarAbb();
    for(int i = 0; i < cont; i++){
        raiz = InserirAbb(raiz, SteamGames[i]);
    }
    printf("Indexacao concluida com sucesso!\n\n");

    // Preparação para as pesquisas
    int acessos_aleatorios = 0;
    int acessos_sequenciais = 0;
    clock_t tempo_inicial, tempo_final;
    double tempo_aleatorio, tempo_sequencial;

    // 3. Pesquisar 100 chaves aleatórias existentes no vetor
    tempo_inicial = clock();
    for(int i = 0; i < 100; i++) {
        int indice_aleatorio = rand() % cont;
        int chave_busca = SteamGames[indice_aleatorio].AppID;
        BuscaAbb(raiz, chave_busca, &acessos_aleatorios);
    }
    tempo_final = clock();
    tempo_aleatorio = ((double)(tempo_final - tempo_inicial)) / CLOCKS_PER_SEC;

    // 4. Pesquisar 100 chaves sequenciais a partir de um ponto aleatório confiável
    int inicio_sequencial = rand() % (cont > 100 ? cont - 100 : 1);
    tempo_inicial = clock();
    for(int i = 0; i < 100; i++) {
        int chave_busca = SteamGames[inicio_sequencial + i].AppID;
        BuscaAbb(raiz, chave_busca, &acessos_sequenciais);
    }
    tempo_final = clock();
    tempo_sequencial = ((double)(tempo_final - tempo_inicial)) / CLOCKS_PER_SEC;

    // 5. Mostrar a comparação das pesquisas
    printf("==================================================\n");
    printf("      RESULTADOS E COMPARATIVO DAS PESQUISAS     \n");
    printf("==================================================\n");
    printf("Metodo de Pesquisa: Busca Binaria em Arvore (ABB)\n");
    printf("Quantidade de chaves buscadas por bateria: 100\n\n");
    
    printf("-> PESQUISA ALEATORIA:\n");
    printf("   Total de acessos (comparacoes): %d\n", acessos_aleatorios);
    printf("   Media de acessos por chave:    %.2f\n", acessos_aleatorios / 100.0);
    printf("   Tempo total de execucao:       %.6f segundos\n\n", tempo_aleatorio);

    printf("-> PESQUISA SEQUENCIAL:\n");
    printf("   Total de acessos (comparacoes): %d\n", acessos_sequenciais);
    printf("   Media de acessos por chave:    %.2f\n", acessos_sequenciais / 100.0);
    printf("   Tempo total de execucao:       %.6f segundos\n", tempo_sequencial);
    printf("==================================================\n");

    return 0;
    /*
    int cont;
    cont = CarregaGames();
    for(int i = 0; i < cont; i++){
        if(i < 10)
        printf("AppID: %d\nNome do Jogo: %s\nData de Lancamento: %s\nGenero Primario: %s\nTodas as Tags: %s\nPreco(Dolar) %.2lf\nPorcentagem Disconto: %.2lf\nPorcentagem Score Review: %.2lf\nTotal Reviews: %d\nSteam Deck Status: %s\nQuantidade Vendidos: %d\nPico de Jogadores 24h: %d\nChave: %d\n\n",
               SteamGames[i].AppID,
               SteamGames[i].Name, SteamGames[i].Release_Date, SteamGames[i].Primary_Genre,
               SteamGames[i].All_Tags, SteamGames[i].Price_USD, SteamGames[i].Discount_Pct, SteamGames[i].Review_Score_Pct,
               SteamGames[i].Total_Reviews, SteamGames[i].Steam_Deck_Status, SteamGames[i].Estimated_Owners, SteamGames[i]._24h_Peak_Players, SteamGames[i].Data);
        char sdia[5], smes[5], sano[5];
        sscanf(SteamGames[i].Release_Date, "%2s/%2s/%4s", sdia, smes, sano);
        int Chave = DataConv(atoi(sdia), atoi(smes), atoi(sano));
    }
    printf("\n%d Registros Carregados!\n", cont);
    printf("\n\n");
    return 0;
    */
}

