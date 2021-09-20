#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

struct listaEncadeada{
    int valor;
    ListaEncadeada* proximo;
};

ListaEncadeada* criarLista(int valor){ //criação de um elemento de uma lista encadeada
    ListaEncadeada* lista = (ListaEncadeada*) malloc(sizeof(ListaEncadeada)); //aloca memória para elemento
    
    if(lista){ //verifica se foi alocado da forma correta e seta o próximo elemento da lista como nulo e o valor com o parametro passado
        lista->valor = valor;
        lista->proximo = NULL;
    } 

    return lista;
}

int ehVazio(ListaEncadeada* primeiroTermo){ // retorna se a lista é ou não vazia, através do primeiro elemento
    return (primeiroTermo == NULL);
}

int insereInicio(ListaEncadeada** primeiroTermo, int valor){ // insere um novo elemento da lista, como primeiro elemento
    ListaEncadeada* lista = criarLista(valor); // criação do novo elemento

    if(lista){ // verifica se foi criado com sucesso
        lista->proximo = *primeiroTermo; // seta o antigo primeiro termo como o segundo (próximo)

        *primeiroTermo = lista; // coloca a variável primeiroTermo como o novo
        return 1;
    }

    return 0;
}

int insereFim(ListaEncadeada** primeiroTermo, int valor){ // insere um novo elemento da lista, como ultimo elemento
    if(ehVazio(*primeiroTermo)){ // verifica se o primeiro elemento é vazio, caso sim, adiciona como primeiro elemento
        return insereInicio(primeiroTermo, valor);
    }

    ListaEncadeada* lista = criarLista(valor); // cria elemento da lista

    if(lista){ // se criada com sucesso
        ListaEncadeada* auxiliar = *primeiroTermo;
        
        while(auxiliar->proximo != NULL){ // procura pelo ultimo elemento
            auxiliar = auxiliar->proximo;
        }

        auxiliar->proximo = lista; // seta elemento como o ultimo
        return 1;
    }
    return 0;
}

int existe(ListaEncadeada* primeiroTermo, int valor){ // procura se valor esta contido na lista
    if(ehVazio(primeiroTermo)){ // verifica se é vazio, caso sim, não contem
        return 0;
    }

    while(primeiroTermo != NULL){ // passa por todos elementos
        if(primeiroTermo->valor == valor){ // caso tenha valores iguais, retorna que contem
            return 1;
        }

        primeiroTermo = primeiroTermo->proximo;
    }
    return 0; // caso não ache, não possui
}

void printLista(ListaEncadeada* primeiroTermo, char* mensagem){ // printa todos elementos da lista, com uma mensagem
    printf("%s: ", mensagem);

    while(primeiroTermo != NULL){
        printf("%d ", primeiroTermo->valor);
        primeiroTermo = primeiroTermo->proximo;
    }

}

void limpa(ListaEncadeada** primeiroTermo){ // libera a memória de toda lista
    ListaEncadeada* proximo = NULL;
    ListaEncadeada* lista = *primeiroTermo;

    while(lista != NULL){ // passa por cada elemento limpando-o e pegando o próximo
        proximo = lista->proximo;
        free(lista);
        lista = proximo;
    }
    *primeiroTermo = NULL;
}

int remover(ListaEncadeada** primeiroTermo, int valor){ // libera memória de elemento com valor especifico
    ListaEncadeada* anterior = NULL;
    ListaEncadeada* lista = *primeiroTermo;
    int flag = 0;

    while(lista != NULL){ // passa por toda lista, procurando se existe o elemento especifico, setando a flag como verdadeiro e quebrando o laço
        if(lista->valor == valor){
            flag = 1;
            break;
        }
        anterior = lista;
        lista = lista->proximo;
    }

    if(flag){ // se achado
        if(anterior == NULL){ // se for o primeiro elemento, troca o valor do primeiroElemento para o segundo e libera a memória 
            *primeiroTermo = lista->proximo;
            free(lista);
            return 1;
        }
        anterior->proximo = lista->proximo; // caso não, atualiza o próximo do anterior e libera a memória
        free(lista);
        return 1;
    }

    return 0;
}

int insereOrdem(ListaEncadeada** primeiroTermo, int valor){ // insere elemento em ordem de valor
    if(ehVazio(*primeiroTermo)){ // verifica se lista é vazio, caso sim, insere no inicio
        return insereInicio(primeiroTermo, valor);
    }

    ListaEncadeada* lista = criarLista(valor); // cria elemento da lista

    if(lista){ // se criado com sucesso
        ListaEncadeada* anterior = NULL;
        ListaEncadeada* auxiliar = *primeiroTermo;

        while(auxiliar != NULL && auxiliar->valor < valor){ // passa por todos elementos, até acabar ou achar um elemento com valor maior
            anterior = auxiliar;
            auxiliar = auxiliar->proximo;
        }

        if(anterior == NULL){ // se for o primeiro elemento, atualiza o valor do próximo, como o antigo primeiro elemento e atualiza o primeiroTermo
            lista->proximo = *primeiroTermo;
            *primeiroTermo = lista;
            return 1;
        }

        lista->proximo = anterior->proximo;  // caso não, atualiza os valores dos proximos, inserindo o novo elemento no meio
        anterior->proximo = lista;
        return 1;
    } 
    return 0;
}