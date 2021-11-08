#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int ehBalanceada(char *string){
    Pilha* pilha = NULL;
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == '{' || string[i] == '[' || string[i] == '('){
            inserePilha(&pilha, string[i]);
        }
        else{
            char topo = removerPilha(&pilha);
            if(!((string[i] == '}' && topo == '{') || (string[i] == ']' && topo == '[') || (string[i] == ')' && topo == '('))){
                limpaPilha(&pilha);
                return 0;
            }
        }
    }
    if(ehVazioPilha(pilha)){
        limpaPilha(&pilha);
        return 1;
    }
    else{
        limpaPilha(&pilha);
        return 0;
    }
}

int main(void){
    char string_1[100] = "{[()]}";
    char string_2[100] = "{[(()]}";
    char string_3[100] = "{[[(())]]}";
    char string_4[100] = "([[[{]]}";

    printf("%s: %d \n", string_1, ehBalanceada(string_1));
    printf("%s: %d \n", string_2, ehBalanceada(string_2));
    printf("%s: %d \n", string_3, ehBalanceada(string_3));
    printf("%s: %d \n", string_4, ehBalanceada(string_4));
}