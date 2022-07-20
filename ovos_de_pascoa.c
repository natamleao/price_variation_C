#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct lista{
    int identificador_ovo;
    float preco_ovo;

    struct lista *proximo_ovo;
}ovos_de_pascoa;

void entrada_de_dados();
void adicionar_ovo_na_lista(int identificador, float preco, int posicao);
float media_de_precos_dos_ovos();
void consultar_precos_dos_ovos();

ovos_de_pascoa *lista = NULL;
int tamanho_lista = 0;

int main(){
    setlocale(LC_ALL, "");

    //entrada_de_dados();

    adicionar_ovo_na_lista(291839, 45.0, 0);
    adicionar_ovo_na_lista(928302, 80.0, 1);
    adicionar_ovo_na_lista(292719, 75.0, 2);
    adicionar_ovo_na_lista(281720, 66.0, 3);
    adicionar_ovo_na_lista(281920, 15.0, 4);

    consultar_precos_dos_ovos();

    return 0;
}

void entrada_de_dados(){
    int quantidade_de_ovos, identificador, posicao;
    float preco;
    printf("\n----------------------------------------ADICIONAR NA LISTA----------------------------------------\n\n");
    printf("INFORME A QUANTIDADE DE OVOS: ");
    scanf("%d", &quantidade_de_ovos);
    printf("\n");
    for(int i = 0; i < quantidade_de_ovos; i++){
        printf("INFORME A POSIÇÃO NA LISTA, IDENTIFICADOR E PREÇO DO %dº OVO: ", (i+1));
        scanf("%d %d %f", &posicao, &identificador, &preco);
        adicionar_ovo_na_lista(identificador, preco, posicao);
        setbuf(stdin, NULL);
    }
}

void adicionar_ovo_na_lista(int identificador, float preco, int posicao){
    if(posicao >= 0 && posicao <= tamanho_lista){
        ovos_de_pascoa *novo_ovo = malloc(sizeof(ovos_de_pascoa));
        novo_ovo->identificador_ovo = identificador;
        novo_ovo->preco_ovo = preco;
        novo_ovo->proximo_ovo = NULL;
        if(lista == NULL){
            lista = novo_ovo;
        }
        else if(posicao == 0){
            novo_ovo->proximo_ovo = lista;
            lista = novo_ovo;
        }
        else{
            ovos_de_pascoa *copia_lista = lista;
            for(int i = 0; i < (posicao-1); i++){
                copia_lista = copia_lista->proximo_ovo;
            }
            novo_ovo->proximo_ovo = copia_lista->proximo_ovo;
            copia_lista->proximo_ovo = novo_ovo;
        }
        tamanho_lista++;
    }
}

float media_de_precos_dos_ovos(){
    float soma_precos_ovos = 0;
    ovos_de_pascoa *copia_lista = lista;
    for(int i = 0; i < tamanho_lista; i++){
        soma_precos_ovos += copia_lista->preco_ovo;
        copia_lista = copia_lista->proximo_ovo;
    }
    return (soma_precos_ovos/tamanho_lista);
}

void consultar_precos_dos_ovos(){
    float media_de_precos = media_de_precos_dos_ovos();
    ovos_de_pascoa *copia_lista = lista;
    for(int i = 0; i < tamanho_lista; i++){
        if(copia_lista->preco_ovo < (media_de_precos/2)){
            printf("Ovo de Páscoa %d: TALVEZ DÊ PARA COMPRAR\n", copia_lista->identificador_ovo);
        }
        else if(copia_lista->preco_ovo >= (media_de_precos/2) && copia_lista->preco_ovo <= media_de_precos){
            printf("Ovo de Páscoa %d: ACHO QUE É MELHOR COMPRAR O VALOR EM BARRA DE CHOCOLATE\n", copia_lista->identificador_ovo);
        }
        else{
            printf("Ovo de Páscoa %d: NEM GOSTO DE CHOCOLATE MESMO, MELHOR COMPRAR UMA BARRA DE OURO COM ESSE DINEHIRO\n", copia_lista->identificador_ovo);
        }
        copia_lista = copia_lista->proximo_ovo;
    }
}