/*************************************************************** PUBLIC INTERFACE *****************************************************************/

#ifndef EASTEREGGS_H
#define EASTEREGGS_H

#include <stdbool.h>

typedef struct _easterEggs EasterEggs;
typedef struct _list List;
/**
 * @brief Cria a lista de ovos de pascoa
 * 
 * @return List* 
 */
List *ListCreate();
/**
 * @brief Cria os ovos de pascoa, e pede pra pra alocar na lista
 * 
 * @param identifier Identificador do ovo de pascoa
 * @param price Preco do ovo de pascoa
 * @return EasterEggs* 
 */
EasterEggs *EasterEggsCreate(int identifier, float price);
/**
 * @brief Adiciona o ovo de pascoa a lista de ovos
 * 
 * @param list Lista de ovos
 * @param identifier Identificador do ovo de pascoa
 * @param price Preco do ovo de pascoa
 */
void ListAdd(List *list, int identifier, float price);
/**
 * @brief Desaloca toda a lista 
 * 
 * @param list Lista de ovos
 */
void ListDestroy(List **list);
/**
 * @brief Calcula a media dos ovos de pascoa que estao na lista
 * 
 * @param list Lista de ovos
 * @return float 
 */
float EggsAveragePrice(List *list);
/**
 * @brief Mostra os resultados, de acordo com a media de precos dos ovos
 * 
 * @param list Lista de ovos
 */
void EggsSearchPrice(List **list);

#endif

/**************************************************************************************************************************************************/