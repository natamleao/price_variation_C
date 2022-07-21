#include "easterEggs.h"
#include <stdio.h>

int main(){

    List *ListEggs = ListCreate();
    int numberEggs, identifier;
    float price;

    printf("\n+----------------------------- ADICIONAR NA LISTA -----------------------------+\n\n");
    printf("INFORME A QUANTIDADE DE OVOS: ");
    scanf("%d", &numberEggs);
    puts("");
    for(int i = 0; i < numberEggs; i++){
        printf("INFORME O IDENTIFICADOR E O PREÇO DO %dº OVO: ", (i+1));
        scanf(" %d%f", &identifier, &price);
        ListAdd(ListEggs, identifier, price);
    }

    EggsSearchPrice(&ListEggs);

    printf("Lista == NULL: %d\n", ListEggs == NULL);

    return 0;
}
