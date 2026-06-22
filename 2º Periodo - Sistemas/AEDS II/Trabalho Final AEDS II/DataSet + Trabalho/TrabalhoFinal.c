#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int AppID;
    char Name[51],Release_Date[12],Primary_Genre[21],All_Tags[201];
    double Price_USD,Discount_Pct,Review_Score_Pct;
    int Total_Reviews;
    char Steam_Deck_Status[21];
    int Estimated_Owners,_24h_Peak_Players;
    int Data;
} steam_games_2026;
steam_games_2026 SteamGames[50000];


int DataConv(int Dia, int Mes, int Ano){
    return (1461*(Ano + 4800 + (Mes - 14)/12))/4+
        (367 * (Mes - 2 - 12 * ((Mes - 14) / 12)))/12 -
        (3 * ((Ano + 4900 + (Mes - 14)/12)/100))/4 +
        Dia - 32075;
}

char * replace(char s[40], char c1, char c2)
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
    if(fscanf(fp, " %[^\n]", Linha) == EOF) return 0;
    while(fscanf(fp, " %[^\n]", Linha) != EOF){
        p = strtok(Linha, ",");
        campo = 0;
        while(p != NULL){
            strcpy(texto, p);
            if(texto[0] == '\"'){ 
                strcpy(texto, p+1); 
                p = strtok(NULL, "\""); 
                strcat(texto, ","); 
                if(p != NULL) strcat(texto, p);
            }
            if(campo == 0) SteamGames[cont].AppID = atoi(texto);
            if(campo == 1) strcpy(SteamGames[cont].Name, texto);
            if(campo == 2) {
                strcpy(SteamGames[cont].Release_Date, texto);
                char sdia[5], smes[5], sano[5];
                sscanf(p, "%2s/%2s/%4s", sdia, smes, sano);
                SteamGames[cont].Data = DataConv(atoi(sdia), atoi(smes), atoi(sano));
            }
            if(campo == 3) strcpy(SteamGames[cont].Primary_Genre, texto);
            if(campo == 4) strcpy(SteamGames[cont].All_Tags, texto);
            if(campo == 5) SteamGames[cont].Price_USD = strtof(replace(texto, ',', '.'), NULL);
            if(campo == 6) SteamGames[cont].Discount_Pct = strtof(replace(texto, ',', '.'), NULL);
            if(campo == 7) SteamGames[cont].Review_Score_Pct = strtof(replace(texto, ',', '.'), NULL);
            if(campo == 8) SteamGames[cont].Total_Reviews= atoi(texto);
            if(campo == 9) strcpy(SteamGames[cont].Steam_Deck_Status, texto);
            if(campo == 10) SteamGames[cont].Estimated_Owners= atoi(texto);
            if(campo == 11) SteamGames[cont]._24h_Peak_Players= atoi(texto);
                
            char *q = p;
            p = strtok(NULL, ",");
            campo++;
        }
        cont++;
    }
    return cont;
}

int main()
{
    int cont;
    cont = CarregaGames();
    for(int i = 0; i < cont; i++){
        if(i < 10)
        printf("AppID: %d\nNome do Jogo: %s\nData de Lancamento: %s\nGenero Primario: %s\nTodas as Tags: %s\nPreco(Dolar) %.2lf\nPorcentagem Disconto: %.2lf\nPorcentagem Score Review: %.2lf\nTotal Reviews: %d\nSteam Deck Status: %s\nQuantidade Vendidos: %d\nPico de Jogadores 24h: %d\nData Convertida: %d\n\n",
               SteamGames[i].AppID,
               SteamGames[i].Name, SteamGames[i].Release_Date, SteamGames[i].Primary_Genre,
               SteamGames[i].All_Tags, SteamGames[i].Price_USD, SteamGames[i].Discount_Pct, SteamGames[i].Review_Score_Pct,
               SteamGames[i].Total_Reviews, SteamGames[i].Steam_Deck_Status, SteamGames[i].Estimated_Owners, SteamGames[i]._24h_Peak_Players, SteamGames[i].Data);
        char sdia[5], smes[5], sano[5];
        sscanf(SteamGames[i].Release_Date, "%2s/%2s/%4s", sdia, smes, sano);
        int Chave = DataConv(atoi(sdia), atoi(smes), atoi(sano));
    }
    printf("\n%d Registros Carregados!\n", cont);
    printf("\n\n\n");
    return 0;
}
