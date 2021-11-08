#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha{
    char valor;
    Pilha* proximo;
};

Pilha* criaPilha(char valor){ //criação de um elemento de uma pilha
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    
    if(pilha){
        pilha->valor = valor;
        pilha->proximo = NULL;
    }

    return pilha;
}

int ehVazioPilha(Pilha* primeiroTermo){ // retorna se a pilha é ou não vazia, através do primeiro elemento
    return (primeiroTermo == NULL);
}

int inserePilha(Pilha** primeiroTermo, char valor){ // insere um novo elemento da pilha, como ultimo elemento

    Pilha* pilha = criaPilha(valor);

    if(pilha){

        if(ehVazioPilha(*primeiroTermo)){
            *primeiroTermo = pilha;
            return 1;
        }

        Pilha* auxiliar = *primeiroTermo;
        
        while(auxiliar->proximo != NULL){
            auxiliar = auxiliar->proximo;
        }

        auxiliar->proximo = pilha;
        return 1;
    }
    return 0;
}

int existePilha(Pilha* primeiroTermo, char valor){ // procura se valor esta contido na pilha
    if(ehVazioPilha(primeiroTermo)){ 
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

void printaPilha(Pilha* primeiroTermo, char* mensagem){ // printa todos elementos da pilha, com uma mensagem
    printf("%s: ", mensagem);

    while(primeiroTermo != NULL){
        printf("%c ", primeiroTermo->valor);
        primeiroTermo = primeiroTermo->proximo;
    }

}

void limpaPilha(Pilha** primeiroTermo){ // libera a memória de toda pilha
    Pilha* proximo = NULL;
    Pilha* pilha = *primeiroTermo;

    while(pilha != NULL){
        proximo = pilha->proximo;
        free(pilha);
        pilha = proximo;
    }
    *primeiroTermo = NULL;
}

char removerPilha(Pilha** primeiroTermo){ // libera memória do ultimo elemento
    Pilha* anterior = NULL;
    Pilha* pilha = *primeiroTermo;
    char valor;

    while(pilha->proximo != NULL){
        anterior = pilha;
        pilha = pilha->proximo;
    }
    valor = pilha->valor;

    Pilha* primeiroElemento = *primeiroTermo;
    if(primeiroElemento->proximo == NULL){
        *primeiroTermo = NULL;
    }
    else{
        anterior->proximo = NULL;
        free(pilha);
    }
    return valor;
}