#ifndef ARVORE_BUSCA_H
#define ARVORE_BUSCA_H

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

Abb* CriarAbb();
Abb* InserirAbb(Abb* a, steam_games_2026 NovoJogo);
void ImprimirAbb(Abb* a);
Abb* BuscaAbb(Abb* a, int v, int *acessos);
Abb* RetirarAbb(Abb* a, int v);

#endif