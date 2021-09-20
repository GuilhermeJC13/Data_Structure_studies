#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

/*
● Exercício 3: Implemente as funções para o TAD um vetor dinâmico realocável
*/

int main(void){

    Vetor *vetor;

    vetor = cria_vetor(3);

    insere_vetor(vetor, 1);
    insere_vetor(vetor, 2);
    insere_vetor(vetor, 3);
    insere_vetor(vetor, 4);
    insere_vetor(vetor, 5);

    printf("Vetor = [ ");
    float valor;

    for(int i = 0; i < tamanho_vetor(vetor); i++){
        acessa_vetor(vetor, i, &valor);
        printf("%.2f ", valor);
    }

    printf("] \n");

    printf("Tamanho = %d", tamanho_vetor(vetor));

    libera_vetor(vetor);

}