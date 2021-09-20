#include <stdio.h>
#include <stdlib.h>
#include "conjunto_reais.h"

struct conjuntoReais{
    float valor;
    ConjuntoReais* proximo;
};

ConjuntoReais* AlocarConjunto(){
    return (ConjuntoReais*) malloc(sizeof(ConjuntoReais));
}

ConjuntoReais* criarConjunto(float valor){ //criação de um elemento de uma conjunto encadeada
    ConjuntoReais* conjunto = AlocarConjunto(); //aloca memória para elemento
    
    if(conjunto){ //verifica se foi alocado da forma correta e seta o próximo elemento da conjunto como nulo e o valor com o parametro passado
        conjunto->valor = valor;
        conjunto->proximo = NULL;
    } 

    return conjunto;
}

int ehVazio(ConjuntoReais* primeiroTermo){ // retorna se a conjunto é ou não vazia, através do primeiro elemento
    return (primeiroTermo == NULL);
}

int existe(ConjuntoReais* primeiroTermo, float valor){ // procura se valor esta contido na conjunto
    if(ehVazio(primeiroTermo)){ // verifica se é vazio, caso sim, não contem
        return 0;
    }

    while(primeiroTermo != NULL){ // passa por todos elementos
        if(primeiroTermo->valor == valor){ // caso tenha valores iguais, retorna que contem
            return 1;
        }

        primeiroTermo = primeiroTermo->proximo;
    }
    return 0; // caso não ache, não possui
}

void limpa(ConjuntoReais** primeiroTermo){ // libera a memória de toda conjunto
    ConjuntoReais* proximo = NULL;
    ConjuntoReais* conjunto = *primeiroTermo;

    while(conjunto != NULL){ // passa por cada elemento limpando-o e pegando o próximo
        proximo = conjunto->proximo;
        free(conjunto);
        conjunto = proximo;
    }
    *primeiroTermo = NULL;
}

int remover(ConjuntoReais** primeiroTermo, float valor){ // libera memória de elemento com valor especifico
    ConjuntoReais* anterior = NULL;
    ConjuntoReais* conjunto = *primeiroTermo;
    int flag = 0;

    while(conjunto != NULL){ // passa por toda conjunto, procurando se existe o elemento especifico, setando a flag como verdadeiro e quebrando o laço
        if(conjunto->valor == valor){
            flag = 1;
            break;
        }
        anterior = conjunto;
        conjunto = conjunto->proximo;
    }

    if(flag){ // se achado
        if(anterior == NULL){ // se for o primeiro elemento, troca o valor do primeiroElemento para o segundo e libera a memória 
            *primeiroTermo = conjunto->proximo;
            free(conjunto);
            return 1;
        }
        anterior->proximo = conjunto->proximo; // caso não, atualiza o próximo do anterior e libera a memória
        free(conjunto);
        return 1;
    }

    return 0;
}

int insereInicio(ConjuntoReais** primeiroTermo, float valor){ // insere um novo elemento da lista, como primeiro elemento
    ConjuntoReais* conjunto = criarConjunto(valor); // criação do novo elemento

    if(conjunto){ // verifica se foi criado com sucesso
        conjunto->proximo = *primeiroTermo; // seta o antigo primeiro termo como o segundo (próximo)

        *primeiroTermo = conjunto; // coloca a variável primeiroTermo como o novo
        return 1;
    }

    return 0;
}

int insereOrdem(ConjuntoReais** primeiroTermo, float valor){ // insere elemento em ordem de valor

    if(existe (*primeiroTermo, valor)) return 0;

    if(ehVazio(*primeiroTermo)){ // verifica se conjunto é vazio, caso sim, insere no inicio
        
        printf ("VAZIO\n");
        printConjunto (*primeiroTermo, "Conjunto:");

        return insereInicio(primeiroTermo, valor);
    }

    ConjuntoReais* conjunto = criarConjunto(valor); // cria elemento da conjunto

    if(conjunto){ // se criado com sucesso
        ConjuntoReais* anterior = NULL;
        ConjuntoReais* auxiliar = *primeiroTermo;

        while(auxiliar != NULL && auxiliar->valor < valor){ // passa por todos elementos, até acabar ou achar um elemento com valor maior
            anterior = auxiliar;
            auxiliar = auxiliar->proximo;
        }

        if(anterior == NULL){ // se for o primeiro elemento, atualiza o valor do próximo, como o antigo primeiro elemento e atualiza o primeiroTermo
            conjunto->proximo = *primeiroTermo;
            *primeiroTermo = conjunto;
            return 1;
        }

        conjunto->proximo = anterior->proximo;  // caso não, atualiza os valores dos proximos, inserindo o novo elemento no meio
        anterior->proximo = conjunto;
        return 1;
    } 
    return 0;
}

ConjuntoReais* uniao(ConjuntoReais* primeiroTermo1, ConjuntoReais* primeiroTermo2){

    ConjuntoReais* primeiroTermo = AlocarConjunto();
    ConjuntoReais* conjunto1 = primeiroTermo1;
    ConjuntoReais* conjunto2 = primeiroTermo2;

    if(!ehVazio(conjunto1)) {
        primeiroTermo->valor = conjunto1->valor;
        primeiroTermo->proximo = NULL;
    } 
    else if(!ehVazio(conjunto2)) {
        primeiroTermo->valor = conjunto2->valor;
        primeiroTermo->proximo = NULL;
    }

    while(conjunto1 != NULL) {
        insereOrdem(&primeiroTermo, conjunto1->valor);
        conjunto1 = conjunto1->proximo;
    }

    while(conjunto2 != NULL) {
        insereOrdem(&primeiroTermo, conjunto2->valor);
        conjunto2 = conjunto2->proximo;
    }

    return primeiroTermo;
}

ConjuntoReais* intercessao(ConjuntoReais* primeiroTermo1, ConjuntoReais* primeiroTermo2){
    ConjuntoReais* primeiroTermo = AlocarConjunto();
    ConjuntoReais* conjunto1 = primeiroTermo1;
    ConjuntoReais* conjunto2 = primeiroTermo2;

    int contador = 0;
    while (conjunto1 != NULL) {

        conjunto2 = primeiroTermo2;
        while (conjunto2 != NULL) {

            if(conjunto1->valor == conjunto2->valor){
                if(contador == 0) {
                    primeiroTermo->valor = conjunto1->valor;
                    primeiroTermo->proximo = NULL;
                }

                insereOrdem(&primeiroTermo, conjunto1->valor);
                contador++;
                
            }

            conjunto2 = conjunto2->proximo;
        }
        conjunto1 = conjunto1->proximo;
    }

    return primeiroTermo;
}

int igualdade(ConjuntoReais* primeiroTermo1, ConjuntoReais* primeiroTermo2){

    if(tamanho(primeiroTermo1) != tamanho(primeiroTermo2)){
        return 0;
    }

    ConjuntoReais* conjunto1 = primeiroTermo1;
    ConjuntoReais* conjunto2 = primeiroTermo2;

    for(int i = 0; i <= tamanho(primeiroTermo1); i++){
        if(conjunto1->valor != conjunto2->valor){
            return 0;
        }
        conjunto1 = conjunto1->proximo;
        conjunto2 = conjunto2->proximo;
    }

    return 1;

}

int tamanho(ConjuntoReais* primeiroTermo){

    if(ehVazio(primeiroTermo)){ // verifica se o primeiro elemento é vazio, caso sim, retorna 0
        return 0;
    }

    int contador = 0;

    ConjuntoReais* auxiliar = primeiroTermo;
    
    while(auxiliar != NULL){ // procura pelo ultimo elemento
        auxiliar = auxiliar->proximo;
        contador++;
    }
    return contador;
}

void printConjunto(ConjuntoReais* primeiroTermo, char* mensagem){ // printa todos elementos do conjunto, com uma mensagem
    printf("%s: ", mensagem);

    while(primeiroTermo != NULL){
        printf("%.1f ", primeiroTermo->valor);
        primeiroTermo = primeiroTermo->proximo;
    }

    printf ("\n");

}