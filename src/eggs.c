#include "eggs.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/***************************************************** PUBLIC INTERFACE *******************************************************/

struct _eggs{
    int identifier;
    float price;
    struct _eggs *next;
};

struct _list{
    size_t size;
    Eggs *begin;
};

bool ListIsEmpty(List *list){
    return list->size == 0;
}

/***************************************************** PRIVATE INTERFACE ******************************************************/

List *ListCreate(){
    List *listAlloc = (List*)malloc(sizeof(List));
    listAlloc->size = 0;
    listAlloc->begin = NULL;
    return listAlloc;
}

Eggs *EggsCreate(int identifier, float price){
    Eggs *eggsAlloc = (Eggs*)malloc(sizeof(Eggs));
    eggsAlloc->identifier = identifier;
    eggsAlloc->price = price;
    eggsAlloc->next = NULL;
    return eggsAlloc;
}

void ListAdd(List *list, int identifier, float price){
    Eggs *eggsAlloc = EggsCreate(identifier, price);
    eggsAlloc->next = list->begin;
    list->begin = eggsAlloc;
}

void ListDestroy(List **list){
    Eggs *previous = NULL, *actual = (*list)->begin;
    while(actual != NULL){
        previous = actual, actual = actual->next;
        free(previous);
    }
    free(*list);
    *list = NULL;
}

float EggsAveragePrice(List *list){
    float sumEggPrices = 0.0;
    Eggs *auxiliary = list->begin;
    while(auxiliary != NULL){
        sumEggPrices += auxiliary->price;
        auxiliary = auxiliary->next;
    }
    return (sumEggPrices / list->size);
}

void EggsSearchPrice(List *list){
    float priceHedging = EggsAveragePrice(list);
    Eggs *auxiliary = list->begin;
    printf("\n+------------------------------- RESULTADO --------------------------------+\n\n");
    while(auxiliary != NULL){
        if(auxiliary->price < (priceHedging / 2))
            printf("Ovo de Páscoa %d: TALVEZ DÊ PARA COMPRAR\n", auxiliary->identifier);
        else if(auxiliary->price <= priceHedging)
            printf("Ovo de Páscoa %d: ACHO QUE É MELHOR COMPRAR O VALOR EM BARRA DE CHOCOLATE\n", auxiliary->identifier);
        else
            printf("Ovo de Páscoa %d: MELHOR COMPRAR UMA BARRA DE OURO COM ESSE DINEHIRO\n", auxiliary->identifier);
        printf("\n+--------------------------------------------------------------------------+\n\n");
        auxiliary = auxiliary->next;
    }
}

/******************************************************************************************************************************/