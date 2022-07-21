#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

typedef struct _easterEggs{
    int identifier;
    float price;
    struct _easterEggs *next;
}EasterEggs;

typedef struct _list{
    size_t size;
    EasterEggs *begin;
}List;

List *ListCreate();
EasterEggs *EasterEggsCreate(int identifier, float price);
void ListAdd(List *list, int identifier, float price);
void ListAddFirst(List *list, EasterEggs *easterEggs);
void ListAddMiddle(List *list, EasterEggs *easterEggs);
float EggsAverageprice(List *list);
void EggsSearchprice(List *list);
bool ListIsEmpty(List *list);

int main(){

    List *ListEggs = ListCreate();
    int numberEggs, identifier;
    float price;

    printf("\n----------------------------------------ADICIONAR NA LISTA----------------------------------------\n\n");
    printf("INFORME A QUANTIDADE DE OVOS: ");
    scanf("%d", &numberEggs);
    puts("");
    for(int i = 0; i < numberEggs; i++){
        printf("INFORME A POSIÇÃO NA list->begin, identifier E PREÇO DO %dº OVO: ", (i+1));
        scanf("%d %f ", &identifier, &price);
        ListAdd(ListEggs, identifier, price);
    }
    //ListAdd(291839, 45.0, 0);
    //ListAdd(928302, 80.0, 1);
    //ListAdd(292719, 75.0, 2);
    //ListAdd(281720, 66.0, 3);
    //ListAdd(281920, 15.0, 4);

    return 0;
}

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

bool ListIsEmpty(List *list){
    return list->size == 0;
}

void ListAdd(List *list, int identifier, float price){
    EasterEggs *newEasterEggs = EasterEggsCreate(identifier, price);
    if(ListIsEmpty(list) || list->begin->price > newEasterEggs->price)
        ListAddFirst(list, newEasterEggs);
    else
        ListAddMiddle(list, newEasterEggs);
    list->size++;
}

void ListAddFirst(List *list, EasterEggs *easterEggs){
    easterEggs->next = list->begin;
    list->begin = easterEggs;
}

void ListAddMiddle(List *list, EasterEggs *easterEggs){
    EasterEggs *assistent = list->begin;
    while(assistent->next != NULL && easterEggs->price > assistent->next->price)
        assistent = assistent->next;
    easterEggs->next = assistent->next;
    assistent->next = easterEggs;
}

float EggsAverageprice(List *list){
    float sumEggPrices = 0.0;
    EasterEggs *assistent = list->begin;
    while(assistent != NULL){
        sumEggPrices += assistent->price;
        assistent = assistent->next;
    }
    return (sumEggPrices / list->size);
}

void EggsSearchprice(List *list){
    float priceHedging = EggsAverageprice(list);
    EasterEggs *assistent = list->begin;
    while(assistent != NULL){
        if(assistent->price < (priceHedging/2))
            printf("Ovo de Páscoa %d: TALVEZ DÊ PARA COMPRAR\n", assistent->identifier);
        else if(assistent->price <= priceHedging)
            printf("Ovo de Páscoa %d: ACHO QUE É MELHOR COMPRAR O VALOR EM BARRA DE CHOCOLATE\n", assistent->identifier);
        else
            printf("Ovo de Páscoa %d: NEM GOSTO DE CHOCOLATE MESMO, MELHOR COMPRAR UMA BARRA DE OURO COM ESSE DINEHIRO\n", assistent->identifier);
        assistent = assistent->next;
    }
}