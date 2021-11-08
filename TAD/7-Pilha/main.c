#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void){
    Pilha* pilha = criaPilha('A');

    inserePilha(&pilha, 'B');

    inserePilha(&pilha, 'C');
    inserePilha(&pilha, 'D');
    inserePilha(&pilha, 'E');

    inserePilha(&pilha, 'F');

    printaPilha(pilha, "pilha");

    limpaPilha(&pilha);

    inserePilha(&pilha, 'A');
    inserePilha(&pilha, 'B');

    printaPilha(pilha, "pilha");

    removerPilha(&pilha);
    printaPilha(pilha, "pilha");

    if(existePilha(pilha, 'A')){
        printf("Existe um 'A' na pilha");
    }

    limpaPilha(&pilha);
}