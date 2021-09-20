#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

struct vetor{
    int numero_elementos;
    int dimensao;
    float *valor;
};


Vetor * cria_vetor(int dimensao){ // cria o vetor dinamico

    Vetor* vetor = (Vetor *) malloc(sizeof(Vetor)); // aloca memória para o struct vetor

    if(vetor == NULL){ // verifica se foi criado com sucesso
        return 0;
    }
    // seta valor de dimensão e numero de elementos como 0 (ainda sem elementos)
    vetor->dimensao = dimensao;
    vetor->numero_elementos = 0;

    vetor->valor = (float*) malloc(dimensao * sizeof(float *)); // aloca vetor de float baseado no numero de dimensões no valor do struct

    return vetor;
}

int insere_vetor(Vetor* vetor, float valor){ // insere valor no vetor

    if(vetor->numero_elementos == vetor->dimensao){ // se o numero de elementos for igual ao de dimensões, aloca mais memória e insere o novo valor
        vetor->dimensao++;
        vetor->valor = (float *) realloc(vetor->valor, sizeof(float) * vetor->dimensao);
        vetor->valor[vetor->numero_elementos] = valor;
        vetor->numero_elementos++;
    }
    else{ // caso não, apenas insere mais um elemento
        vetor->valor[vetor->numero_elementos] = valor;
        vetor->numero_elementos++;
    }

    return 1;
}

int tamanho_vetor(Vetor* vetor){ // retorna o numero de elementos
    return vetor->numero_elementos;
}

int acessa_vetor(Vetor* vetor, int posicao, float *valor){ // acessa um elemento do vetor
    *valor = vetor->valor[posicao];
    return 1;
}

void libera_vetor(Vetor* vetor){ // libera a memória dos valores e do struct
    free(vetor->valor);
    free(vetor);
}