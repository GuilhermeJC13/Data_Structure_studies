#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numero_complexo.h"

Numero_complexo* cria_numero_complexo(double real, double imaginario){

    Numero_complexo* numero_complexo = (Numero_complexo*) malloc(sizeof(Numero_complexo));

    if(numero_complexo == NULL){
        printf("ERRO! memória insuficiente para concluir procedimento! \n");
        exit(1);
    }

    numero_complexo->real = real;
    numero_complexo->imaginario = imaginario;

    return numero_complexo;

}

void libera_numero_complexo(Numero_complexo * numero_complexo){
    free(numero_complexo);
}

int atribui_numero_complexo(Numero_complexo* numero_complexo, double real, double imaginario){
    numero_complexo->real = real;
    numero_complexo->imaginario = imaginario;
    return(0);
}

void acessa_numero_complexo(Numero_complexo* numero_complexo){
    printf("%.2lf + %.2lfi \n", numero_complexo->real, numero_complexo->imaginario);
}

Numero_complexo* soma_numero_complexo(Numero_complexo* a, Numero_complexo* b){
    return cria_numero_complexo(a->real + b->real, a->imaginario + b->imaginario);
}

Numero_complexo* subtrai_numero_complexo(Numero_complexo* a, Numero_complexo* b){
    return cria_numero_complexo(a->real - b->real, a->imaginario - b->imaginario);
}

Numero_complexo* multiplica_numero_complexo(Numero_complexo* a, Numero_complexo* b){
    return cria_numero_complexo((a->real * b->real) - (a->imaginario * b->imaginario) , (a->imaginario * b->real) + (a->real * b->imaginario));
}

Numero_complexo* divide_numero_complexo(Numero_complexo* a, Numero_complexo* b){
    return cria_numero_complexo(((a->real * b->real) + (a->imaginario * b->imaginario)) / (pow(b->real, 2) + pow(b->imaginario, 2)), ((a->imaginario * b->real) - (a->real * b->imaginario)) / (pow(b->real, 2) + pow(b->imaginario, 2)));
}

