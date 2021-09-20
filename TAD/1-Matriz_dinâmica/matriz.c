#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz
{
    int linhas;
    int colunas;
    float * valor;
};

Matriz *cria_matriz(int numero_linhas, int numero_colunas)
{
    Matriz *matriz = (Matriz *)malloc(sizeof(Matriz));

    if (matriz == NULL)
    {
        printf("ERRO! memória insuficiente para concluir procedimento! \n");
        exit(1);
    }

    matriz->linhas = numero_linhas;
    matriz->colunas = numero_colunas;
    matriz->valor = (float *)malloc(numero_linhas * numero_colunas * sizeof(float));

    return (matriz);
}

void libera_matriz(Matriz *matriz)
{
    free(matriz->valor);
    free(matriz);
}

int acessa_matriz(Matriz *matriz, int linha, int coluna, float *valor)
{
    int index;

    if (linha < 0 || coluna < 0 || linha > matriz->linhas || coluna > matriz->colunas)
    {
        return(0);
    }

    index = linha * matriz->linhas + coluna;

    *valor = matriz->valor[index];

    return(1);
}

int atribui_matriz(Matriz *matriz, int linha, int coluna, float valor)
{
    int index;

    if (linha < 0 || coluna < 0 || linha > matriz->linhas || coluna > matriz->colunas)
    {
        printf("ERRO! Atribuição indevido! \n");
        exit(1);
    }

    index = linha * matriz->linhas + coluna;

    matriz->valor[index] = valor;

    return (0);
}

int numero_linhas(Matriz *matriz)
{
    return (matriz->linhas);
}

int numero_colunas(Matriz *matriz)
{
    return (matriz->colunas);
}