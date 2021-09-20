#include <stdio.h>
#include <stdlib.h>
#include "conjunto_reais.h"

int main (void) {

    ConjuntoReais * conjunto = criarConjunto(9);

    if(ehVazio(conjunto)) {
        printf("O conjunto 1 eh vazio\n");
    } 
    else {
        printf("O conjunto 1 nao eh vazio\n");
    }

    printf("\n");

    insereOrdem(&conjunto, 19);

    insereOrdem(&conjunto, 3);

    insereOrdem(&conjunto, 5.9);


    remover(&conjunto, 3); 

    printConjunto(conjunto, "Conjunto"); 


    ConjuntoReais * conjunto2 = criarConjunto(1);

    insereOrdem(&conjunto2, 22);

    insereOrdem(&conjunto2, 19);

    insereOrdem(&conjunto2, 1.2);

    insereOrdem(&conjunto2, 19);

    printConjunto(conjunto2, "Conjunto 2");

    if(igualdade(conjunto, conjunto2)) {
        printf("Os conjuntos sao iguais\n");
    } 
    else {
        printf("Os conjuntos sao diferentes\n");
    }

    ConjuntoReais* conjuntoUniao = uniao(conjunto, conjunto2);
    printConjunto(conjuntoUniao, "Uniao dos conjuntos");

    ConjuntoReais* conjuntointer = intercessao(conjunto, conjunto2);
    printConjunto(conjuntointer, "Interseccao dos conjuntos");

    printf("\n");

    printf("Tamanho conjunto: %d\n", tamanho(conjunto));
    printf("Tamanho conjunto 2: %d\n", tamanho(conjunto2));
    printf("Tamanho conjunto uniao: %d\n", tamanho(conjuntoUniao));
    printf("Tamanho conjunto interseccao: %d\n", tamanho(conjuntointer));

    printf("\n");

    limpa(&conjunto);
    limpa(&conjunto2);
    limpa(&conjuntoUniao);
    limpa(&conjuntointer);

    return 0;
}