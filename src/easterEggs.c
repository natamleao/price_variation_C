#include "easterEggs.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*************************************************************** PUBLIC INTERFACE *****************************************************************/

struct _easterEggs{
    int identifier;
    float price;
    struct _easterEggs *next;
};

struct _list{
    size_t size;
    EasterEggs *begin;
};

bool ListIsEmpty(List *list){
    return list->size == 0;
}

/*************************************************************** PRIVATE INTERFACE ****************************************************************/

List *ListCreate(){
    List *newList = (List*)malloc(sizeof(List));
    newList->size = 0;
    newList->begin = NULL;
    return newList;
}

EasterEggs *EasterEggsCreate(int identifier, float price){
    EasterEggs *newEasterEggs = (EasterEggs*)malloc(sizeof(EasterEggs));
    newEasterEggs->identifier = identifier;
    newEasterEggs->price = price;
    newEasterEggs->next = NULL;
    return newEasterEggs;
}

void ListAdd(List *list, int identifier, float price){
    EasterEggs *newEasterEggs = EasterEggsCreate(identifier, price);
    newEasterEggs->next = list->begin;
    list->begin = newEasterEggs;
}

void ListDestroy(List **list){
    EasterEggs *previous = NULL, *actual = (*list)->begin;
    while(actual != NULL){
        previous = actual, actual = actual->next;
        free(previous);
    }
    free(*list);
    *list = NULL;
}

float EggsAveragePrice(List *list){
    float sumEggPrices = 0.0;
    EasterEggs *assistent = list->begin;
    while(assistent != NULL){
        sumEggPrices += assistent->price;
        assistent = assistent->next;
    }
    return (sumEggPrices / list->size);
}

void EggsSearchPrice(List **list){
    float priceHedging = EggsAveragePrice(*list);
    EasterEggs *assistent = (*list)->begin;
    while(assistent != NULL){
        if(assistent->price < (priceHedging / 2))
            printf("Ovo de Páscoa %d: TALVEZ DÊ PARA COMPRAR\n", assistent->identifier);
        else if(assistent->price <= priceHedging)
            printf("Ovo de Páscoa %d: ACHO QUE É MELHOR COMPRAR O VALOR EM BARRA DE CHOCOLATE\n", assistent->identifier);
        else
            printf("Ovo de Páscoa %d: NEM GOSTO DE CHOCOLATE MESMO, MELHOR COMPRAR UMA BARRA DE OURO COM ESSE DINEHIRO\n", assistent->identifier);
        assistent = assistent->next;
    }
    ListDestroy(list);
}

/**************************************************************************************************************************************************/