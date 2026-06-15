#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "avl.h"

typedef struct {
    int order_details_id,
        order_id;
    char pizza_id[31];
    int quantity;
    char order_date[21],
         order_time[16];
    double unit_price,
           total_price;
    char pizza_size[6],
         pizza_category[31],
         pizza_ingredients[201],
         pizza_name[31];
    int data_juliana;
} PizzaSales;
PizzaSales Sales[50000];

int DataJuliana(int Dia, int Mes, int Ano){
    return (1461*(Ano + 4800 + (Mes - 14)/12))/4+
        (367 * (Mes - 2 - 12 * ((Mes - 14) / 12)))/12 -
        (3 * ((Ano + 4900 + (Mes - 14)/12)/100))/4 +
        Dia - 32075;
}

char * replace(char s[40], char c1, char c2) // Troca caracteres na string
{
    int l = strlen(s);

    // loop to traverse in the string
    for (int i = 0; i < l; i++)
    {
        // Check for c1 and replace
        if (s[i] == c1)
            s[i] = c2;

        // Check for c2 and replace
        //else if (s[i] == c2)
        //    s[i] = c1;
    }
    return s;
}


int CarregaSales(){
    FILE *fp = fopen("PizzaSales.csv", "r");
    if(fp == NULL){
        printf("Nao abrir PizzaSales.csv!\n");
        exit(1);
    }
    char Linha[10000], *p, texto[10000]; // Declare texto
    int cont = 0, campo;
    if(fscanf(fp, " %[^\n]", Linha) == EOF) return 0;
    while(fscanf(fp, " %[^\n]", Linha) != EOF){
        //printf("%s\n", Linha);
        p = strtok(Linha, ","); // Troque o ; por ,. Altere o outro strtok também
        campo = 0;
        while(p != NULL){
            strcpy(texto, p);
            if(texto[0] == '\"'){ // Se tem uma aspas
                strcpy(texto, p+1); // Tira a aspas
                p = strtok(NULL, "\""); // Localiza a aspas de finalização
                strcat(texto, ","); // Coloca a vírgula
                if(p != NULL) strcat(texto, p); // Cópia o restante até antes da próxima aspas
            }
            // Nas linhas abaixo troque p por texto
            if(campo == 0) Sales[cont].order_details_id = atoi(texto); // Campo inteiro use atoi()
            if(campo == 1) Sales[cont].order_id = atoi(texto);
            if(campo == 2) strcpy(Sales[cont].pizza_id, texto); // Campo string use strcpy()
            if(campo == 3) Sales[cont].quantity = atoi(texto);
            if(campo == 4) {
                strcpy(Sales[cont].order_date, texto);
                char sdia[5], smes[5], sano[5];
                sscanf(p, "%2s/%2s/%4s", sdia, smes, sano);
                // Converto o campo data para um inteiro data juliana
                // se quiser indexar pela data
                Sales[cont].data_juliana = DataJuliana(atoi(sdia), atoi(smes), atoi(sano));
                //printf("%s %s %s\n", sdia, smes, sano);

            }
            if(campo == 5) strcpy(Sales[cont].order_time, texto);
            if(campo == 6) Sales[cont].unit_price = strtof(replace(texto, ',', '.'), NULL); // Campo valor monetário use replace() e strtof() ou atof()
            if(campo == 7) Sales[cont].total_price = strtof(replace(texto, ',', '.'), NULL);
            if(campo == 8) strcpy(Sales[cont].pizza_size, texto);
            if(campo == 9) strcpy(Sales[cont].pizza_category, texto);
            if(campo == 10) strcpy(Sales[cont].pizza_ingredients, texto);
            if(campo == 11) strcpy(Sales[cont].pizza_name, texto);
                //printf("Texto: %s\n",texto);
            char *q = p;
            //if(*(q + strlen(p)+1) == ',') campo++;
            p = strtok(NULL, ",");
            campo++;
        }
        cont++;
        //if(cont >= 5000) break;
    }
    return cont;
}

int main()
{
    int cont;
    //Avl *a = NULL;

    cont = CarregaSales();

    for(int i = 0; i < cont; i++){
        if(i < 10)
        printf("detalhe: %d\nid do pedido: %d\nid da pizza: %s\nquantidade: %d\ndata: %s\nhora: %s\npreco unitario: %.2lf\npreco total: %.2lf \nsize: %s\ncategoria: %s\ningredientes: %s\nnome: %s\ndata juliana: %d\n\n",
                Sales[i].order_details_id,
               Sales[i].order_id, Sales[i].pizza_id, Sales[i].quantity,
               Sales[i].order_date, Sales[i].order_time, Sales[i].unit_price, Sales[i].total_price,
               Sales[i].pizza_size, Sales[i].pizza_category, Sales[i].pizza_ingredients, Sales[i].pizza_name, Sales[i].data_juliana);

        char sdia[5], smes[5], sano[5];
        sscanf(Sales[i].order_date, "%2s/%2s/%4s", sdia, smes, sano);
        // Converto o campo data para um inteiro data juliana se quiser indexar pela data
        int Chave = DataJuliana(atoi(sdia), atoi(smes), atoi(sano));
        //printf("%s %s %s\n", sdia, smes, sano);

        //a = InserirAvl(a, Chave, &Sales[i]);
    }
    printf("\n%d registros carregados!\n", cont);
    return 0;
    /*
    ImprimirAvl(a);
    printf("\n\n\n");
    ImprimirAvl2(a,0);

    printf("Digite uma data para consultar: ");
    //scanf("%s", sData);
    char sdia[5], smes[5], sano[5];
    scanf("%2s/%2s/%4s", sdia, smes, sano);
    int dj = DataJuliana(atoi(sdia), atoi(smes), atoi(sano));

    Avl *p = BuscarAvl(a, dj);
    if(p == NULL){
        printf("Nao encontrei vendas neste dia!\n\n");
    }
    else{
        printf("%-6s %-5s %-20s %-4s %-10s %-8s %-7s %-7s %-30s\n\n", "Item", "Ped", "Codigo Pizza", "Qtde", "Data", "Hora", "Pc Unit", "Total", "Noma Pizza");
        Lista* l = p->Dados;
        while(l != NULL){
            /*
            printf("%d %d %s %d %s %s %.2lf %.2lf %s %s %s %s %d\n", ((PizzaSales*)l->Info)->order_details_id,
               ((PizzaSales*)l->Info)->order_id, ((PizzaSales*)l->Info)->pizza_id, ((PizzaSales*)l->Info)->quantity,//
               ((PizzaSales*)l->Info)->order_date, ((PizzaSales*)l->Info)->order_time, ((PizzaSales*)l->Info)->unit_price, ((PizzaSales*)l->Info)->total_price,
               ((PizzaSales*)l->Info)->pizza_size, ((PizzaSales*)l->Info)->pizza_category, ((PizzaSales*)l->Info)->pizza_ingredients, ((PizzaSales*)l->Info)->pizza_name,
               ((PizzaSales*)l->Info)->data_juliana);
               */
               /*
            PizzaSales *p = (PizzaSales*)l->Info;
            printf("%06d %05d %-20s %4d %10s %-8s %7.2lf %7.2lf %-30s\n", p->order_details_id,
               p->order_id, p->pizza_id, p->quantity,
               p->order_date, p->order_time, p->unit_price, p->total_price,
               p->pizza_name);
               l = l->prox;

        }
    }
*/
    return 0;

    printf("\n\n\n");
    //a = RetirarAvl(a, 55);
    //a = RetirarAvl(a, 50);

    //ImprimirAvl(a);
    printf("\n\n\n");
    //ImprimirAvl2(a,0);

    return 0;
}
