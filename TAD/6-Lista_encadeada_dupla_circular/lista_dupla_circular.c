#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla_circular.h"

struct listaDuplaCircular{
    int valor;
    ListaDuplaCircular* proximo;
    ListaDuplaCircular* anterior;
};

ListaDuplaCircular* criarLista(int valor){ //criação de um elemento de uma lista encadeada

    ListaDuplaCircular* lista = (ListaDuplaCircular*) malloc(sizeof(ListaDuplaCircular));

    if(lista){
        lista->valor = valor;
        lista->proximo = lista;
        lista->anterior = lista;

        return 1;
    }

    return 0;
}

int ehVazio(ListaDuplaCircular* primeiroTermo){ // retorna se a lista é ou não vazia, através do primeiro elemento
    return (primeiroTermo == NULL);
}

int insereInicio(ListaDuplaCircular** primeiroTermo, int valor){ // insere um novo elemento da lista, como primeiro elemento
    ListaDuplaCircular* lista = criarLista(valor);

    if(lista){
        ListaDuplaCircular* auxiliar = *primeiroTermo;

        lista->proximo = auxiliar;
        auxiliar->anterior->proximo = lista;
        auxiliar->anterior = lista;
        lista->anterior = auxiliar->anterior;

        *primeiroTermo = lista;

        return 1;
    }

    return 0;
}

int insereFim(ListaDuplaCircular** primeiroTermo, int valor){ // insere um novo elemento da lista, como ultimo elemento
    ListaDuplaCircular* lista = criarLista(valor);

    if(lista){
        ListaDuplaCircular* auxiliar = *primeiroTermo;

        lista->proximo = auxiliar;
        auxiliar->anterior->proximo = lista;
        lista->anterior = auxiliar->anterior;
        auxiliar->anterior = lista;

        return 1;
    }

    return 0;
}

int existe(ListaDuplaCircular* primeiroTermo, int valor){
if(ehVazio(primeiroTermo)){ 
        return 0;
    }

    while(primeiroTermo != NULL){ 
        if(primeiroTermo->valor == valor){
            return 1;
        }

        primeiroTermo = primeiroTermo->proximo;
    }
    return 0;
}

void printLista(ListaDuplaCircular* primeiroTermo, char* mensagem){ // printa todos elementos da lista, com uma mensagem

}

void limpa(ListaDuplaCircular** primeiroTermo){ // libera a memória de toda lista

}

int remover(ListaDuplaCircular** primeiroTermo, int valor){ // libera memória de elemento com valor especifico
    
}

int insereOrdem(ListaDuplaCircular** primeiroTermo, int valor){ // insere elemento em ordem de valor
    
}