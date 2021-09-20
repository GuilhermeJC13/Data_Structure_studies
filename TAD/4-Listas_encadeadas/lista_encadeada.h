typedef struct listaEncadeada ListaEncadeada;

ListaEncadeada* criarLista(int valor);
int ehVazio(ListaEncadeada* PrimeiroTermo);
int insereInicio(ListaEncadeada** primeiroTermo, int valor);
int insereFim(ListaEncadeada** primeiroTermo, int valor);
int existe(ListaEncadeada* primeiroTermo, int valor);
void printLista(ListaEncadeada* primeiroTermo, char* mensagem);
void limpa(ListaEncadeada** primeiroTermo);
int remover(ListaEncadeada** primeiroTermo, int valor);
int insereOrdem(ListaEncadeada** primeiroTermo, int valor)