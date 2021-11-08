#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila{
    char valor;
    Fila* proximo;
    Fila* anterior;
};

Fila* criaFila(char valor){ //criação de um elemento de uma fila
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    
    if(fila){
        fila->valor = valor;
        fila->proximo = NULL;
        fila->anterior = NULL;
    } 

    return fila;
}

int ehVazioFila(Fila* primeiroTermo){ // retorna se a fila é ou não vazia, através do primeiro elemento
    return (primeiroTermo == NULL);
}

int insereFila(Fila** primeiroTermo, char valor){ // insere um novo elemento da fila, como ultimo elemento

    Fila* fila = criaFila(valor);

    if(fila){

        if(ehVazioFila(*primeiroTermo)){
            *primeiroTermo = fila;
            return 1;
        }

        Fila* auxiliar = *primeiroTermo;
        
        while(auxiliar->proximo != NULL){
            auxiliar = auxiliar->proximo;
        }

        auxiliar->proximo = fila;
        fila->anterior = auxiliar;
        return 1;
    }
    return 0;
}

int existeFila(Fila* primeiroTermo, char valor){ // procura se valor esta contido na fila
    if(ehVazioFila(primeiroTermo)){ 
        return 0;
    }

    while(primeiroTermo != NULL){ // passa por todos elementos
        if(primeiroTermo->valor == valor){ 
            return 1;
        }

        primeiroTermo = primeiroTermo->proximo;
    }
    return 0; 
}

void printaFila(Fila* primeiroTermo, char* mensagem){ // printa todos elementos da fila, com uma mensagem
    printf("%s: ", mensagem);

    while(primeiroTermo != NULL){
        printf("%d ", primeiroTermo->valor);
        primeiroTermo = primeiroTermo->proximo;
    }

}

void limpaFila(Fila** primeiroTermo){ // libera a memoria de toda fila
    Fila* proximo = NULL;
    Fila* fila = *primeiroTermo;

    while(fila != NULL){
        proximo = fila->proximo;
        free(fila);
        fila = proximo;
    }
    *primeiroTermo = NULL;
}

char removerFila(Fila** primeiroTermo){ // libera memória do primeiro elemento
    Fila* proximo = NULL;
    Fila* fila = *primeiroTermo;

    proximo = fila->proximo;
    proximo->anterior = NULL;
    char valor = fila->valor;
    free(fila);

    *primeiroTermo = proximo;

    return valor;
}