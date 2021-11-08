#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void){
    Fila* fila = criaFila(2);

    insereFila(&fila, 10);

    insereFila(&fila, 5);
    insereFila(&fila, 30);
    insereFila(&fila, 15);

    insereFila(&fila, 130);

    printaFila(fila, "fila");

    limpaFila(&fila);

    insereFila(&fila, 3);
    insereFila(&fila, 10);

    printaFila(fila, "fila");

    removerFila(&fila);
    printaFila(fila, "fila");

    if(existeFila(fila, 3)){
        printf("Existe um 3 na fila");
    }

    limpa(&fila);
}