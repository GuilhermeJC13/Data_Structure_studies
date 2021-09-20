#include <stdio.h>
#include <stdlib.h>
#include "numero_complexo.h"

/*
● Exercício 2: Implemente um TAD para representar números complexos. Um
número complexo é da forma a+bi, em que a e b são números reais e i a unidade
imaginária. O TAD deve implementar as seguintes operações:
● Criação de número complexo, dados a e b.
● Liberação de um número complexo criado.
● Pegar os valores de a e b
● Setar os valores de a e b
● Soma de dois números complexos
● (a+bi)+(c+di) = (a+c)+(b+d)i
● Subtração de dois números complexos
● (a+bi)-(c+di) = (a-c)+(b-d)i
● Multiplicação de dois números complexos
● (a+bi)(c+di) = (ac-bd)+(bc+ad)i
● Divisão de dois números complexos
● (a+bi)/(c+di) = (ac+bd)/(c2
 + d2) +((bc-ad)/(c2
 + d2)) i
● Utilize seu TAD para implementar uma calculadora de números complexos.
*/

int main(void)
{

    Numero_complexo *numero_complexo_1;
    Numero_complexo *numero_complexo_2;

    Numero_complexo *numero_complexo_3;

    numero_complexo_1 = cria_numero_complexo(2, 3);
    acessa_numero_complexo(numero_complexo_1);

    numero_complexo_2 = cria_numero_complexo(3, 2);
    acessa_numero_complexo(numero_complexo_2);

    numero_complexo_3 = soma_numero_complexo(numero_complexo_1, numero_complexo_2);
    acessa_numero_complexo(numero_complexo_3);
}