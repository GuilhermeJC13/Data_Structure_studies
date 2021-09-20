#include <stdio.h>
#include "lista_encadeada.h"

int main(void){

    ListaEncadeada* lista = NULL;

    insereInicio(&lista, 10);

    insereOrdem(&lista, 5);
    insereOrdem(&lista, 30);
    insereOrdem(&lista, 15);

    insereFim(&lista, 130);

    printLista(lista, "Lista");

    limpa(&lista);

    insereInicio(&lista, 3);
    insereInicio(&lista, 10);

    printLista(lista, "Lista");

    remover(&lista, 10);
    printLista(lista, "Lista");

    if(existe(lista, 3)){
        printf("Existe um 3 na lista");
    }

    limpa(&lista);

}