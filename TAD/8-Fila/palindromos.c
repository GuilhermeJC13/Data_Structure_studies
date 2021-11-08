#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "../7-Pilha/pilha.h"

int ehPalindromo(char* string){
    Pilha* pilha = NULL;
    Fila* fila = NULL;

    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] != ' '){
            inserePilha(&pilha, string[i]);
            insereFila(&fila, string[i]);
        }
    }

    while(!ehVazioFila(fila) && !ehVazioPilha(pilha)){
        if((removerPilha(&pilha) != removerFila(&fila))){
            return 0;
        }
    }
    return 1;
}

int main(void){
    char string_a[100] = "subi no onibus";
    char string_b[100] = "roma";
    char string_c[100] = "eu morri";
    char string_d[100] = "anotaram a data da maratona";

    printf("%s: %d\n", string_a, ehPalindromo(string_a));
    printf("%s: %d\n", string_b, ehPalindromo(string_b));
    printf("%s: %d\n", string_c, ehPalindromo(string_c));
    printf("%s: %d\n", string_d, ehPalindromo(string_d));
}