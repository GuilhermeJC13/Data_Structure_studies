#include <stdio.h>
#include "matriz.c"

//● Exercício 1: Implemente as funções para o TAD Matriz Dinâmica

int main(void){

    Matriz *matriz;

    matriz = cria_matriz(4, 4);

    //Atribuição da matriz
    for(int i = 0; i < matriz->linhas; i++){
        for(int j = 0; j < matriz->colunas; j++){
            atribui_matriz(matriz, i, j, (i + j));
        }
    }

    //Acesso da matriz
    float valor;

    for(int i = 0; i < matriz->linhas; i++){
        for(int j = 0; j < matriz->colunas; j++){
            acessa_matriz(matriz, i, j, &valor);
            printf("Matriz[%d][%d] = %.1f \n", i, j, valor);
        }
    }

    printf("Linhas = %d \n", matriz->linhas);
    printf("Coluas = %d \n", matriz->colunas);

    libera_matriz(matriz);

    return 0;
}